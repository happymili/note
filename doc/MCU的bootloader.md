# 升级功能必不可少

## 厂家固化的 bootloader

- 芯片在出厂前都会在内部存储一段 bootloader 的代码，这部分代码的作用一般是用于烧录产品程序固件
  - 51 系列的 mcu 一般支持通过串口烧录程序，烧录程序的过程其实就是运行内部的 bootloader 程序，然后通过一定的协议，将固件程序通过串口发给 bootloader 程序处理并存储
  - ST 的 cortex 系统 MCU 一般支持多种接口烧录固件，比如 UART，SPI，IIC，USB，CAN
    - [github 上有通过厂家固化的 bootloader 烧录 stm32 固件的 repo 示例](https://github.com/ARMinARM/stm32flash)
    - [ST 官方文档：通过 USART 协议更新固件 USART protocol used in the STM32 bootloader](https://www.st.com/content/ccc/resource/technical/document/application_note/51/5f/03/1e/bd/9b/45/be/CD00264342.pdf/files/CD00264342.pdf/jcr:content/translations/en.CD00264342.pdf)
    - [ST 官方文档：通过 SPI 协议更新固件 SPI protocol used in the STM32 bootloader](https://www.st.com/content/ccc/resource/technical/document/application_note/7a/8a/0a/8f/8f/38/47/c0/DM00081379.pdf/files/DM00081379.pdf/jcr:content/translations/en.DM00081379.pdf)
    - [ST 官方文档：通过 I2C 协议更新固件 I2C protocol used in the STM32 bootloader](https://www.st.com/content/ccc/resource/technical/document/application_note/4c/68/fe/72/a8/cd/47/83/DM00072315.pdf/files/DM00072315.pdf/jcr:content/translations/en.DM00072315.pdf)
    - [ST 官方文档：通过 USB 协议更新固件 USB protocol used in the STM32 bootloader](https://www.st.com/content/ccc/resource/technical/document/application_note/6a/17/92/02/58/98/45/0c/CD00264379.pdf/files/CD00264379.pdf/jcr:content/translations/en.CD00264379.pdf)
    - [ST 官方文档：通过 CAN 协议更新固件 CAN protocol used in the STM32 bootloader](https://www.st.com/content/ccc/resource/technical/document/application_note/56/94/0c/7d/63/f6/4d/96/CD00264321.pdf/files/CD00264321.pdf/jcr:content/translations/en.CD00264321.pdf)
- 如果用厂家的 bootloader 升级固件，需要有外部设备对芯片进行操作，甚至有时候需要人工操作

## 用户 bootloader

- 实际产品发布后，由于产品功能更新需要对 MCU 更新固件，但是不希望通过外部设备操作，这时候需要在 MCU 内部烧录一个用户 bootloader，专门用于更新代码
- MCU 支持自我更新固件的条件是该 MCU 支持可编程，且 MCU 能通过产品自身的通讯功能获取到新版本的固件

## 用户 bootloader 的作用

- 目前 MCU 的 bootloader 作用相对比较简单，一般就是用于更新固件
- 还有一些对安全要求较高的场合，称为 secure bootloader
  - 用户 bootloader 是固化不可擦除的
  - 升级前 bootloader 要对新版本固件进行验证，验证通过才能升级
  - bootloader 每次启动都要检查固件代码的准确无误，保证安全启动

## 用户 bootloader 通过何种方式获取新版本固件

- 通过硬件接口，比如 UART，SPI，IIC，USB，Ethernet...
- 通过无线通讯 OTA，比如 Bluetooth，Wi-Fi，Sub-1G，2.4GHz...
