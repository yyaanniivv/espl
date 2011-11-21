

all: bcmp

bcmp: bcmp.o
	gcc  bcmp.o -o bcmp

bcmp.o: bcmp.c
	gcc -c bcmp.c

.PHONY: clean
clean:
	@rm  -f *.o bfix