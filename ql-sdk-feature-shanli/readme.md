# SDK说明

## 编译环境构建 

1. 编译kernel需要armcc编译工具。提供以下两种方式使用armcc。
    (1) 使用在ql-cross-tool\win32\owtoolchain目录下提供的ammcc编译工具，但需要在ql-cross-tool\win32\owtoolchain目录放入正版license。
	(2) 安装DS-5开发软件，并将armcc编译工具所在目录加入环境变量PATH中，添加变量ARMLMD_LICENSE_FILE到环境变量中，ARMLMD_LICENSE_FILE设置为armcc所使用的license；
2. 编译APP（ql-application）需要arm-gcc编译工具，SDK中已提供。

## 目录结构

### ql-sdk	根目录 

	---ql-config
		---quec-project	项目相关配置

	---ql-application 
		---threadx
			---api_map	从kernel测映射相关API到application
			---common	共用头文件及库
			---config	编译相关配置
			---interface app侧api接口以及示例代码
				---at
				---audio
				---camera
				---dev
				---driver
				---flash
				---fs
				---ftp
				---http
				---keypad
				---lcd
				---log
				---mbedtls
				---mqtt
				---network
				---ntp
				---os
				---ping
				---ssl
				---time
			---init		初始化

	---ql-cross-tool	交叉编译工具
		---win32	win32平台
			---host		主机工具 aboot
			---owtoolchain	交叉编译工具armmcc gcc gnumake

	---ql-kernel	系统内核代码及相关库
		---threadx	threadx系统
			---api_map	从kernel测映射相关API到application
			---audio
			---camera
			---common	共用头文件及库
			---config	编译相关配置
			---hal		外设驱动
			---init		启动相关代码
			---lcd
			---quec
			---quec_mbedtls	
			---tools	系统内核编译相关工具
	
	---ql-bootloader
		---boot33	bootloader

	---target 升级固件

## 编译指令：

1. ql-sdk目录下，执行 build.bat app		编译APP镜像(application)，若对app未做任何修改，可以不执行
2. ql-sdk目录下，执行 build.bat kernel		编译kernel，若对kernel未做任何修改，可以不执行
3. ql-sdk目录下，执行 build.bat bootloader	编译bootloader，若对bootloader未做任何修改，可以不执行
4. ql-sdk目录下，执行 build.bat firmware	生成固件

>> 注：未执行编译操作的组件，默认使用ql-sdk\ql-config\quec-project\aboot\images目录下的镜像


## Release History：

	
**[LTE01R06A02_C_SDK_A_BETA0527][01] 2022-05-27**
 --1，新增支持uart 256KHz 波特率的功能

**[LTE01R06A02_C_SDK_A_BETA0602][01] 2022-06-02**
 --1，新增支持SPI CLK  100KHZ~700KHZ 的功能
 --2 删除common\lib中的camera和lcd库，否则lcd和camera无法裁剪
 --3 解决调用ql_usb相关接口死机问题

**[LTE01R06A02_C_SDK_A_BETA0608][01] 2022-06-08**
 --1,新增LOGO侧获取时间count功能
 --2 800MCNGA项目增加GNSS功能
 --3,新增LOGO侧LCD显示功能

**[LTE01R06A02_C_SDK_A][02] 2022-06-08**

**[LTE01R06A02_C_SDK_A_BETA0610A][01] 2022-06-10**
 --1 800MCNGA项目增加GNSS功能
 --2,修复ADC不能正常读取

**[LTE01R06A02_C_SDK_A_BETA0613][01] 2022-06-13**

**[LTE01R06A02_C_SDK_A_BETA0614][01] 2022-06-14**
 --1，解决开机进行数据拨号失败的问题
 --2解决调用socket接口编译报错问题

**[LTE01R06A02V03_C_SDK_A][03] 2022-06-15**

**[LTE01R06A02_C_SDK_A_BETA0618][01] 2022-06-18**
 --1,新增获取SN2 功能
 --2,logo阶段新增SPI驱动
 --3,新增boot侧ADC功能

**[LTE01R06A02_C_SDK_A_BETA0620A][01] 2022-06-20**
 --1，新增支持双卡单待功能

**[LTE01R06A02_C_SDK_A_BETA0623][01] 2022-06-23**

**[LTE01R06A02_VOLTE_C_SDK_A_BETA0630][01] 2022-06-30**

**[LTE01R06A02_C_SDK_A_BETA0704][01] 2022-07-04**
 --1解决camera无法裁剪完全的问题,app侧lib库后缀名由.a修改为.lib
 --2，新增wifiscan功能

**[LTE01R06A02_VOLTE_C_SDK_A_BETA0705][01] 2022-07-05**

**[EC800MCNGAR06A01M08_OCPU_VOLTE_BETA0711][01] 2022-07-11**

**[LTE01R06A02_VOLTE_C_SDK_A_BETA0711][01] 2022-07-12**

**[LTE01R06A02_C_SDK_A_BETA0712][01] 2022-07-12**
 --1 优化软关机流程

**[LTE01R06A02_VOLTE_C_SDK_A_BETA0713][01] 2022-07-13**

**[LTE01R06A01_VOLTE_C_SDK_A][01] 2022-07-19**
 --1,OPEN版本取消网络模式灯和网络状态灯的控制

**[LTE01R06A03_C_SDK_A][01] 2022-07-21**

**[LTE01R06A03_C_SDK_A_BETA0723][01] 2022-07-23**

**[LTE01R06A03_C_SDK_A_BETA0726][01] 2022-07-26**

**[LTE01R06A03_C_SDK_A_THIN_BETA0805][01] 2022-08-05**

**[LTE01R06A03_C_SDK_A_BETA0811][01] 2022-08-11**

**[LTE01R06A03_C_SDK_A_BETA0815][01] 2022-08-15**
**[EC600MCNLAR06A03M08_OCPU_BL_BETA0819A][01] 2022-08-19**
**[LTE01R06A04_C_SDK_A][01] 2022-08-19**


**[LTE01R06A04_C_SDK_A_BETA0821][01] 2022-08-21**

**[EC600MCNLAR06A04M08_OCPU_BL_BETA0822A][01] 2022-08-22**

**[LTE01R06A02_VOLTE_C_SDK_A][01] 2022-08-23**

**[LTE01R06A04_C_SDK_A_BETA0826][01] 2022-08-26**

**[EC600MCNLAR06A04M08_OCPU_BL_BETA0829][01] 2022-08-29**

**[LTE01R06A02_VOLTE_C_SDK_A_BETA0831][01] 2022-08-31**

**[EC600MCNLAR06A01M08_OCPU_SIMB_BETA0906][01] 2022-09-07**

**[LTE01R06A04_C_SDK_A_BETA0907][01] 2022-09-07**

**[LTE01R06A02_VOLTE_C_SDK_A_BETA0913][01] 2022-09-14**

**[LTE01R06A04_C_SDK_A_BETA0921][01] 2022-09-19**
 --1,升级到最新的010.075Q基线

**[LTE01R06A02_VOLTE_C_SDK_A_BETA0921][01] 2022-09-21**

**[LTE01R06A05_C_SDK_A_BETA0924][01] 2022-09-24**

**[LTE01R98A01_C_SDK_A][02] 2022-09-24**

**[LTE01R06A05_C_SDK_A_BETA0928][01] 2022-09-28**

**[LTE01R06A02_VOLTE_C_SDK_A_BETA0928][01] 2022-09-28**

**[LTE01R06A05_C_SDK_A_BETA1011][01] 2022-10-11**
 --1: 车网客户定制需求增加接口用于ap侧主动发起agps数据的接口

**[LTE01R06A02_VOLTE_C_SDK_A_BETA1011][01] 2022-10-11**

**[LTE01R06A02_VOLTE_C_SDK_A_BETA1018][01] 2022-10-18**

**[LTE01R06A05_C_SDK_A_BETA1021][01] 2022-10-21**

**[LTE01R06A02_VOLTE_C_SDK_A_BETA1026][01] 2022-10-26**

**[LTE01R06A06_C_SDK_A_BETA1026][01] 2022-10-26**

**[LTE01R06A06_C_SDK_A_BETA1031][01] 2022-10-31**
 --1,新增获取ADC原始寄存器值的api
 --2，新增获取ADC原始寄存器值的api
 --3,新增调整多媒体播放eq参数api
 --4,解决阿尔丰客户POS机语音播报延时的问题

**[EC600MCNLAR06A01M08_OCPU_SIMB_BETA1101][01] 2022-11-01**
 --1新增nand文件系统

**[EC600MCNLAR06A02M08_OCPU_THIN_BETA1101][01] 2022-11-01**

**[LTE01R06A06_C_SDK_A_BETA1102][01] 2022-11-02**

**[LTE01R06A07_C_SDK_A][01] 2022-11-02**
 --1,优化QuecOpen SDK 头文件存放的位置

**[EC600MCNLAR06A02M08_OCPU_THIN][02] 2022-11-03**

**[LTE01R06A02_VOLTE_C_SDK_A_BETA1105][01] 2022-11-05**
 --1,优化增强型面参数检查
 --2,修复短信ql_get_sms_msg_mode() Api存在内存泄漏的问题

**[LTE01R06A07_C_SDK_A_BETA1107][01] 2022-11-07**
 --1,新增加nand文件系统文件夹创建、打开、读取、关闭功能
 --2,修复ql_nw_get_cell_info查邻区api返回的邻区信息错位显示

**[EC600MCNLAR06A01M08_OCPU_SIMB_BETA1124][01] 2022-11-24**

**[LTE01R06A07_C_SDK_A_BETA1201][01] 2022-12-01**
 --1,修复产线拼版烧录boot continue功能
 --2,修复开机原因获取不准

**[LTE01R06A02_VOLTE_C_SDK_A_BETA1201][01] 2022-12-01**
 --1,新增ql_rtos_task_create_ex接口用于实现任务的分时调度

**[EC800MCNGAR06A01M08_OCPU_BETA1202][01] 2022-12-02**
 --1,修复ql_play_mp3_stream_start接口播放MP3流概率出现开头杂音的问题

**[LTE01R06A02_VOLTE_C_SDK_A_BETA1206][01] 2022-12-06**

**[LTE01R06A07_C_SDK_A_BETA1207][01] 2022-12-07**

**[LTE01R06A07_C_SDK_A_BETA1208][01] 2022-12-08**

**[LTE01R06A08_C_SDK_A][01] 2022-12-09**

**[LTE01R06A03_VOLTE_C_SDK_A][01] 2022-12-10**

**[EC600MCNLAR06A02M08_OCPU_THIN_BETA1214][01] 2022-12-14**

**[LTE01R06A08_C_SDK_A_BETA1214][01] 2022-12-14**

**[EC600MCNLAR06A02M08_OCPU_BL][01] 2022-12-22**
 --1, 新增acctimer接口，实现us级别的定时

**[LTE01R06A08_C_SDK_A_BETA1228][01] 2022-12-28**

**[EC800MCNGAR06A01M08_BT_OCPU_BETA0106][01] 2023-01-06**

**[LTE01R06A08_C_SDK_A_BETA0202][01] 2023-02-02**

**[LTE01R06A08_C_SDK_A_BETA0208][01] 2023-02-08**

**[LTE01R06A03_VOLTE_C_SDK_A_BETA0213][01] 2023-02-14**

**[LTE01R06A03_VOLTE_C_SDK_A_BETA0216][01] 2023-02-16**
 --1,修复2+4项目fota后会导致NVM格式化，从而引起的相关问题

**[LTE01R06A08_C_SDK_A_BETA0218][01] 2023-02-18**

**[LTE01R06A09_C_SDK_A][01] 2023-02-26**
 --1,修复修改点52002同升级085基线存在冲突问题

**[LTE01R06A09_C_SDK_A_BETA0306][01] 2023-03-06**

**[LTE01R06A03_VOLTE_C_SDK_A_BETA0309][01] 2023-03-10**

**[LTE01R06A09_C_SDK_A_BETA0321][01] 2023-03-21**
 --1，解决特定场景下触发DSP_COM_ERR=0x8888的问题
 --2/N，为Y时，填写RN描述
 --3，新增fbf差分升级fota签名功能
 --4,修复QLTS指令使用引起的QENG指令无法正常使用的问题
 --5,修复小系统绑网卡异常fota失败
 --6，+CREG 兼容对于EPS ONLY网络拒绝值上报，对于LTEONLY的项目建议使用AT+CEREG?查询网络状态

**[LTE01R06A04_VOLTE_C_SDK_A_BETA0325][01] 2023-03-25**

**[LTE01R06A04_VOLTE_C_SDK_A][02] 2023-03-30**

**[EC200MCNGBR06A01M08_OCPU_BETA0330][01] 2023-03-30**

**[EC600NCNACR06A01M08_OCPU_BETA0403][01] 2023-04-03**
 --1，SDK中固件打包时将使用的feedback也打包到DBG下

**[LTE01R06A09_C_SDK_A_BETA0417][01] 2023-04-17**

**[LTE01R06A09_C_SDK_A_BETA0428][01] 2023-04-28**

**[EC600NCNACR06A01M08_OCPU_BETA0508][01] 2023-05-08**
 --1,修复DCS默认不指定类型时，MT=1，收到短信以CMT形式上报问题
 --2,修复被错误裁剪的audioloop指令
 --3，解决BIP下udp建立socket失败的问题；EAB功能配置指定的AC等级不生效的问题

**[LTE01R06A04_VOLTE_C_SDK_A_BETA0509][01] 2023-05-09**
 --1 增加持续输出PCM时钟

**[LTE01R06A09_C_SDK_A_BETA0524][01] 2023-05-24**
 --1，解决Open获取phonenum失败问题
 --2，解决AT+CPBR返回结果少了\r\n的问题
 --3，播报延时优化
 --4,修复OPEN 8M LTEONLY THIN项目双卡被裁剪问题
 --5，使能PB功能AT命令
 --6/N，为Y时，填写RN描述
 --7/N，为Y时，填写RN描述
 --8，新增支持设置url后进行边下载边升级的全量升级app方案
 --9，新增支持设置url后进行边下载边升级的全量升级app方案

**[LTE01R06A10_C_SDK_A][01] 2023-06-01**
 --1，新增fbf方式差分升级支持差分包存放于外挂文件系统功能
 --2,修复LTE ONLY项目国外运营商cops查询不到结果问题
 --3

**[LTE01R06A10_C_SDK_A_BETA0601][01] 2023-06-01**

**[LTE01R06A02_BT_C_SDK_A][01] 2023-06-30**
 --1,新增备份app功能
 --2,优化camera预览噪点问题
 --3,修复开机设置音频参数死机问题
 --4，THIN M2 版本使能SIM卡热插拔
 --5/N，为Y时，填写RN描述
 --6/N，为Y时，填写RN描述

**[EC200MCNGBR06A01M08_OCPU_BETA0701][01] 2023-07-01**

**[LTE01R06A05_VOLTE_C_SDK_A][01] 2023-08-11**

**[LTE01R06A10_C_SDK_A_BETA0915][01] 2023-09-15**
 --1,修复wifi下发dhcp携带dns地址，DNS解析异常问题
 --2， 修复除主串口外其他串口初始化115200以下波特率时发生死机问题
 --3,修复AT+CPBW测试命令不显示text字段的问题
 --4，同步startup目录下SPI驱动中GPIO18/19的pinmux分配错误修改

**[LTE01R06A05_VOLTE_C_SDK_A_BETA1020][01] 2023-10-20**
 --1/N，为Y时，填写RN描述

**[LTE01R06A05_VOLTE_C_SDK_A_BETA1107][01] 2023-11-07**
 --1,合入Bug #90761 patch修复存储在SM，CLASS0&MT=1上报+CMTI问题，使用+CMT上报
 --2，优化开机阶段播放tts卡顿问题
 --3，修复ql_fota_image_verify调用之后内存没有及时释放的问题
 --4，优化ql_audio_track_write写入耗时
 --5，修复PA场景下打开tts播放首个字时会丢音
 --6，增加旧音频API适配
 --7,修复AT+QSCLK=1/0开机阶段打开文件系统概率性卡住问题
 --8,修复ql_wifi_opt_get获取网卡地址不正确问题
 --9,新增需求1602平台项目对Manufacturer、Porduct修改，模块Manufacturer为Quectel，Porduct为项目名称
 --10/N，为Y时，填写RN描述
 --11，[open]同步R07的app加载逻辑到R06分支

**[LTE01R06A12_C_SDK_A][02] 2023-11-17**
 --1/N，为Y时，填写RN描述

**[LTE01R06A06_VOLTE_C_SDK_A][01] 2023-11-17**

**[LTE01R06A03_BT_C_SDK_A_BETA1216][01] 2023-12-16**

**[LTE01R06A12_C_SDK_A_BETA1226][01] 2023-12-26**
 --1,新增XLAT功能
 --2,新增音频降噪算法
 --3,新增音频降噪算法
 --4,新增音频降噪算法

**[LTE01R06A12_C_SDK_A_DM_BETA0104][01] 2024-01-04**
 --1,新增注册\注销特殊功能引脚唤醒中断接口

**[LTE01R06A12_C_SDK_A_BETA0105][01] 2024-01-05**
 --1/N，为Y时，填写RN描述

**[LTE01R06A03_BT_C_SDK_A][02] 2024-01-09**
 --1/N，为Y时，填写RN描述
 --2,新增白名单功能

**[LTE01R06A13_C_SDK_A_BETA0116][01] 2024-01-16**

**[EC800MCNLER06A01M08_CAC_OCPU_BETA0120][EC800MCNLER06A01M08_CAC_OCPU_BETA0120] 2024-01-20**
 --1，修复asr remap功能失效问题
 --2,新增是否立即发送周期性发送心跳包数据的配置
 --3/N，为Y时，填写RN描述

**[LTE01R06A13_C_SDK_A_DM_BETA0126][01] 2024-01-26**
 --1，开启回环音AT指令功能
 --2，CFUN1,1关机前先配置模块CFUN=0
 --3，开启回环音AT指令功能
 --4，新增AT+QNWCFG="lte_csi_ext"指令

**[LTE01R06A06_VOLTE_C_SDK_A_BETA0129][01] 2024-01-29**

**[LTE01R06A13_C_SDK_A_BETA0222][01] 2024-02-22**
 --1,新增at+qnwlock="lte"
 --2,修改first_send的默认初始值为1为立即发送

**[LTE01R06A06_VOLTE_C_SDK_A_BETA0329][01] 2024-03-29**
 --1,修改PDP激活状态未绑网卡状态下CGPADDR查询不到IPV6问题或者查询的为错误IPV6地址
 --2,修改PDP激活状态未绑网卡状态下CGPADDR查询不到IPV6问题
 --3,新增新大陆定制需求-注销卡、欠费卡也能查询到CSQ
 --4,修复双卡项目下只使用卡2时，usb网卡拨号之后能正常使用，但是qnetdevctl指令查询state为0的问题
 --5，1602 2M 默认打开老方案, 其余项目默认打开新方案(仅打开场景一)

**[LTE01R06A14_C_SDK_A][01] 2024-04-08**
 --1，EC200MCN_GB,EG800KCN_GC支持配置AGPS服务器

**[LTE01R06A14_C_SDK_A_BETA0412][01] 2024-04-12**

**[LTE01R06A14_C_SDK_A_BETA0425][01] 2024-04-25**
 --1,新增音频降噪算法
 --2/N，为Y时，填写RN描述
 --3,新增音频降噪算法
 --4,新增KWS语音识别算法
 --5，修复at+qcfg="clat"返回参数个数少一个的问题

**[EC600MCNLAR06A02M08_OCPU_THIN_BETA0426][01] 2024-04-26**

**[LTE01R06A07_VOLTE_C_SDK_A_BETA0514][01] 2024-05-14**
 --1,新增KWS语音识别算法
 --2,修复ql_sim_get_phonenumber获取到错误电话号码的问题;
 --3,新增海外ims配置，添加APN自适应功能（备注：APN自适应功能，仅会纠偏使能功能前，默认承载的APN配置。如果在使能功能后，客户有自行配置非空APN，即使无法使用，也不进行纠偏。）
 --4,新增海外ims配置，添加APN自适应功能
 --5,新增海外ims配置，添加APN自适应功能
 --6，修复at+qcfg="clat"测试指令返回值少逗号的问题
 --7,删除QFTPPUT失败上报多余的ERRPR的问题

**[LTE01R06A14_C_SDK_A_BETA0515][01] 2024-05-15**

**[LTE01R06A07_VOLTE_C_SDK_A][02] 2024-06-06**
 --1，修复AT+QSLCFG="negotiatetime"指令的参数单位由(ms)变为(s)，保持与文档一致。

**[LTE01R06A14_C_SDK_A_BETA0618][01] 2024-06-18**
 --1,新增[AT+QICFG="TCP/RAWDATA/CRC"]命令用于TCP进入透传后与上位机加入CRC16校验
 --2，新大陆定制AT+QIACT=1第一路激活逻辑修改为,激活时检测到第一路激活且绑定，返回ok
 --3，弱网环境下处于无服务时ql_nw_get_cell_info接口返回时间长的问题

**[EC800MCNLER06A01M08_CAC_OCPU_BETA0619][01] 2024-06-19**

**[LTE01R06A04_BT_C_SDK_A_BETA0621][01] 2024-06-21**

**[LTE01R06A07_VOLTE_C_SDK_A_BETA0626][01] 2024-06-26**
 --1,优化AT+CFUN指令在特定条件下执行报错的问题;
 --2,合入Bug #89652 patch解决开启UAC+WIFI部分host无法正常枚举USB
 --3,释放ql_xlat.h头文件

**[LTE01R06A15_C_SDK_A][01] 2024-07-24**
 --1,优化at+qcfg="cmux/channel"指令
 --2，EG810MLALC和EG810MEU_LC，放开at+qcfg="ims"指令
 --3,修复PDNConnectivityReq无法携带CHAP/PAP的鉴权参数的问题
 --4，1606 8M项目新增at+qnetdualchcfg指令
 --5，1606 8M项目新增at+qnetdualchcfg指令

**[LTE01R06A07_VOLTE_C_SDK_A_BETA0731][01] 2024-07-31**
 --1，优化xlat功能再xlat网络和非xlat网络切换后，出现数传异常的问题
 --2,修复字符和数字组合号码解析乱码问题
 --3，优化长短信的reference_num，UDH中的reference_num每发送一条自增1（对255取余数，用于区分长短信
 --4,优化at+qcfg="cmux/channel"指令

**[LTE01R06A08_VOLTE_C_SDK_A][01] 2024-08-02**

**[LTE01R06A15_C_SDK_A_BETA0808][01] 2024-08-08**
 --1/N，为Y时，填写RN描述

**[LTE01R06A04_BT_C_SDK_A_BETA0810][01] 2024-08-10**

**[LTE01R06A05_BT_C_SDK_A][01] 2024-08-12**

**[LTE01R06A16_C_SDK_A][01] 2024-09-07**
 --1，解决开启clat后进行ECM拨号，查询绑定网卡状态失败的问题

**[LTE01R06A16_C_SDK_A_BETA0912][01] 2024-09-12**
 --1，AT+QGPSLOC支持配置主动上报URC，支持周期上报和定位时上报
 --2，解决开启clat后进行ECM拨号，查询绑定网卡状态失败的问题

**[New Version]**
