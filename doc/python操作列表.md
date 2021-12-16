# for循环
```
magicians = ['bob', 'alis', 'tom', 'jassy']
for magician in magicians:
    print(magician.title().strip() + ", that was a great trik!")
    print("I can't wait to see your next trik, " + magician.title().strip() + ".\n")

print("Thank you, everyone. That was a great magic show!")
```
output
```
Bob, that was a great trik!
I can't wait to see your next trik, Bob.

Alis, that was a great trik!
I can't wait to see your next trik, Alis.

Tom, that was a great trik!
I can't wait to see your next trik, Tom.

Jassy, that was a great trik!
I can't wait to see your next trik, Jassy.

Thank you, everyone. That was a great magic show!
```

# range
使用函数range()生成一系列的数字
```
for value in range(1,6):
    print(value)
```
output
```
1
2
3
4
5
```

# list
使用函数list()将range()的结果直接转换为列表
```
numbers = list(range(1,6))
print(numbers)
for value in numbers:
    print(value)
```
output
```
[1, 2, 3, 4, 5]
1
2
3
4
5
```



# range指定步长
下面的例子从2开始，然后不断的加2
```
even_numbers = list(range(2,12,2))
print(even_numbers)
```
output
```
[2, 4, 6, 8, 10]
```


# squre
两个星号表示求开方
```
squres = []
for value in list(range(1,11)):
    squres.append(value**2)
print(squres)
```
output
```
[1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
```

# min max sum
使用min max sum对数字列表执行简单的统计计算
```
numbers = list(range(1,11))
print("Min = " + str(min(numbers)))
print("Max = " + str(max(numbers)))
print("Sum = " + str(sum(numbers)))
```
output
```
Min = 1
Max = 10
Sum = 55
```

# 列表解析
使用一行代码即可生成想要的列表
```
squres = [value**2 for value in range(1,11)]
print(squres)
```
output
```
[1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
```


# 列表的切片
```
players = ['lily', 'lucy', 'tom', 'tina', 'fla', 'dan']
print(players)

print(players[0:3])

print(players[1:4])

print(players[:4])

print(players[2:])

print(players[-3:])
```
output
```
['lily', 'lucy', 'tom', 'tina', 'fla', 'dan']
['lily', 'lucy', 'tom']
['lucy', 'tom', 'tina']
['lily', 'lucy', 'tom', 'tina']
['tom', 'tina', 'fla', 'dan']
['tina', 'fla', 'dan']
```


# 遍历切片
```
players = ['lily', 'lucy', 'tom', 'tina', 'fla', 'dan']
print("Here are the first three players:")
for player in players[0:3]:
    print(player)
```
outpupt
```
Here are the first three players:
lily
lucy
tom
```



# 复制列表
### 将整个列表切片，可以复制整个列表
```
my_food = ['pizza', 'falafel', 'carrot cake']
friend_food = my_food[:]

my_food.append('cannoli')
friend_food.append('ice cream')

print("My favourite foods are:")
print(my_food)

print("My friend's favourite foods are:")
print(friend_food)
```
output
```
My favourite foods are:
['pizza', 'falafel', 'carrot cake', 'cannoli']
My friend's favourite foods are:
['pizza', 'falafel', 'carrot cake', 'ice cream']
```

### 直接赋值并不是复制
```
my_food = ['pizza', 'falafel', 'carrot cake']
friend_food = my_food

my_food.append('cannoli')
friend_food.append('ice cream')

print("My favourite foods are:")
print(my_food)

print("My friend's favourite foods are:")
print(friend_food)
```
output
```
My favourite foods are:
['pizza', 'falafel', 'carrot cake', 'cannoli', 'ice cream']
My friend's favourite foods are:
['pizza', 'falafel', 'carrot cake', 'cannoli', 'ice cream']
```



# 元组
* 不可变的列表称为元组，使用圆括号扩起来，而列表是用方括号扩起来
* 不可以修改元组的元素，但是可以修改元组变量
```
dimensions = (200, 50)
print(dimensions)

print(dimensions[0])
print(dimensions[1])

print("\nOriginal dimensions:")
for dimension in dimensions:
    print(dimension)

print("\nModified dimensions:")
dimensions = (400,100)
for dimension in dimensions:
    print(dimension)
```
output
```
(200, 50)
200
50

Original dimensions:
200
50

Modified dimensions:
400
100
```

