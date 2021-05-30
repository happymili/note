* [Magic numbers should not be used](#Magic-numbers-should-not-be-used)
* [Boolean operators should have boolean operands](#Boolean-operators-should-have-boolean-operands)
* [Standard outputs should not be used directly to log anything](#Standard-outputs-should-not-be-used-directly-to-log-anything)
* [Control flow statements should not be nested too deeply](#Control-flow-statements-should-not-be-nested-too-deeply)
* [Identifiers should not be longer than 31 characters](#Identifiers-should-not-be-longer-than-31-characters)
* [Loops with at most one iteration should be refactored](#Loops-with-at-most-one-iteration-should-be-refactored)
* [Insecure functions should not be used](#Insecure-functions-should-not-be-used)
* [Loops should not have more than one "break" or "goto" statement]()
* [Cognitive Complexity of functions should not be too high](#Cognitive-Complexity-of-functions-should-not-be-too-high)
* [Functions or methods should not have too many lines](#Functions-or-methods-should-not-have-too-many-lines)
* [Results of ~ and << operations on operands of underlying types unsigned char and unsigned short should immediately be cast to the operand's underlying type]()
* [Unions should not be used](#Unions-should-not-be-used)
* [Files should not have too many lines of code](#Files-should-not-have-too-many-lines-of-code)
* [Function parameters should not be reassigned](#Function-parameters-should-not-be-reassigned)
* [Limited dependence should be placed on operator precedence](#Limited-dependence-should-be-placed-on-operator-precedence)
* [Increment (++) and decrement (--) operators should not be used in a method call or mixed with other operators in an expression]()
* [typedef should be used for function pointers](#typedef-should-be-used-for-function-pointers)
* [Conditional operators should not be nested](#Conditional-operators-should-not-be-nested)

## Magic numbers should not be used

A magic number is a number that comes out of nowhere, and is directly used in a statement. Magic numbers are often used, for instance to limit the number of iterations of a loops, to test the value of a property, etc.

Using magic numbers may seem obvious and straightforward when you're writing a piece of code, but they are much less obvious and straightforward at debugging time.

That is why magic numbers must be demystified by first being assigned a name. This is classically done by using a constant (constexpr or const if your compiler does not support constexpr yet) or an enumeration.

-1, 0 and 1 are not considered magic numbers.

Noncompliant Code Example
```
void doSomething(int var) {
  for(int i = 0; i < 42; i++) { // Noncompliant - 42 is a magic number
    // ...
  }

  if (var == 42) { // Noncompliant - magic number
    // ...
  }
}
```
Compliant Solution
```
enum Status {
STATUS_KO = 0,
STATUS_OK = 42,
};

void doSomething(Status var) {
  constexpr int maxIterations = 42; // Compliant - in a declaration
  for(int i = 0; i < maxIterations ; i++){ // Compliant: 0 is excluded, and maxIterations is a named constant
    // ...
  }

  if (STATUS_OK == var) { // Compliant - number comes from an enum
    // ...
  }
}
```
## Boolean operators should have boolean operands

The use of operands with types other than bool with these operators is unlikely to be meaningful (or intended). This rule allows the detection of such uses, which often occur because the logical operators (&&, || and !) can be easily confused with the bitwise operators (&, | and ~).

Noncompliant Code Example
```
if ( 1 && ( c < d ) ) // Noncompliant
if ( ( a < b ) && ( c + d ) ) // Noncompliant
if ( u8_a && ( c + d ) ) // Noncompliant
if ( !0 ) // Noncompliant, always true
if ( !ptr ) // Noncompliant
if ( ( a < b ) && ( c < d ) ) // Compliant
if ( !false ) // Compliant
```
Compliant Solution
```
if ( 1 != 0 && ( c < d ) ) // Compliant, but left operand is always true
if ( ( a < b ) && ( c + d ) != 0 ) // Compliant
if ( u8_a != 0 && ( c + d ) != 0) // Compliant
if ( 0 == 0 ) // Compliant, always true
if ( ptr != NULL ) // Compliant
```

## Standard outputs should not be used directly to log anything

When logging a message there are several important requirements which must be fulfilled:

* The user must be able to easily retrieve the logs
* The format of all logged message must be uniform to allow the user to easily read the log
* Logged data must actually be recorded
* Sensitive data must only be logged securely

If a program directly writes to the standard outputs, there is absolutely no way to comply with those requirements. That's why defining and using a dedicated logger is highly recommended.

Noncompliant Code Example
```
std::cout << "My Message";                // Noncompliant
std::cerr << "My Message";                // Noncompliant
printf("My Message");                     // Noncompliant
```
Compliant Solution
```
Log().Get(logINFO) << "My Message";
```

## Control flow statements should not be nested too deeply

Nested if, for, do, while, switch and try statements is a key ingredient for making what's known as "Spaghetti code".

Such code is hard to read, refactor and therefore maintain.

Noncompliant Code Example

With the default threshold of 3:
```
  if (condition1) {                  // Compliant; depth = 1
    /* ... */
    if (condition2) {                // Compliant; depth = 2
      /* ... */
      for(int i = 0; i < 10; i++) {  // Compliant; depth = 3, not exceeding the limit
        /* ... */
        if (condition4) {            // Noncompliant; depth = 4
          if (condition5) {          // Depth = 5, exceeding the limit, but issues are only reported on depth = 4
            /* ... */
          }
          return;
        }
      }
    }
  }
```
Exceptions

Each use of a macro containing control flow statements is counted as one nesting level, even if the macro contains more than one control flow statement.
```
  #define FOREACH(V,ARR) if(ARR!=nullptr) for(int V=0; V<(sizeof(ARR)/sizeof(ARR[0])); V++)

  if (condition1) {       // Compliant; depth = 1
    if (condition2) {     // Compliant; depth = 2
      FOREACH(i, arr) {     // Compliant; depth = 3 (not 4)
        if (condition3) {   // Noncompliant; depth = 4
          /* ... */
        }
      }
    }
  }
```
Maximum allowed control flow statement nesting depth: Default Value 3

## Identifiers should not be longer than 31 characters

In addition to being difficult to use, too-long variable names can limit code portability. The ISO standard requires that variable, type, function and label names be no more than 31 characters long.

Note that 31 characters is an upper bound, rather than a length recommendation. Shorter names are better, as long as they're still communicative.

Noncompliant Code Example
```
int this_is_a_very_long_identifier_that_definitely_should_be_renamed = 0;
```
Compliant Solution
```
int reasonable_identifier = 0;
```

## Loops with at most one iteration should be refactored

A loop with at most one iteration is equivalent to the use of an if statement to conditionally execute one piece of code. No developer expects to find such a use of a loop statement. If the initial intention of the author was really to conditionally execute one piece of code, an if statement should be used instead.

At worst that was not the initial intention of the author and so the body of the loop should be fixed to use the nested return, break or throw statements in a more appropriate way.

Noncompliant Code Example
```
for (int i = 0; i < 10; i++) { // noncompliant, loop only executes once
  printf("i is %d", i);
  break;
}
...
for (int i = 0; i < 10; i++) { // noncompliant, loop only executes once
  if(i == x) {
    break;
  } else {
    printf("i is %d", i);
    return;
  }
}
```
Compliant Solution
```
for (int i = 0; i < 10; i++) {
  printf("i is %d", i);
}
...
for (int i = 0; i < 10; i++) {
  if(i == x) {
    break;
  } else {
    printf("i is %d", i);
  }
}
```

## Insecure functions should not be used

When using legacy C functions, it's up to the developer to make sure the size of the buffer to be written to is large enough to avoid buffer overflows. Buffer overflows can cause the program to crash at a minimum. At worst, a carefully crafted overflow can cause malicious code to be executed.

This rule reports use of the following insecure functions: strcpy(), strcat(), sprintf(), gets() and getpw().

In such cases, it's better to use an alternate, secure function which allows you to define the maximum number of characters to be written to the buffer:

* strlcpy (BSD library) or strncpy
* strlcat (BSD library) or strncat
* snprintf
* fgets
* getpwuid

(Be aware that strncpy and strncat don't guarantee the string will be null-terminated.)

Noncompliant Code Example
```
sprintf(str, "%s", message);   // Noncompliant
strcpy(str, message); // Noncompliant
```
Compliant Solution
```
snprintf(str, sizeof(str), "%s", message);
strlcpy(str, message, sizeof(str));

strncpy(str, message, sizeof(str) -1); // Leave room for null
str[sizeof(str) - 1] = '\0'; // Make sure the string is null-terminated
```

## Loops should not have more than one "break" or "goto" statement

Restricting the number of exits from a loop is done in the interests of good structured programming. One break or goto statement is acceptable in a loop since this allows, for example, for dual-outcome loops or optimal coding.

Noncompliant Code Example

With the default threshold of 1:
```
for (int i = 0; i < 10; i++) {
  if (...) {
    break;      //  Compliant
  }
  else if (...) {
    break;      //  Non-compliant - second jump from loop
  }
  else {
    ...
  }
}
while (...) {
  if (...) {
    break;      // Compliant
  }
  if (...) {
    break;      // Non-compliant - second jump from loop
  }
}
```
Compliant Solution
```
for (int i = 0; i < 10; i++) {
  if (...) {
    break;      //  Compliant
  }
}
while (...) {
  if (...) {
    break;    // Compliant
  }
}
```

## Cognitive Complexity of functions should not be too high

Cognitive Complexity is a measure of how hard the control flow of a function is to understand. Functions with high Cognitive Complexity will be difficult to maintain.

See
* [Cognitive Complexity](http://redirect.sonarsource.com/doc/cognitive-complexity.html)

## Functions or methods should not have too many lines

A function that grows too large tends to aggregate too many responsibilities.

Such functions inevitably become harder to understand and therefore harder to maintain.

Above a specific threshold, it is strongly advised to refactor into smaller functions which focus on well-defined tasks.

Those smaller functions will not only be easier to understand, but also probably easier to test.

Maximum authorized lines in a function: Default Value 100

## Results of ~ and << operations on operands of underlying types unsigned char and unsigned short should immediately be cast to the operand's underlying type

When ~ and << are applied to small integer types (unsigned char or unsigned short), the operations are preceded by integral promotion, and the result may contain high-order bits which have not been anticipated.

Noncompliant Code Example
```
unsigned char port = 0x5aU;
unsigned char result_8;
unsigned short result_16;
unsigned short mode;
result_8 = (~port) >> 4; // Noncompliant; '~port' is 0xFFA5 on a 16-bit machine but 0xFFFFFFA5 on a 32-bit machine. Result is 0xFA for both, but 0x0A may have been expected.
result_16 = ((port << 4) & mode) >> 6; // Noncompliant; result_16 value depends on the implemented size of an int.
```
Compliant Solution
```
result_8 = ((unsigned char)(~port)) >> 4; // Compliant
result_16 = ((unsigned short)((unsigned short) port << 4) & mode) >> 6; // Compliant
```
See

* MISRA C:2004, 10.5 - If the bitwise operators ~ and << are applied to an operand of underlying type unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand.

* MISRA C++:2008, 5-0-10 - If the bitwise operators ~ and << are applied to an operand with an underlying type of unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand.

## Unions should not be used

The use of unions to access an object in different ways may result in the data being misinterpreted. Therefore, this rule prohibits the use of unions for any purpose.

Noncompliant Code Example
```
union U1 { // Noncompliant
    float j;
    int i;
};
```
See

* MISRA C:2004, 18.4 - Unions shall not be used.
* MISRA C++:2008, 9-5-1 - Unions shall not be used.
* MISRA C:2012, 19.2 - The union keyword should not be used

## Files should not have too many lines of code

A source file that grows too much tends to aggregate too many responsibilities and inevitably becomes harder to understand and therefore to maintain. Above a specific threshold, it is strongly advised to refactor it into smaller pieces of code which focus on well defined tasks. Those smaller files will not only be easier to understand but also probably easier to test.

The maximum authorized lines: Default Value 1000

## Function parameters should not be reassigned

While it is technically correct to assign to parameters from within function bodies, it is better to use temporary variables to store intermediate results.

Allowing parameters to be assigned to also reduces the code readability as developers will not be able to know whether the original parameter or some temporary variable is being accessed without going through the whole function.

Noncompliant Code Example
```
int glob = 0;
void function (int a) {
  a = glob; // Noncompliant
  ...
}
```
Compliant Solution
```
int glob = 0;
void function (int a) {
  int b = glob;
  ...
}
```
See

* MISRA C:2012, 17.8 - A function parameter should not be modified

## Limited dependence should be placed on operator precedence

The rules of operator precedence are complicated and can lead to errors. For this reason, parentheses should be used for clarification in complex statements. However, this does not mean that parentheses should be gratuitously added around every operation.

Parentheses are not needed:

* with a unary operator, except when ! is used as left operand in comparison expressions
* when all the operators in an expression are the same
* when only a single operator is involved
* around the right-hand side of an assignment operator unless the right-hand side itself contains an assignment

Parentheses are needed:

* in the condition of a ternary operator if it uses operators
* when overloaded shift operator << or >> is used in an expression with comparison operators

Noncompliant Code Example
```
x = a + b;
x = a * -1;
x = a + b + c;
x = f ( a + b, c );

x = a == b ? a : a - b; // Noncompliant
x = a + b - c + d; // Noncompliant
x = a * 3 + c + d; // Noncompliant

if (a = f(b,c) == true) { ... } // Noncompliant; == evaluated first
x - b ? a : c; // Noncompliant; "-" evaluated first
s << 5 == 1; // Noncompliant; "<<" evaluated first
```
Compliant Solution
```
x = a + b;
x = a * -1;
x = a + b + c;
x = f ( a + b, c );

x = ( a == b ) ? a : ( a - b );
x = ( a + b ) - ( c + d );
x = ( a * 3 ) + c + d;

if ( (a = f(b,c)) == true) { ... }
(x - b) ? a : c; // Compliant
(s << 5) == 1; // Compliant
```

## Increment (++) and decrement (--) operators should not be used in a method call or mixed with other operators in an expression
The use of increment and decrement operators in method calls or in combination with other arithmetic operators is not recommended, because:

* It can significantly impair the readability of the code.
* It introduces additional side effects into a statement, with the potential for undefined behavior.
* It is safer to use these operators in isolation from any other arithmetic operators.

Noncompliant Code Example
```
u8a = ++u8b + u8c--;
foo = bar++ / 4;
```
Compliant Solution

The following sequence is clearer and therefore safer:
```
++u8b;
u8a = u8b + u8c;
u8c--;
foo = bar / 4;
bar++;
```

## "typedef" should be used for function pointers

Function pointer syntax can be hard on the eyes, particularly when one function is used as a parameter to another. Providing and using a **typedef** instead can make code easier to read, and should be preferred.

Noncompliant Code Example
```
extern void (*signal(int, void(*)(int)))(int);
```
Compliant Solution
```
typedef void (*SignalHandler)(int signum);
extern SignalHandler signal(int signum, SignalHandler handler);
```

## Conditional operators should not be nested

Just because you can do something, doesn't mean you should, and that's the case with nested ternary operations. Nesting ternary operators results in the kind of code that may seem clear as day when you write it, but six months later will leave maintainers (or worse - future you) scratching their heads and cursing.

Instead, err on the side of clarity, and use another line to express the nested operation as a separate statement.

Noncompliant Code Example
```
int max(int p1, int p2, int p3) {
  return p1 > p2 ? (p1 > p3 ? p1 : p3) : (p2 > p3 ? p2 : p3); // Noncompliant
}
```
Compliant Solution
```
int max(int p1, int p2, int p3) {
  if (p1 > p2) {
    return p1 > p3 ? p1 : p3;
  } else {
    return p2 > p3 ? p2 : p3;
  }
}
```
