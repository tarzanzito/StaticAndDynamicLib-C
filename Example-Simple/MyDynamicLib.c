//
// Example of Static Lib C
//
// Project settings //
//--------------------
//Project properties
//right click on project -> properties -> Build targets -> Type -> Static library
//--------------------
//
//https://www.geeksforgeeks.org/c/how-to-create-a-static-library-in-c/
//
// Must terminate with *Lib
//
//Compile

//gcc -c -fPIC MyDynamicLib.c -o obj\Debug\MyDynamicLib.o   ?!?!??! -fPIC

//gcc.exe -Wall -g  -c MyDynamicLib.c -o obj\Debug\MyDynamicLib.o
//gcc.exe -shared -Wl,--output-def=bin\Debug\libMyDynamicLib.def  -Wl,--dll  obj\Debug\MyDynamicLib.o  -o bin\Debug\MyDynamicLib.dll


//---------------------------------------------

#include <stdio.h>
#include <string.h>
#include "MyDynamicLib.h"

// A function adding two integers and returning the result
int SampleAddInt(int a, int b)
{
    int ret = a + b;
    printf("Hello, SampleAddInt(%d, %d) is %d\n", a, b, ret);

    return ret;
}

// A function doing nothing ;)
void SampleFunction1()
{
    // insert code here
	printf("Hello, SampleFunction1!\n");
}

// A function always returning zero
int SampleFunction2(char* text)
{
    int ret = strlen(text);
    // insert code here
	printf("Hello, %d SampleFunction2('%s')\n", ret, text);

    return ret;
}
