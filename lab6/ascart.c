
#include <stdlib.h>
#include <stdio.h>
#include "font.h"

int main(int argc, char **argv) {
int iline;
char *word=argv[1];



for(iline = 0; iline!=SYMBOL_HEIGHT; ++iline) {
char c=word[0];
int z=0;
while (c!=0) {
char *(*symbol)[SYMBOL_HEIGHT] = &alphabet[c-32];
printf("%s", (*symbol)[iline]);
c=word[z];
++z;
}
printf("\n");
}
return 0;
}

