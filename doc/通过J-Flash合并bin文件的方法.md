# 通过J-Flash合并bin文件的方法

### hex文件举例
* 打开J-Flash
* 打开第一个文件，比如app文件， File -> Open data file
* 然后在菜单栏选择 File-> Merge data file -> 选择bootloader文件打开即可
* 如果合并的文件需要存储，则在菜单栏选择 File -> Save data file as -> 选择需要存储的格式及命名

### bin文件举例
* 打开J-Flash
* 打开第一个文件，比如app文件， File -> Open data file，**指定起始地址**
* 然后在菜单栏选择 File-> Merge data file -> 选择bootloader文件，**指定起始地址**，然后打开即可
* 如果合并的文件需要存储，则在菜单栏选择 File -> Save data file as -> 选择需要存储的格式及命名
