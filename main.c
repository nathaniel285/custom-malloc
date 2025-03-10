#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mcheck.h>


int test_0()
{
	int allocate_amount = 10;
	int* ptr = malloc(allocate_amount * sizeof(int));
	int* ptr2 = malloc(allocate_amount * sizeof(int));
	for(int i =0; i < allocate_amount; i++)
	{
		ptr[i] = i;
		ptr2[i] = i;
		printf("ptr[%d] is %d\n", i, ptr[i]);
	}
	free(ptr2);
	free(ptr);
return 0;
}


int main()
{
        test_0();
	return 0;
}
