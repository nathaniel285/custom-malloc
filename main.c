#include <stdio.h>
#include "t_malloc.h"

int main()
{
puts("testing shared library of malloc\n");
	int * ptr = t_malloc(5);
	return 0;
}
