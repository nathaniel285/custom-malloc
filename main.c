#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mcheck.h>
int main()
{
	int allocate_amount = 10;
	int* ptr = malloc(allocate_amount * sizeof(int));
	for(int i =0; i < allocate_amount; i++)
	{
		ptr[i] = i;
printf("ptr[%d] is %d\n", i, ptr[i]);
	}

	return 0;
}
