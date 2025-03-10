#include "malloc.h"
void *malloc(size_t size)
{
	write(STDOUT_FILENO, "HI\n", 4);
	return NULL;
}

void free(void * ptr)
{
	return;
}

void * calloc(size_t n, size_t size)
{
	return NULL;
}

void *realloc(void *ptr, size_t size)
{

	return NULL;
}
