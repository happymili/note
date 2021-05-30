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
west build -p auto -b  stm32f429i_disc1 samples/basic/blinky/
```
output
```
-- west build: making build dir /home/linux/zephyrproject/zephyr/build pristine
-- west build: build configuration:
       source directory: /home/linux/zephyrproject/zephyr/samples/basic/blinky
       build directory: /home/linux/zephyrproject/zephyr/build
       BOARD: stm32f429i_disc1 (origin: command line)
-- west build: generating a build system
Zephyr version: 2.1.0
-- Found PythonInterp: /usr/bin/python3 (found suitable version "3.7.3", minimum required is "3.4") 
-- Selected BOARD stm32f429i_disc1
-- Found west: /home/linux/.local/bin/west (found suitable version "0.6.3", minimum required is "0.6.0")
-- Loading /home/linux/zephyrproject/zephyr/boards/arm/stm32f429i_disc1/stm32f429i_disc1.dts as base
Devicetree configuration written to /home/linux/zephyrproject/zephyr/build/zephyr/include/generated/generated_dts_board.conf
Parsing Kconfig tree in /home/linux/zephyrproject/zephyr/Kconfig
Loaded configuration '/home/linux/zephyrproject/zephyr/boards/arm/stm32f429i_disc1/stm32f429i_disc1_defconfig'
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
[2/124] Preparing syscall dependency handling

[119/124] Linking C executable zephyr/zephyr_prebuilt.elf
Memory region         Used Size  Region Size  %age Used
           FLASH:       13208 B         2 MB      0.63%
             CCM:          0 GB        64 KB      0.00%
            SRAM:        4324 B       192 KB      2.20%
        IDT_LIST:         184 B         2 KB      8.98%
[124/124] Linking C executable zephyr/zephyr.elf
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
Info : STLINK V2J27S0 (API v2) VID:PID 0483:3748
Info : Target voltage: 2.882540
Error: jtag status contains invalid mode value - communication failure
Polling target stm32f4x.cpu failed, trying to reexamine
Examination failed, GDB will be halted. Polling again in 100ms
Info : Previous state query failed, trying to reconnect
Error: jtag status contains invalid mode value - communication failure
Polling target stm32f4x.cpu failed, trying to reexamine
Examination failed, GDB will be halted. Polling again in 300ms
Info : Listening on port 3333 for gdb connections
    TargetName         Type       Endian TapName            State       
--  ------------------ ---------- ------ ------------------ ------------
 0* stm32f4x.cpu       hla_target little stm32f4x.cpu       unknown

Info : Unable to match requested speed 2000 kHz, using 1800 kHz
Info : Unable to match requested speed 2000 kHz, using 1800 kHz
Error: mem2array: Read @ 0xe0042004, w=4, cnt=1, failed
Error executing event examine-end on target stm32f4x.cpu:
/home/linux/zephyr-sdk/sysroots/x86_64-pokysdk-linux/usr/share/openocd/scripts/mem_helper.tcl:6: Error: 
in procedure 'ocd_process_reset' 
in procedure 'ocd_process_reset_inner' called at file "embedded:startup.tcl", line 214
in procedure 'mmw' called at file "/home/linux/zephyr-sdk/sysroots/x86_64-pokysdk-linux/usr/share/openocd/scripts/target/stm32f4x.cfg", line 79
in procedure 'mrw' called at file "/home/linux/zephyr-sdk/sysroots/x86_64-pokysdk-linux/usr/share/openocd/scripts/mem_helper.tcl", line 36
at file "/home/linux/zephyr-sdk/sysroots/x86_64-pokysdk-linux/usr/share/openocd/scripts/mem_helper.tcl", line 6
Info : Previous state query failed, trying to reconnect
target halted due to debug-request, current mode: Thread 
xPSR: 0x01000000 pc: 0x08000d38 msp: 0x20000670
Polling target stm32f4x.cpu failed, trying to reexamine
Info : stm32f4x.cpu: hardware has 6 breakpoints, 4 watchpoints
Info : device id = 0x10036419
Info : flash size = 2048 kbytes
Info : Dual Bank 2048 kiB STM32F42x/43x/469/479 found
auto erase enabled
wrote 16384 bytes from file /home/linux/zephyrproject/zephyr/build/zephyr/zephyr.hex in 0.752763s (21.255 KiB/s)

Info : Unable to match requested speed 2000 kHz, using 1800 kHz
Info : Unable to match requested speed 2000 kHz, using 1800 kHz
target halted due to debug-request, current mode: Thread 
xPSR: 0x01000000 pc: 0x08001040 msp: 0x20000670
verified 13208 bytes in 0.134592s (95.834 KiB/s)

Info : Unable to match requested speed 2000 kHz, using 1800 kHz
Info : Unable to match requested speed 2000 kHz, using 1800 kHz
shutdown command invoked
```
