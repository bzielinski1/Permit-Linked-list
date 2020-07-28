permits: permits.o request.o readline.o
	gcc -o permits permits.o request.o readline.o

permits.o: permits.c request.h
	gcc -c permits.c

request.o: request.c request.h readline.h
	gcc -c request.c
	
readline.o: readline.c readline.h
	gcc -c readline.c