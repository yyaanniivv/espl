 
%.o: %.asm
	nasm -g -f elf -o $@ $<

%.o: %.c
	gcc -m32 -g -nostdlib -fno-stack-protector -c -o $@ $<

.PHONY: clean all

all: ahalan

ahalan: start.o main.o ahalan.o asmwrite.o puts.o
	ld -melf_i386 -g -o $@ $^


asmwrite.o: asmwrite.asm
ahalan.o: ahalan.asm
start.o: start.asm
puts.o: puts.c asmwrite.asm
#	gcc -m32 -g -nostdlib -fno-stack-protector -c -o $@ $<
main.o: main.c

clean:
	@rm -f *.o ahalan