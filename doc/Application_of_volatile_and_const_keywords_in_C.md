The const volatile are fascinating keywords that make many people confuse. The volatile keyword is a type qualifier that prevents the objects from the compiler optimization. According to C standard, an object that has volatile-qualified type may be modified in ways unknown to the implementation or have other unknown side effects. You can also say that the value of the volatile-qualified object can be changed at any time without any action being taken by the code. If an object is qualified by the volatile qualifier, the compiler reloads the value from memory each time it is accessed by the program that means it prevents from cache a variable into a register. Reading the value from memory is the only way to check the unpredictable change of the value.

Note: Reading the value from memory is the only way to check the unpredictable change of the value.

In this article, I will discuss two contrast keyword const and volatile and describe their uses in a program. As we already know the const keyword protects the value of the object and it does not allow any operation (++, –, =) on the object which modify its value. If you are not aware of the volatile qualifier, I recommend you read [understanding volatile qualifier in c](Understanding_volatile_qualifier_in_C.md) before going on. Because I assumed that you have the knowledge of volatile qualifier.


# Does it ever make sense to use volatile and const together?

It is a common question that is generally asked by the people, to understand this question first let us know the difference between the volatile and const keyword.

The const keyword is compiler-enforced and says that the program could not change the value of the object that means it makes the object nonmodifiable type.

On the side, volatile prevents any compiler optimization and says that the value of the object can be changed by something that is beyond the control of the program and so that compiler will not make any assumption about the object.

Now it’s time for the answer, suppose you have worked on a project where you need to read the status of the register. I am assuming that the address of the register is 0x00020000. To access the value of the status register, we need to map the address of register with a pointer.

Mapping of the register address with the pointer.
```
uint32_t *pStatusReg = (uint32_t *) 0x00020000;
```

Using the pointer (pStatusReg), we can read the value of the status register but problem is that the pointed address is not qualified by the const so that the program can change the value of the status register. It creates a problem because you will not get the proper value from the status register.

So to avoid this problem we have to qualify the address with the const keyword.
```
uint32_t const *pStatusReg = (uint32_t *) 0x00020000;
```

Now const qualifier makes the value of status register nonmodifiable but still, there is one more problem. It can be possible the address that is pointing by the pointers can be changed because the pointer is not constant type, so we have to qualify the pointer with a const qualifier.

```
uint32_t const * const pStatusReg = (uint32_t *) 0x00020000;
```

In the above expression pointer and address both qualified by const qualifier, so might be compiler put the value of the status register to a cache memory for the fast processing because they have found that program is not able to modify the value of the status register and the value of the status register will be the same in every read.

So here volatile can resolve your problems because when the data is marked as volatile the compiler won’t make such an assumption (because the object can be changed at any time without any action being taken by the code) and so it will reread the value from the status register.
```
uint32_t const volatile * const pStatusReg = (uint32_t *) 0x00020000;
Register_Status = *pStatusReg ; // Read value from the Status Register
```

Note:  According to C standard If an attempt is made to refer to an object defined with a volatile-qualified type through the use of an lvalue with a non-volatile-qualified type, the behavior is undefined.

Let’s take a small code which has the responsibility to receive the data during the communication.

In this example code, we will monitor the status of the receiving flag. The flag will set after receiving the data bytes.

```
#define COM_STATUS_BIT  0x00000006
uint32_t const volatile * const pStatusReg = (uint32_t*)0x00020000;
unit32_t GetRecvData()
{
  //Code to recv data
  while (((*pStatusReg)  & COM_STATUS_BIT) == 0)
  {
    // Wait until flag does not set
  }
  
  return RecvData;
}
```

Note: If any object qualifies by both volatile and const, the value of the object could not be altered by its own program, but could be altered by another process.


# Some places where const volatile are used together

There is a lot of places where we need to use volatile and const together, in the below section, I am describing some important places where we have to require volatile and const together.

### Access the GPIO

One of the great use of volatile and const keyword together is at the time of accessing the GPIO registers. In the case of GPIO, its value will be changed by the ‘external factors’ (if a switch or any output device is attached with GPIO), if it is configured as an input. In that situation, volatile plays an important role and ensures that the compiler always read the value from the GPIO address and avoid to make any assumption.

After using the volatile keyword, you will get the proper value whenever you are accessing the ports but still here is one more problem because the pointer is not const type so it might be your program change the pointing address of the pointer. So we have to create a constant pointer with a volatile keyword.

Syntax of declaration,
```
int volatile * const PortRegister;
```

How to read the above declaration
```
int volatile * const PortRegister;
 |     |     |   |    |
 |     |     |   |    +------> PortRegister is a
 |     |     |   +-----------> constant
 |     |     +---------------> pointer to a
 |     +---------------------> volatile
 +---------------------------> integer
```

Consider a simple below example:
```
#define PORTX 0x00020000  // Address of the GPIO 

uint32_t volatile * const pcPortReg = (uint32_t *) PORTX;
```
The pcPortReg is a constant pointer to a volatile unsigned integer, using *pcPortReg we can access the memory-mapped register.
```
*pcPortReg = value; // Write value to the port

value = *pcPortReg; // Read value from the port
```

### Read-only object

There is a lot of embedded software that can be calibrated at runtime. The const and volatile is useful when the flash is used as storage for a variable, if you reprogram this flash in runtime, the value of the variable will be updated by the new value.

For example,
```
const volatile int device_status;
```
Read from the status register

There are a lot of registers which are used to reflect the status of the device at the different stage of the hardware. These registers are read-only types and their value changes by asynchronously by the other events. If you want to access these register, you have to use const and volatile together with pointers (I have already explained at the beginning of the article).

Syntax of declaration,
```
 int const volatile * const PortRegister;
```
How to read the above declaration
```
int const volatile * const  ptr;
 |    |      |     |   |     |
 |    |      |     |   |     +------> ptr is a
 |    |      |     |   +------------> constant
 |    |      |     +----------------> pointer to a
 |    |      +----------------------> volatile
 |    +-----------------------------> const
 |
 +----------------------------------> integer
 ```
 
### Read-Only Shared-Memory Location

If two processor communicates to each other using the shared memory location and processor uses the location only to the read the data, we have to make the location read-only type using the const keyword.

Syntax of declaration,
```
uint8_t  const volatile acSharedBuffer[BUFFER_SIZE];
```

# Conclusion:
The proper use of volatile and const keywords is beneficial but if you don’t know the proper place where volatile and const is required, you can face the problem.
