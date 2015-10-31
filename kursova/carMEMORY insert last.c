#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

carMEMORY *insertLAST(carMEMORY **head,carIN info)
{
carMEMORY *temp1=(carMEMORY*)malloc(sizeof(carMEMORY));
carMEMORY *lastp1;
if (temp1 == NULL)
    printf("Allocation ERROR \n");
  strcpy(temp1->code,info.code1);
  strcpy(temp1->color,info.color1);
  temp1->engine = info.engine1;
  strcpy(temp1 -> mark,info.mark1);
  temp1->price = info.price1;
  if(*head == NULL)
  {
    *head=temp1;
    temp1->pointer = NULL;
  }
  else
  {
      lastp1 = last(head);
      lastp1->pointer = temp1;
      temp1->pointer = NULL;
  }

  return *head;
}
