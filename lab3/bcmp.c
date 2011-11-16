#include <stdlib.h>
#include <stdio.h>
#include "diff.h"
int main(int argc, char *argv[] ) //int main ( int argc, char *argv[] )
{
    //printf("args %s \n", argv[1]);
    FILE *f1, *f2;
    f1 = fopen(argv[1],"r+"); 
    f2 = fopen(argv[2],"r");
    struct diff diff;
    long i=0;
    if (f1!=NULL || f2!=NULL)
    {
      while (!(feof(f2)))
      {
	char line[512];
	//read line from files
	parsediff( fgets(line,512,f2), &diff); // NOTICE we got error here
	
	while(i!= diff->offset)
	  i++;
	int newbyte=diff->new;
	//fix byte
	fwrite(&newbyte,1,1,f1); // NOTICE we got here
	
      }
      /*
      char  x='a', y='a'; //mini buffers
      //int i=0, j=0;
      //while (f1 !=EOF)
      
      while (!(feof(f1)) | !(feof(f2))) //end of file!?! 
      {
	fread(&x, 1, 1,f1);
	fread(&y, 1, 1,f2);
	if ((x!=y) &&  (!(feof(f1)) | !(feof(f2))))
	{      
	  printf("byte %d -%d +%d\n",i, x, y);
	  //for -> to the bad byte
	  //change the byte -> //fwrite(&x/y,,,);
	}
	i++;

      }
      */
    fclose(f1) ;
    fclose(f2) ;  
    }
    else {
      printf("error loading files via args\nargc=  %d \n", argc); // %s , %s argv[1], argv[2] 
  }
    return 0;
}