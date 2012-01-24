#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "font.h"
void printword(char* word);

void prsym(int idx) {
  int iline;
  char *(*symbol)[SYMBOL_HEIGHT] = &alphabet[idx];
  for(iline = 0; iline!=SYMBOL_HEIGHT; ++iline)
  printf("%s\n", (*symbol)[iline]);
}


int main(int argc, char **argv) {
  switch(argc) {
  case 1: {
    int idx;
    for(idx = 0;; ++idx) {
      if(!alphabet[idx][0])
	break;
      prsym(idx);
      }
    }
    break;
  /*
   * case 2:
    printf("here case 2, argv[1] = %s\n", argv[1]);
    
    
    prsym(atoi(argv[1]));//prsym('a');
    break;
    */
  default:
    //printf("print all available symbols or a symbol by the given index in ASCII art.\n\nusage: %s [symbol-index]\n", argv[0]);
    {
      int i;
      printf("argc is %d,\n", argc);
      for(i=0;i<argc ; i++)
      {
	printword(argv[i]);
      }
    }
    return 1;
  }
return 0;
}

void printword(char* word)
{
  //aggregate the line - each letters top iline. print. then again. 
  int iline,jline;
  //char *(*symbol)[SYMBOL_HEIGHT] = &alphabet[33];
  
  for(iline = 0; iline!=SYMBOL_HEIGHT; ++iline)
  {
    for(jline = 0; jline<strlen(word);jline++)
    {  
      char letter=word[jline];
      printf("%c",letter);
//       char *c[SYMBOL_HEIGHT]=&alphabet[]
      //(*symbol)[SYMBOL_HEIGHT] = &alphabet[word[jline] ];
//       printf("%s", (*symbol)[iline]);
    }
    printf("\nhere");
  }

}
/*
 void prsym(int idx) {
  int iline;
  char *(*symbol)[SYMBOL_HEIGHT] = &alphabet[idx];
  for(iline = 0; iline!=SYMBOL_HEIGHT; ++iline)
  printf("%s\n", (*symbol)[iline]);
}
 
  
  
 
	printf("\n %d: %s\n",i, argv[i]);
	for (j=0;j<strlen(argv[i]);j++)
	{
	  printf("%c: %d, ",argv[i][j] ,argv[i][j]);
	}
	*/