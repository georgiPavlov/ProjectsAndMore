#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"h10.h"

void DATE(char *buffDATE)
{
    char mas1DATE[10],mas2DATE[10],mas3DATE[10];
    int i=0,j=0;
    while( (buffDATE[i]!='.'))
    {
        mas1DATE[j] = buffDATE[i];
        i++;
        j++;

    }
    i++;
    j=0;
    while( (buffDATE[i]!='.'))
    {
        mas2DATE[j] = buffDATE[i];
        i++;
        j++;
    }
    i++;
    j=0;
    while(buffDATE[i]!='\0')
    {
        mas3DATE[j] = buffDATE[i];
        i++;
        j++;

    }

    day=atoi(mas1DATE);
    month=atoi(mas2DATE);
    year=atoi(mas3DATE);
}
