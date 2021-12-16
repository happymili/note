# Zephyr Getting Started Guide(Ubuntun)

* [Getting Started Guide](https://docs.zephyrproject.org/latest/getting_started/index.html)
* [Beyond the Getting Started Guide](https://docs.zephyrproject.org/latest/guides/beyond-GSG.html)
* [Application Development](https://docs.zephyrproject.org/latest/application/index.html)
* [Debug Host Tools](https://docs.zephyrproject.org/latest/guides/debugging/host-tools.html)
* [Debug Probes](https://docs.zephyrproject.org/latest/guides/debugging/probes.html)
* [Supported Boards](https://docs.zephyrproject.org/latest/boards/index.html#boards)
  * [cc26x2r1_launchxl](https://docs.zephyrproject.org/latest/boards/arm/cc26x2r1_launchxl/doc/index.html)
  * [efm32wg_stk3800](https://docs.zephyrproject.org/latest/boards/arm/efm32wg_stk3800/doc/index.html)
  * [frdm_k64f](https://docs.zephyrproject.org/latest/boards/arm/frdm_k64f/doc/index.html)
  * [frdm_kl25z](https://docs.zephyrproject.org/latest/boards/arm/frdm_kl25z/doc/index.html)
  * [mimxrt1064_evk](https://docs.zephyrproject.org/latest/boards/arm/mimxrt1064_evk/doc/index.html)
  * [nrf52_pca10040](https://docs.zephyrproject.org/latest/boards/arm/nrf52_pca10040/doc/index.html)
  * [stm32f429i_disc1](https://docs.zephyrproject.org/latest/boards/arm/stm32f429i_disc1/doc/index.html)
  * [stm32f4_disco](https://docs.zephyrproject.org/latest/boards/arm/stm32f4_disco/doc/index.html)


### update

```
sudo apt-get update
sudo apt-get upgrade
```


### Install dependencies


* Use apt to install following tools
```
sudo apt install --no-install-recommends git cmake ninja-build gperf \
  ccache dfu-util device-tree-compiler wget \
  python3-pip python3-setuptools python3-tk python3-wheel xz-utils file \
  make gcc gcc-multilib
```


* Verify the version of cmake installed on your system
```
cmake -version
```
If it’s not version 3.13.1 or higher, install it by [build source code](cmake_build_install.md) or follow the [Getting Started Guide](https://docs.zephyrproject.org/latest/getting_started/index.html#install-dependencies) to add the kitware third-party apt repository to get an updated version of cmake


* Install west
```
pip3 install --user -U west
echo 'export PATH=~/.local/bin:"$PATH"' >> ~/.bashrc
source ~/.bashrc
```
The pip3 --user option puts installed Python packages into your ~/.local/bin folder so we’ll need to add this to the PATH so these packages will be found. Adding the PATH specification to your .bashrc file ensures this setting is permanent.


### get zephyr source code

* Zephyr’s multi-purpose west tool simplifies getting the Zephyr project git repositories and external modules used by Zephyr. Clone all of Zephyr’s git repositories in a new zephyrproject directory using west:
```
cd ~
west init zephyrproject
cd zephyrproject
west update
```

* Another way is to clone the source code from [github](https://github.com/zephyrproject-rtos/zephyr)
```
git clone https://github.com/zephyrproject-rtos/zephyr.git
git checkout zephyr-v2.0.0 
```

### Install needed Python packages
The Zephyr source folders we downloaded contain a requirements.txt file that we’ll use to install additional Python tools used by the Zephyr project:
```
cd zephyr
pip3 install --user -r scripts/requirements.txt 
```



### Install Software Development Toolchain

A toolchain includes necessary tools used to build Zephyr applications including: compiler, assembler, linker, and their dependencies.

* [download from github page](https://github.com/zephyrproject-rtos/sdk-ng/releases)
  * [zephyr-sdk-0.11.0-alpha-7-setup.run](https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.11.0-alpha-7/zephyr-sdk-0.11.0-alpha-7-setup.run)
* Run the installation binary, installing the SDK
```
chmod +x zephyr-sdk-0.11.0-alpha-7-setup.run
./zephyr-sdk-0.11.0-alpha-7-setup.run
```
* Set environment variables to let the build system know where to find the toolchain programs:
  * Enter target directory for SDK, default is ~/zephyr-sdk/
  * setup the environment variables, default create ~/.zephyrrc with environment variables
```
Verifying archive integrity... All good.
Uncompressing SDK for Zephyr  100%  
Enter target directory for SDK (default: /home/linux/zephyr-sdk/): 
Installing SDK to /home/linux/zephyr-sdk
Creating directory /home/linux/zephyr-sdk
Success
 [*] Installing arm tools... 
 [*] Installing arm64 tools... 
 [*] Installing arc tools... 
 [*] Installing nios2 tools... 
 [*] Installing riscv64 tools... 
 [*] Installing sparc tools... 
 [*] Installing x86_64 tools... 
 [*] Installing xtensa_sample_controller tools... 
 [*] Installing xtensa_intel_apl_adsp tools... 
 [*] Installing xtensa_intel_s1000 tools... 
 [*] Installing additional host tools... 
Success installing SDK.

You need to setup the following environment variables to use the toolchain:

     export ZEPHYR_TOOLCHAIN_VARIANT=zephyr
     export ZEPHYR_SDK_INSTALL_DIR=/home/linux/zephyr-sdk

Update/Create /home/linux/.zephyrrc with environment variables setup for you (y/n)? 
y
SDK is ready to be used.
```
* The SDK contains a udev rules file that provides information needed to identify boards and grant hardware access permission to flash tools. Install these udev rules with these commands:
```
sudo cp ${ZEPHYR_SDK_INSTALL_DIR}/sysroots/x86_64-pokysdk-linux/usr/share/openocd/contrib/60-openocd.rules /etc/udev/rules.d
sudo udevadm control --reload
```



### Build the Blinky Application

* Set build environment variables:
```
cd ~/zephyrproject/zephyr
source zephyr-env.sh
```
the environment variables changed blow is an example:
```
ZEPHYR_BASE=/home/linux/zephyrproject/zephyr
ZEPHYR_TOOLCHAIN_VARIANT=zephyr
ZEPHYR_SDK_INSTALL_DIR=/home/linux/zephyr-sdk
```

* Build the blinky sample. Specify your board name (see [Supported Boards](https://docs.zephyrproject.org/latest/boards/index.html#boards)) in the command below:
```
west build -p auto -b <your-board-name> samples/basic/blinky
```
This west command uses the -p auto parameter to automatically clean out any byproducts from a previous build if needed, useful if you try building another sample.




### Flash and Run the Application
* Flash the blinky application you just built using the command:
```
west flash
```
