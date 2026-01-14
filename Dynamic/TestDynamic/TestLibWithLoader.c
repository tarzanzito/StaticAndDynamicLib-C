
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
//#include "../MyDynamicLib/MyDynamicLib.h"

int main(int argc, char *argv[])
{
    printf("Hello world!\n");
    int res = call_with_loader("libMyDynamicLib");

    return res;
}

//load library ar runtime
//No need link library
int call_with_loader(char* file_name)
{

    void* libHandle = dlopen(file_name, RTLD_LAZY);
	if (libHandle == NULL)
	{
		printf("dlopen error.\n");
		return 1;
	}
	
	//signature of function to call.

	//int SampleAddInt(int a, int b);
    int (*pSampleAddInt)(int, int);

	//void SampleFunction1();
    void (*pSampleFunction1)();

	//int SampleFunction2(char* text);
	int (*pSampleFunction2)(char*);
	
	pSampleAddInt = dlsym(libHandle, "SampleAddInt");
	pSampleFunction1 = dlsym(libHandle, "pSampleFunction1");
	pSampleFunction2 = dlsym(libHandle, "pSampleFunction2");
	
	if(pSampleAddInt == NULL)
	{
		printf("pSampleAddInt error.\n");
		return 1;
	}
	if(pSampleFunction1 == NULL)
	{
		printf("pSampleFunction1 error.\n");
		return 1;
	}
	if(pSampleFunction2 == NULL)
	{
		printf("pSampleFunction2 error.\n");
		return 1;
	}
	
	int res1 = pSampleAddInt(10, 20);
	pSampleFunction1();
	int res3 = pSampleFunction1("Example");
	
	dlclose(libHandle);
}
