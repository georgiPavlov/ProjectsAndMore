#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"h10.h"

wareHOUSE *insertLAST(wareHOUSE **head, warehouseTEMP info)
{
    wareHOUSE *temp1=(wareHOUSE*)malloc(sizeof(wareHOUSE));
    wareHOUSE *lastp1;
   if (temp1==NULL);
    {
     printf("pointer error \n");
     MEMORYfree(head);
     exit(2);
    }


    temp1->code      =   info.code;
    strcpy(temp1->name, info.name);
    temp1->price    =   info.price;
    temp1->amount     =   info.amount;
    strcpy(temp1->date, info.date);

    if (*head == NULL)
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
