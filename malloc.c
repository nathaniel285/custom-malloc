#include "malloc.h"


void *malloc(size_t size)
{
	void * ptr = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
        write(STDOUT_FILENO, "allocating \n", 12);
	return ptr;	
}

void free(void * ptr)
{
	return;
}

