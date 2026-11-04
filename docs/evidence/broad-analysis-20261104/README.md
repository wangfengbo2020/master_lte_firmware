# Broad 与 SDK 静态分析证据索引

本目录支持两份代码阅读文档：[音频采集与播放](../../shanli_audio_code_guide.md)、[低功耗与 Broad 移除](../../shanli_low_power_and_broad_removal.md)。整理于 2026-11-04，源文件分析主要完成于 2026-11-03。没有把反汇编伪装成原始 C 源码，也没有进行新的板上测试。

## 分析对象与版本

源码基线为 `f93851d96225f49473addfb64bdda7c95ba4a1ab`。以下相对路径以仓库根目录为起点。

| 对象 | 说明 | SHA-256 |
|---|---|---|
| `ql-sdk-feature-shanli/ql-kernel/threadx/common/lib/broad.lib` | 含版本 `5.0.4-20260812-release`；主要反汇编对象 | `ad2f68d5d06e71dd577b5e2d37bea5a7e5d74a251a0fd7f13b2e70c311fa4130` |
| `ql-sdk-feature-shanli/ql-kernel/threadx/common/lib/quectel-build.lib` | SDK 实现，含 `ql_platform.o`、`ql_power.o`；不应给它套用 Broad 版本号 | `63ee17bc14005305f062ef152d799b5431ed3f6748ceda5db205c3b17362095d` |
| `ql-sdk-feature-shanli/ql-config/quec-project/aboot/images/kernel.bin` | 5,025,792 字节，含 `5.0.4-20251022-release`，与既有设备日志一致 | `b276be1dc30ea395050ec1b4ce97ddac826e98f0088c1b5545561fc152202208` |

**新库和预编译内核存在版本差异。** 新库中的函数、调频和定时策略不能直接当作旧内核运行事实。`image_provenance.txt` 还记录了现有 `kernel.axf` 与 `kernel.bin` 的不匹配证据，不能直接将前者的地址映射到后者。

应用目录 `ql-application/threadx/common/lib/broad.lib` 是通过 `m_get_api_ptr` 转发的包装层；本文分析 Broad 内部行为时用的是上表中的**内核目录**库。

## 文件与用途

| 文件 | 来源及支持的结论 |
|---|---|
| [audio_core.txt](audio_core.txt) | Broad 音频关键函数、符号重定位和相关字符串：PCM 采集、编码、队列、解码、播放、启停调频 |
| [hardware_boundary.txt](hardware_boundary.txt) | Broad PA 回调保存、转发、SDK 回调注册；软件按键事件与讲话业务 |
| [hardware_refs.txt](hardware_refs.txt) | Broad 对 `ql_*` 系统/硬件 API 的静态引用列表 |
| [named_functions.txt](named_functions.txt) | Broad OEM wake lock 空实现、HAL 包装和业务 power mode 相关函数 |
| [session_power_core.txt](session_power_core.txt) | Broad 时间换算、会话空闲判定及 power mode 分支 |
| [power_behavior.txt](power_behavior.txt) | Broad 业务定时器、事件 42 通知、软件 alarm 路径 |
| [event42_dispatch.txt](event42_dispatch.txt) | 聚焦 API/AT 两条分发路径对事件 42 的默认处理；包含原文件位置和跳表验证 |
| [ql_platform.disasm.txt](ql_platform.disasm.txt) | SDK `ql_platform.o`，特别是 `ql_cpu_fre_set(4/255)` 与 `fc_config_fix` |
| [ql_power.disasm.txt](ql_power.disasm.txt) | SDK `ql_power.o`，自动休眠开关、sleep flags、wake lock 的门控与引用计数 |
| [original_example_lpm.c](original_example_lpm.c) | 原始 Shanli 基线 `9976d975d7b4a0073fb67def9718727bdf7aca06` 的应用休眠示例；只作历史对照，不参与编译 |
| [image_provenance.txt](image_provenance.txt) | 打包内核的大小、哈希、Broad 版本、与已有 ELF 的对应关系检查 |

`ql_power.o` 提取对象的 SHA-256 为 `8635f7525d56022d530bfb0652c95243c37e363e3f1fa3240c9bc063a88d92a6`，已核对证据对象与当前仓库 `quectel-build.lib` 中的同名成员一致。虽然证据原路径含 `vendor`，这里不是仅凭供应商名称推断实现相同。

各证据文件的校验值列在 [SHA256SUMS](SHA256SUMS)。校验只证明本目录文件未变，不替代行为验证。

## 如何阅读反汇编

1. `audio_core.txt` 等聚焦提取文件可能把函数显示地址重置为 0。头部 `OBJECT`、`FUNCTION`、`OFFSET` 指明原对象和函数偏移。
2. 重定位项 `R_ARM_THM_CALL` / `R_ARM_ABS32` 用于确认真实被调函数或常量引用。未链接目标文件中显示的临时跳转地址不等于最终固件地址。
3. 函数内常量池可能被反汇编器显示成指令，不能据此推导执行逻辑。参数、跳表结论需要结合寄存器、常量池和重定位核对。
4. 可见符号中没找到 GPIO/EINT 调用，属于限定范围的静态检查结果，不能证明所有间接路径和其他版本均不存在硬件访问。
5. `event42_dispatch.txt` 仅证明所检查的 Broad API/AT 包装路径没有处理 42，不等于证明整个系统不存在其他消费者。

## 在 WSL 复核的命令入口

在仓库根目录执行；以下命令只读取源库，并把提取对象放入新的临时目录：

```bash
sdk="$PWD/ql-sdk-feature-shanli"
bin="$sdk/ql-cross-tool/Linux/gcc-arm-none-eabi-9-2019-q4-major/bin"
broad="$sdk/ql-kernel/threadx/common/lib/broad.lib"
vendor="$sdk/ql-kernel/threadx/common/lib/quectel-build.lib"
analysis_dir=$(mktemp -d /tmp/shanli-audio-power-check.XXXXXX)

sha256sum "$broad" "$vendor" \
  "$sdk/ql-config/quec-project/aboot/images/kernel.bin"
"$bin/arm-none-eabi-ar" t "$broad"
"$bin/arm-none-eabi-nm" -A -u "$broad"

"$bin/arm-none-eabi-ar" p "$broad" oem_dsp.o > "$analysis_dir/oem_dsp.o"
"$bin/arm-none-eabi-objdump" -dr "$analysis_dir/oem_dsp.o" \
  > "$analysis_dir/oem_dsp.disasm.txt"
"$bin/arm-none-eabi-ar" p "$vendor" ql_platform.o > "$analysis_dir/ql_platform.o"
"$bin/arm-none-eabi-objdump" -dr "$analysis_dir/ql_platform.o" \
  > "$analysis_dir/ql_platform.disasm.txt"
"$bin/arm-none-eabi-ar" p "$vendor" ql_power.o > "$analysis_dir/ql_power.o"
"$bin/arm-none-eabi-objdump" -dr "$analysis_dir/ql_power.o" \
  > "$analysis_dir/ql_power.disasm.txt"
```

这些是复核入口，生成完整对象反汇编，输出布局不一定与已整理的聚焦证据相同。工具链需先按仓库现有解压流程准备好。不要把反汇编中的业务名称、网络常量或保存配置的函数误当成硬件省电的证明。
