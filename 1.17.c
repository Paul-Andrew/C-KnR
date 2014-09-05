#include <stdio.h>
#define MAXLINE 1000
//int getline(char line[], int maxline);

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
  char line[MAXLINE];
  int len = 0, i;
  for (len = getaline(line,MAXLINE); len > 1; len = getaline(line,MAXLINE)){
    (len >= 80) ? printf("%s",line) : printf("%i\n",len);
  }//for len
  return 0;
}