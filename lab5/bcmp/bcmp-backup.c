 //TODO asmread asmwrite asmopen asmclose
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
//to make an outputfile called c.txt from the output stream
//	./bcmp a.txt b.txt>c.txt
int main(int argc, char *argv[] ) //int main ( int argc, char *argv[] )
{
    //printf("args %s \n", argv[1]);
    int f1, f2;
    //f1 = fopen(argv[1],"r"); //TODO asmopen
    //f2 = fopen(argv[2],"r"); //TODO asmopen
    f1 = asmopen(argv[1],444);
    f2 = asmopen(argv[2],444);
    int i=0;
    if ((f1!=-1 || f2!=-1)  && argc==3)
    {
      char  x='a', y='a'; //mini buffers
      //int i=0, j=0;
      //while (f1 !=EOF)
      
      while (!(feof(&f1)) | !(feof(&f2))) //end of file!?! 
      {
	fread(&x, 1, 1,&f1);   //TODO asmread
	fread(&y, 1, 1,&f2);   //TODO asmread
	if ((x!=y) &&  (!(feof(&f1)) | !(feof(&f2))))
	{      
/*	  char msg[80];
	  strcpy (msg,"byte ");	  
	  char * num = malloc(8*sizeof(i));
	  itoa(i,num,10);
	  strcat (msg, num);
	  strcat (msg," -\n");
	  asmwrite(1,msg,length(msg));
*/

	  printf("byte %d -%d +%d\n",i, x, y); // TODO asmwrite
	  //break;
	}
	i++;

      }
      
    fclose(&f1) ; //TODO asmopen
    fclose(&f2) ; //TODO asmopen
    }
    else {
      char* errmsg="error loading files via args\n";
      asmwrite(1,errmsg, length(errmsg)); // %s , %s argv[1], argv[2]  // TODO asmwrite
  }
    return 0;
}

int length(char *s) 
{
char *t = s;
while(*t) ++t;
return t-s;
}