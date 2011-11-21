#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "namelist.h"

void checkTxt(namelist nl, char *filename);
int compareNameStrings(const void *a, const void *b);

//canalyze a.txt b.txt
int main(int argc, char **argv ) 
{
    int files=1;
    namelist nl;
    nl = make_namelist();
    /*
     //nl and string tests
    char seg[100]="segev";
    char noa[100]="";
    char noale[100]="noa'le";
    strcpy(noa,noale);
    char freddy[100]="";
    freddy[0]='F';
    freddy[1]='r';
    freddy[2]='e';
    freddy[3]='d';
    //freddy[4]=' ';
    //freddy[5]='\0';
    printf("freddy = %s\n",freddy);
    
    add_name(nl, "yaniv");
    add_name(nl, seg);
    add_name(nl, noa);
    add_name(nl, freddy);
    printf("%s is the first name in the namelist \n", nl->names[0].name);
    printf("%s is the second name in the namelist \n", nl->names[1].name);
    printf("%s is the third name in the namelist \n", nl->names[2].name);
    printf("%s is the forth name in the namelist \n", nl->names[3].name);
    printf("argc[0]= %s \n",argv[0]);
    printf("argc= %d \n",argc);

    char kw[32][10] = {"auto", "double", "int", "long", "break", "else", "long", "switch", "case", "enum", "register", "typedef", "char", "extern", "return", "union", "const", "float", "short", "unsigned", "continue", "for", "signed", "oid", "default", "goto", "sizeof", "volatile", "do", "if", "static", "while"};
    int j;
    for (j=0 ;j<32; j++)
      printf(" - %s ", kw[j]);
    printf("\n");
    */
    
    while (files<argc)
    {
      //printf("%s file is in process \n",argv[files]);
      checkTxt(nl,  argv[files] );
      files++;
    }
    
    int k; //not sorted yet
    qsort(nl->names , nl->size, sizeof(nl->names[0]), compareNameStrings); //sorting via compareNameStrings.
    //printf("sorted?\n");
      
    for (k=0;k<nl->size ;k++)
    {
	  
	  //printf("%d, %d=return value\n",k,compareNameStrings(nl->names[k].name, nl->names[k+1].name) );
          printf("%s %d \n", nl->names[k].name, nl->names[k].count);
    }
    return 0;
    
}


/*strcmp(strings a,b) = -1 0 1
 * strcmp>0 iff a>b.
 strcmp=0 iff a=b
 strcmp<0 iff a<b
 */

int compareNameStrings(const void *a, const void *b)
{
  //printf("%s=a, %s=b\n",a, b);
  return strcmp(a, b);
}

/*
 */
void checkTxt(namelist nl, char *filename)
{
    FILE *f1;
    f1 = fopen(filename,"r");
    char kw[32][10] = {"auto", "double", "int", "long", "break", "else", "long", "switch", "case", "enum", "register", "typedef", "char", "extern", "return", "union", "const", "float", "short", "unsigned", "continue", "for", "signed", "oid", "default", "goto", "sizeof", "volatile", "do", "if", "static", "while"};

    char  x;
    int wordi=0;
    
    if (ferror (f1))
	printf("error reading file - %s\n",filename );
   
    else
    {
	char word[NAMELEN]="";
	x=fgetc(f1);
	while (x != EOF)// not EOF  (!feof(f1)) 
	{
	  if ((isdigit(x)!=0 )|( isalpha(x)!=0 )) //INWORD proccessing
	  {
	    word[wordi]=x;
	    wordi++;
	    x =fgetc(f1);
	  }
	  else //if buffer full - wordi!=0  - save word ->> in namelist. else next char 
	  {
	    if (wordi!=0)  //not in word and buffer is full
	    {
	      
	      int j,flag=0;
	      word[wordi]='\0'; //NOTICE \0 at end of string	
	      //printf("%s \n",word);
	      for (j=0;j<32;j++)   //NOTICE check word is not keyword
	      {
		if (! strcmp(word,kw[j]))
		{
		  flag=1;
		  j=32;
		}
	      }
	      if (!flag) //add word
		add_name(nl, word);
	      else	//keyword, dont add it
		flag=0;
	      wordi=0; //c=fgetc(f1);
	    }
	    else  //not in word and buffer is empty = > get next char
	    {
	      //printf("else else else -not a word and word buffer is 0) \n");
	      x =fgetc(f1);  
	    }
	  }
	    
	}
    }


    fclose(f1);
}
