#include <elf.h> 
#include <stdio.h>
#include<string.h>
#include <unistd.h>

void main (int argc, char** argv) {
    Elf32_Ehdr header;
    FILE *elf=fopen(argv[1], "r");
    if (!(elf)) {
        printf ("failed to open file %s\n",argv[1]);
        return;
    }
    fread( &header, sizeof(header),1,elf);
    if (header.e_ident[4]!=1 )
      printf("supporting Elf32 files only. Sorry!. EI_CLASS = %i \n", header.e_ident[4] );
    else 
    {
      printheader(header);
      
    }
}
void printheader();
