#include <stdio.h>
void strrcat(char * s,char * t)
{
    int i,j;
    for (i = 0; s[i];i++)
        ;
    for(j=0;s[i] = t[j];i++,j++)
        ;
}
//5.04
int strrlen(char*s)
{
    char *p = s;

    while(*p)
        p++;
    return p - s;
}

int strrend(char *s, char *t)
{
    int i,j;
    i = strrlen(s);
    j = strrlen(t);
    if (i >= j)
        for (;s[i] == t[j];i--,j--) {
            if (j == 0) {
                return 1;
            }
        }
    return 0;
}

void main(){
    char s[1000] = "this is a ";
    char *t = "string";
    strrcat(s,t);
    printf("%s",s);
    int i = strrend(s,t);
    printf("%i",i);
}