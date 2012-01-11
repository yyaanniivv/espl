# nasm
# gcc -m32
elfheader:elfheader.o
	gcc -o elfheader elfheader.o

elfheader.o:elfheader.c
	gcc -c elfheader.c

clean:
	rm -f elfheader *.o