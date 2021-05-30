The volatile keyword has a lot of importance in the programming language but problem is that many programmers are not aware of to how to use the volatile keyword and when need to qualify a variable from the volatile keyword. Most of the textbooks don’t give importance to this topic either and hence it remains partially unexplained most of the time.

In this article, I will try to clear the concept of volatile keyword and describe the benefits of volatile qualifier in c language.

A volatile keyword is a qualifier which prevents the objects, from the compiler optimization and tells the compiler that the value of the object can be change at any time without any action being taken by the code. It prevents from the cache a variable into a register and ensures that on every access variable is fetched from the memory.

The volatile keyword is mainly used where we directly deal with GPIO, interrupt or flag Register. It is also used where a global variable or buffer is shared between the threads.

# Declaration of volatile in c

We can declare a variable volatile to put volatile keyword after or before the data type at the time of variable declaration.

```
int volatile iData;
volatile int iData;
```

Note: We can also use the volatile keyword with pointers same like as variables.

# Volatile keywords can be used with pointers in following ways

We can use the pointer with a volatile keyword in many ways.In below section, I am describing some situation where pointer and volatile keyword come together.

### Pointer to the volatile variable

```
int volatile *piData;
volatile int *piData;
```

In this scenario, a pointer points to the variable which qualifies with volatile keyword. In this situation, the compiler assumes that value of the variable, which is pointed by pointer can be change unexpectedly any time. So when we read or write \*piData, compiler is always aware of the unexpected changes of variable value.

```
volatile int iValue;
volatile int* piData = &iValue;
```

Note: If you declare a T(data type) variable as volatile, then should not use T \* to point this variable.

consider the below example

wrong way to use the pointer with the volatile variable

```
volatile int iValue;
int* piData = &iValue;
```

Right way to use the pointer with the volatile variable

```
volatile int iValue;
volatile int* piData = &iValue;
```

### Volatile pointer to the non-volatile variable

In this case, the pointer is volatile and it is a point to a non-volatile variable.

```
int *volatile piData;
```

### Volatile pointer to the volatile variable

Here pointer and variable both are volatile, means there is no optimization applicable on the pointer and on its pointed variable.

```
volatile int * volatile piData;
```

# Use of volatile qualifier with the structure

A volatile keyword is also useful with user define data types.When we declare a variable of structure volatile then all member of the structure are volatile but sometime in the program, we need only some specific member as volatile so in that situation, we have to declare this member implicitly volatile.

Its totally depend on requirements to how to use volatile keyword with structure.In below section, I am describing some examples of volatile and structure.

Example 1.

```
typedef struct  {

  unsigned int PortReg;
  unsigned int FlagReg;

}My_Reg;

My_Reg volatile sMyHardwareReg;
```

In above example, all member of the sMyHardwareReg is volatile.

Example 2.

```
typedef volatile struct  {

  unsigned int PortReg;
  unsigned int FlagReg;

}My_Reg;
```

In above example, My_Reg is a user define data type, whose all member are volatile.

Example 3.

```
typedef struct  {

  unsigned int volatile PortReg;
  unsigned int FlagReg;

}My_Reg;

My_Reg sMyHardwareReg;
```

In above example, PortReg is only volatile member of sMyHardwareReg variable.

Note: Differences between marking the struct variable as volatile vs marking individual fields volatile.

Below example describes the difference

```
typedef struct
{
  int *piPortReg;
  int TimerReg;
} MyReg;

volatile MyReg sMyReg;
```

That would act like:

```
typedef struct
{
  int * volatile piPortReg;
  int volatile TimerReg;

} MyReg;
```

and not like:

```
typedef struct
{
  volatile int *piPortReg;
  int volatile TimerReg;

} MyReg;
```

Note: So in the case of structure, if there is a member who is the pointer and you want to this pointer point to a volatile memory then you have to implicitly declare this pointer.

```
typedef struct
{
  volatile int *piPortReg;
  int TimerReg;

} MyReg;
```

# When need to use volatile keyword

It is very important to understand when to use the volatile keyword in the program.Many programmers know the concept of volatile but they are not aware of the situation where using of volatile keyword is beneficial.

There is the following situation where you may need to use the volatile keyword in the program.

- Program works fine but when increase the optimization level of compiler its behavior change and not work as per the desire.
- Everything is going good but as soon as you enable the interrupt, code behavior change and does not work as per the expectation.
- Flaky hardware drivers.
- Tasks that work fine in isolation but crash when another task is enabled.

# how do volatile affect the program?

The volatile keyword used to restrain the compiler from making the assumption about the object value. It tells the compiler to re-read the value of the object in every execution.

For better understanding, I am taking a small program to describe the importance of volatile keyword.

```
unsigned char FLAG_REG;   // Hardware flag register

void func (void)
{
  while (FLAG_REG & 0x01)   // Repeat while bit 0 is set
  {
    //Perform any operation
  }
}
```

When we increase the compiler optimization level for a program then for the better performance compiler load the FLAG_REG value in a register and does not re-read again although the value of FLAG_REG change by the hardware.
In that situation, your code would not be work as per your expectation.

when you qualify the FLAG_REG from the volatile keyword then compiler understand that may be the value of FLAG_REG change by the outer word so it avoids implementing any optimization on it.

```
unsigned volatile char FLAG_REG;   //qualify from the volatile


void func (void)
{
  while (FLAG_REG & 0x01)   // Repeat while bit 0 is set
  {
    //Perform any operation
  }
}
```

# A proper place to use the volatile keyword

A variable should be declared volatile when its value could be changed unexpectedly. In practice, you must declare a variable as volatile whenever you are:

- Accessing the memory-mapped peripherals register.
- Sharing the global variables or buffers between the multiple threads.
- Accessing the global variables in an interrupt routine or signal handler.

In below section, I am talking about all three cases.

### Peripheral Register

In the embedded system, all peripherals are located at the specific memory address. Peripherals have the registers, the value of these register can be change asynchronously to code flow.

In a program, to access the peripherals register in a convenient way, we have to map the peripherals register with c variable and access this variable using the pointer.

Note: In mapping not only care about size and address of the registers but also need to care about its alignment in memory.

Consider a simple example, here a 32-bit flag status register at an address 0x40000000 and we have to monitor its first bit and wait in the loop until its first bit is one.

```
#define   STATUS_REG            (unsigned int*)(0x40000000)

unsigned int  *puiData = STATUS_REG;
while((*puiData) & 0x01) // Wait until first bit is set
{
  //do some work
}
```

But when we qualify the status register address with a volatile keyword then compiler understand that value of this address can change anytime without any prior information. So compiler not performs any optimization on this variable and always re-read the value from the address.

### Interrupt service routine (ISR)

In the case of Interrupt service routine, often a global variable is shared between ISR and main function. In this scenario value of global variable set or check by either the ISR or main function, for better understanding, I am taking a sample example.

```
int giFlag = 0;

ISR(void)
{
  giFlag = 1;
}

int main(void)
{

  while (!giFlag)
  {
      //do some work
  }

  return 0;
}
```

In the above code, the global flag is the monitor in the main function and main function does some other task until the global flag value is zero.

When we have turned on the optimization level of the compiler then might be this code work fine because the compiler is unaware of the value changed of the global variable in ISR, so it assumes that while loop is always true and it never exits from the loop.

A solution of this problem is to make the global flag volatile, this technique prevents the compiler from applying any optimization on the global flag and tells the compiler that value of this flag can change by external event at any time without any action being taken the by code.

```
volatile int giFlag = 0;

ISR(void)
{
  giFlag = 1;
}

int main(void)
{

  while (!giFlag)
  {
      //do some work
  }

  return 0;
}
```

### Multithread application

In a multithread application, two thread communicate to each other using the pipes or message queue but beside it, there is one more technique through which thread can communicate to each other this technique is shared location (shared buffer or global variable).

Generally, the thread is executed in an asynchronous way. If we do not declare these shared locations with volatile and we increase the optimization level of the compiler then the compiler will store these values in a local variable of thread context and always read the value from theses local variable. So for the desired operation, we have to declare shared buffer or global variable as volatile.

```
int gValue;

void Task_1(void)
{
    gValue = 0;

    while (gValue == 0)
    {
        sleep(1);
    }
    ...
}

void Task_2(void)
{
    ...
    gValue++;
    sleep(10);
    ...
}
```

When increasing the optimization level of the compiler then might be above code failed and not perform as the acceptation.

# const and volatile qualifier together

It is very interesting to use volatile and const keyword together because the quality of the volatile (“any time-changing”) and const (“read-only”) seems like opposed, but sometimes it is useful to use this keyword together with a variable.

In below section, I am describing some scenario where using this keyword make a sense and beneficial.

### Constant address for GPIO Register

Both qualifier const and volatile frequently uses in the scenario where we access the GPIO register or any hardware register.To access these register, we need to declare a constant pointer to the volatile register.

```
unsigned int volatile * const pLcdReg = (unsigned int volatile *) 0x00020000;
```

The proper way to read the above complex declaration is as

pLcdReg is a constant pointer to a volatile unsigned integer.

In this declaration the only pointer is constant (i.e., the fixed address 0x00020000) means that throughout the program its value does not change. The keyword volatile only modify the behavior of unsigned integer.

This is most useful and safer declaration of the pointer to access the GPIO or hardware register.

```
*pLcdReg = WRITE_DATA; // to write data on LCD
READ_DATA = *pLcdReg; //to read data from the LCD
```

### Read-Only Shared-Memory Location

This scenario is also very important where const and volatile use together. If two processor communicates to each other using shared location and processor uses the location only for the read then we have to make these location read only type using the const keyword.

We can declare the shared memory location in following way

```
unsigned int const volatile gSharedFlag;

unsigned char const volatile acSharedBuffer[BUFFER_SIZE];
```

### Read only-only status register

There are following hardware registers, which represent the status of the different stage of hardware.This register is the read-only type, to access these register, we need to declare a constant pointer to the constant volatile register.

```
unsigned int const volatile * const pStatusFlagReg = (uint8_t *) 0x20000000;
```

The proper way to read this complex declaration is as

pStatusFlagReg is a constant pointer to a volatile constant unsigned integer.

```
READ_DATA = * pStatusFlagReg; //to read status from the status register

* pStatusFlagReg = WRITE_DATA // Not possible because address qualify by const keyword
```
