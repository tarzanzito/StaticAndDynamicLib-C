
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <unistd.h>
//#include "../MyDynamicLib/MyDynamicLib.h"

void callSampleFunction1(void* libHandle);
void callSampleAddInt(void* libHandle);
void callSampleFunction2(void* libHandle);


int main(int argc, char *argv[])
{
    char* fileName = "libMyDynamicLib.dll";  //OK
    //char* fileName = "libMyDynamicLib";    //OK

    printf("Hello world! 6 \n");

    ///validate file exists
    if (access(fileName, F_OK) != 0)
    {
        printf("file not exists!\n");
        return 1;
    }

    //open library file
    void* libHandle = dlopen(fileName, RTLD_LAZY);
	if (libHandle == NULL)
	{
		printf("dlopen error.\n");
		return 1;
	}

    callSampleFunction1(libHandle);
    callSampleAddInt(libHandle);
    callSampleFunction2(libHandle);

    dlclose(libHandle);

    return 0;
}


void callSampleFunction1(void* libHandle)
{
    //define pointer for function (signature)

    //void SampleFunction1();
    void (*pSampleFunction1)();

    //Associate function with signature
    pSampleFunction1 = dlsym(libHandle, "SampleFunction1");

    if (pSampleFunction1 == NULL)
    {
        printf("Call pSampleFunction1 error.\n");
        return;
    }

    //Call library function
    pSampleFunction1();
}

void callSampleAddInt(void* libHandle)
{
	//int SampleAddInt(int a, int b);
    int (*pSampleAddInt)(int, int);

	//Associate function
	pSampleAddInt = dlsym(libHandle, "SampleAddInt");
	if (pSampleAddInt == NULL)
	{
		printf("Call pSampleAddInt error.\n");
		return;
	}

	//Call library function
	int r = pSampleAddInt(10, 20);

	printf("pSampleAddInt return=%d\n", r);
}

void callSampleFunction2(void* libHandle)
{
	//int SampleFunction2(char* text)
    int (*pSampleFunction2)(char* text);

    //Associate function with signature
    pSampleFunction2 = dlsym(libHandle, "SampleFunction2");

    char* text = "Passing info...";
	int r2 = pSampleFunction2(text);

	printf("pSampleFunction2 return=%d\n", r2);
}
