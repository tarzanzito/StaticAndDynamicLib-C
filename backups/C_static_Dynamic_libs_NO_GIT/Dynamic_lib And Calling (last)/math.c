
#include "math.h"

void printHello(char * msg)
{
    printf("Messag: %s", msg);
}


int add(int a, int b)
{
    return a + b;
}

// int * addPtr(int * a, int * b)
// {
//     *return *a + *b;
// }

//----------------------------------------------------------------------------------
//BUILDING_MATH_DLL is defined in "math.h"

//compile
// # gcc -c -fPIC -o math.o math.c 

//generate Lib (prefix with "lib"
// # gcc -shared -o libmath.so math.o                       ( LINUX )
// # gcc -shared -o libmath.dll math.o -DBUILDING_MATH_DLL  ( WINDOWS e  MSYS2 )


