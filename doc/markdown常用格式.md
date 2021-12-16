# 编辑工具
理论上任何一款文本编辑器都能用于编辑 Markdown 文档，它们分别提供了不同程度的语法高亮、预览等功能，以下只是列举其中一部分，选择自己称手的即可。
* 现代编辑器: VSCode / Atom
* 传统编辑器: Vim / Emacs / Sublime Text / Notepad++
* IDE 自带编辑器: IntelliJ IDEA / Android Studio / WebStorm
* 专用编辑器: Ulysses / Mou / Typora / Markpad
* 在线编辑器: 各种支持 Markdown 的网站都提供了在线编辑器

# 一级标题
## 二级标题
### 三级标题
#### 四级标题
##### 五级标题
###### 六级标题

# 行内格式
对段落或者部分文本的强调效果

后面俩字**加黑**

后面俩字*斜体*

# 超链接
Markdown支持行内式链接和引用式链接

行内式[GitHub](https://github.com)链接

引用式[GitHub][1]链接

[1]: https://github.com

# 图片
* 绝对链接
![Jetson Nano](https://github.com/happymili/Blog/blob/master/jpg/JetsonNano.jpg)
* 相对链接
![Jetson Nano](../jpg/JetsonNano.jpg)

# 列表

包括有序列表和无序列表

* 李子
* 西瓜
* 香蕉

- 苹果
- 葡萄
- 榴莲

1. 苹果
2. 葡萄
3. 榴莲

# 代码块
```
if(0 == i){

}else{

}
```

# 底纹

`sudo apt install tree`

# 水平分割线
单独行里使用三个'*'或者'-' 来生产一条水平分割线

***
* * *
-----

- - -

# 表格

| 编号  | 姓名（左） | 年龄（右） | 性别（中） |
| ----- | :-------- | ---------: | :------:   |
| 0     | 张三       | 20         | 男         |
| 1     | 李四       | 21         | 男         |

# 任务列表
在 GitHub / GitLab 里有较好的支持

- [x] 洗碗
- [ ] 扫地
- [ ] 擦桌子
- [x] 洗衣
* [ ] 叠被
* [x] 倒垃圾
* [ ] 叠衣服
* [x] 擦玻璃

# 删除线

# 文档目录

* [编辑工具](#编辑工具)
* [一级标题](#一级标题)
* [行内格式](#行内格式)
