#include <stdio.h>

int atod (char *number)
{
    int i=0;
    int j;
    for (j=0;number[j]!='\0' ;j++) {
      i=i*10;
      i=i+(number[j]-'0');
    }
    
    return i;
}