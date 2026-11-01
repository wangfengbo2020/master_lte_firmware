# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build and flash commands

This repository is a Quectel OpenCPU SDK tree for EC800MCN_LE. Linux development is centered on the application layer; kernel and bootloader rebuilds are primarily Windows/ARMCC flows.

### Linux

```bash
./build.sh                # build app and package firmware
./build.sh app            # build ql-application/threadx only
./build.sh firmware       # package firmware from existing app build output
./build.sh clean          # remove app and packaged artifacts
./build.sh rebuild        # clean, rebuild app, and package firmware
./build.sh help           # show script help
./flash.sh                # extract latest target/*.zip and flash with QDloader (uses sudo if needed)
```

### Direct make invocation

```bash
cd ql-application/threadx
make -f Makefile PLATFORM=linux        # compile app.bin and package firmware via arelease.sh
make -f Makefile PLATFORM=linux clean  # clean application build output
```

Use this when iterating on application-layer changes without the wrapper script.

### Windows / full SDK rebuild flows

```bat
build.bat app
build.bat kernel
build.bat bootloader
build.bat firmware
build.bat clean
```

Notes:
- `build.bat kernel` requires ARM Compiler 5 and a valid `ARMLMD_LICENSE_FILE`.
- `build.bat project_name -p <name> ...` changes the target project configuration.
- Linux builds use the bundled GCC toolchain under `ql-cross-tool/Linux/gcc-arm-none-eabi-9-2019-q4-major/`; the makefile auto-extracts it from the tarball if needed.

## Testing and verification

There is no unit test framework, linter, or CI pipeline in this repository.

Verification is manual:
1. Build firmware.
2. Flash it to the module with `./flash.sh` or the packaged QDloader flow.
3. Validate behavior on hardware through serial logs and AT/UART commands.

For the current POC application, useful manual checks include:

```text
AT+PTT=1      # simulate PTT press over MCU UART
AT+PTT=0      # simulate PTT release
AT+VOL=UP     # raise speaker volume
AT+VOL=DOWN   # lower speaker volume
AT+NOISE=1    # enable denoise
AT+NOISE=0    # disable denoise
```

There is no single-test runner; validation is done by exercising the relevant feature on-device.

## Repository structure

The important top-level areas are:
- `ql-application/threadx/` — application-layer code you will usually modify.
- `ql-kernel/threadx/` — prebuilt kernel/platform layer; rebuilding it is a separate Windows/ARMCC workflow.
- `ql-bootloader/boot33/` — bootloader sources.
- `ql-config/` — device/project configuration and packaging inputs.
- `ql-cross-tool/` — bundled Linux and Windows toolchains plus packaging utilities.
- `tools/QDloader` — flashing utility used by `flash.sh`.
- `target/` — packaged firmware output copied here by `build.sh`.
- `readme/` — vendor PDFs and platform documentation.

## Parent design and hardware docs

Some of the most important design context is not inside this repository tree, but in the parent `../doc/` directory.

Read these before changing production mode, USB CDC, or MCU protocol behavior:
- `../doc/usb_cdc_config_and_production_design.md` — primary design for the E02T USB CDC AT-style production/config protocol.
- `../doc/usb_cdc_pc_validation_checklist.md` — expected PC-side validation flow for USB CDC production features.
- `../doc/mcu_4g_uart_protocol.md` — existing MCU↔4G runtime UART protocol used outside the PC production flow.
- `../doc/production_test_design.md` — older design notes with useful mode-gating ideas, but it includes an earlier JSON-style direction and should not override the implemented AT-style CDC protocol.

Important hardware and product references in `../doc/`:
- `../doc/E02T电路原理图1.pdf`
- `../doc/E02_MAIN_ESIM_V2.1_260317.pdf`
- `../doc/e02t_v0.0.0.1/云耳机E02T产品需求说明书V1.1.pdf`

Keep the two command domains separate:
- PC↔modem production/config commands run over `QL_USB_CDC_PORT`.
- MCU↔modem runtime control commands run over `QL_MAIN_UART_PORT`.

## Architecture overview

### Layered firmware build

The firmware is assembled from three layers:
1. **Bootloader** in `ql-bootloader/boot33/`
2. **Kernel/platform** in `ql-kernel/threadx/`
3. **Application** in `ql-application/threadx/`

Application development is mostly isolated to layer 3. The app links against prebuilt platform libraries from `ql-application/threadx/common/lib/` and is packaged with existing kernel images into a firmware zip.

### How the application build is composed

`ql-application/threadx/Makefile` is the top-level app build selector. It does not compile every interface module; it only builds the directories listed in `COMMPILE_DIRS`. Right now that list enables:
- `interface/posix`
- `interface/wifi`
- `interface/log/src`
- `interface/driver`
- `interface/dev`
- `interface/poc`
- `interface/production`

Each enabled module has its own `Makefile` that produces a static library under its local `build/` directory. The common build logic lives in `ql-application/threadx/config/common/makefile.mk`, which:
- configures the ARM Cortex-R4 GCC toolchain
- compiles each module into a `.lib`
- links the app ELF/BIN
- runs `arelease.sh` to package firmware on Linux
- copies debug artifacts (`.elf`, `.map`, kernel symbols) into `target/<VERSION>/DBG/`

The active device target is stored in `ql-config/config/QuecCurPrj.txt` and is currently `EC800MCN_LE`.

### Runtime registration model

Application entry points are not collected from a central main function. Instead, tasks are registered with the SDK using `application_init(...)`. The kernel discovers these registrations at boot and starts the corresponding tasks.

In the current POC module, `example_poc.c` registers at least:
- the main POC task
- a GPIO/EINT initialization task

When adding a module, the usual steps are:
1. create a new directory under `ql-application/threadx/interface/`
2. add a module `Makefile`
3. register one or more entry tasks with `application_init(...)`
4. add the module path to `COMMPILE_DIRS`
5. add any needed prebuilt libraries to `DEFAULT_LIBS` if required

### Current product logic: POC application

The main product logic lives in `ql-application/threadx/interface/poc/`.

Important files:
- `example_poc.c` — main POC task, network/audio init, Shanli SDK integration, GPIO PTT handling
- `e02t_uart_mcu.c` / `.h` — UART protocol bridge between MCU and modem for PTT/volume/noise commands
- `tts_gbk.c` — Chinese TTS text conversion/playback helper
- `fota_test.c`, `fota_version_check.c` — FOTA-related support code

The high-level startup flow in `example_poc.c` is:
1. wait for early platform init
2. create the shared PTT event flag
3. initialize network: SIM check -> registration wait -> data call
4. wait for Shanli `broad` SDK init to finish
5. initialize audio and TTS
6. configure Shanli platform settings and log in
7. set Broad SDK volumes
8. initialize the MCU UART command channel
9. enter the main event loop handling PTT press/release and keepalive ping

### Dual PTT input path

PTT events can come from two sources that converge on the same flag-based event loop:
- **GPIO interrupt** on `GPIO_PIN_NO_14`
- **MCU UART commands** parsed from `AT+PTT=1` / `AT+PTT=0`

`e02t_uart_mcu.c` intentionally splits UART handling into:
- an interrupt callback that only reads bytes and queues them
- a dedicated RTOS parser task that assembles lines and converts commands into flag events

Those UART-generated events reuse the same `QL_PTTKEY_*` flags defined in `e02t_uart_mcu.h`, so GPIO and UART inputs follow the same debounce and speak/release logic in `example_poc.c`.

### Audio and PA control behavior

The POC app coordinates three related state machines:
- login/in-group readiness
- speak vs listen state from the Shanli `broad_*` SDK
- PA GPIO control on `GPIO_PIN_NO_53`

A key implementation detail is that PA shutdown is guarded during active listening and during PTT ownership transitions, so code that changes PTT/audio behavior should be checked carefully for regressions in receive-audio continuity.

### Production and config protocol

The production implementation lives in `ql-application/threadx/interface/production/` and already follows the AT-style USB CDC design from `../doc/usb_cdc_config_and_production_design.md`.

Current implemented areas in `production_test.c`:
- USB CDC transport on `QL_USB_CDC_PORT`
- capability and identity commands such as `AT+CAP?`, `AT+VER?`, `AT+DEV?`
- config file workflow for `U:/config.ini` via `AT+CFGINFO?`, `AT+CFGSTART`, `AT+CFGSET=`, `AT+CFGSAVE`, `AT+CFGREAD?`, `AT+CFGDEF`
- modem self-test commands including `AT+MDINFO?`, `AT+MDSIM?`, `AT+MDREG?`, `AT+MDSIG?`, `AT+MDDATA?`, `AT+MDDNS=`, `AT+MDPING=`, `AT+MDALL?`
- MCU bridge commands including `AT+MCURST`, `AT+MCUBVER?`, `AT+MCULED=`, `AT+MCUMAC?`, `AT+MCUCHG?`, `AT+MCUVBAT?`, `AT+MCUFBMIC=`, `AT+MCUPMIC=`, `AT+MCUKEY`, `AT+MCUGAUGE`, `AT+MCUTIME=`, `AT+MCURAW=`
- production mode state APIs exposed by `production_test.h`: `production_enter_mode()`, `production_exit_mode()`, `production_is_enabled()`

When changing MCU UART parsing in `interface/poc/e02t_uart_mcu.c`, check how `production_test.c` uses `e02t_uart_register_line_handler()`. Production forwarding captures MCU replies from the same UART path, so parser changes must not break either:
- normal runtime MCU commands such as `AT+PTT`, `AT+VOL`, `AT+NOISE`
- USB CDC to MCU forwarding done by `forward_to_mcu()`

### Version metadata in builds

The POC module `Makefile` injects git-derived metadata into the build:
- `GIT_VERSION`
- `GIT_COMMIT_DATE`
- `GIT_BRANCH`

`example_poc.c` logs these at startup together with the application version macros. If build reproducibility or version display changes are needed, inspect `ql-application/threadx/interface/poc/Makefile` and `version.h` together.
