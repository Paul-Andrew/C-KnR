#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 1000

/*htoi converts hexadecimal to decimal*/

int getaline(char s[], int lim)
{
  int c, i;
  
  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

main()
{
  char line[MAXLINE], c;
  int len = 0, i, dec = 0, power;
  char *abcdef = "abcdefABCDEF";
  for (len = getaline(line,MAXLINE); len > 1; len = getaline(line,MAXLINE)){
    if (line[1]=='x'||line[1]=='X'){
      for(i=2;i<len;i++) {
	line[i-2]=line[i];
      }
      len -=2;
    }
       ;//ignores 0x / 0X prefix
    for (i=0; i<len-1; i++){
      dec *=16;
      c = line[i];
      if(isdigit(c)){
	dec +=(c-'0');
      }//if
      else if (index(abcdef,c)){
	dec += ((c-'A')%('a'-'A'))+10;//hex value of a given letter
      }//else if
      else {
	printf("%c is not valid in hexadecimal!\n",c);
	break;
      }
    }//for
    printf("%i\n",dec);
    dec = 0;
  }//for
}//main

/*
 
 printf("%i\t",dec);
 printf("%c\t",line[i]);
 printf("%i\t",line[i]-'A');
 printf("%i\t",i);
 printf("%i\t",16*i);
 printf("dec = %i\n\n",dec);

 printf("%i\n",((('f'-'A')%('a'-'A'))+10)+(16*0));
 
 */