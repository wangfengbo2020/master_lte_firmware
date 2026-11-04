# Shanli 音频采集、播放与 GPIO 控制：代码阅读指南

本文回答三个问题：应用如何拿到麦克风 PCM、音频如何送到扬声器、Broad 与板级硬件分别负责什么。配套文档是[低功耗策略与 Broad 移除方案](shanli_low_power_and_broad_removal.md)。

分析日期：2026-11-04。源码基线：`f93851d96225f49473addfb64bdda7c95ba4a1ab`。本文只整理证据和后续设计，没有改变固件行为。行号均指该基线；后续改动请优先按函数名定位。

## 1. 先分清两条音频路径

**想从 C 代码学习采集和播放，先读产测回环 `mic_loopback_core()`。** 它直接调用 SDK 读取 PCM，再写入播放通道，不经过 Broad 对讲协议。

正常 POC 对讲则是另一条路径：应用处理 PTT 按键，调用 `broad_speak(1/0)`；Broad 内部完成采集、编码、网络收发、解码和播放。应用收到的 `ui_audio_state()` 是状态通知，**不包含 PCM 缓冲区**。

```text
产测回环：麦克风 → SDK record_read → 应用 PCM 缓冲区 → SDK track_write → 扬声器

POC 上行：PTT → 应用事件处理 → broad_speak(1)
                            → Broad 内部采集/编码 → 网络
POC 下行：网络 → Broad 内部解码/播放 → SDK 音频通道 → 功放/扬声器
                                    └→ PA 状态回调 → 应用 GPIO/MCU 控制
```

当前测试配置暂停了 Broad 业务登录，PTT 事件也会被清除。下面的正常对讲流程描述的是源码中的业务路径，不能据此认为当前测试固件已在运行对讲。

## 2. 按这个顺序读源码

以下路径均在 `ql-sdk-feature-shanli/ql-application/threadx/` 内。

| 顺序 | 入口 | 阅读目的 |
|---|---|---|
| 1 | [production_test.c:834](../ql-sdk-feature-shanli/ql-application/threadx/interface/production/production_test.c#L834) `mic_loopback_core` | 完整的 PCM 打开、读取、播放、关闭流程 |
| 2 | [ql_audio.h:932](../ql-sdk-feature-shanli/ql-application/threadx/common/include/ql_audio.h#L932) | 核对 record/track API 和参数 |
| 3 | [example_poc.c:342](../ql-sdk-feature-shanli/ql-application/threadx/interface/poc/example_poc.c#L342) `ql_audio_init` | codec、增益、音量、TTS 和音频路径 |
| 4 | [example_poc.c:824](../ql-sdk-feature-shanli/ql-application/threadx/interface/poc/example_poc.c#L824) `poc_start_speak` | PTT 如何进入 Broad 业务 |
| 5 | [example_poc.c:492](../ql-sdk-feature-shanli/ql-application/threadx/interface/poc/example_poc.c#L492) `ui_audio_state` | 讲话、收听状态如何反馈给应用 |
| 6 | [example_poc.c:277](../ql-sdk-feature-shanli/ql-application/threadx/interface/poc/example_poc.c#L277) `pa_set_level` | GPIO、MCU 外部功放与业务状态的关系 |
| 7 | [example_poc.c:1096](../ql-sdk-feature-shanli/ql-application/threadx/interface/poc/example_poc.c#L1096) `example_eint_test` | PTT 的 GPIO 中断注册 |
| 8 | [tts_gbk.c:63](../ql-sdk-feature-shanli/ql-application/threadx/interface/poc/tts_gbk.c#L63) `tts_play_cn` | 独立于对讲编码器的中文 TTS 路线 |

## 3. 应用如何直接获取和播放 PCM

### 3.1 当前回环参数

参数定义在 [production_test.c:787](../ql-sdk-feature-shanli/ql-application/threadx/interface/production/production_test.c#L787)：

```c
#define MIC_LOOP_RATE       16000
#define MIC_LOOP_CHANNELS   2
#define MIC_LOOP_FRAME_MS   20
#define MIC_LOOP_VOLUME     7
#define MIC_LOOP_TRACK_OPT  0x100
```

这条路径配置为 16 kHz、2 通道，每轮期望读取 20 ms 数据。帧长度按每采样点 2 字节计算：

```text
16000 samples/s × 2 channels × 2 bytes/sample × 20/1000 s = 1280 bytes
```

这里的“2 通道”是 SDK 配置值，不能据此推断电路板有两个独立麦克风。`0x100` 只传给**播放**接口；录音 option 为 0。根据 [ql_audio.h:288](../ql-sdk-feature-shanli/ql-application/threadx/common/include/ql_audio.h#L288)，播放 option 的 bit8–11 是 EQ 索引，因此这里选索引 1；格式字段为 0，对应 [S16_LE](../ql-sdk-feature-shanli/ql-application/threadx/common/include/ql_audio.h#L221)。

### 3.2 真正取得音频的代码

以下为原代码节选，省略了外层任务和时长控制，**不是可以单独复制编译的完整函数**：

```c
/* 打开播放、采集通道。 */
track_hd = ql_audio_track_open(
    MIC_LOOP_RATE, MIC_LOOP_CHANNELS, MIC_LOOP_TRACK_OPT, NULL);
record_hd = ql_audio_record_open(
    MIC_LOOP_RATE, MIC_LOOP_CHANNELS, 0, NULL);

/* 在 while (!g_mic_loop_stop) 内，每轮重置可用缓冲区大小。 */
unsigned int read_len = frame_len;
if (ql_audio_record_read(record_hd, buf, &read_len) == 0 && read_len > 0)
{
    ql_audio_track_write(track_hd, buf, read_len);
    done_bytes += read_len;
}
else
{
    ql_rtos_task_sleep_ms(5);
}
```

来源：[打开通道](../ql-sdk-feature-shanli/ql-application/threadx/interface/production/production_test.c#L868)、[读取并播放](../ql-sdk-feature-shanli/ql-application/threadx/interface/production/production_test.c#L884)。

`buf` 就是应用拿到的原始音频。`read_len` 同时承担输入容量和输出有效长度的角色，每轮必须重新设置，不能一直使用上次返回的短帧长度。PCM 是二进制数据，不能用 `strlen()` 计算长度，也不能用 `%s` 输出内容。

以后要把音频发往自己的服务器，采集点就在这里。但需要在发送前明确采样率、声道、位宽、帧长、编码方式和包格式；目前每 3 秒发送一次的 TCP/UDP 心跳不是实时音频传输服务。

### 3.3 完整生命周期与当前代码的限制

`mic_loopback_core()` 的流程是：等待 SDK 音频就绪 → 分配 1280 字节缓冲区 → 选择内部 codec → 保存原音量、设置测试音量及 receiver 路径 → 开 PA → 打开 track/record → 循环读写 → 恢复音量 → 关 PA → 关闭两个句柄 → 释放缓冲区。

现有实现适合作为阅读入口，生产化复用前需要补足以下处理：

- 等待 `ql_get_audio_state()` 没有超时，初始化异常时可能一直等待。
- 检查了 `malloc`，但没有完整检查通道打开失败和 `track_write` 返回值。`done_bytes` 增加不等于这些字节已经全部从扬声器播放。
- 关闭操作应只针对已成功打开的句柄，异常路径也应关闭 PA、恢复音量并释放资源。
- Broad、TTS、产测若共享音频设备，需要统一协调占用、停止和恢复，不能假设任意并发打开都安全。
- 此函数依赖 POC 任务提前初始化 PA GPIO。把函数复制到新项目并不等于搬走了全部依赖。

这些是源码检查结果和后续改进建议，本次未修改实现。

### 3.4 如何触发已有回环

在连接到**产测 USB CDC 命令通道**后，逐步操作，不要把启停命令整段粘贴：

1. 发送 `AT+PROD=1` 并等待应答，进入产测。
2. 发送 `AT+MDMIC=1`，等待 `[PROD] MIC loopback: running (dur=0ms)` 日志，再对麦克风说话，检查扬声器输出。
3. 测试结束发送 `AT+MDMIC=0`，等待 `[PROD] MIC loopback: stopped`。
4. 发送 `AT+PROD=0` 退出产测。

入口见 [产测模式解析](../ql-sdk-feature-shanli/ql-application/threadx/interface/production/production_test.c#L1070) 和 [MIC 命令处理](../ql-sdk-feature-shanli/ql-application/threadx/interface/production/production_test.c#L929)。启停命令的 `+MDMIC:OK` 只表示已创建任务或设置停止标志，不代表录放音已经启动或资源已经释放。这是应用自己的命令协议；此前日志中的 `+CMD:ERR,MODE` 不能直接解释为蜂窝调制解调器 AT 接口异常。

本次整理没有操作板子或执行上述命令。建议下一轮先验证本地回环能稳定录放，再加入网络传输，分别记录读取字节、播放返回值、停止后的句柄和 PA 状态。

## 4. 音频初始化和音量究竟在哪里设置

[`ql_audio_init()`](../ql-sdk-feature-shanli/ql-application/threadx/interface/poc/example_poc.c#L342) 的真实主体如下：

```c
while (!ql_get_audio_state())
{
    ql_rtos_task_sleep_ms(50);
}
ql_codec_choose(AUD_INTERNAL_CODEC, NULL);
ql_set_audio_gain();
ql_tts_init(tts_cb);
ql_set_denoise_flag(1);
ql_set_volume(8);
ql_tts_set_volume(-17000);
ql_set_audio_path_receiver();
```

`ql_set_audio_gain()` 先设置主音量 6、DTMF 音量 8、TX DSP gain 6、TX codec gain 2，等待 100 ms；随后上面的主音量又设为 8。不要把首次设置的 6 当作最终主音量。

初始化之后还执行了 [Broad 音量配置](../ql-sdk-feature-shanli/ql-application/threadx/interface/poc/example_poc.c#L974)：`BND_VOICE=0`、`BND_TTS=2`、`BND_TONE=10`。Broad 的业务音量与 SDK 主音量不是同一接口，不能直接按数值相互替换。源码部分旧注释与实际参数不一致，应以执行代码和板上测量为准。

源码选择了内部 codec 和 receiver 路径，并启用了降噪开关；它本身不足以证明具体麦克风接线、完整回声消除算法或实际增益曲线，这些还需要 SDK 文档、原理图和录音测试。

## 5. PTT 是应用监听的，Broad 接收业务请求

### 5.1 板级定义

[e02t_board_cfg.h:12](../ql-sdk-feature-shanli/ql-application/threadx/common/include/e02t_board_cfg.h#L12) 当前启用 `E02T_BOARD_NEW_4G`：

| 用途 | 当前定义 | 直接控制者 |
|---|---|---|
| PTT 输入 | `GPIO_PIN_NO_16` | 应用 `example_poc.c` |
| PA 输出 | `GPIO_PIN_NO_20` | 应用 PA 函数、产测函数 |
| MCU UART | `QL_BT_UART_PORT`，115200 | 应用 MCU 协议模块 |
| GNSS 电源 / 复位 | `GPIO_PIN_NO_17` / `GPIO_PIN_NO_5` | 应用 GNSS 任务 |

这些是 SDK GPIO 编号，不能未经原理图核对就当作模组封装脚号。旧板条件分支的 PA/PTT/GNSS 电源分别为 53/14/6。

### 5.2 GPIO 中断到业务线程

[`example_eint_test()`](../ql-sdk-feature-shanli/ql-application/threadx/interface/poc/example_poc.c#L1096) 初始化 PA 为低电平，PTT 为上拉输入，然后注册：

```c
ret = ql_eint_register(CORGET_POC_PTT_PIN, PIN_BOTH_EDGE,
                      PIN_PULL_PU, ptt_key_irq_handler, NULL);
ql_eint_enable(CORGET_POC_PTT_PIN, PIN_BOTH_EDGE);
```

[回调](../ql-sdk-feature-shanli/ql-application/threadx/interface/poc/example_poc.c#L882) 只负责通知和重新使能：

```c
static void ptt_key_irq_handler(void)
{
    ql_rtos_flag_release(ptt_key_event_flag,
                         QL_PTTKEY_CHANGE_FLAG, QL_FLAG_OR);
    ql_eint_enable(CORGET_POC_PTT_PIN, PIN_BOTH_EDGE);
}
```

主任务在 [第 1009 行](../ql-sdk-feature-shanli/ql-application/threadx/interface/poc/example_poc.c#L1009) 等待事件，再等待 20 ms 去抖，通过 `ql_gpio_get_level()` 读取电平。低电平按下、高电平释放，之后调用 `poc_start_speak()` / `poc_stop_speak()`。

```text
GPIO16 双边沿 → ptt_key_irq_handler → 事件标志
→ 工作任务去抖、读电平 → poc_start_speak / poc_stop_speak
→ broad_speak(1 / 0)
```

`poc_start_speak()` 还检查登录、入组、已在讲话、正在收听等条件。`poc_stop_speak()` 只有在 `g_is_speaking` 成立时才通知 Broad 停止，避免失败的抢麦请求错误干扰收听。

另有 [MCU UART 的 `AT+PTT=1/0` 路径](../ql-sdk-feature-shanli/ql-application/threadx/interface/poc/e02t_uart_mcu.c#L288)，它向同一工作任务发送 PRESS/RELEASE 事件。因此替换 Broad 时，GPIO 与 MCU 两个输入都要保留或明确重新定义。

事件对象当前由主任务创建，GPIO 中断由另一个初始化任务启用。重构时应保证“创建事件对象 → 注册回调 → 启用中断”的顺序；这里只指出潜在启动时序风险，未证明现有板子已触发该故障。

### 5.3 普通按键中断不等于深睡唤醒

[`ql_eint_register` 声明](../ql-sdk-feature-shanli/ql-application/threadx/common/include/ql_gpio.h#L100) 区分普通回调和 wakeup 回调；当前 PTT 把 wakeup 回调传为 `NULL`，这条活跃路径也没有调用 `ql_eint_enable_wakeup()`。所以可以确认应用在监听 GPIO，不能据此确认 PTT 已具备所有低功耗状态下的唤醒能力。

## 6. 功放是谁开的，谁关的

应用通过 [第 789 行](../ql-sdk-feature-shanli/ql-application/threadx/interface/poc/example_poc.c#L789) 注册 `broad_register_pa_cb(shanli_audio_pa_contrl)`。

`shanli_audio_pa_contrl()` 的策略是：PTT 按住时保持 PA 开启；正在收听时拒绝关闭请求；其他情况下才执行 Broad 给出的状态。

[`pa_set_level()`](../ql-sdk-feature-shanli/ql-application/threadx/interface/poc/example_poc.c#L277) 执行实际硬件动作：

| 操作 | 执行顺序 |
|---|---|
| 打开 | GPIO20 拉高；MCU 已就绪时发送 `AT+PA=OPEN` |
| 关闭 | MCU 已就绪时发送 `AT+PA=CLOSE` 并等待 50 ms；GPIO20 拉低 |
| 重复状态 | 通过 `g_pa_level` 跳过重复设置 |

开启路径**实际没有 50 ms 等待**，不要照搬该行旧注释。产测还有独立的 [`prod_pa_set()`](../ql-sdk-feature-shanli/ql-application/threadx/interface/production/production_test.c#L797)，未来统一音频服务时，应收拢这些控制入口，避免 TTS、对讲、回环互相关掉功放。

Broad 对硬件的影响不只通过应用回调。新库反汇编显示，`broad_task()` 注册 SDK 的 `ql_bind_speakerpa_cb(speak_pa_cb)`；SDK 状态经 `broad_notify_pa_status()` 转发给上述应用回调。详见 [PA 调用证据](evidence/broad-analysis-20261104/hardware_boundary.txt)。删除 Broad 后需要由自己的服务接管这个通知链，同时避免与仍在运行的 Broad 内核重复注册同一回调。

## 7. Broad 内部怎样采集、编码和播放

### 7.1 版本和可信范围

以下内容来自静态反汇编，不是恢复出的原始 C 源码：

| 分析对象 | 确认结果 |
|---|---|
| `ql-kernel/threadx/common/lib/broad.lib` | 字符串版本 `5.0.4-20260812-release`，完整业务实现 |
| `ql-application/threadx/common/lib/broad.lib` | 通过 `m_get_api_ptr` 转发的应用 API 包装层 |
| 打包使用的 `ql-config/quec-project/aboot/images/kernel.bin` | 含 `5.0.4-20251022-release`，与之前设备日志一致 |

**新静态库与实际打包的旧内核不是同一版本。** 下述线程和参数可用来理解已有实现，但不能保证逐项就是板上旧内核正在执行的行为；也不能用现有 `kernel.axf/map` 强行解释这个 `kernel.bin`。哈希和来源见[证据索引](evidence/broad-analysis-20261104/README.md)。

### 7.2 上行采集链

依据 [audio_core.txt](evidence/broad-analysis-20261104/audio_core.txt) 中 `oem_stream_recorder_start/thread/on_timer` 及其重定位信息，可重建为：

```text
oem_stream_recorder_start
  → 创建编码器、采集线程，配置 20 ms 软件定时回调
oem_stream_recorder_thread
  → ql_pcm_open（1 通道、8000 Hz、periodcnt=2、flags=5）
  → ql_pcm_read（每次请求 320 字节 PCM）
  → hal_encoder_run（编码输出容量参数 40）
  → 内部队列记录：4 字节长度字段 + 40 字节负载空间
oem_stream_recorder_on_timer
  → 把实际长度的编码数据回调给上层
  → hal_dsp_on_has_data / RTP 上行 → socket 发送
```

320 字节对应 8 kHz、单声道、16 位的 20 ms PCM。40 字节是编码输出容量相关参数，44 字节是内部队列记录大小，**不能当成完整网络包长度**。具体编码器名称尚未可靠确认，不能直接写成 AMR、Opus 等。

这里看到的是线程调用 `ql_pcm_read()`，再通过软件回调交付编码帧；没有证据表明应用直接收到了麦克风 DMA 中断数据。

### 7.3 下行播放链

```text
socket 可读 → RTP 接收/取帧
  → hal_sound_write_frame → hal_dsp_write
  → oem_stream_player_write → 内部队列
oem_stream_player_thread
  → ql_pcm_open（1 通道、8000 Hz、periodcnt=1、flags=9）
  → hal_decoder_run
  → 解出 160 samples 时 ql_pcm_write（320 字节）
```

这是库里观察到的参数，不是新代码的通用推荐配置；尤其 `periodcnt=1` 与头文件中的范围说明存在差异，复用前应对照实际 SDK。

`oem_aud.o` 还有另一条 `ql_pcm_play_init()` → `ql_pcm_play()` 适配路径。虽然函数名为 `oem_audin_*`，从调用关系看这里用于播放，不能仅按名字把它认成麦克风采集。

### 7.4 录放音时的 CPU 频率

新 Broad 库的采集/播放启动函数调用 `ql_cpu_fre_set(4)`；头文件将 4 定义为 `QL_PP4`、624 MHz。停止路径调用 `ql_cpu_fre_set(255)`。

对同 SDK `quectel-build.lib:ql_platform.o` 的分析确认，255 分支会**清零 `fc_config_fix` 并返回 -1**，不直接设置一个低频档位。这是解除固定频率标志，不是释放睡眠锁，也不是已测得 CPU 立即降频。详细说明见配套低功耗文档及 [ql_platform.disasm.txt](evidence/broad-analysis-20261104/ql_platform.disasm.txt)。

## 8. 中文 TTS 是独立的播放路线

[`tts_play_cn()`](../ql-sdk-feature-shanli/ql-application/threadx/interface/poc/tts_gbk.c#L63) 当前代码：

```c
void tts_play_cn(const char *utf8_text)
{
    char hex_buf[512];
    int len = tts_utf8_to_ucs2_hex(utf8_text, hex_buf, sizeof(hex_buf));
    if (len > 0) {
        ql_tts_play(1, hex_buf);
    }
}
```

文件名虽叫 `tts_gbk.c`，实际是 UTF-8 转 UCS2 十六进制文本后交给 SDK。它不需要应用调用 Broad 对讲编码器，但仍需要 SDK TTS 初始化、合理的 PA 控制和与其他播放通道的协调。

## 9. 不依赖 Broad 的音频模块应如何拆分

下面是后续重构建议，**当前工程尚未实现这些模块**：

```text
board_io：PTT GPIO / MCU PTT → 统一事件
audio_service：初始化、设备占用、PCM capture/playback、停止清理
pa_service：统一管理播放/录音/TTS/产测的功放请求
voice_transport：自己的编码、网络帧、抖动缓冲和重连
intercom_service：登录、组、抢麦等业务状态（需要时保留）
```

先保留产测回环作为板级验证，再替换 Broad 音频链。不能只把 `broad_speak()` 换成一次 `record_read()`：原库还承担流式录放、编解码、网络缓冲、业务状态和功放通知。

拆分时最先解决启动依赖：[主任务](../ql-sdk-feature-shanli/ql-application/threadx/interface/poc/example_poc.c#L949) 在初始化音频和 MCU UART 之前一直等 `broad_get_init_status()`。超过 120 秒只报错，没有跳出。若先移除 Broad 初始化，后面的板级服务也会一直无法启动。

下一轮可按三个可观察阶段推进：

1. 独立启动音频、MCU、PTT、PA，确认本地回环、TTS、按键日志和停止清理正常。
2. 固定音频格式，先完成一条采集上传和一条接收播放路径，记录每帧长度、序号、丢帧和缓冲深度。
3. 再迁移对讲业务与功耗策略，完成应用和内核两层 Broad 移除；具体依赖及验收见[另一份文档](shanli_low_power_and_broad_removal.md)。

## 10. 证据与阅读边界

- [证据索引与库哈希](evidence/broad-analysis-20261104/README.md)：说明来源、版本差异和反汇编地址读法。
- [音频函数反汇编](evidence/broad-analysis-20261104/audio_core.txt)：采集、编码、队列、解码及播放。
- [硬件引用清单](evidence/broad-analysis-20261104/hardware_refs.txt)：Broad 对 SDK 音频、UART、网络等接口的直接引用。
- [PA 与按键业务边界](evidence/broad-analysis-20261104/hardware_boundary.txt)：PA 回调与软件按键事件；本次静态检查未发现 Broad 直接注册 GPIO/EINT 的可见符号，不能扩大为“任何版本和间接路径都不接触 GPIO”。

本文核对的是源码和静态库，没有新增板上音频测试或功耗实测；真实音质、增益、深睡唤醒和旧内核行为仍需硬件验证。
