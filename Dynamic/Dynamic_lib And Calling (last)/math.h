//#include pragma once
//or
#ifndef MATHLIB_H
  #define MATHLIB_H 

#ifdef BUILD_DLL_EXPORT
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT
//    #define DLL_EXPORT __declspec(dllimport)
#endif

#include <stdio.h>

//const int x (tipo de dados primitivo) não vale a pena porque o parametro é passado por copia.
//            nestes casos só garante que nao pode alterar o valor dentro da função.
//coonst int * x (tipo de dados primitivo) vale a pena porque o parametro é passado por referencia,
//               economizando memoria e tempo de processamento.

DLL_EXPORT void printHello(const char * msg);
DLL_EXPORT int add(int a, int b);
DLL_EXPORT void c_function_ref(int *num); 

//int * addPtr(int * a, int * b); ?!?!?!

#endif


//Nota no windows as function dentro de uma biblioteca não são publicas, ao contrario do linux, então é necessário declarar a função como exportável,
//para funcionar no windows temmos exportar as functions que queremos ver de fora,
//  para isso usamos o __declspec(dllexport) antes da function.
//example:
// __declspec(dllexport) int add(int a, int b);
//
//para passar a variavel para o compilador que estamos construindo a biblioteca, usamos a flag -DBUILDING_MATH_DLL