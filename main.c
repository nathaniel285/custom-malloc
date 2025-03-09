#include <stdio.h>
#include <stdlib.h>

int main()
{
	puts("testing shared library of malloc\n");
	int * ptr = malloc(5);
	if(ptr == NULL)
	{
		printf("ptr is null, it worked\n");
	} else 
	{
		printf("ptr not null, did not work\n");
	}
	return 0;
}
