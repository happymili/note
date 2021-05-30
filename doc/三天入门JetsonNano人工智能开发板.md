# 购买开发板及配件

* Jetson Nano 开发板
* SD卡
    * SD卡至少32GB，Jetbot实验需要64GB的SD卡
    * SD卡优选高速卡，速度太慢会很卡导致体验很差
* 键盘
* 鼠标
* 显示器
* HDMI/DP连接线
* 5V/4A电源适配器
    * USB供电不足会出现宕机的情况
    * 强烈建议购买
* 摄像头
    * 树莓派摄像头v2.1
    * [支持的camera类型](https://elinux.org/Jetson_Nano#Cameras)
    * 摄像头建议购买，可玩性会高很多
* USB cable: Micro-B To Type-A with DATA enabled
    * Nvidia在线课程会用到
* Jetson Nano 外壳
    * 建议购买，目的是保护开发板
* Jetson Nano 风扇
    * 建议购买，价格不贵
* 无线网卡
    * Intel 8265
    * [支持的网卡类型](https://elinux.org/Jetson_Nano#Wireless)
    * Jetbot项目会用到无线网卡,开发板本身有有线网卡，所以视个人情况而定
    
# Jetson Nano的各种参数

* [TECHNICAL SPECIFICATIONS](https://developer.nvidia.com/embedded/jetson-nano)
* Quad-core ARM Cortex-A57 MPCore processor，128 NVIDIA CUDA® cores
* Jetson Nano支持4K60Hz解码，也就是说可以本地播放4K视频，本人实际测试过
* 目前youtube最高支持1080P30Hz播放，官方的sdk暂时不支持硬件解码
* Nvidia Shield TV用的是同系列Tegra X1芯片，差别是含256 NVIDIA CUDA® cores
* Nvidia Shield TV Pro用的是同系列Tegra X1 Plus芯片，官方称性能相比Tegra X1提升25%
* 任天堂Switch游戏机用的同系列Tegra X1定制芯片

# 先看一篇blog热热身

* [Jetson Nano Brings AI Computing to Everyone](https://devblogs.nvidia.com/jetson-nano-ai-computing/)

# Nvidia在线课程

先注册账号，然后就可以开始学习如何使用Jetson Nano
* [Getting Started with AI on Jetson Nano](https://courses.nvidia.com/courses/course-v1:DLI+C-RX-02+V1/about)

# Jetson Nano开发者论坛

* [Jetson Nano Developer Forum](https://devtalk.nvidia.com/default/board/371/jetson-nano/)

# Jetson Nano开发者博客

* [NVIDIA Developer Blog](https://devblogs.nvidia.com/)

# Jetson Nano开发者社区项目

* [Jetson Community Projects](https://developer.nvidia.com/embedded/community/jetson-projects)

***
***
***

# 制作SD卡

* [从官网下载image](https://developer.nvidia.com/embedded/downloads)
* [将image写入SD卡](https://developer.nvidia.com/embedded/learn/get-started-jetson-nano-devkit#prepare)

# 查看GPU运行图

clone [gpuGraph](https://github.com/JetsonHacksNano/gpuGraph)的repo
```
$ sudo git clone https://github.com/JetsonHacksNano/gpuGraph.git
```
安装Matplotlib
```
The graph is implemented as an animated Python Matplotlib graph. The app requires the Python Matplotlib library.
For Python 2.7, Matplotlib may be installed as follows:

$ sudo apt-get install python-matplotlib

For Python 3, Matplotlib may be installed as follows:

$ sudo apt-get install python3-matplotlib
```
运行gpuGraph
```
You can run the app:

$ ./gpuGraph.py

or:

$ python gpuGraph.py

or:

$ python3 gpuGraph.py
```

# 运行yolov3 

* 来源于该repo: https://github.com/alsolh/jetson-nano.git

* building yolo clone change below GPU=1 CUDNN=1 OPENCV=1

* best configuration for full yolo (3-4fps performance) yolov3.cfg change below lines batch=1 subdivisions=1 width=220 height=220

* configure the env 
```
export LD_LIBRARY_PATH=/usr/local/cuda/lib
export PATH=$PATH:/usr/local/cuda/bin
```

* command to run yolo demo in CSI connected camera like rpi
```
./darknet detector demo cfg/coco.data cfg/yolov3.cfg yolov3.weights "nvarguscamerasrc auto-exposure=1 ! video/x-raw(memory:NVMM), width=(int)1280, height=(int)720, format=(string)NV12, framerate=(fraction)60/1 ! nvvidconv flip-method=0 ! video/x-raw, width=(int)1280, height=(int)720, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink -e"
```
