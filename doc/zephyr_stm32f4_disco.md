### config env
```
cd ~/zephyrproject/zephyr/
source zephyr-env.sh 
```

### delete build folder
`sudo rm build -r`

### build
```
west build -p auto -b  stm32f4_disco samples/basic/blinky/
```
output
```
-- west build: build configuration:
       source directory: /home/linux/zephyrproject/zephyr/samples/basic/blinky
       build directory: /home/linux/zephyrproject/zephyr/build (created)
       BOARD: stm32f4_disco (origin: command line)
-- west build: generating a build system
Zephyr version: 2.1.0
-- Found PythonInterp: /usr/bin/python3 (found suitable version "3.7.3", minimum required is "3.4") 
-- Selected BOARD stm32f4_disco
-- Found west: /home/linux/.local/bin/west (found suitable version "0.6.3", minimum required is "0.6.0")
-- Loading /home/linux/zephyrproject/zephyr/boards/arm/stm32f4_disco/stm32f4_disco.dts as base
Devicetree configuration written to /home/linux/zephyrproject/zephyr/build/zephyr/include/generated/generated_dts_board.conf
Parsing Kconfig tree in /home/linux/zephyrproject/zephyr/Kconfig
Loaded configuration '/home/linux/zephyrproject/zephyr/boards/arm/stm32f4_disco/stm32f4_disco_defconfig'
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
[1/127] Preparing syscall dependency handling

[122/127] Linking C executable zephyr/zephyr_prebuilt.elf
Memory region         Used Size  Region Size  %age Used
           FLASH:       14208 B         1 MB      1.35%
             CCM:          0 GB        64 KB      0.00%
            SRAM:        4360 B       128 KB      3.33%
        IDT_LIST:         184 B         2 KB      8.98%
[127/127] Linking C executable zephyr/zephyr.elf
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
Info : The selected transport took over low-level target control. The results might differ compared to plain JTAG/SWD
Info : clock speed 2000 kHz
Info : STLINK V2J17S0 (API v2) VID:PID 0483:3748
Info : Target voltage: 2.906461
Info : stm32f4x.cpu: hardware has 6 breakpoints, 4 watchpoints
Info : Listening on port 3333 for gdb connections
    TargetName         Type       Endian TapName            State       
--  ------------------ ---------- ------ ------------------ ------------
 0* stm32f4x.cpu       hla_target little stm32f4x.cpu       running

target halted due to debug-request, current mode: Thread 
xPSR: 0x01000000 pc: 0x0800101c msp: 0x200006a0
Info : device id = 0x10016413
Info : flash size = 1024 kbytes
auto erase enabled
wrote 16384 bytes from file /home/linux/zephyrproject/zephyr/build/zephyr/zephyr.hex in 0.918821s (17.414 KiB/s)

target halted due to debug-request, current mode: Thread 
xPSR: 0x01000000 pc: 0x0800101c msp: 0x200006a0
verified 14208 bytes in 0.313186s (44.303 KiB/s)

shutdown command invoked
```
