# 列表是什么

* 列表由一系列按特定顺序排列的元素组成
* 在python中， 用方括号[]来表示列表，并用逗号来分隔其中的元素
bicycles.py
```
bicycles = ['trek', 'cannondale', 'redline', 'specialized']
print(bicycles)
```
输出
```
['trek', 'cannondale', 'redline', 'specialized']
```

### 访问列表元素

bicycles.py
```
bicycles = ['trek', 'cannondale', 'redline', 'specialized']
print(bicycles[0].title())
```
输出
```
Trek
```

### 索引
* 第一个列表元素的索引是0，第二个列表元素的索引是1
* 通过将索引指定为-1，访问列表最后面一个元素，指定为-2，访问倒数第二个元素，以此类推

bicycles.py
```
bicycles = ['trek', 'cannondale', 'redline', 'specialized']
print(bicycles[-1].upper())
```
输出
```
SPECIALIZED
```

### 使用列表中的各个值
* 可以像使用变量一样使用列表中的各个值
* 可以做字符串拼接

bicycles.py
```
bicycles = ['trek', 'cannondale', 'redline', 'specialized']
message = "My first bicycle was a " + bicycle[0].title() + "."
print(message)
```
输出
```
My first bicycle was a Trek.
```

# 修改，添加和删除元素

### 修改列表元素

motorcycles.py
```
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)

motorcycles[0] = 'ducati'
print(motorcycles)
```
输出
```
['honda', 'yamaha', 'suzuki']
['ducati', 'yamaha', 'suzuki']
```

### 在列表中添加元素

##### 在列表末尾添加元素
* 通过append()方法在列表末尾添加元素，需要指定元素的值
```
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)

motorcycles.append('ducati')
print(motorcycles)
```
输出
```
['honda', 'yamaha', 'suzuki']
['honda', 'yamaha', 'suzuki', 'ducati']
```

##### 在列表中插入元素
通过insert指定索引位置插入元素，需要指定索引和元素的值
```
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)

motorcycles.insert(0, 'ducati')
print(motorcycles)
```
输出
```
['honda', 'yamaha', 'suzuki']
['ducati', 'honda', 'yamaha', 'suzuki']
```

### 从列表中删除元素
##### 通过del删除列表索引指定的元素
```
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)

del motorcycles[1]
print(motorcycles)
```
输出
```
['honda', 'yamaha', 'suzuki']
['honda', 'suzuki']
```

##### 使用pop方法删除元素
* 方法pop()可删除列表末尾的元素，并让你能够接着使用它
```
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)

popped = motorcycles.pop()
print(motorcycles)
print(popped)
```
输出
```
['honda', 'yamaha', 'suzuki']
['honda', 'yamaha']
suzuki
```
* 方法pop()并指定索引可弹出任何位置的元素
```
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)

popped = motorcycles.pop(1)
print(motorcycles)
print(popped)
```
输出
```
['honda', 'yamaha', 'suzuki']
['honda', 'suzuki']
yamaka
```

##### 使用remove()方法根据值删除元素
* 不知道元素的位置，但是知道元素的值，可以使用remove()方法删除元素
* 方法remove()只能删除第一个指定的值
```
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)

too_expensive = 'yamaha'
motorcycles.remove(too_expensive)
print(motorcycles)
print("A " + too_expensive.title() + " is too expensive for me.")
```
输出
```
['honda', 'yamaha', 'suzuki']
['honda', 'suzuki']
A yamaha is too expensive for me.
```

# 组织列表
### 使用sort()方法对列表永久性排序
* 按照字母正序排列

cars.py
```
cars = ['bwm', 'audi', 'toyota']
cars.sort()
print(cars)
```
输出
```
['audi', 'bwm', 'toyota']
```
* 按照字母反序排列

cars.py
```
cars = ['bmw', 'audi', 'toyota']
cars.sort(reverse=True)
print(cars)
```
输出
```
['toyota', 'bmw', 'audi']
```

### 使用sorted()方法对列表进行临时排序
* 按照字母顺序正向排序

cars.py
```
cars = ['bwm', 'audi', 'toyota']

print("here is the original list:")
print(cars)

print("here is the sorted list:")
print(cars.sorted())

print("here is the original list again:")
print(cars)
```
输出
```
here is the original list:
['bmw', 'audi', 'toyota']
here is the sorted list:
['audi', 'bmw', 'toyota']
here is the original list again:
['bmw', 'audi', 'toyota']
```

* 按照字母顺序反向排序

cars.py
```
cars = ['bwm', 'audi', 'toyota']

print("here is the original list:")
print(cars)

print("here is the sorted list:")
print(cars.sorted(reverse=True))

print("here is the original list again:")
print(cars)
```
输出
```
here is the original list:
['bmw', 'audi', 'toyota']
here is the sorted list:
['toyota', 'bmw', 'audi']
here is the original list again:
['bmw', 'audi', 'toyota']
```
### 倒着打印列表
```
cars = ['bwm', 'audi', 'toyota']
print(cars)

cars.reverse()
print(cars)
```
输出
```
['bmw', 'audi', 'toyota']
['toyota', 'audi', 'bmw']
```
### 确定列表长度
```
>>> cars = ['bmw', 'audi']
>>> len(cars)
2
```
