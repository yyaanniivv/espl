#include <elf.h> 
#include <stdio.h>
#include<string.h>
#include <unistd.h>

void main (int argc, char** argv) {
    Elf32_Ehdr header;
    char s=0, S=1;
//opt
    
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
    int offset=header.e_shoff;
    int shstrndx = header.e_shstrndx;
    int shentsize = header.e_shentsize;
    
    printf("Section offset: %d \nSection Header Str index: %d \nSection Header Ent Size: %d \nfseek names at: %d",header.e_shoff, shstrndx, shentsize, (offset+shstrndx*shentsize));
    
    char buf[1000];
    //----set file pointer to STRNDX
    fseek(elf,offset+shstrndx*shentsize,0);  //SEEK_SET
    Elf32_Shdr shstr;
    fread(&shstr, sizeof(shstr), 1, elf);
    //-----
    fseek(elf, shstr.sh_offset, 0);
    fread(buf, shstr.sh_size, 1, elf);
    printf("%s \n",buf);

    //fwrite(buf,1,100,stdout);
    //printf("names: %s\n",buf+27);
    
    
      /*     if (s) {
	Elf32_Sym symbolTable;
	int offSymbol=header.e_shoff;  //!?!?!?!?
	fseek(elf,offSymbol,SEEK_SET);
	fread(&symbolTable,sizeof(symbolTable),1,elf);
	
	
      } //symbols  Elf32_Sym;
      */
      if (S) {
	Elf32_Shdr sectionTable;
	int offSection=header.e_shoff;
	fseek(elf,offSection,SEEK_SET);
	fread(&sectionTable,sizeof(sectionTable),1,elf);
	//printf("sectiontable sizeof:  %lu \n", sizeof(sectionTable));
	printf("SECTION HEADERS: \n  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al \n");
	int i=0;
	//sectionTable+=1;
	while( i<24 )
	{
	  printf("  [%i] %s              %d           Addr     Off    Size   ES Flg Lk Inf Al \n"
	  ,i, buf+sectionTable.sh_name, sectionTable.sh_type);
	  fread(&sectionTable,sizeof(sectionTable),1,elf);
	  i++;
	 }
	 
	
      } //sections    Elf32_Shdr;

    }
    fclose(elf);
}

