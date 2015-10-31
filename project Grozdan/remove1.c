
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"h10.h"

wareHOUSE *remove1(wareHOUSE *temp33,wareHOUSE *p,wareHOUSE **head)
{

    if(temp33 == *head)
    {

        if((*head)->pointer !=NULL)
        {
            *head=(*head)->pointer;
            free(temp33);
            printf("list deleted \n");


        }
        else
        {
            *head=NULL;
            free(temp33);
            printf("list deleted \n");


        }

    }

    else if(temp33->pointer == NULL)
    {
        p->pointer=NULL;
        free(temp33);
        temp33=*head;
        printf("list deleted \n");


    }

    else
    {
        p->pointer=temp33->pointer;
        free(temp33);
        temp33=*head;
        printf("list deleted \n");


    }
    return *head;
}
