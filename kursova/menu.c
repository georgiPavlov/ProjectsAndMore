#include <stdio.h>

int menu()
{
 int result;
 printf("                        MENU         \n");
 printf("ENTER 1 to add new cars\n");
 printf("ENTER 2 to view the cars in the list by mark \n");
 printf("ENTER 3 to delete car from the list by ID \n");
 printf("ENTER 4 to view the cars with price higher than average\n");
 printf("ENTER 5 to EXIT\n");
 scanf("%d",&result);
 return result;
}
