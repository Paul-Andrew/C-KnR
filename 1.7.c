#define _GNU_SOURCE
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
/*
Converts between Celsius, Fehrenheit, and Kelvin, 
or prints a list of conversions from -40F to 200F
Uses pointers to pass memory locations to conversion
functions.
*/

//converts Fahrenheit to Celsius/
void To_Celsius(float* fahr_to_cels)
{
    *fahr_to_cels = ((5.0/9.0) * (*fahr_to_cels - 32.0));
}
//converts Celsius to Fahrenheit
void To_Fahr(float* cels_to_fahr)
{
    *cels_to_fahr = (((9.0/5.0) * (*cels_to_fahr))+32.0);
}

void get_input(char* temp_return)
 {
    char temp_in[2];
    int i;//Iterator, Clears getchar
    for(i=0;i!=1;)
     {
        temp_in[i] = getchar();
        if(temp_in[i]=='F'|| temp_in[i]=='K'|| temp_in[i]=='C'|| temp_in[i]=='L' )
            i=1;
        else if(temp_in[i] == 'f')
		{
            temp_in[i] = 'F';
			i=1;
		}
        else if(temp_in[i] =='k')
		{
            temp_in[i] = 'K';
			i=1;
		}
        else if(temp_in[i] =='c')
		{
            temp_in[i] = 'C';
			i=1;
		}
        else if(temp_in[i] == 'l')
		{
            temp_in[i] = 'L';
			i=1;
		}
        else if(temp_in[i] != '\n')
            printf("Not Allowed\n");
    }
   *temp_return = temp_in[0];
}

void get_num(float* degrees)
{

    char *line = NULL;
    size_t len = 0;
    ssize_t read;


    while ((read = getline(&line, &len,stdin)) != -1) {
        if((*degrees = atof(line)))
            break;
		//printf("Not a valid Number:\n");
     }
    printf("%06.3f\n",*degrees);
    free(line);
}

int main()
{
    char deg_in, deg_out; //text flags for conversions
    float deg_num = 0.0; // input number
    float kelvin_loop = 0.0;
    float celsius_loop = 0.0;

    int i; //iterator.
    printf("\nWould you like to convert from (F)ahrenheit, (C)elsius, (K)elvin, or see a (L)ist of conversions?\n");
   get_input(&deg_in);
	if(deg_in != 'L')
	{
    	printf("Convert to (F)ahrenheit, (C)elsius, or (K)elvin?\n"); 
    	get_input(&deg_out);
	}

 //printf("\nin %c\nout %c\n",deg_in, deg_out);
    switch (deg_in)
    {
        case 'F' :

            if(deg_out == 'C')
            {
                printf("Enter Temperature to convert:\n");
                get_num(&deg_num);
                To_Celsius(&deg_num);
                printf("%06.3f Degrees Celsius\n",deg_num);
             }
            else if(deg_out == 'K')
            {
				printf("Enter Temperature to convert:\n");
                get_num(&deg_num);
                To_Celsius(&deg_num);
                deg_num += 273.15;
                printf("%06.3f Kelvin\n",deg_num);
             }
            else if(deg_out =='F')
            {
				printf("Enter Temperature to convert:\n");
                get_num(&deg_num);
                printf("%06.3f Degrees Fahrenheit, Duh\n",deg_num);
             }
        break;

        case 'C' :
	    if(deg_out == 'F')
            {
        	printf("Enter Temperature to convert:\n");
                get_num(&deg_num);
                To_Fahr(&deg_num);
                printf("%06.3f Degrees Fahrenheit\n",deg_num);
            }
            else if(deg_out == 'K')
            {
				printf("Enter Temperature to convert:\n");
                get_num(&deg_num);
                deg_num += 273.15;
                printf("%06.3f Kelvin\n",deg_num);
             }
            else if(deg_out =='C')
            {
		printf("Enter Temperature to convert:\n");
                get_num(&deg_num);
                printf("%06.3f Degrees Celsius, Duh\n",deg_num);
             }
	break;

        case 'K' :

            if(deg_out == 'F')
            {
                printf("Enter Temperature to convert:\n");
                get_num(&deg_num);
                deg_num -= 273.15;
                To_Fahr(&deg_num);
                printf("%06.3f Degrees Fehrenheit\n",deg_num);
             }
            else if(deg_out == 'C')
            {
				printf("Enter Temperature to convert:\n");
                get_num(&deg_num);
                deg_num -= 273.15;
                printf("%06.3f Celsius\n",deg_num);
             }
            else if(deg_out =='K')
            {
				printf("Enter Temperature to convert:\n");
                get_num(&deg_num);
                printf("%06.3f Kelvin, Duh\n",deg_num);
             }
        break;

        case 'L' :

            printf("Fahrenheit\tCelcius\tKelvin\n\n");
            for(i=-40;i<=200;i+=20)
            {
                celsius_loop = i;
                kelvin_loop = i;
                To_Celsius(&celsius_loop);
                To_Celsius(&kelvin_loop);
                kelvin_loop += 273.15;
                printf("\n\t%3d\t%06.3f\t%06.3f\n",i, celsius_loop, kelvin_loop);
             }
        break;

        default:
		printf("Something went wrong.\n");
        break;
     }
}  //ends main

