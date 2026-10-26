//
// Example of Static Lib C
//
// Project setting //
//-------------------
//Project properties
//right click on project -> properties -> Build targets -> Type -> Console Application
//right click on project -> Build options -> Linker Settings -> Link Libraries -> Add -> MyStaticLib.a
//-------------------
//
// Compile //
//-----------
//MyStaticLib
// debud mode
//gcc.exe -Wall -g  -c E:\_MEGA_DRIVE\_C\C_static_Dynamic_libs\MyStaticLib\MyStaticLib.c -o obj\Debug\MyStaticLib.o
//cmd /c if exist bin\Debug\libMyStaticLib.a del bin\Debug\libMyStaticLib.a
//ar.exe -r -s bin\Debug\libMyStaticLib.a obj\Debug\MyStaticLib.o
//release mode
//gcc.exe -O2 -Wall  -c E:\_MEGA_DRIVE\_C\C_static_Dynamic_libs\MyStaticLib\MyStaticLib.c -o obj\Release\MyStaticLib.o
//cmd /c if exist bin\Release\libMyStaticLib.a del bin\Release\libMyStaticLib.a
//ar.exe -r -s bin\Release\libMyStaticLib.a obj\Release\MyStaticLib.o


//TestStatic
//
//gcc.exe -Wall -g  -c E:\_MEGA_DRIVE\_C\C_static_Dynamic_libs\TesteStatic\main.c -o obj\Debug\main.o
//gcc.exe  -o bin\Debug\TesteStatic.exe obj\Debug\main.o   ..\MyStaticLib\bin\Debug\MyStaticLib.a

// Info //
//--------
//ar.exe -r -c -s
//or
//ar.exe rcs
//-r - replace existing pr insert new file<s> into the archive
//-c - do not warn if the library had to be created
//-s - do not build a symbol table
//
//---------------------------------------------

//youtube
//https://www.geeksforgeeks.org/c/how-to-create-a-static-library-in-c/
//


#include <stdio.h>
#include <stdlib.h>
#include "..\MyStaticLib\MyStaticLib.h"

int main()
{
    printf("Hello world!\n");

    int res = SampleAddInt(2, 3);
    printf("result: %d\n", res);

    SampleFunction1();

    char text[] = "Paul";
    int res2 = SampleFunction2(text);
    printf("result: %d\n", res2);

    return 0;
}
