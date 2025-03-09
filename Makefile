default:
	gcc -c -Wall -Werror -fpic malloc.c
	gcc -shared -o libmalloc.so malloc.o
	gcc -L"$(PWD)" -Wall -o test main.c -lmalloc

clean:
	rm *.o *.so test 
