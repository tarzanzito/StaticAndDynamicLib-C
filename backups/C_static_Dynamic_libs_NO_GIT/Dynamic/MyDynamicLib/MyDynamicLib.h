//
// Example of Dynamic Lib C
//
//include guards or  header guards
//Modern compilers offer an alternative to include guards: #pragma once.
// It works similarly to #ifndef and #define, but it’s more concise. Here’s how it would look:
//#pragma once
//
//IN Windows is need to export function
//__declspec(dllexport) int test(int magic);  ?!?!??!

#ifndef MY_DYNAMIC_LIB_H
#define MY_DYNAMIC_LIB_H

#ifdef BUILDING_MATH_DLL
    #define MATH_API __declspec(dllexport)
#else
    #define MATH_API
//    #define MATH_API __declspec(dllimport)
#endif

// A function adding two integers and returning the result
MATH_API int SampleAddInt(int a, int b);

// A function doing nothing ;)
MATH_API void SampleFunction1();

// A function always returning zero
MATH_API int SampleFunction2(char* text);


#endif // MY_DYNAMIC_LIB_H
