#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mcheck.h>
int main()
{


	mtrace();
	puts("testing shared library of malloc\n");
for(int i =0; i < 25; i++)
{

	void* sbreak = sbrk(0);
	printf("sbreak is %p\n", sbreak);
	int * ptr = malloc(8164);
	void* sbreak2 = sbrk(0);
	printf("sbreak is now %p\n", sbreak2);
}
	if(ptr == NULL)
	{
		printf("ptr is null, it worked\n");
	} else 
	{
		printf("ptr not null, did not work\n");
		ptr[0] = 1;
	}
	return 0;
}
