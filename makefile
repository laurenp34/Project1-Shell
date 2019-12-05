all: main.o shell.o
	gcc -o shell main.o

main.o: main.c
	gcc -c main.c

shell.o: shell.c shell.h
	gcc -c shell.c

run:
	./shell

clean:
	rm *.o
	rm *~
