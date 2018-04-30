lib: obj
	gcc -shared -o lib/liblogit.so src/logit.o
	rm src/logit.o

obj:
	gcc -c -Wall -Werror -fPIC src/logit.c -o src/logit.o
	
