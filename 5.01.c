#include <ctype.h>
int getch(void);
void ungetch(int);

int getint(int *pn)
{
    int c, sign;
    
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch();
        return 0;
    }
    sign = (c =='-') ? -1 : 1;
    if (c == '+' || c == '-')
        if (isdigit(c = getch())) {
            for (*pn = 0; isdigit(c); c = getch())
                *pn = 10 * *pn + (c - '0');
        *pn *= sign;
        }
    if (c != EOF)
        ungetch(c);
    return c;
}

