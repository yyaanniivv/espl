 
#include<stdio.h>

//to make an outputfile called c.txt from the output stream
//	./bcmp a.txt b.txt>c.txt
int main(int argc, char *argv[] ) //int main ( int argc, char *argv[] )
{
    //printf("args %s \n", argv[1]);
    FILE *f1, *f2;
    f1 = fopen(argv[1],"r"); 
    f2 = fopen(argv[2],"r");
    int i=0;
    if ((f1!=NULL || f2!=NULL)  && argc==3)
    {
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
	  //break;
	}
	i++;

      }
      
    fclose(f1) ;
    fclose(f2) ;  
    }
    else {
      printf("error loading files via args\nargc=  %d \n", argc); // %s , %s argv[1], argv[2] 
  }
    return 0;
}