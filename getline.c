#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    float num = 0.0;




    while ((read = getline(&line, &len,stdin)) != -1) {
       if((num = atof(line)))
           break;
        // printf("Retrieved line of length %zu :\n", read);
       // printf("%s", line);
    }
    printf("%f\n",num);
    free(line);
    exit(EXIT_SUCCESS);
}

