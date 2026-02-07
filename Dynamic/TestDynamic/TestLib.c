
#include <stdio.h>
#include "../MyDynamicLib/MyDynamicLib.h"

int main(int argc, char *argv[])
{
    printf("Hello world!\n");

    SampleFunction1();

    int r1 = SampleAddInt(10, 20);
	printf("SampleAddInt return=%d\n", r1);

    char* text = "Passing info...";
	int r2 = SampleFunction2(text);
	printf("SampleFunction2 return=%d\n", r2);

    return 0;
}
