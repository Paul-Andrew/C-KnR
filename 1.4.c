#include  <stdio.h>

main()
{
    int c;
    char end = EOF;
    printf("ctrl-d to exit\n");
        
    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
       printf("Printing EOF:\nRight here> %c\n", end);
}
