//#include pragma once
//or
#ifndef MATHLIB_H

#ifdef BUILDING_MATH_DLL
    #define MATH_API __declspec(dllexport)
#else
    #define MATH_API
//    #define MATH_API __declspec(dllimport)
#endif

#include <stdio.h>

MATH_API void printHello(char * msg);
MATH_API int add(int a, int b);

//int * addPtr(int * a, int * b);

#endif


//Nota no windows as function dentro de uma biblioteca não são publicas, ao contrario do linux, então é necessário declarar a função como exportável,
//para funcionar no windows temmos exportar as functions que queremos ver de fora,
//  para isso usamos o __declspec(dllexport) antes da function.
//example:
// __declspec(dllexport) int add(int a, int b);
//
//para passar a variavel para o compilador que estamos construindo a biblioteca, usamos a flag -DBUILDING_MATH_DLL