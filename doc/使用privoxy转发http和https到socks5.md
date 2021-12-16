# 安装和配置(Ubuntun)

## 首先安装 privoxy

```shell
sudo apt-get install privoxy -y
```

## 修改配置文件

- 默认的配置文件是/etc/privoxy/config，在最后加上如下代码
- 不要忘记最后的 .
- 假设 sock5 的端口是 1080

```shell
forward-socks5t / 127.0.0.1:1080 .
```

## 重启服务

```shell
sudo /etc/init.d/privoxy start
```

## 查看运行状态

```shell
systemctl status privoxy.service
```

## 实际使用

### 打开 socks5 服务

first make sure socks5 service is running on your laptop.

#### Method 1: 打开终端修改 http/https 代理

- privoxy 的默认端口是 8118

```shell
export http_proxy=http://127.0.0.1:8118
export https_proxy=http://127.0.0.1:8118
```

- 在终端测试下载

```shell
wget www.ti.com
```

- run software in terminal

  - run browser in the terminal, sometimes need to setup the browser proxy
  - run gitkraken in the terminal

#### Method 2: change current user environment

- add following code to the end of file ~/.bashrc and save

```shell
export http_proxy=http://127.0.0.1:8118
export https_proxy=http://127.0.0.1:8118
```

- then execure

```shell
source ~/.bashrc
```

- run software without terminal or run software in terminal
  - run browser, sometimes need to setup the browser proxy
  - run gitkraken
  - run terminal

|      software       |                                   Ubuntu 18.04                                   |                  Linux Mint                   |                   MX linux                    |
| :-----------------: | :------------------------------------------------------------------------------: | :-------------------------------------------: | :-------------------------------------------: |
|      terminal       |                                                                                  |                                               |                                               |
| terminal clone code |                                                                                  |                                               |                                               |
|  terminal download  |                                                                                  |                                               |                                               |
|       vscode        |                                                                                  |                                               |                                               |
|      gitkraken      |                                                                                  |                                               |                                               |
|   chrome browser    |                                                                                  | must run in terminal, needn't setup the proxy | must run in terminal, needn't setup the proxy |
|   firefox browser   | must setup the proxy: Manual proxy configuration, then SOCKS HOST 127.0.0.1:1080 |             must setup the proxy              |             must setup the proxy              |
