# IAR

## 常用设置（菜单点击 Tools，选择 Options）

- Editor

  - Tab size Tab 键缩进多少个字符
  - Indent size 普通缩进多少个字符
  - Tab Key Function
    - Insert tab 插入 tab 键
    - Insert with spaces 插入空格
  - Show right margin
    - Pringting edge 打印边缘
    - Columns 字符数
  - File Encoding
    - Default character encoding
    - Auto-detect character encoding 自动探测编码格式
    - EOL characters
      - PC 如果 PC 是 windows，换行符是 0d 0a "\r\n"
      - UNIX 按照 UNIX 标准，换行符是 0a "\n"
      - Preserve
  - Syntax highlighting 语法高亮
  - Auto indent 自动缩进
  - Show line numbers 显示行号
  - Scan for changed files
  - Show bookmarks 显示书签
  - Show fold margin
  - Enable virtual space
  - Remove trailing blanks
  - Auto code completion and parameter hints
  - Show source browser tooltips
  - Show line break characters
  - Show whitespaces

- Project

  - Stop build operation on
  - Save editor windows before building
  - Save workspace and projects before building
  - Make before debugging
  - Reload last workspace at startup
  - Play a sound after build operations
  - Generate browse information
  - No source browser and build status updates when the IDE is not the foreground process
  - Enable project connections
  - Enable parallel build 使能多进程编译
  - Processes 进程数

## project 设置（鼠标点中 project 名，右键选择 Options）

- General Options
  - Target 设置芯片类型
  - Output 生成可执行文件/生成库文件
  - Library Configuration
    - Library
- C/C++ Compiler
  - Extra Options
    - Command line options
  - Preprocessor
    - Additional include directories 头文件
    - Defined symbols 宏定义
  - Optimizations
    - Level 编译等级
  - Diagnostics
    - Suppress these diagnostics (Pa082,Pa050,Pe167,Pg002) 诊断
- Output Converter
  - Generate additional output
    - Output format 生成文件的格式
      - Output file
        - Override default
- Linker
  - Config
    - Linker configuration file 链接配置文件
      - Override default
        - Edit
    - Configuration file symbol definitions:(one per line)
  - Library
    - Additional libraries 库文件
  - Optimizations
    - Inline small routines
  - Output
    - Output filename out 文件的生成
  - Extra Options
    - Command line options
- Debugger
  - setup
    - Driver 调试器类型
    - Run to 是否直接跳转到 main 函数
  - Plugins 可选插件，比如操作系统相关的插件，可以更方便的调试

## IAR C/C++ Development Guide Compiling and Linking

- pack
- **IAR_SYSTEMS_ICC**

## windows 编译脚本文件实例

```bat
@if exist build_project_boot.log (@del /q/f build_project_boot.log)
"C:\Program Files (x86)\IAR Systems\Embedded Workbench 8.3\common\bin\IarBuild.exe" ./bootloader.ewp Debug -parallel 16 2>&1 | tee build_project_boot.log
```
