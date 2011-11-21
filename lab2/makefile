
#objects= canalyze.o namelist.o
#canalyze: $(objects)
#	gcc -o canalyze $(objects)

#canalyze:  canalyze.o namelist.o namelist.h


all:canalyze

#dependant of ... 
canalyze:  canalyze.o namelist.o
#rules / commands / linker
	gcc -o canalyze canalyze.o namelist.o 

canalyze.o: canalyze.c
#rules / commands / compile
	gcc -c -Wall canalyze.c

namelist.o: namelist.c namelist.h
	gcc -c -Wall namelist.c


#clean has no prerequests!
# rm *.o canalyze
# - to ignore errors
# @ to not print in terminal
.PHONY: clean
clean: 
	@rm -f canalyze.o  namelist.o  canalyze
