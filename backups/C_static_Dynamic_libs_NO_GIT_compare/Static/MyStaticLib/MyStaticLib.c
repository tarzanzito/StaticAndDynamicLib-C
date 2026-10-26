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
//gcc -Wall -g -c MyStaticLib.c -o MyStaticLib.o
//-c - Compile and assemble, but do not link
//-g - with debug

//complete
//---------
//mkdir  E:\_MEGA_DRIVE\_C\C_static_Dynamic_libs\MyStaticLib\obj
//mkdir  E:\_MEGA_DRIVE\_C\C_static_Dynamic_libs\MyStaticLib\bin
//
//compile
//gcc.exe -Wall -g -c E:\_MEGA_DRIVE\_C\C_static_Dynamic_libs\MyStaticLib\MyStaticLib.c -o obj\MyStaticLib.o
//
//cmd /c if exist bin\Debug\libMyStaticLib.a del bin\libMyStaticLib.a
//
//archive
//ar.exe -r -c -s bin\libMyStaticLib.a obj\Debug\MyStaticLib.o
//or
//ar.exe rcs bin\libMyStaticLib.a obj\Debug\MyStaticLib.o
//-r - replace existing pr insert new file<s> into the archive
//-c - do not warn if the library had to be created
//-s - do not build a symbol table
//
//---------------------------------------------

#include <stdio.h>
#include <string.h>
#include "MyStaticLib.h"

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
