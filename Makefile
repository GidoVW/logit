all: lib/src/log_it.c
	gcc -c -Wall -Werror -fPIC lib/src/log_it.c -o lib/src/log_it.o
	gcc -shared -o lib/liblog.so lib/src/log_it.o
	rm lib/src/log_it.o
