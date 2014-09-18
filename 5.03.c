void strcat(char * s,char * t)
{
    int i,j;
    for (i = 0; s[i];i++)
        ;
    for(j=0;s[i] = t[j];i++,j++)
        ;
}
//5.04
int strlen(char*s)
{
    char *p = s;

    while(*p)
        p++
    return p - s;
}

int strend(char *s, char *t)
{
    if (i = strlen(s) >= j = strlen(t))
        for (;s[i] == t[j];i--,j--) {
            if (j == 0) {
                return 1;
            }
        }
    return 0;
}
