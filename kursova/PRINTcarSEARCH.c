#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
carMEMORY *PRINTcarSEARCH(carMEMORY **head,double priceT)
{
 carMEMORY *temp3;
 char buffer1[20];
 int true=0;
 if(*head!=NULL)
 {
     printf("Enter car mark: \n");
     scanf("%s",buffer1);
    for (temp3 = *head;temp3!=NULL;temp3=temp3->pointer)
    {
      if(!strcmp(buffer1,temp3->mark))
      {
       if(temp3->price > priceT)
       {
       printf(" %s  %s  %.0lf  %s  %.2lf \n\n", temp3->code,temp3->color,temp3->engine,temp3->mark,temp3->price);
       true=1;
       }
      }

    }
    if(true==0)
           {
              printf("There is not such a car with that mark! \n ");
           }
 }
 else
 printf("list in empty!");
}
