.PHONY: clean all

%.o: %.asm
	nasm -g -f elf -o $@ $<

all: main

main: main.o hsvmhr.o
	gcc  -m32 -o main hsvmhr.o main.o

main.o:
	gcc -m32 -c main.c

clean:
	@rm  -f *.o main
