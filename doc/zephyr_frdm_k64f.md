### config env
```
cd ~/zephyrproject/zephyr
source zephyr-env.sh
```

### delete build folder
`sudo rm build/ -r`


### build
`west build -p auto -b frdm_k64f samples/basic/blinky/`

output
```
-- west build: making build dir /home/linux/zephyrproject/zephyr/build pristine
-- west build: build configuration:
       source directory: /home/linux/zephyrproject/zephyr/samples/basic/blinky
       build directory: /home/linux/zephyrproject/zephyr/build
       BOARD: frdm_k64f (origin: command line)
-- west build: generating a build system
Zephyr version: 2.1.0
-- Found PythonInterp: /usr/bin/python3 (found suitable version "3.7.3", minimum required is "3.4") 
-- Selected BOARD frdm_k64f
-- Found west: /home/linux/.local/bin/west (found suitable version "0.6.3", minimum required is "0.6.0")
-- Loading /home/linux/zephyrproject/zephyr/boards/arm/frdm_k64f/frdm_k64f.dts as base
Devicetree configuration written to /home/linux/zephyrproject/zephyr/build/zephyr/include/generated/generated_dts_board.conf
Parsing Kconfig tree in /home/linux/zephyrproject/zephyr/Kconfig
Loaded configuration '/home/linux/zephyrproject/zephyr/boards/arm/frdm_k64f/frdm_k64f_defconfig'
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
           FLASH:       13248 B         1 MB      1.26%
            SRAM:        4028 B       192 KB      2.05%
        IDT_LIST:          88 B         2 KB      4.30%
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
-- west flash: using runner pyocd
WARNING: runners.pyocd: hex file (/home/linux/zephyrproject/zephyr/build/zephyr/zephyr.hex) does not exist; falling back on .bin (/home/linux/zephyrproject/zephyr/build/zephyr/zephyr.bin). Consider enabling CONFIG_BUILD_OUTPUT_HEX.
-- runners.pyocd: Flashing file: /home/linux/zephyrproject/zephyr/build/zephyr/zephyr.bin
[====================] 100%
0002238:INFO:loader:Erased 0 bytes (0 sectors), programmed 0 bytes (0 pages), skipped 16384 bytes (4 pages) at 19.10 kB/s
```
