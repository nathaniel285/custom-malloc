default:
	gcc -c -Wall -Werror -fpic malloc.c -g
	gcc -shared -o libmalloc.so malloc.o -g
	gcc -L"$(PWD)" -Wall -o test main.c -lmalloc -g

clean:
	rm -f *.o *.so test 

run:
	./test
