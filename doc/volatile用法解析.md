# volatile 的作用

* 告诉编译器不要优化被修饰的参数
  * 比如一些调试用的变量，在优化等级调高时，这些变量还会存在，不会被优化掉
* 告诉编译器，这个参数随时可能在程序的其他地方会被修改，需要每次从内存读取参数的值，而不能用寄存器里面的缓存
  * 线程之间共享的全局变量或者全局buffer
  * 中断服务程序会访问到的非自动变量（全局变量，静态变量）
* 告诉编译器，这个参数随时可能产生非软件修改导致的变化，需要每次从内存读取参数的值，而不能用寄存器里面的缓存
  * 硬件寄存器：比如GPIO输入状态，随时可能改变，需要每次从内存地址读取

# 从汇编层面理解volatile

### Peripheral Registers

Embedded systems contain real hardware, usually with sophisticated peripherals. These peripherals contain registers whose values may change asynchronously to the program flow. As a very simple example, consider an 8-bit status register that is memory mapped at address 0x1234. It is required that you poll the status register until it becomes non-zero. The naive and incorrect implementation is as follows:
```
uint8_t * p_reg = (uint8_t *) 0x1234;

// Wait for register to read non-zero 
do { ... } while (0 == *p_reg)
```

This code will almost certainly fail as soon as you turn compiler optimization on.  That's because the compiler will generate assembly language (here for an 16-bit x86 processor) that looks something like this:
```
  mov p_reg, #0x1234
  mov a, @p_reg
loop:
  ...
  bz loop
```
  
The rationale of the optimizer is quite simple: having already read the variable's value into the accumulator (on the second line of assembly), there is no need to reread it, since the value will (duh!) always be the same. Thus, from the third line of assembly, we enter an infinite loop. To force the compiler to do what we want, we should modify the declaration to:
```
uint8_t volatile * p_reg = (uint8_t volatile *) 0x1234;
```
The assembly language now looks like this:
```
  mov p_reg, #0x1234
loop:
  ...
  mov a, @p_reg
  bz loop
```

The desired behavior is thus achieved.

Subtler sorts of bugs tend to arise when registers with special properties are accessed without volatile declarations. For instance, a lot of peripherals contain registers that are cleared simply by reading them. Extra (or fewer) reads than you are intending could result in quite unexpected behavior in these cases.
