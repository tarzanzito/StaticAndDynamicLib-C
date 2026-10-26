
#include <stdio.h>
#include "library.h"


int main(void)
{
	printf("Hello from 'main'\n");
	
	int res1 = add(4, 5);
	int res2 = sub(10, 7);
	printf("%d + %d = %d\n", 4, 5,res1);
	printf("%d - %d = %d\n", 10, 7, res2);
	
	return 0;
}


