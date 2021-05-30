# 变量
hello_world.py
```
message = "Hello Python world!"
print(message)
```
输出
```
Hello Python world!
```
# 变量的命名和使用
* 变量名只能包含字母,数字和下划线
* 变量名不能包含空格
* 不要将Python关键字和函数名用作变量名
* 变量名应既简短又具有描述性

# 字符串
* 用引号括起来的都是字符串，其中的引号可以是**单引号**，也可以是**双引号**
```
"This is a string."
'This is also a string."
```
* 可以在字符串中包含**引号**和**撇号**
```
'I told my friend, "Python is my favourite language!"'
"The language 'Python' is named after Monty Python, not the snake."
"One of Python's strengths is its diverse and supportive community."
```
### 修改字符串的大小写
* title()以首字符大写的方式显示每个单词
* upper()将字符串改为全部大写
* lower()将字符串全部改为小写

name.py
```
name = "ada lovelace"
print(name.title())
print(name.upper())
print(name.lower())
```
输出
```
Ada Lovelace
ADA LOVELACE
ada lovelace
```
### 合并（拼接）字符串
namecat.py
```
first_name = "ada"
last_name = "lovelace"
full_name = first_name + " " + last_name
message = "Hello, " + full_name.title() + "!"
print(message)
```
输出
```
Hello, Ada Lovelace!
```

### 使用制表符或换行符添加空白
table.py
```
print("Language:\n\tPython\n\tC\n\tJavaScript")
```
输出
```
Language:
    Python
    C
    JavaScript
```

### 删除空白
* rstrip()确保字符串末尾没有空白
* lstrip()确保字符串开头没有空白
* strip()全包字符串开头和末尾都没有空白

delete_space.py
```
language = ' python '
print(language.rstrip() + " language")
print(language.lstrip() + " language")
print(language.strip() + " languange")
```
输出
```
 python language
python  language
python language
```

# 数字
### 整数
* 加减乘除
```
>>> 2 + 3
5
>>> 3 - 2
1
>>> 2 * 3
6
>>> 3 / 2
1.5
```
* 乘方
```
>>> 3 ** 2
9
>>> 3 ** 3
27
>>> 10 ** 6
1000000
```
* 运算优先级
```
>>> 2 + 3 * 4
14
>>> (2 + 3) * 4
20
```
### 浮点数
* 浮点运算
```
>>> 0.1 + 0.1
0.2
>>> 0.2 + 0.2
0.4
>>> 2 * 0.1
0.2
>>> 2 * 0.2
0.4
```
* 小数位可能是不确定的
```
>>> 0.2 + 0.1
0.30000000000000004
```

### 使用函数str()避免类性错误
age.py
```
age = 23
message = "Happy " + str(age) + "rd Birthday!"
print(message)
```
输出
```
Happy 23rd Birthday!
```
