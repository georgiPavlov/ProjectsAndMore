
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"h10.h"



wareHOUSE *EDIT(wareHOUSE **head)
{
    if(*head!=NULL)
    {


        wareHOUSE *temp111=*head;
        wareHOUSE *temp222=*head;
        long buffI;
        int am;
        printf("Enter ID : ");
        fflush(stdin);
        scanf("%li",&buffI);


        while(temp111!=NULL)
        {

            if(buffI == temp111->code)
            {
                printf("Enter amount : ");
                fflush(stdin);
                scanf("%d",&am);
                if(am > temp111->amount)
                {
                    printf("there is not enough amount! \n");
                    break;
                }
                else if(am == temp111->amount)
                {
                    printf("everything okay! \n");
                    remove1(temp222,temp111,head);
                    break;
                }
                else
                {

                    temp222->amount=temp222->amount - am;
                    printf("everything okay! \n");
                    break;
                }

            }
            temp222=temp111;
            temp111=temp111->pointer;

        }
    }
    else
        printf("list is empty \n");
    return *head;

}
