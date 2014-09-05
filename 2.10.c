#include <stdio.h>


int string_length(char *s)
{
  int c = 0;
  
  while(*(s+c))
    c++;
  
  return c;
}

char *lower(char *s){
  int i,c;
  
  printf("%i",string_length(s));
  for (i=0;i < (int)string_length(s);i++) {
    c = s[i];
    s[i] = (c >='A' && c <='Z') ? c -('A'-'a') : c;
  }
  return s;
}



int main(int argc,char *argv[])
{
  if (argc == 2)
    printf("%s\n",lower(argv[1]));
  else
    printf("I need a \"string\"\n");
}
