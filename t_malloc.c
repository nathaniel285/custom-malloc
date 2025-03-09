#include <stdio.h>

void *t_malloc(size_t size)
{
puts("malloc called in shared library\n");
return NULL;
}
