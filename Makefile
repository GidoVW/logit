lib: obj
	ar rcs lib/liblogit.a src/logit.o
	rm src/logit.o

obj:
	gcc -c -Wall -Werror -fPIC src/logit.c -o src/logit.o
	
