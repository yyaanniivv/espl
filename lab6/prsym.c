 
#include <stdlib.h>
#include <stdio.h>
#include "font.h"


/*
int length(char *s) 
{
char *t = s;
while(*t) ++t;
return t-s;
}
*/

void prsym(int idx) {
  int iline;
  char *(*symbol)[SYMBOL_HEIGHT] = &alphabet[idx];
  for(iline = 0; iline!=SYMBOL_HEIGHT; ++iline)
  {
   // printf("%s\n", (*symbol)[iline]);
    asmwrite(1,(*symbol)[iline] , length((*symbol)[iline]) );
    asmwrite(1,"\n", 1 );
    
  }
}


/*
void innerWhileBody (char* c,char * word,int* z)
{
      prsym((*c)-32);
      (*z)++;
      (*c)=word[(*z)];
}
*/

void outerWhilebody(int *i, int argc, char **argv)
{
    char *word=argv[(*i)];
    int z=0;
    char c =word[0];
    while (c!=0) 
    {
      innerWhileBody ((&c),word,(&z));
     }
    (*i)++;
}

void theOtherMain(int argc, char** argv)
{
  int i=1;
  while (i<argc) 
  {
    outerWhilebody(&i, argc, argv);
  }
}

//int main(int argc, char **argv) {
  
//  theOtherMain(argc,argv);

//  return 0;
//}

