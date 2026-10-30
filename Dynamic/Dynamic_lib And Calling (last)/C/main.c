#include "math.h"
#include "other.h"

int main() {

    printf("Hello world\n");

    char* msg = "Hello from main\n";
    int a;
    int b;
    int x;

    printHello(msg); //math.h
    a = 20;
    b = 10;
    x = add(a, b); //math.h
    printf("Add: %d\n", x);

    c_function_ref(&a); //math.h
    printf("c_function_ref: %d\n", a);
 
    ///////////////////////////

    //void printmessage(const char* ptrSource, char* ptrReturn, size_t lengthSource,  size_t lengthReturn)
    //void printmessageTemp(const char* ptrSource, char* ptrReturn, size_t lengthSource,  size_t lengthReturn)

    x = subtract(a, b); //other.h
    printf("Subtract: %d\n", x);

    return 0;
}


//Compile
// # gcc -c -o main.o main.c

// -c  = compile only to object

 //Creating executable

// #  gcc main.o -o program -L. -lmath -lother              se windows e SYS2 precisa ser extensao .dll
// #  gcc main.c -o program -L./libs --lmath -lother

//verify that you did it and have the right functions as dynamic symbols you can use:
 // # nm -D libmarh.so