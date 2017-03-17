all: bisection

bisection: bisection.o
	gcc -o bisection bisection.o -lm

bisection.o: bisection.c
	gcc -ansi -pedantic-errors -Wall -c bisection.c

clean:
	rm -f *.o
	rm -f bisection
	clear
