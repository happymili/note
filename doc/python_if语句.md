# if语句
判断相等用==，判断不相等用！=
```
cars = ['bmw', 'audi', 'mazada', 'toyota']
for car in cars:
    if car == 'audi':
        print(car.upper())
    else:
        print(car.lower())

brand = 'toyota'
if brand != car:
    print("\nnot the same brand")
else:
    print("\nsame brand")
```
output
```
bmw
AUDI
mazada
toyota

same brand
```

# compare numbers
```
answer = 17

if answer != 42:
    print("That's not the right answer, please try again.")
```
output
```
That's not the right answer, please try again.
```


# and or
用and和or检查多个条件
```
Python 3.7.3 (default, Oct  7 2019, 12:56:13) 
[GCC 8.3.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> tom = 12
>>> jim = 15
>>> (tom > 10) and (jim < 20)
True
>>> (tom > 30) or (jim < 16)
True
>>> 
```

# check
* 检查特定值是否包含在列表中
```
users = ['tom', 'lisa', 'lina']
user = 'lisa';
if user in users:
    print(user.title() + " is in allowed user list.")
else:
    print(user.title() + " is not in allowed user list.")
```
* 检查特定值是否不包含在列别中，下面是例子：
```
banned_users = ['andrew', 'carolina', 'david']
user = 'david'

if user not in banned_users:
    print(user.title().strip() + ", you can post a response if you wish.")
else:
    print(user.title().strip() + ", you can't post a response.")
```
output
```
David, you can't post a response.
```


# bool
布尔表达式
```
Python 3.7.3 (default, Oct  7 2019, 12:56:13) 
[GCC 8.3.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> game_active = True
>>> can_edit = False
>>> print(game_active == True)
True
>>> print(can_edit != False)
False
>>> 
```

# if_elif_else

```
age = 12

if age < 4:
    price = 0
elif age < 18:
    price = 5
elif age < 65:
    price = 10
else:
    price = 5

print("Your ticket price is: " + str(price))
```
output
```
Your ticket price is: 5
```


# check special element
```
requested_toppings = ['mushrooms', 'green peppers', 'extra cheese']

for requested_topping in requested_toppings:
    if requested_topping == 'green peppers':
        print("Sorry, " + requested_topping + " is not available now.")
    else:
        print("Adding " + requested_topping + ".")

print("\nFinished making your pizza.")
```
output
```
Adding mushrooms.
Sorry, green peppers is not available now.
Adding extra cheese.

Finished making your pizza.
```


# check if the list is empty
```
requested_toppings = []

if requested_toppings:
    for requested_topping in requested_toppings:
        print("Adding " + requested_topping + ".")
    print("\nFinished making your pizza.")
else:
    print("Are you sure you want a plain pizza?")
```
output
```
Are you sure you want a plain pizza?
```

# use several lists
```
available_toppings = ['mushrooms', 'olives', 'green peppers',
        'pepperoni', 'pineapple', 'extra cheese']

requested_toppings = ['mushrooms', 'french fries', 'extra cheese']

for requested_topping in requested_toppings:
    if requested_topping in available_toppings:
        print("Adding " + requested_topping + ".")
    else:
        print("Sorry, " + requested_topping + " is not available.")

print("\nFinished making your pizza.")
```
output
```
Adding mushrooms.
Sorry, french fries is not available.
Adding extra cheese.

Finished making your pizza.
```
