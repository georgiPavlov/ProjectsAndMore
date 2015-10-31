#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

double PRICEcar(carMEMORY **head)
{
 carMEMORY *temp4;
 int true=0;
 double SUM=0;
 int s=0;
 char buffer2[20];
 if(*head!=NULL)
 {
     printf("Enter car mark to sum the price \n");
     scanf("%s",buffer2);
    for (temp4 = *head;temp4!=NULL;temp4=temp4->pointer)
    {
      if(!strcmp(buffer2,temp4->mark))
      {
       SUM= SUM +(temp4->price);
       s++;
       true=1;
      }

    }
    if(true==0)
           {
              printf("There is not such a car with that mark! \n ");
           }
 }
 else
 printf("list in empty!");
 printf("\n");
 return (SUM/s);
}
