.PHONY: all clean

all: bcmp

%.o: %.asm
	nasm -g -f elf -o $@ $<

bcmp: bcmp.o asmwrite.o
	gcc -m32 -o $@ $^

bcmp.o: bcmp.c
	gcc -m32 -c bcmp.c
asmwrite.o: asmwrite.asm

#	gcc -m32 -c atod.c
#	gcc -c -m32 -S -masm=intel atod.c

clean:
	@rm -f *.o bcmp
