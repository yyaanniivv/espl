

all: bcmp

bcmp: bcmp.o diff.o
	gcc  bcmp.o -o bcmp

bcmp.o: bcmp.c
	gcc -c -Wall bcmp.c

diff.o: diff.c diff.h
	gcc -c -Wall diff.c
clean:
	rm *.o