#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"h10.h"

wareHOUSE *ADDinLAST(wareHOUSE **head)
{

    wareHOUSE *temp=(wareHOUSE*) malloc(sizeof(wareHOUSE));
    if (!temp)
    {
        printf("pointer error \n");
        MEMORYfree(head);
        exit(2);
    }
    wareHOUSE *lastp;
    wareHOUSE *tempID1;
    int trueID1=0;
    long tc=0;
    if(temp == NULL)
        printf("Allocation ERROR \n");

    int daysinmonth[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int legit = 0;


    char buff[30];


    printf("Enter ID: ");
    fflush(stdin);
    scanf("%li",&tc);


    for( tempID1=*head; tempID1!=NULL; tempID1=tempID1->pointer)
    {
        if(tc == tempID1->code)
        {
            printf("THE ID ID USED ALREADY!! \n");
            trueID1=1;
            break;
        }
    }

    if(trueID1==0)
    {
        temp->code=tc;
        printf("Enter name: ");
        fflush(stdin);
        scanf("%s",temp->name);
        printf("Enter price: ");
        fflush(stdin);
        scanf("%lf",&temp->price);
        printf("Enter amount: ");
        fflush(stdin);
        scanf("%d",&temp->amount);
        printf("Enter the date with format !! day.month.year !! : ");
        fflush(stdin);
        scanf("%s", buff);

        DATE(buff);

        if((year % 400 == 0 ) || (year %4 == 0 ))
            daysinmonth[1]=29;

        if (month<13 && month>0)
        {
            if( day <= daysinmonth[(month)-1] )
                legit=1;
        }
        if (legit==0)
        {
            printf("It's not a legitimate date! \n");
            printf("Please again. ");
            free(temp);
        }
        else
        {
            strcpy(temp->date,buff);

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
    }


    return *head;

}
