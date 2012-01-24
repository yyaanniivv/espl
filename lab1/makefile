prsym: prsym.o font.o
	gcc -Wall -o prsym prsym.o font.o

prsym.o: prsym.c
	gcc -Wall -c prsym.c

ascart: ascart.o font.o
	gcc -Wall -o ascart ascart.o font.o

ascart.o: ascart.c
	gcc -Wall -c ascart.c

font.o: font.c font.h
	gcc -Wall -c font.c

clean:
	rm -f ascart prsym *.o