
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"h10.h"

wareHOUSE *old(wareHOUSE **head)
{


    if(*head!=NULL)
    {
        int true1=0;
        int true2=0;
        int legit1=0;
        char buff7[20];
        char buff8[20];
        int d,m,y;
        int daysinmonth1[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        printf("Enter the date: ");
        fflush(stdin);
        scanf("%s", buff7);

        DATE(buff7);

        d=day;
        m=month;
        y=year;
        if((y%400 == 0 ) || (y%4 == 0 ))
            daysinmonth1[1]=29;

        if (m<13 && m>0)
        {
            if( d <= daysinmonth1[m-1] )
                legit1=1;
        }



        if(legit1==1)
        {
            wareHOUSE *temp7=*head;



            for( temp7=*head; temp7!=NULL; temp7=temp7->pointer)

            {

                strcpy(buff8,temp7->date);
                DATE(buff8);

                if(y>year)
                {

                    true1=1;
                    true2=1;
                }
                if((m>month)&& (y==year))
                {
                    true1=1;
                    true2=1;
                }
                if((d>day)&& (y==year)&& (m==month) )
                {
                    true1=1;
                    true2=1;
                }
                if(true1==1)
                {
                    printf(" expire: code: %li name: %s price: %lf amount: %d date: %s \n ",temp7->code,temp7->name,temp7->price,temp7->amount,temp7->date);
                }
                true1=0;
            }

            if(true2==0)
            {
                printf("there is not any freightage that is expire \n");
            }




        }
        else
            printf("wrong time \n");




    }
    else
        printf("the list is empty \n");

}
