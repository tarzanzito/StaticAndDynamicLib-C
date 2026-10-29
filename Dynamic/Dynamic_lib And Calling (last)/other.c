
#include "other.h"

// BUILDING_MATH_DLL int subtract(int a, int b);
// char * printmessage(char * msg)
// {
//      snprintf(buffer, 64, "Hello, %s!", name);
//     char * msg = "Message " + msg;
//     printf("Message %s", msg);
// }


void printmessageTemp(const char* ptrSource,  size_t lengthSource, char* ptrReturn, size_t lengthReturn)
{
    printf("Func:printmessageTemp\n");

    const char* sufix = " print message";
    
    size_t lengthSufix = strlen(sufix);
    size_t lengthTotal = lengthSource + lengthSufix;

    // Validate: lengthReturn vs lengthTotal tem espaço para o texto + '\0'
    if (lengthReturn < (lengthTotal + 1)) {
        printf("Erro: O buffer de destino é demasiado pequeno!\n");
        return;
    }

    // memory allocation: lengthTotal + 1 byte for '\0'
    char* ptrTemp = (char*)malloc((lengthTotal + 1) * sizeof(char));
    if (ptrTemp == NULL) return;

    // Secure copy
    memcpy(ptrTemp, ptrSource, lengthSource);
    ptrTemp[lengthSource] = '\0'; // Garante o \0 for o strcat
   
    // Join sufix (strcat set '\0' at end)
    strcat(ptrTemp, sufix);

    // final copy
    memcpy(ptrReturn, ptrTemp, lengthTotal);
    ptrReturn[lengthTotal] = '\0'; // set '\0' at the end

    // print test
    printf("Message: %s\n", ptrTemp);

    // remove for no MEMORY LEAK
    free(ptrTemp);
}

void printmessage(const char* ptrSource, size_t lengthSource, char* ptrReturn, size_t lengthReturn)
{
    printf("Func:printmessage\n");

    const char* sufix = " print message";
    size_t lengthSufix = strlen(sufix);
    size_t lengthTotal = lengthSource + lengthSufix;

   // Validate: lengthReturn vs lengthTotal tem espaço para o texto + '\0'
    if (lengthReturn < (lengthTotal + 1)) {
        printf("Erro: O buffer de destino é demasiado pequeno!\n");
        return;
    }

    // 2. copy direct from soure to return
    memcpy(ptrReturn, ptrSource, lengthSource);
    ptrReturn[lengthSource] = '\0'; // set '\0' at the end
   
    // Append
    strcat(ptrReturn, sufix);

    // 5. Imprime o resultado final direto do destino
    printf("Message: %s\n", ptrReturn);
}

void printmessage_pro(char* destino, size_t tam_max, const char* s1, const char* s2) {
    size_t len1 = strnlen(s1, tam_max);
    size_t len2 = strnlen(s2, tam_max);

    // Validação estrita de segurança antes de tocar na memória
    if (len1 + len2 + 1 > tam_max) {
        // Trata o erro de tamanho insuficiente (ex: retorna código de erro)
        return; 
    }

    // Copia os blocos de memória diretamente (muito mais rápido que strcat)
    memcpy(destino, s1, len1);
    memcpy(destino + len1, s2, len2);
    
    // Adiciona manualmente o caractere nulo no local exato
    destino[len1 + len2] = '\0';
}


int subtract(int a, int b)
{
    printf("Func:subtract\n");
    return a - b;
}

//----------------------------------------------------------------------------------
//BUILD_DLL_EXPORT is defined in "other.h"

//compile
// # gcc -c -fPIC -o other.o other.c 

//generate Lib (prefix with "lib"
// # gcc -shared -o libother.so other.o                       ( LINUX )
// # gcc -shared -o libother.dll other.o -DBUILD_DLL_EXPORT  ( WINDOWS e  MSYS2 )
//                                       -D flag !!!

