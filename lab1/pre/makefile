all:invert

invert: invert.o
	gcc -o invert -Wall invert.o

invert.o: invert.c
	gcc -c -Wall invert.c 

clean:
	rm -f *.o invert

.PHONY: all clean