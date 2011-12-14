 
%.o: %.asm
	nasm -g -f elf -o $@ $<

%.o: %.c
	gcc -m32 -g -nostdlib -fno-stack-protector -c -o $@ $<

all:asmart


asmart: asmart.o prsym.o font.o
	ld -melf_i386 -g -o $@ $^

prsym.o: prsym.c asmart.asm
asmart.o: asmart.asm
puts.o: puts.c asmwrite.asm
asmwrite.o: asmwrite.asm

hello.o: hello.c
	gcc -c -o prsym.o prsym.c
	gcc -c -o font.o font.c

clean:
	@rm -f *.o asmart
