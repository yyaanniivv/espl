all:runprog

runprog: runprog.o
	gcc runprog.o -Wall -o runprog

runprog.o: runprog.c
	gcc -c runprog.c -Wall

clean:
	@rm -f runprog *.o
