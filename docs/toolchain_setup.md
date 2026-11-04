# Ubuntu / WSL 工具链恢复

仓库已包含 Linux GCC 工具链压缩包，由 Git LFS 保存：

`ql-sdk-feature-shanli/ql-cross-tool/Linux/gcc-arm-none-eabi-9-2019-q4-major-x86_64-linux.tar.bz2`

版本为 GNU Arm Embedded 9-2019-q4-major / GCC 9.2.1，压缩包为
116,802,378 字节，解压后约 496 MiB。适用于 **x86_64 Linux / WSL**，
不能直接在 ARM Ubuntu 或 Windows 原生环境执行。

解压目录被 `.gitignore` 忽略，所以另一台机器克隆后没有该目录是正常的。
如果没有安装 Git LFS、跳过了 LFS 下载或使用源码 ZIP，压缩包也可能只是一个
很小的文本指针，不能交给 tar 解压。

## 在另一台 Ubuntu 上使用

先安装构建和解压工具（需要时由你在该机器上执行）：

```bash
sudo apt-get update
sudo apt-get install git git-lfs make tar bzip2
git lfs install
```

进入已有的 `master_lte_firmware` Git 克隆，获取本次开发分支：

```bash
git fetch origin
git switch codex/tcpudp-domain
git pull --ff-only
git lfs pull
cd ql-sdk-feature-shanli
bash ./extract_toolchain.sh
./build.sh
```

`git lfs pull` 下载 SDK 所需的全部 LFS 对象，包含内核库。解压脚本自身只会
按需下载工具链压缩包；它不会把其他 SDK 大文件的指针自动变成真实库文件。

也可以直接运行 `./build.sh`：`all` 和 `app` 构建已自动调用该脚本。
无需把编译器目录加入系统 PATH，也无需 sudo 解压。

## 脚本行为

- 已有可运行的编译器、汇编器、链接器、头文件和核心库时直接复用。
- 压缩包缺失或为 Git LFS 指针时，尝试只拉取对应工具链对象。
  没有 Git 克隆或 Git LFS 时给出具体操作提示。
- 解压前验证固定 SHA256；校验失败时停止，不使用损坏的压缩包。
- 在临时目录解压，验证关键程序能运行，并实际编译包含标准头文件的 ARM 对象。
- 验证成功后才安装到构建所需位置。原有不完整目录保存在
  `ql-cross-tool/Linux/.toolchain-backup.XXXXXX/`，不会直接删除。
- 临时文件和备份都被 Git 忽略；脚本退出时清理自身创建的临时解压目录。

```bash
bash ./extract_toolchain.sh --check   # 只检查，不下载、不解压
bash ./extract_toolchain.sh --force   # 重新解压，保留旧目录备份
bash ./extract_toolchain.sh --help
```

原 Makefile 也有自动解压逻辑，但仅判断工具链目录是否存在；空目录或部分解压
会让它跳过解压。新脚本检查关键文件和可执行程序，可处理这种情况。

压缩包 SHA256：
`bcd840f839d5bf49279638e9f67890b2ef3a7c9c7a9b25271e83ec4ff41d177a`
