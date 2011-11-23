#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int main (int argc,char *argv[])
{
  int opt, hflag=0, lflag=0;
  while ((opt=getopt(argc, argv, "hl")) !=-1)
  {
    switch(opt)
    {
      case 'h':
	hflag=1;
	break;
      case 'l':
	lflag=1;
	break;
      default:
	printf("unknown flag. run with -h for help\n");
	break;
    }
  }
  //dir code
  if (!hflag)
  {
    
    if (optind < argc)      //read dir from argv//
    {
      printf("directory: %s\n", argv[optind]);
    }
    else //read current location dir
    {
       printf("%s\n",getcwd(NULL,0));
    }
  }
  else
  {
    printf("\tOPTIONS\n \t\t  -h   print summary of options and exit.\n 	\t\t  -l   print file size in bytes before the file name.\n");
  }
  return 0;
}