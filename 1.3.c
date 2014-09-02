#include <stdio.h>

/* Prints conversion of celcius to Fehrenheit for 0-300 fahrenheit*/


main()
    {
        float fahr, cels;
        int lower, upper, step;

        lower = -40;
        upper = 300;
        step = 20;

        fahr = lower;
        printf("Fahrenfeit \t Celsius\n");
        while (fahr<=upper) {
            cels = (5.0/9.0) * (fahr - 32.0);
            printf("%3.0f \t\t %6.1f\n", fahr, cels);
            fahr=fahr + step;
        }
    } //ends main
