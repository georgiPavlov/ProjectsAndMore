#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void removeCAR(carMEMORY **head)
{
    int g=0,nn;
    char buffer[20];
    carMEMORY *temp2;
    if(*head != NULL)
    {
    printf("How many cars you want to remove: \n");
    scanf("%d",&nn);
    for(g = 0;g<nn; g++)
     {
      printf("Enter car ID: \n");
      scanf("%s",buffer);
       for (temp2 = *head;temp2!=NULL;temp2=temp2->pointer)
       {
           if(!strcmp(buffer,temp2->code))
           {
              temp2 = temp2->pointer;
              free(temp2);
              printf("car removed! \n");
              break;
           }
           if(temp2->pointer == NULL)
           {
              printf("Wrong ID \n");
              break ;
           }
       }
     }
    }
    else
    printf("list in empty!");
}
