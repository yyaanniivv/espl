.PHONY: all clean

all: calc

%.o: %.asm
	nasm -g -f elf -o $@ $<

calc: calc.o atod.o
	gcc -m32 -o $@ $^

calc.o: calc.c
	gcc -m32 -c calc.c
atod.o: atod.c
	gcc -m32 -c atod.c
#	gcc -c -m32 -S -masm=intel atod.c

clean:
	@rm -f *.o calc
