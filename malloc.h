#ifndef malloc_h__
#define malloc_h__
#include <stddef.h>
#include <unistd.h>
#include <sys/mman.h>

struct memory_node
{
size_t size;
struct memory_node * next_node;
};

extern struct memory_node * head;
extern void *malloc(size_t size);
extern void free(void *);
#endif
