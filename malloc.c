#include <stdio.h>

void *malloc(size_t size)
{
puts("malloc called in shared library\n");
return NULL;
}
