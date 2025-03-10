#include "malloc.h"


struct memory_node *head = NULL;

// this is the exact memcpy from gcc
void * malloc_memcpy(void *dest, const void *src, size_t len)
{
	char *d = dest;
	const char *s = src;
	while (len--)
		*d++ = *s++;
	return dest;
}

void *malloc(size_t size)
{
	void * ptr = mmap(NULL, size + sizeof(struct memory_node), PROT_WRITE | PROT_READ, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	struct memory_node tmp;
	// including size of the memory node
	tmp.size = size + sizeof(struct memory_node);
	tmp.next_node = head;
	head = ptr;
	malloc_memcpy(ptr, &tmp, sizeof(struct memory_node));
	return ptr + sizeof(struct memory_node);	
}

void free(void * ptr)
{
	void * real_ptr = ptr - sizeof(struct memory_node);
	struct memory_node tmp;
	malloc_memcpy(&tmp, real_ptr, sizeof(struct memory_node));
	head = tmp.next_node;
	munmap(real_ptr, tmp.size);

//	write(STDOUT_FILENO, "HERE\n", 6);
	return;
}

