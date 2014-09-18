#include <stdio.h>
#include <stdlib.h>
void inttoa(int i, char* s,int n)
{
  if (i/10) {
    inttoa(i/10,s,n-1);
  }
  s[n] = (char)(((int)'0')+i%10);
}

char * intoa(int i)
{
  int c,d=1;
  for (c=0;i/d;c++) {
    d*=10;
  }
  static char s[100];
  inttoa(i,s,c-1);
  s[c]='\0';
  return s;
}

int main()
{ char a[5] = "\n";
  char *s = a;
  if(1)
    s = intoa(54321);
  else
    s = "Error";
  printf("%s\n",s);
  return 0;
}





int atoint(char * s)
{
  int i = 0,n=0;
  while (1){
    if (s[n]) {
      i+=(int)s[n];
      i*=10;
    }
    else
      break;
    n++;
  }
  
  return i/10;
}