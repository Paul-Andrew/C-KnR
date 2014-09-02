#include <stdio.h>

#define IN 1 //in a word
#define OUT 0 //out of a word
main()
{
    int c, nc, nl, nw, P = OUT, cl = 1;
    // Character received, New Character count, NewLine count,
    // New Word count, Part of a word or not, Continue Loop?

        printf("I will count your characters, words, and lines.\n"); 
    while(cl == 1)
    {
        nc = 0;
        nl = 0;
        nw = 0;

        printf("Type below, ctrl+d to stop\n");
        while((c = getchar()) != EOF)
        {
             ++nc;
            if (c == '\n')
                 ++nl;
            if (c == ' ' || c == '\t' || c == '\n')
                 P = OUT;
            else if (P == OUT)
            {    P = IN;
                ++nw;
            }
            if(nl == 0 && nc > 0)
                nl++;
       }
       printf("\nFound: %d lines, %d words, %d Characters\n", nl, nw, nc);
       printf("Try again? (Y or N)\n");
       cl = -1;
       while(cl == -1)
       {
            c = getchar();
            if(c == 'n' || c == 'N')
                cl = 0;
            else if(c == 'y' || c == 'Y')
                    cl = 1;
            else if(c != '\n')
                printf("Y or N please.\n");
        }//response while
    }
}

