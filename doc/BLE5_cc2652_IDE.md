# TI BLE5 development environment

## Windows 环境软件安装

### 安装 SDK

- [SIMPLELINK-CC13X2-26X2-SDK](http://www.ti.com/tool/download/SIMPLELINK-CC13X2-26X2-SDK)

  - [Windows Installer for Simplelink CC13X2 26X2 SDK 3.10.00.53](https://www.ti.com/licreg/docs/swlicexportcontrol.tsp?form_type=2&prod_no=simplelink_cc13x2_26x2_sdk_3_10_00_53.exe&ref_url=http://software-dl.ti.com/simplelink/esd/simplelink_cc13x2_26x2_sdk/3.10.00.53)

  - [Linux Installer for SimpleLink CC13X2 26X2 SDK 3.10.00.53](https://www.ti.com/licreg/docs/swlicexportcontrol.tsp?form_type=2&prod_no=simplelink_cc13x2_26x2_sdk_3_10_00_53.run&ref_url=http://software-dl.ti.com/simplelink/esd/simplelink_cc13x2_26x2_sdk/3.10.00.53)

    ```shell
    chmod +x simplelink_cc13x2_26x2_sdk_3_10_00_53.run
    ./simplelink_cc13x2_26x2_sdk_3_10_00_53.run
    ```

  - [Windows Installer for Simplelink CC13X2 26X2 SDK 3.20.00.68](https://www.ti.com/licreg/docs/swlicexportcontrol.tsp?form_type=2&prod_no=simplelink_cc13x2_26x2_sdk_3_20_00_68.exe&ref_url=http://software-dl.ti.com/simplelink/esd/simplelink_cc13x2_26x2_sdk/3.20.00.68)

  - [Linux Installer for SimpleLink CC13X2 26X2 SDK 3.20.00.68](https://www.ti.com/licreg/docs/swlicexportcontrol.tsp?form_type=2&prod_no=simplelink_cc13x2_26x2_sdk_3_20_00_68.run&ref_url=http://software-dl.ti.com/simplelink/esd/simplelink_cc13x2_26x2_sdk/3.20.00.68)

  - [Windows Installer for Simplelink CC13X2 26X2 SDK 3.30.00.03](https://www.ti.com/licreg/docs/swlicexportcontrol.tsp?form_type=2&prod_no=simplelink_cc13x2_26x2_sdk_3_30_00_03.exe&ref_url=http://software-dl.ti.com/simplelink/esd/simplelink_cc13x2_26x2_sdk/3.30.00.03)

  - [Linux Installer for SimpleLink CC13X2 26X2 SDK 3.30.00.03](https://www.ti.com/licreg/docs/swlicexportcontrol.tsp?form_type=2&prod_no=simplelink_cc13x2_26x2_sdk_3_30_00_03.run&ref_url=http://software-dl.ti.com/simplelink/esd/simplelink_cc13x2_26x2_sdk/3.30.00.03)

  - [Windows Installer for Simplelink CC13X2 26X2 SDK 3.40.00.02](https://www.ti.com/licreg/docs/swlicexportcontrol.tsp?form_type=2&prod_no=simplelink_cc13x2_26x2_sdk_3_40_00_02.exe&ref_url=http://software-dl.ti.com/simplelink/esd/simplelink_cc13x2_26x2_sdk/3.40.00.02)

  - [Linux Installer for SimpleLink CC13X2 26X2 SDK 3.40.00.02](https://www.ti.com/licreg/docs/swlicexportcontrol.tsp?form_type=2&prod_no=simplelink_cc13x2_26x2_sdk_3_40_00_02.run&ref_url=http://software-dl.ti.com/simplelink/esd/simplelink_cc13x2_26x2_sdk/3.40.00.02)

  - [Windows Installer for Simplelink CC13X2 26X2 SDK 4.30.00.54](https://www.ti.com/licreg/docs/swlicexportcontrol.tsp?form_type=2&prod_no=simplelink_cc13x2_26x2_sdk_4_30_00_54.exe&ref_url=http://software-dl.ti.com/simplelink/esd/simplelink_cc13x2_26x2_sdk/4.30.00.54)

  - [Linux Installer for SimpleLink CC13X2 26X2 SDK 4.30.00.54](https://www.ti.com/licreg/docs/swlicexportcontrol.tsp?form_type=2&prod_no=simplelink_cc13x2_26x2_sdk_4_30_00_54.run&ref_url=http://software-dl.ti.com/simplelink/esd/simplelink_cc13x2_26x2_sdk/4.30.00.54)

### 安装 IAR

- [EWARM-CD-8323-20228](https://www.iar.com/iar-embedded-workbench/#!?architecture=Arm)

- file -> Open Workspace

- [IAR setting for Ti SDK "Configure Custom Argument Variables"](http://dev.ti.com/tirex/explore/content/simplelink_cc13x2_26x2_sdk_3_20_00_68/docs/simplelink_mcu_sdk/html/quickstart-guide/ble5-quick-start.html#using-ble5-stack-projects-with-iar)

- 在 IAR 导入环境变量：Tools -> Configure Custom Argument Variables -> Import -> C:\ti\simplelink_cc13x2_26x2_sdk_3_10_00_53\tools\iar\SIMPLELINK_CC13X2_26X2_SDK.custom_argvars

  - 环境变量包含 SDK 安装目录
  - XDCtool 的安装目录
  - SDK 源代码目录等等

- rebuild all

### 安装 CCS

- [CCS Studio](http://www.ti.com/tool/download/CCSTUDIO)

  - [Windows single file installer for CCS IDE 9.2.0.00013](http://software-dl.ti.com/ccs/esd/CCSv9/CCS_9_2_0/exports/CCS9.2.0.00013_win64.zip)

  - [Linux single file installer for CCS IDE 9.2.0.00013](http://software-dl.ti.com/ccs/esd/CCSv9/CCS_9_2_0/exports/CCS9.2.0.00013_linux-x64.tar.gz)

  - [Windows single file installer for CCS IDE 10.1.1.00004](https://software-dl.ti.com/ccs/esd/CCSv10/CCS_10_1_1/exports/CCS10.1.1.00004_win64.zip)

  - [Linux single file installer for CCS IDE 10.1.1.00004](https://software-dl.ti.com/ccs/esd/CCSv10/CCS_10_1_1/exports/CCS10.1.1.00004_linux-x64.tar.gz)

- import project
  - file -> import -> C/C++ -> CSS Projects -> Next -> Browse
- open project from local filesystem
  - file -> Open Projects From File System
- build
  - clean project
  - rebuild all

### XDCtools 的安装

安装 SDK 和 CCS 时会默认安装 XDCtool，不同的 SDK 及 CCS 安装的 XDCtool 版本如下

|       SDK/CCS       |     xdctool version      |
| :-----------------: | :----------------------: |
|   SDK 3.10.00.53    | xdctools_3_51_02_21_core |
|   SDK 3.20.00.68    | xdctools_3_51_03_28_core |
|   SDK 3.30.00.03    | xdctools_3_60_00_24_core |
|   SDK 3.40.00.02    | xdctools_3_60_02_34_core |
| CCS IDE 9.2.0.00013 | xdctools_3_60_01_27_core |

启动 CCS 后，会提示安装 xdctools，然后安装即可

## Linux 环境软件安装

### Linux CCS installation

- first unzip the CCS9.2.0.00013_linux-x64.tar.gz file, then execute

```shell
cd CCS9.2.0.00013_linux-x64/
./ccs_setup_9.2.0.00013.bin
```

- install driver and then reboot for debug avaliable

```shell
cd ~/ti/ccs920/ccs/install_scripts
sudo ./install_drivers.sh
```

- run the ccstudio

double click the desktop shorcut or execute this command

```shell
sudo ./<install_path>/ccs920/ccs/eclipse/ccstudio
```

- desktop shortcuts won't work

`Right-click the shortcut and select "Allow launching"`

- ccstudio start failed

log

```shell
libpython2.7.so.1.0: cannot open shared object file: No such file or directory
There was a problem loading "/home/linux/ti/ccs920/ccs/eclipse/../ccs_base/common/bin/libMiniDump.so".
```

solution

```shell
sudo apt-get install libpython2.7
```

- error #10234-D: unresolved symbols remain

this error is typically generated when the include path/variable to a library is missing/in need of correction.
But in Linux environment, maybe it is a permission issue.
The solution is

```shell
cd ~/ti/ccs920/ccs/install_scripts/
sudo ./ti_permissions_install.sh
```

### 安装烧录工具 UniFlash

- [UniFlash for most TI Microcontrollers (MCUs) and mmWave sensors](https://www.ti.com/tool/download/UNIFLASH)

  - [Windows Installer for UniFlash 5.2.0.2519](http://software-dl.ti.com/ccs/esd/uniflash/uniflash_sl.5.2.0.2519.exe)
  - [Linux Installer for UniFlash 5.2.0.2519](http://software-dl.ti.com/ccs/esd/uniflash/uniflash_sl.5.2.0.2519.run)

    - failed to locate system libraries required for UniFlash operation: libgconf-2.so.4 libusb-0.1.so.4

    ```shell
    sudo apt install libgconf2-4
    sudo apt install libusb-0.1-4
    ```

### 安装 uart trace 串口调试工具

- [minicom installation](minicon使用方法.md)

```shell
sudo apt install minicom
```

## 开发相关配置问题及测试

### 开发环境的配置

|            IAR            |            CCS            |
| :-----------------------: | :-----------------------: |
|       SDK 路径选择        |       SDK 路径选择        |
| 编译的.opt 文件选择及修改 | 编译的.opt 文件选择及修改 |
|        头文件包含         |        头文件包含         |
|          宏定义           |          宏定义           |
|       输出文件格式        |                           |
|         链接配置          |                           |
|        调试器配置         |                           |
|                           |     .cfg 文件修改配置     |

### 编译测试

IDE 版本

- IAR Debug
- IAR Release
- CCS Windows Debug
- CCS Ubuntu Debug

SDK 版本

- SDK version

XDC 版本

- CCS XDCtools version

### 编译常见问题处理方法

- 出现编译异常时，优先导入 SDK 的示例工程编译测试
- IAR & CCS 同时开发时，本地最好分别使用代码库
- Linux CCS 在 debug 时不能烧录代码，需要安装 driver 解决
- **UniFlash 找不到开发板？**
- Ubuntu CCS 编译以前没有问题，现在突然经常特别卡
  - 重装 CCS
  - 重新建 workspace
  - 重新 clone 代码或者清理本地 repo 的垃圾文件
- Windows CCS 由于 IAR 的残留文件而编译失败
  - 删除 IAR 生成的文件夹
  - 重新 clone 代码或者清理本地 repo 的垃圾文件
- Windows CCS 找不到 XDStool
  - 卸载 CCS
  - 删除本地 XDStool
  - 重装 CCS
- 编译耗时较长时
  - 升级通知的编译器软件版本可以解决部分问题
- 选择正确的 sdk 版本
- CCS 不弹出升级软件
  - 检查网络连接
