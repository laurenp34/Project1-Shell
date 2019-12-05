all: main.o shell.o
	gcc -o runshell main.o

main.o: main.c
	gcc -c main.c

shell.o: shell.c shell.h
	gcc -c shell.c

run:
	./runshell

clean:
	rm *.o
	rm *~
