//
// Example of Dynamic Lib C
//
//include guards or  header guards
//Modern compilers offer an alternative to include guards: #pragma once.
// It works similarly to #ifndef and #define, but it’s more concise. Here’s how it would look:
//#pragma once
//
#ifndef MY_DYNAMIC_LIB_H
#define MY_DYNAMIC_LIB_H

// A function adding two integers and returning the result
int SampleAddInt(int a, int b);

// A function doing nothing ;)
void SampleFunction1();

// A function always returning zero
int SampleFunction2(char* text);

//__declspec(dllexport) int test(int magic);  ?!?!??!

#endif // MY_DYNAMIC_LIB_H
