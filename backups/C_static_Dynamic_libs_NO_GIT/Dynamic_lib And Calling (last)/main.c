#include "math.h"

int main() {

    printf("Hello world\n");

    printHello("Hello printHello\n");

    //int x = 10, y = 20;
    // int *res = add(&x, &y);
    
    // if (res != NULL) {
    //     printf("Soma: %d\n", *res);
    //     free(res); // IMPORTANTE: Libera a memória alocada
    // }

    int x = add(10, 20);
    
    printf("Soma: %d\n", x);

    return 0;
}


//Compile
// # gcc -c -o main.o main.c

// -c  = compile only to object

 //Creating executable

// #  gcc main.o -o program -L. -lmath              se windows e SYS2 precisa ser extensao .dll
// #  gcc main.c -o program -L./libs -lmatematica

//verify that you did it and have the right functions as dynamic symbols you can use:
 // # nm -D libmarh.so