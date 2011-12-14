//int length(char *s);
//#include "length.c"

int length(char *s) 
{
char *t = s;
while(*t) ++t;
return t-s;
}


int puts(char *s)
{
  int len = length(s);
  asmwrite(1, s, len);
}
