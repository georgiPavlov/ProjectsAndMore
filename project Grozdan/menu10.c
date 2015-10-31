

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"h10.h"

int menu()
{
    int result;
    printf("************************* MENU *************************\n\n\n");
    printf("Enter 1 to add freightage. \n");
    printf("Enter 2 to edit the amount of freightage \n");
    printf("Enter 3 to view the freightages that are expire. \n");
    printf("Enter 4 to view information about freightage  \n");
    printf("Enter 5 to write freightage on single FILE \n");
    printf("Enter 6 to EXIT\n");
    scanf("%d",&result);
    return result;
}
