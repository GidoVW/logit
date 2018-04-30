lib: obj
	gcc -shared -o lib/liblog.so src/log_it.o
	rm src/log_it.o

obj:
	gcc -c -Wall -Werror -fPIC src/log_it.c -o src/log_it.o
	
