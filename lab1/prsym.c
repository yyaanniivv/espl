#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "font.h"


int main(int argc, char * argv[])
{
  //printf(" argc = %d:\n",argc);
  int  i,j,k;
  char rowk[120];
  //strcpy(rowk,' ');
  for (k=0;(k<SYMBOL_HEIGHT);k++)
  {
//    if ((k!=SYMBOL_HEIGHT-3)& (k!=5)&(k!=0))
//    {
     printf("%d",k);
     strcpy(rowk,"");
     for (i=0;i<argc;i++) //WORD[i]
     {
       //printf(" argv[%d] = %s ",i,argv[i]);
       char cch;
       for(j=0; argv[i][j]!='\0' ; j++) //LETTER[j] =WORD[i][j]
       {
 	cch=argv[i][j];
 	//printf(" '%c' = %d\n", cch,cch);
	strcat(rowk,alphabet[cch-' '][k]);
	//prsym(cch-' ') ; 
       } //AGGREGATE ' ' (SPACE BETWEEN WORDS)
       strcat(rowk,"    ");
       printf("%s",rowk);
       printf("\n");
     }
  //}
  }
  return 1;

}

