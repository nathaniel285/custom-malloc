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
	tmp.prev_node = NULL;
	if(head != NULL)
	{

		head->prev_node = ptr;
	}
	head = ptr;

	malloc_memcpy(ptr, &tmp, sizeof(struct memory_node));
	return ptr + sizeof(struct memory_node);	
}

void free(void * ptr)
{
	void * real_ptr = ptr - sizeof(struct memory_node);
	struct memory_node tmp;
	malloc_memcpy(&tmp, real_ptr, sizeof(struct memory_node));
	if(tmp.next_node != NULL)
	{
		tmp.next_node->prev_node = tmp.prev_node;
	}
	if(tmp.prev_node !=NULL)
	{

		tmp.prev_node->next_node = tmp.next_node;
	}
	if(real_ptr == head)
	{
		head = tmp.next_node;
	}
	munmap(real_ptr, tmp.size);
write(STDOUT_FILENO, "hi\n", 3);

	return;
}

