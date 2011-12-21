#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "font.h"

void prsym(int isym) {
	int iline;
	char *(*symbol)[SYMBOL_HEIGHT] = &alphabet[isym];
	for(iline = 0; iline!=SYMBOL_HEIGHT; ++iline)
		printf("%s\n", (*symbol)[iline]);
}


int main(int argc, char **argv) {
	int isym, iline;
	int offset;

	printf("section .data\n\tglobal alphabet\n\n");
	/* first print the data */
	printf("a");
	for(isym = 0; alphabet[isym][0]; ++isym) {
		for(iline=0; iline!=SYMBOL_HEIGHT; ++iline) {
			printf("\tdb \"%s\",0\n", alphabet[isym][iline]);
		}
	}
	/* then the array of pointers */
	printf("\nalphabet:\n");
	offset = 0;
	for(isym = 0; alphabet[isym][0]; ++isym) {
		printf("\tdd");
		for(iline=0; iline!=SYMBOL_HEIGHT; ++iline) {
			printf(" a+%d,", offset);
			offset += strlen(alphabet[isym][iline])+1;
		}
		printf("\n");
	}
	printf("\tdd 0");

	return 0;
}
