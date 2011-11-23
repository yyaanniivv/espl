#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "diff.h"


int main(int argc, char *argv[] )
{
  int hflag=0, mflag=0, rflag=0, optflag;
  while((optflag=getopt(argc,argv, "hrm"))!=-1)
  {
    switch(optarg)  //NOTICE /////////////////////////////////////////////////////////
    {
      case 'h':
	break;
	
      case 'r':
	
      case 'r':

      default:
	printf("unknown flag, -h for help");
    }
  }
  /*
   while (getopt (,,)!= -1)
     if r - rflag=1
       h - hlag=1
       m - mflag=1
       ? = do nothing \ dont care
   */
    if (argc > 2) 
      //flags input here.
    /*
#include <unistd.h>

int getopt(int argc, char * const argv[], 
		     const char *optstring);

OPTIONS
   -h  print a summary of options and exit
   -r  reverse the differences
   -m  print a message each time a change is applied

     */
    {
    FILE *f1, *f2;
    f1 = fopen(argv[1],"r+"); //    f1 = fopen(argv[optind],"r+"); 
    f2 = fopen(argv[2],"r"); //    f2 = fopen(argv[optind+1],"r");

    struct diff diff;
    long i=0;

    while (!(feof(f2)))
      {
	char line[512]="",x[16]="";
	fgets(line,512,f2);
//	printf("this is the line:fgets %s - strlen %d\n",line, strlen(line) );
	if(strlen(line) > 10)
	{
	    parsediff( line, &diff);	//throws segmentation fault on an empty/small (under 7 chars) string!
//	    printf("diff.old = %d, diff.new= %d, diff.offset= %ld\n",diff.old,diff.new,diff.offset);
	    /* used fseek instead
	    while(i!= (diff.offset) )
	    {
	      i++;
	      fread(&x, 1, 1,f1);
//	      printf(" -%c i'm in da loop\n",*x); //test fread is working. it is.
	      //fgetc(f1);
	    } 
	    */
	    
	    fseek(f1,diff.offset,SEEK_SET);
	    //if (rflag) tmp = diff.new ,diff.new = old ,diff.old =tmp; //NOTICE
	    //if (mflag) printf("change has been applied to the file");
	    fwrite(&diff.new,1,1,f1);
	    }
	    else
	    {
		//if (hflag)
		//print options
		//else
		printf("This bytefix command line isn't legal: %s", line);
	    }
      }

      fclose(f1) ;
//      printf("f1 ");
      fclose(f2) ;
//      printf("and f2 are closed\n");
    }
    else 
    {
      printf("error reading argument values\nargc=  %d \n", argc); // %s , %s argv[1], argv[2] 
    }
    return 0;
}