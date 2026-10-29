//#include pragma once
//or
#ifndef OTHER_H
    #define OTHER_H

#ifdef BUILD_DLL_EXPORT
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT
//    #define DLL_EXPORT __declspec(dllimport)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//perigoso, não é seguro, mas funciona para teste, pode gerar memory leak
//BUILD_DLL_EXPORT const char * printmessage(char * msg); 

//metodo seguro, que não gera memory leak, mas precisa de um buffer para receber a string
DLL_EXPORT void printmessage(const char* ptrSource, char* ptrReturn, size_t lengthSource,  size_t lengthReturn);
DLL_EXPORT void printmessageTemp(const char* ptrSource, char* ptrReturn, size_t lengthSource,  size_t lengthReturn);

DLL_EXPORT int subtract(int a, int b);

#endif


//Nota no windows as function dentro de uma biblioteca não são publicas, ao contrario do linux, então é necessário declarar a função como exportável,
//para funcionar no windows temmos exportar as functions que queremos ver de fora,
//  para isso usamos o __declspec(dllexport) antes da function.
//example:
// __declspec(dllexport) int add(int a, int b);
//
//para passar a variavel para o compilador que estamos construindo a biblioteca, usamos a flag -DBUILDING_MATH_DLL