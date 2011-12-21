.PHONY: all clean dist
.SUFFIXES: .c .o .h

all: prsym ascart font2asm

OBJS=font.o
CFLAGS=-g -m32 -O -Wall
LDFLAGS=$(CFLAGS)


%.o: %.asm
	nasm -g -f elf -o $@ $<

%.o: %.c
	gcc $(CFLAGS) -c $<

font.asm:
	./font2asm > font.asm

font2asm: font2asm.o $(OBJS)
	gcc $(LDFLAGS) -o $@ $^

prsym: prsym.o $(OBJS)
	gcc $(LDFLAGS) -o $@ $^

ascart: ascart.o $(OBJS)
	gcc $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o *~

dist:
	(cd ..; zip ascart/ascart.zip ascart/font.c ascart/font.h ascart/prsym.c)
