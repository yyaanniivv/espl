#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main (int argc,char *argv[])
{
  int opt, hflag=0, lflag=0;
  char *path;
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
    
    if (optind < argc) //receive dir from argv
    {
      //printf("directory: %s\n", argv[optind]);
      path=argv[optind];
    }
    else //read current location as dir
    {
       //printf("%s\n",getcwd(NULL,0));
       path=getcwd(NULL,0);
    }
    //go though dirctory 
    DIR *dip;
    struct dirent *dit;

    if( (dip=opendir(path)) != NULL)
    {
	//go over dir for each entry print it.
	//if l flag is up - print more details.
      struct stat * filestats;
      while( (dit=readdir(dip)) !=NULL) //segmentation fault on flag -l
      {  
	if (lflag)
	{
	  stat(dit->d_name, filestats); //segmentation fault on flag -l //NOTICE
	  printf("bytes: %lu ", filestats->st_size);
	}
	printf(" filename %s\n",dit->d_name );
      }
    }
    else // hflag
      printf("error opening directory %s \n",argv[optind]);
  }
  else
  {
    printf("OPTIONS\n\t-h   print summary of options and exit.\n\t-l   print file size in bytes before the file name.\n");
  }
  return 0;
} 