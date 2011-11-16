#include<stdio.h>

int main(int argc, char *argv[] ) //int main ( int argc, char *argv[] )
{
    //printf("args %s \n", argv[1]);
    FILE *f1, *f2;
    f1 = fopen(argv[1],"r"); // fopen (argv[1] , "r");   //file a = x 1 
    f2 = fopen(argv[2],"r"); // fopen (argv[2] , "r");   //file b = y 2
    
    if (f1!=NULL || f2!=NULL)
    {
      char  x[100], y[100];
      int line=0;   
      int i;
      
      while ((fgets(x,100,f1) !=NULL ) | (fgets(y,100,f2) !=NULL))
      {
	line++;
	i=0;
	//STRCMP  returns 0 if equal
	while ((i<100) &( (x[i]!='\n')| (y[i]!='\n')))
	{
	    if  (x[i]!=y[i])
	    {
	      printf("-%d: %s",line, x);
	      printf("+%d: %s",line, y);
	      i=200;
	    }
	   i++;
	}
      
      }
      
    fclose(f1) ;
    fclose(f2) ;  
    }
    else {
      printf("error loading files via args"); // %s , %s argv[1], argv[2] 
    }
    return 0;
}
  