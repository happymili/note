# const的声明

只读整型数
```
const int a;
int const a;
```

指向只读整形数的指针
```
const int *a;
```

只读指针
```
int * const a;
```

指向只读整形数的只读指针
```
int const * const a;
```

# const不一定是常量，而是表示只读

* 下面的例子在Ubuntun上测试运行
* a定义为const int类型
* 然后定义了一个const int * 类型的指针y，将a的地址赋值给y，这里y如果定义为int * 类型，编译器会报错不可以将const int * 类型赋值给int * 类型
* 将y做强制转换成int * 类型，然后对y指向的地址位置赋新的值
* 编译成功，执行结果显示修改成功了
* 根据这个例子，显然const表示为只读更加准确
```
#include <stdio.h>
int main(){
	const int a = 14;
	const int * y = &a;
	*(int *)y = 16;
	printf("a == %d.\n", a);

	return 0;
}
```
output
```
a == 16.
```

# 嵌入式系统里的const

* 嵌入式系统里面的const有一个特殊的用途就是强制将数据存储到ROM或者flash里面，以节约RAM消耗，这时候就不能通过上面代码的方法去修改数据了
* 开发人员应当知道编译器做了什么操作，以及const修饰的变量存储在什么地方

# 用const修饰的传参在函数内被保护
* 测试时，在add函数内对a和b做++操作，编译时就报错了
```
#include <stdio.h>

int add(const int a, const int b){
	++a;
	++b;
	return a+b;
}

int main(){
	int a = 3;
	int b = 4;
	int sum;

	sum = add(a, b);
	printf("sum = %d.\n", sum);
	return 0;	
}
```
编译时报错
```
const03.c: In function ‘add’:
const03.c:4:2: error: increment of read-only parameter ‘a’
  ++a;
  ^~
const03.c:5:2: error: increment of read-only parameter ‘b’
  ++b;
  ^~
```
正确的做法是，在add函数体内，a和b都不可以被修改
```
#include <stdio.h>

int add(const int a, const int b){
	return a+b;
}

int main(){
	int a = 3;
	int b = 4;
	int sum;

	sum = add(a, b);
	printf("sum = %d.\n", sum);
	return 0;	
}
```
执行输出
```
sum = 7.
```

# 加上const的好处
* const可以保护那些不想被修改的参数
* 在MCU开发过程中，修饰为const的参数会存储到ROM或flash，这样可以降低RAM的使用，代码会更加紧凑
* 告诉编译器在编译时检查参数是否在函数体内被修改，如果做了修改要报错，给开发人员自身提供了非常有效的信息，避免bug的产生
* 给读你代码的人传达非常有用的信息，通过const可以清晰的了解到，参数是不可以被修改的
