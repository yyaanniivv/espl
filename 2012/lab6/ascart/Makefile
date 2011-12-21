.PHONY: all clean dist
.SUFFIXES: .c .o .h

all: prsym ascart

OBJS=font.o
CFLAGS=-g -m32 -O -Wall
LDFLAGS=$(CFLAGS)

%.o: %.c
	gcc $(CFLAGS) -c $<

prsym: prsym.o $(OBJS)
	gcc $(LDFLAGS) -o $@ $^

ascart: ascart.o $(OBJS)
	gcc $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o *~

dist:
	(cd ..; zip ascart/ascart.zip ascart/font.c ascart/font.h ascart/prsym.c)
