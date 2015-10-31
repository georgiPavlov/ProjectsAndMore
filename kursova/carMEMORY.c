#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

carMEMORY *ADDinLAST(carMEMORY **head)
{

    int n,i=0;

    printf("Enter how many cars you want to enter\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    carMEMORY *temp =(carMEMORY*) malloc(sizeof(carMEMORY));
    carMEMORY *lastp;
    if (temp == NULL)
    printf("Allocation ERROR \n");

    printf("Enter ID: \n");
    scanf("%s",temp->code);
    printf("Enter color: \n");
    scanf("%s",temp->color);
    printf("Enter engine: \n");
    scanf("%lf",&(temp->engine));
    printf("Enter mark: \n");
    scanf("%s",temp->mark);
    printf("Enter price: \n");
    scanf("%lf",&(temp->price));

    if(*head == NULL)
    {
        *head=temp;

        temp->pointer = NULL;
    }
    else
    {
        lastp = last(head);
        lastp->pointer = temp;
        temp->pointer = NULL;
    }
    }
    return *head;
}
