#include <stdio.h>

int main(int argc, char **argv)
{
   int i=argc; //go down till arg>0
   //printf("argc = %d" ,argc);
   for (i=argc;i>0;i--)
   {
     if(argv[i]!=NULL){
       printf("%s ",argv[i]);
    }
   }
   printf("\n");
   return 1;
}
