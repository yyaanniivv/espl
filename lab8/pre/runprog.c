#include <stdio.h>
#include<string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main (int argc, char ** argv)
{
	char numbers=0;
	if ((argv[1][0]=='-') && (argv[1][1]=='n')) { // checking if -n as been applied
		numbers=1;
	}
  int j;
  char* command=argv[1+numbers];
  printf("%s ", command );
  
  for (j=2;j<argc;j++) {	//printing the command
    printf("%s ", argv[j] );
  }
  printf("\n");

  char inbuf[16];

   int p[2];

   /* open pipe */

   if(pipe(p) == -1)
   {    perror("pipe call error");
        return 1;
   }
  int status=-1;
  int pid = fork();

  if(pid) //fork != 0
  {
	if (numbers) {
		printf("1: ");
	}
	int line=1;
	close(p[1]);

	while (read (p[0], inbuf, 1)) {
		printf("%s",inbuf);	
		if (numbers && inbuf[0]=='\n') {
			line++;
			printf("%i: ",line);
		}
	
	}
	wait(&status);
	printf("exit status: %d \n ", status);
  }
    else {
	dup2(p[1],1);
	close(p[1]);
	close(p[0]);
  	execvp(command,argv+1+numbers);
            printf("kinder is alive error!\n");
  }

  return 0;
}
