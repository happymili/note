### config env
```
cd ~/zephyrproject/zephyr/
source zephyr-env.sh
```

### delete build folder
```
sudo rm build -r
```
 

### build
```
west build -p auto -b efm32wg_stk3800  samples/basic/blinky/
```
output
```
-- west build: build configuration:
       source directory: /home/linux/zephyrproject/zephyr/samples/basic/blinky
       build directory: /home/linux/zephyrproject/zephyr/build (created)
       BOARD: efm32wg_stk3800 (origin: command line)
-- west build: generating a build system
Zephyr version: 2.1.0
-- Found PythonInterp: /usr/bin/python3 (found suitable version "3.7.3", minimum required is "3.4") 
-- Selected BOARD efm32wg_stk3800
-- Found west: /home/linux/.local/bin/west (found suitable version "0.6.3", minimum required is "0.6.0")
-- Loading /home/linux/zephyrproject/zephyr/boards/arm/efm32wg_stk3800/efm32wg_stk3800.dts as base
Devicetree configuration written to /home/linux/zephyrproject/zephyr/build/zephyr/include/generated/generated_dts_board.conf
Parsing Kconfig tree in /home/linux/zephyrproject/zephyr/Kconfig
Loaded configuration '/home/linux/zephyrproject/zephyr/boards/arm/efm32wg_stk3800/efm32wg_stk3800_defconfig'
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
[2/116] Preparing syscall dependency handling

[111/116] Linking C executable zephyr/zephyr_prebuilt.elf
Memory region         Used Size  Region Size  %age Used
           FLASH:       11700 B       256 KB      4.46%
            SRAM:        3940 B        32 KB     12.02%
        IDT_LIST:          40 B         2 KB      1.95%
[116/116] Linking C executable zephyr/zephyr.elf
```

### flash
```
west flash
```
output
```
-- west flash: rebuilding
ninja: no work to do.
WARNING: No cached runners are available in /home/linux/zephyrproject/zephyr/build/CMakeCache.txt
FATAL ERROR: No flash runner available for board efm32wg_stk3800 (ZEPHYR_BOARD_FLASH_RUNNER is not in the cache). Check your board's documentation for instructions.
```
