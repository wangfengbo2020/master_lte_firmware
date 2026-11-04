# LTE TCP/UDP 域名测试

本次将心跳服务器从固定 IPv4 改为 `sip.paitalk.com:19000`，版本标识为
`v0.4-domain-no-autosleep`。2026-11-04 公共 DNS 查询返回 A 记录
`123.57.79.87`；设备实际结果以 LTE 日志为准。

## 实现

- 等待 PDP profile 1 的有效 IPv4，然后通过
  `getaddrinfo_with_pcid("sip.paitalk.com", NULL, ..., 1)` 解析。
- 选择结果列表中的第一个有效 IPv4，复制地址后释放整个结果链表。
  TCP 和 UDP 共用这个地址，socket 仍绑定 profile 1 的本地 IPv4。
- 解析失败或没有有效 IPv4 时不创建 socket、不发送数据，等待 3 秒后重试；
  不回退到固定 IP。DNS 返回码与 socket errno 分开记录。
- 同一次 PDP 连接缓存解析结果，避免每 3 秒重复解析。PDP 不可用、本地 IP
  改变，或断开/恢复通知改变 epoch 时，关闭旧 socket 并重新解析。
  本版本不按 DNS TTL 定期刷新；同一 PDP 期间仅 TCP 重连仍沿用缓存。
  若主动更换服务器 A 记录，需让设备重新建立 PDP 或重启以更新地址。
- SDK DNS 接口同步执行，没有单次超时参数。日志记录解析开始、返回结果及
  SDK tick 耗时；DNS 期间重新检查 PDP 和 epoch，网络变化则丢弃结果。
  因而启动/重连解析阶段不保证严格每 3 秒发送，正常心跳间隔仍为 3 秒。

这次改动延续之前的诊断设置：请求禁止自动休眠，Broad 内核保持初始化、
应用登录暂停，保留 TCP/UDP ACK、接收队列和原始数据诊断。

## 编译和验证

在 WSL 执行：

```bash
cd /home/administrator/myproject/master/master_lte_firmware
./ql-sdk-feature-shanli/ql-application/threadx/interface/poc/tests/run_host_tests.sh
cd ql-sdk-feature-shanli
./build.sh
```

主机 mock 测试覆盖原有连接/接收行为，以及 DNS 失败重试、使用非旧 IP 的
解析结果、UDP 来源校验、结果链表释放、缓存失效和解析期间网络变化。
这些测试不访问真实调制解调器，不能替代烧录后的 SIM 网络验证。

烧录后应看到：

```text
[SL][TCPUDP] v0.4-domain-no-autosleep server=sip.paitalk.com:19000 profile=1 interval=3s
[SL][TCPUDP] DNS start host=sip.paitalk.com profile=1
[SL][TCPUDP] DNS resolved host=sip.paitalk.com ip=123.57.79.87 port=19000 profile=1 elapsed_ticks=...
```

随后应出现 TCP 连接、TCP/UDP 发送及 `TCP received: ACK ...`、
`UDP received: ACK ...`。只有解析成功和 `sent` 日志，仍不足以证明服务器
收到数据或设备收到回复。

- 如果停在 `DNS start`：保留完整日志，关注 SDK DNS 是否返回。
- 如果出现 `DNS failed`：记录 `ret`、PDP IP 和 DNS 地址，检查当前卡的 DNS
  可达性、域名解析和访问策略。
- 如果地址解析正确仍无 ACK：结合服务端接收/回复日志继续定位数据路径。

域名指向阿里云公网 IP 不会自动获得卡商放行；此前提到的
`*.aliyuncs.com` 规则不覆盖 `sip.paitalk.com`。需要卡商规则允许实际域名及
相应 TCP/UDP 访问，最终以设备测试为准。
