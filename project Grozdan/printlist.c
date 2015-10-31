
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"h10.h"

void printLIST(wareHOUSE **head)
{
    if(*head!=NULL)
    {


        wareHOUSE *temp0=*head;
        long IDD;
        int true00=0;
        printf("Enter ID: ");
        fflush(stdin);
        scanf("%li",&IDD);


        for( temp0=*head; temp0!=NULL; temp0=temp0->pointer)
        {
            if(IDD==temp0->code)
            {
                printf(" code: %li name: %s price: %lf amount: %d date: %s \n ",temp0->code,temp0->name,temp0->price,temp0->amount,temp0->date);
                true00=1;
                break;
            }
        }
        if(true00==0)
            printf("wrong ID \n");
    }
    else
    {
        printf("list is empty \n");
    }
}
