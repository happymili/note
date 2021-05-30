### build
```
west build -p auto -b cc26x2r1_launchxl  samples/hello_world/
```
output
```
-- west build: build configuration:
       source directory: /home/linux/zephyrproject/zephyr/samples/hello_world
       build directory: /home/linux/zephyrproject/zephyr/build (created)
       BOARD: cc26x2r1_launchxl (origin: command line)
-- west build: generating a build system
Zephyr version: 2.1.0
-- Found PythonInterp: /usr/bin/python3 (found suitable version "3.7.3", minimum required is "3.4") 
-- Selected BOARD cc26x2r1_launchxl
-- Found west: /home/linux/.local/bin/west (found suitable version "0.6.3", minimum required is "0.6.0")
-- Loading /home/linux/zephyrproject/zephyr/boards/arm/cc26x2r1_launchxl/cc26x2r1_launchxl.dts as base
Devicetree configuration written to /home/linux/zephyrproject/zephyr/build/zephyr/include/generated/generated_dts_board.conf
Parsing Kconfig tree in /home/linux/zephyrproject/zephyr/Kconfig
Loaded configuration '/home/linux/zephyrproject/zephyr/boards/arm/cc26x2r1_launchxl/cc26x2r1_launchxl_defconfig'
Merged configuration '/home/linux/zephyrproject/zephyr/samples/hello_world/prj.conf'
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
[3/115] Preparing syscall dependency handling

[110/115] Linking C executable zephyr/zephyr_prebuilt.elf
Memory region         Used Size  Region Size  %age Used
           FLASH:        9288 B     360360 B      2.58%
      FLASH_CCFG:          88 B         88 B    100.00%
            SRAM:        3816 B        80 KB      4.66%
        IDT_LIST:          40 B         2 KB      1.95%
[115/115] Linking C executable zephyr/zephyr.elf
```


### flash
```
west flash
```
output
```
-- west flash: rebuilding
ninja: no work to do.
-- west flash: using runner openocd
-- runners.openocd: Flashing file: /home/linux/zephyrproject/zephyr/build/zephyr/zephyr.hex
Open On-Chip Debugger 0.10.0+dev-01231-g3d7db5535-dirty (2019-11-20-13:42)
Licensed under GNU GPL v2
For bug reports, read
	http://openocd.org/doc/doxygen/bugs.html
adapter_nsrst_delay: 100

Info : XDS110: connected
Info : XDS110: firmware version = 3.0.0.5
Info : XDS110: hardware version = 0x0023
Info : XDS110: connected to target via JTAG
Info : XDS110: TCK set to 2500 kHz
Info : clock speed 2500 kHz
Error: JTAG scan chain interrogation failed: all zeroes
Error: Check JTAG interface, timings, target power, etc.
Error: Trying to use configured scan chain anyway...
Error: cc26x2.jrc: IR capture error; saw 0x02 not 0x01
Warn : Bypassing JTAG setup events due to errors
Info : Listening on port 3333 for gdb connections
    TargetName         Type       Endian TapName            State       
--  ------------------ ---------- ------ ------------------ ------------
 0* cc26x2.cpu         cortex_m   little cc26x2.cpu         tap-disabled

Info : TAP cc26x2.jrc does not have IDCODE
Info : JTAG tap: auto0.tap tap/device found: 0x3bb4102f (mfg: 0x017 (Texas Instruments), part: 0xbb41, ver: 0x3)
Error: cc26x2.jrc: IR capture error; saw 0x02 not 0x01
Warn : Bypassing JTAG setup events due to errors
Error: Target not examined yet
Error: auto_probe failed
auto erase enabled
Info : XDS110: disconnected
ERROR: command exited with status 1: /home/linux/zephyr-sdk/sysroots/x86_64-pokysdk-linux/usr/bin/openocd -s /home/linux/zephyr-sdk/sysroots/x86_64-pokysdk-linux/usr/share/openocd/scripts -f /home/linux/zephyrproject/zephyr/boards/arm/cc26x2r1_launchxl/support/openocd.cfg -c init -c targets -c 'reset halt' -c 'flash write_image erase /home/linux/zephyrproject/zephyr/build/zephyr/zephyr.hex' -c 'reset halt' -c 'verify_image /home/linux/zephyrproject/zephyr/build/zephyr/zephyr.hex' -c 'reset run' -c shutdown
```
