### build
```
west build -p auto -b mimxrt1064_evk samples/basic/blinky/
```
output
```
-- west build: making build dir /home/linux/zephyrproject/zephyr/build pristine
-- west build: build configuration:
       source directory: /home/linux/zephyrproject/zephyr/samples/basic/blinky
       build directory: /home/linux/zephyrproject/zephyr/build
       BOARD: mimxrt1064_evk (origin: command line)
-- west build: generating a build system
Zephyr version: 2.1.0
-- Found PythonInterp: /usr/bin/python3 (found suitable version "3.7.3", minimum required is "3.4") 
-- Selected BOARD mimxrt1064_evk
-- Found west: /home/linux/.local/bin/west (found suitable version "0.6.3", minimum required is "0.6.0")
-- Loading /home/linux/zephyrproject/zephyr/boards/arm/mimxrt1064_evk/mimxrt1064_evk.dts as base
Devicetree configuration written to /home/linux/zephyrproject/zephyr/build/zephyr/include/generated/generated_dts_board.conf
Parsing Kconfig tree in /home/linux/zephyrproject/zephyr/Kconfig
Loaded configuration '/home/linux/zephyrproject/zephyr/boards/arm/mimxrt1064_evk/mimxrt1064_evk_defconfig'
Merged configuration '/home/linux/zephyrproject/zephyr/samples/basic/blinky/prj.conf'
Configuration saved to '/home/linux/zephyrproject/zephyr/build/zephyr/.config'
-- The C compiler identification is GNU 9.2.0
-- The CXX compiler identification is GNU 9.2.0
-- The ASM compiler identification is GNU
-- Found assembler: /home/linux/zephyr-sdk/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc
-- Cache files will be written to: /home/linux/.cache/zephyr
-- Configuring done
-- Generating done
-- Build files have been written to: /home/linux/zephyrproject/zephyr/build
-- west build: building application
[2/121] Preparing syscall dependency handling

[116/121] Linking C executable zephyr/zephyr_prebuilt.elf
Memory region         Used Size  Region Size  %age Used
           OCRAM:          0 GB       768 KB      0.00%
            DTCM:          0 GB       128 KB      0.00%
            ITCM:          0 GB       128 KB      0.00%
           FLASH:       21972 B         4 MB      0.52%
            SRAM:        3892 B        32 MB      0.01%
        IDT_LIST:          72 B         2 KB      3.52%
[121/121] Linking C executable zephyr/zephyr.elf
```

### flash
```
west flash
```
output
```
-- west flash: rebuilding
ninja: no work to do.
-- west flash: using runner jlink
-- runners.jlink: Flashing file: /home/linux/zephyrproject/zephyr/build/zephyr/zephyr.bin
SEGGER J-Link Commander V6.54c (Compiled Nov  7 2019 17:05:53)
DLL version V6.54c, compiled Nov  7 2019 17:05:41


J-Link Command File read successfully.
Processing script file...

J-Link connection not established yet but required for command.
Connecting to J-Link via USB...FAILED: Cannot connect to J-Link.

J-Link connection not established yet but required for command.
Connecting to J-Link via USB...FAILED: Failed to open DLL

J-Link connection not established yet but required for command.
Connecting to J-Link via USB...FAILED: Failed to open DLL


Script processing completed.

```
