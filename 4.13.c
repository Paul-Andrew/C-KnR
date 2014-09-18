#include <string.h>
#include <stdio.h>

/*
char * reverses(char * s1)
{
  int l = strlen(s)-1;
  char temp=s[0];
  char * s2[l-2];
  s1 = reverses(s2);
  
  return s1;
}
*/
char * reverses(char * s1)
{
  int i,l = strlen(s1);
  if (l>1){
    char first = s1[0];
    char last = s1[l-1];
    char * s2[l];
    for (i=1;i<l-1;i++) {
      s2[i] = s1[i+1];
    }
    s1[1] = reverses(s2);
    s1[0] = last;
    s1[l-1] = first;
  }
  
  
  return s1;
}


main(int argc, char *argv)
{
  if(argc>1)
    printf("%s",reverses(argv[0]));
}
