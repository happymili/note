* [frdm_kl25z](https://docs.zephyrproject.org/latest/boards/arm/frdm_kl25z/doc/index.html)
  * [Programming and Debugging](https://docs.zephyrproject.org/latest/boards/arm/frdm_kl25z/doc/index.html#programming-and-debugging)
    * [DAPLink bootloader update](https://os.mbed.com/blog/entry/DAPLink-bootloader-update/)
* [udev rules on Linux](https://github.com/mbedmicro/pyOCD#udev-rules-on-linux)


### config env
```
cd ~/zephyrproject/zephyr/
source zephyr-env.sh
```

### delete build folder
`sudo rm build -r`


### build
```
west build -p auto -b frdm_kl25z  samples/basic/blinky/
```
output
```
-- west build: build configuration:
       source directory: /home/linux/zephyrproject/zephyr/samples/basic/blinky
       build directory: /home/linux/zephyrproject/zephyr/build (created)
       BOARD: frdm_kl25z (origin: command line)
-- west build: generating a build system
Zephyr version: 2.1.0
-- Found PythonInterp: /usr/bin/python3 (found suitable version "3.7.3", minimum required is "3.4") 
-- Selected BOARD frdm_kl25z
-- Found west: /home/linux/.local/bin/west (found suitable version "0.6.3", minimum required is "0.6.0")
-- Loading /home/linux/zephyrproject/zephyr/boards/arm/frdm_kl25z/frdm_kl25z.dts as base
Devicetree configuration written to /home/linux/zephyrproject/zephyr/build/zephyr/include/generated/generated_dts_board.conf
Parsing Kconfig tree in /home/linux/zephyrproject/zephyr/Kconfig
Loaded configuration '/home/linux/zephyrproject/zephyr/boards/arm/frdm_kl25z/frdm_kl25z_defconfig'
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
           FLASH:       10968 B       128 KB      8.37%
            SRAM:        3864 B        16 KB     23.58%
        IDT_LIST:          40 B         2 KB      1.95%
[116/116] Linking C executable zephyr/zephyr.elf
```

### flash
`west flash`

output
```
-- west flash: rebuilding
ninja: no work to do.
-- west flash: using runner pyocd
WARNING: runners.pyocd: hex file (/home/linux/zephyrproject/zephyr/build/zephyr/zephyr.hex) does not exist; falling back on .bin (/home/linux/zephyrproject/zephyr/build/zephyr/zephyr.bin). Consider enabling CONFIG_BUILD_OUTPUT_HEX.
-- runners.pyocd: Flashing file: /home/linux/zephyrproject/zephyr/build/zephyr/zephyr.bin
No connected debug probes
0000476:CRITICAL:__main__:uncaught exception: 
Traceback (most recent call last):
  File "/home/linux/.local/lib/python3.7/site-packages/pyocd/__main__.py", line 338, in run
    self._COMMANDS[self._args.cmd](self)
  File "/home/linux/.local/lib/python3.7/site-packages/pyocd/__main__.py", line 468, in do_flash
    with session:
  File "/home/linux/.local/lib/python3.7/site-packages/pyocd/core/session.py", line 284, in __enter__
    assert self._probe is not None
AssertionError
ERROR: command exited with status 1: pyocd flash -e sector -t kl25z /home/linux/zephyrproject/zephyr/build/zephyr/zephyr.bin
```

output
```
-- west flash: rebuilding
ninja: no work to do.
-- west flash: using runner pyocd
WARNING: runners.pyocd: hex file (/home/linux/zephyrproject/zephyr/build/zephyr/zephyr.hex) does not exist; falling back on .bin (/home/linux/zephyrproject/zephyr/build/zephyr/zephyr.bin). Consider enabling CONFIG_BUILD_OUTPUT_HEX.
-- runners.pyocd: Flashing file: /home/linux/zephyrproject/zephyr/build/zephyr/zephyr.bin
No connected debug probes
ERROR: command exited with status 1: pyocd flash -e sector -t kl25z /home/linux/zephyrproject/zephyr/build/zephyr/zephyr.bin
```
