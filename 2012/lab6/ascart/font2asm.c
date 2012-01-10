#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "font.h"

void shapes() {
	int isym, iline;

	printf("; letter shapes\n");
	printf("a");
	for(isym = 0; alphabet[isym][0]; ++isym) {
		for(iline=0; iline!=SYMBOL_HEIGHT; ++iline) {
			printf("\tdb \"%s\",0\n", alphabet[isym][iline]);
		}
	}
}

void pointers() {
	int isym, iline;
	int offset;

	printf(";; automatically generated self-bootstrapped font\n\n");

	printf("; the font itself, pointers to each line of each letter\n");
	printf("alphabet:\n");
	offset = 0;
	for(isym = 0; alphabet[isym][0]; ++isym) {
		printf("\tdd");
		for(iline=0; iline!=SYMBOL_HEIGHT; ++iline) {
			printf(" a+%d,", offset);
			offset += strlen(alphabet[isym][iline])+1; /* +1 is for 0 */
		}
		printf("\n");
	}
	printf("\tdd 0"); /* NULL pointer at the end */
}


int main(int argc, char **argv) {
	printf("section .data\n\tglobal alphabet\n\n");
	shapes();
	printf("\n");
	pointers();

	return 0;
}
