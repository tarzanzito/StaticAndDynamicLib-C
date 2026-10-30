
#include "math.h"

void printHello(const char * msg)
{
    printf("Messag: %s", msg);
}


int add(int a, int b)
{
    printf("Func:add\n");
    
    return a + b;
}

void c_function_ref(int *num)
{
    printf("Func:c_function_ref\n");
    printf("'Rreceive by reference: %d\n", *num);

    *num = *num + 10; // to Change value
}

// int * addPtr(int * a, int * b)
// {
//     *return *a + *b;
// }

//----------------------------------------------------------------------------------
//BUILD_DLL_EXPORT is defined in "math.h"

//compile
// # gcc -c -fPIC -o math.o math.c 

//generate Lib (prefix with "lib"
// # gcc -shared -o libmath.so math.o                       ( LINUX )
// # gcc -shared -o libmath.dll math.o -DBUILD_DLL_EXPORT  ( WINDOWS e  MSYS2 )
//                                     -D flag !!!


