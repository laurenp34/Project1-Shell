all: shell.o main.o
	gcc -o runshell shell.o main.o

shell.o: shell.c shell.h
	gcc -c shell.c

main.o: main.c shell.h
	gcc -c main.c

run:
	./runshell

clean:
	rm *.o
	rm *~
