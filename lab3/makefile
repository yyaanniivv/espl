

all: bfix

bfix: bfix.o diff.o
	gcc  -o bfix bfix.o diff.o 

bfix.o: bfix.c
	gcc -c -Wall bfix.c

diff.o: diff.c
	gcc -c -Wall diff.c

.PHONY: clean
clean:
	@rm  -f *.o bfix