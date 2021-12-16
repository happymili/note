* [Nordic nRF5x Segger J-Link](https://docs.zephyrproject.org/latest/guides/tools/nordic_segger.html#nordic-segger)
  * [J-Link Software and documentation pack](https://www.segger.com/downloads/jlink/)
  * [nRF5x Command-Line Tools](https://www.nordicsemi.com/Software-and-Tools/Development-Tools/nRF-Command-Line-Tools/Download)
  * [Installing the nRF5x Command Line Tools](https://infocenter.nordicsemi.com/index.jsp?topic=%2Fug_nrf5x_cltools%2FUG%2Fcltools%2Fnrf5x_installation.html)


### 安装command line tools

* 下载[nRF5x Command-Line Tools](https://www.nordicsemi.com/Software-and-Tools/Development-Tools/nRF-Command-Line-Tools/Download)，找到相应的版本
* 解压缩nRF-Command-Line-Tools_10_5_0_Linux-amd64.tar.gz
* 安装
```
cd nRF-Command-Line-Tools_10_5_0_Linux-amd64/
dpkg -i JLink_Linux_V654c_x86_64.deb
dpkg -i nRF-Command-Line-Tools_10_5_0_Linux-amd64.deb
```


### build
```
cd ~/zephyrproject/zephyr/
sudo rm build/ -r
west build -p auto -b nrf52_pca10040 samples/basic/blinky/
```
output
```
-- west build: making build dir /home/linux/zephyrproject/zephyr/build pristine
-- west build: build configuration:
       source directory: /home/linux/zephyrproject/zephyr/samples/basic/blinky
       build directory: /home/linux/zephyrproject/zephyr/build
       BOARD: nrf52_pca10040 (origin: command line)
-- west build: generating a build system
Zephyr version: 2.1.0
-- Found PythonInterp: /usr/bin/python3 (found suitable version "3.7.3", minimum required is "3.4") 
-- Selected BOARD nrf52_pca10040
-- Found west: /home/linux/.local/bin/west (found suitable version "0.6.3", minimum required is "0.6.0")
-- Loading /home/linux/zephyrproject/zephyr/boards/arm/nrf52_pca10040/nrf52_pca10040.dts as base
Devicetree configuration written to /home/linux/zephyrproject/zephyr/build/zephyr/include/generated/generated_dts_board.conf
Parsing Kconfig tree in /home/linux/zephyrproject/zephyr/Kconfig
Loaded configuration '/home/linux/zephyrproject/zephyr/boards/arm/nrf52_pca10040/nrf52_pca10040_defconfig'
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
           FLASH:       11772 B       512 KB      2.25%
            SRAM:        3908 B        64 KB      5.96%
        IDT_LIST:          56 B         2 KB      2.73%
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
-- west flash: using runner nrfjprog
-- runners.nrfjprog: Flashing file: /home/linux/zephyrproject/zephyr/build/zephyr/zephyr.hex
Parsing hex file.
Erasing page at address 0x0.
Erasing page at address 0x1000.
Erasing page at address 0x2000.
Applying system reset.
Checking that the area to write is not protected.
Programming device.
Enabling pin reset.
Applying pin reset.
-- runners.nrfjprog: Board with serial number 682675382 flashed successfully.
```
