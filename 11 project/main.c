#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "h11.h"

int year,month,day;

int main()
{
    business * head = NULL;

    readFile (&head);
    int key;


    do
    {
        key = menu();
        switch (key)
        {
        case 1:
        {
            ADDinLAST(&head);
            break;
        }
        case 2:
        {
            EDIT(&head);
            break;
        }
        case 3:
        {
            INTERVAL(&head);
            break;
        }
        case 4:
        {
            printLIST(&head);
            break;
        }

        case 5:
        {
            writeFILE(&head);
            MEMORYfree(&head);
            printf("\n\n           _-_-Goodbye!-_-_\n\n");
            return 0;
        }
        }
    }
    while (key != 6);
    return 0;
}

int menu()
{
    int result;
    printf("************************* MENU *************************\n\n\n");
    printf("Enter 1 to add business. \n");
    printf("Enter 2 to edit the information about business  \n");
    printf("ENTER 3 to view each business with profit in the interval (x,y). \n");
    printf("Enter 4 to view information about business   \n");
    printf("Enter 5 to EXIT\n");
    scanf("%d",&result);
    return result;
}

void readFile(business **head)
{


    businessTEMP infoTEMP;
    FILE *fp = fopen("businessInfo.txt","rb");
    if(fp != NULL)
    {
        do
        {
            fread(&(infoTEMP.code),sizeof(long),1,fp);
            fread(infoTEMP.name,sizeof(char),40,fp);
            fread(&(infoTEMP.profitYEAR1),sizeof(double),1,fp);
            fread(&(infoTEMP.profitYEAR2),sizeof(double),1,fp);
            fread(&(infoTEMP.profitYEAR3),sizeof(double),1,fp);
            fread(&(infoTEMP.profitYEAR4),sizeof(double),1,fp);
            fread(&(infoTEMP.profitYEAR5),sizeof(double),1,fp);
            fread(infoTEMP.date,sizeof(char),30,fp);

             insertLAST(head,infoTEMP);
        }while(!feof(fp));
    }
    fclose(fp);
}






business *insertLAST(business **head, businessTEMP info)
{
    business *temp1=(business*)malloc(sizeof(business));
    if (!temp1)
    {
        printf("pointer error \n");
        MEMORYfree(head);
        exit(2);
    }
    business *lastp1;
    temp1->code      =   info.code;
    strcpy(temp1->name, info.name);
    temp1->profitYEAR1    =   info.profitYEAR1;
    temp1->profitYEAR2    =   info.profitYEAR2;
    temp1->profitYEAR3   =   info.profitYEAR3;
    temp1->profitYEAR4    =   info.profitYEAR4;
    temp1->profitYEAR5    =   info.profitYEAR5;
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

business *last(business **head)
{
    business * temp;
    for (temp = *head; temp->pointer!=NULL; temp=temp->pointer)
        ;
    return temp;
}

business *ADDinLAST(business **head)
{
    business *temp=(business*) malloc(sizeof(business));
    if (!temp)
    {
        printf("pointer error \n");
        MEMORYfree(head);
        exit(2);
    }
    business *lastp;
    business *tempID1;
    int trueID1=0;
    long tc=0;
    if(temp == NULL)
        printf("Allocation ERROR \n");

    int daysinmonth[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int legit = 0;


    char buff[30];


    printf("Enter EIK: ");
    fflush(stdin);
    scanf("%li",&tc);


    for( tempID1=*head; tempID1!=NULL; tempID1=tempID1->pointer)
    {
        if(tc == tempID1->code)
        {
            printf("THE EIK I USED ALREADY!! \n");
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
        printf("Enter the profit in  year 1 (1 is current)(1-5):  ");
        fflush(stdin);
        scanf("%lf",&(temp->profitYEAR1));
        printf("Enter the profit of year (2): ");
        fflush(stdin);
        scanf("%lf",&(temp->profitYEAR2));
        printf("Enter the profit of year (3): ");
        fflush(stdin);
        scanf("%lf",&(temp->profitYEAR3));
        printf("Enter the profit of year (4): ");
        fflush(stdin);
        scanf("%lf",&(temp->profitYEAR4));
        printf("Enter the profit of year (5):  ");
        fflush(stdin);
        scanf("%lf",&(temp->profitYEAR5));

        printf("Enter the date with format !! year.day.month !! : ");
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

business *EDIT(business **head)
{

    if(*head!=NULL)
    {

        business *temp444=(business*) malloc(sizeof(business));
        char buffN[40];
        int key2;
        printf("Enter business name: ");
        fflush(stdin);
        scanf("%s",buffN);
        for(temp444=*head; temp444 != NULL ; temp444 = temp444->pointer)
        {
            if(!strcmp(buffN,temp444->name))
            {

                do
                {

                    key2 = menu2();
                    switch (key2)
                    {
                    case 1:
                    {
                        EDITeik(temp444);
                        break;
                    }
                    case 2:
                    {
                        EDITname(temp444);
                        break;
                    }
                    case 3:
                    {
                        EDITprofit(temp444);
                        break;
                    }
                    case 4:
                    {
                        EDITdate(temp444);
                        break;
                    }
                    case 5:
                    {

                        break;
                    }
                    }

                }
                while(key2!=5);


            }
        }
    }
    else
    {
        printf("the list is empty \n");
    }


}


int menu2()
{
    int result2;
    printf("************************* MENU *************************\n\n\n");
    printf("Enter 1 to edit EIK. \n");
    printf("Enter 2 to edit  business name  \n");
    printf("ENTER 3 to edit  profit  \n");
    printf("Enter 4 to edit  business date registration  \n");
    printf("Enter 5 to EXIT\n");
    scanf("%d",&result2);
    return result2;
}

void EDITeik(business *temp21)
{
    long newBUFF1;
    printf("enter new business EIK: ");
    fflush(stdin);
    scanf("%li",&newBUFF1);
    temp21->code = newBUFF1;
}

void EDITname(business *temp22)
{
    char newBUFF2[40];
    printf("enter new business name: ");
    fflush(stdin);
    scanf("%s", newBUFF2);
    strcpy(temp22->name , newBUFF2);
}

int EDITprofit(business *temp23)
{
    int key3;
    key3 = menu3();
    switch (key3)
    {
    case 1:
    {
        EDITprofit1(temp23);
        break;
    }
    case 2:
    {
        EDITprofit2(temp23);
        break;
    }
    case 3:
    {
        EDITprofit3(temp23);
        break;
    }
    case 4:
    {
        break;
    }

    }

}

int menu3()
{
    int result3;
    printf("************************* MENU *************************\n\n\n");
    printf("Enter 1 to edit  current profit. \n");
    printf("Enter 2 to edit  profit in years 1-5  \n");
    printf("ENTER 3 to edit  profit   in every year\n");
    printf("ENTER 4 to EXIT \n");
    scanf("%d",&result3);
    return result3;
}

void EDITprofit1(business *temp24)
{
    int newBUFF3;
    printf("enter new current year profit ");
    fflush(stdin);
    scanf("%d",&newBUFF3);
    temp24->profitYEAR5 = temp24->profitYEAR4;
    temp24->profitYEAR4 = temp24->profitYEAR3;
    temp24->profitYEAR3 = temp24->profitYEAR2;
    temp24->profitYEAR2 = temp24->profitYEAR1;
    temp24->profitYEAR1 = newBUFF3;
}

void EDITprofit2(business *temp25)
{

    int newBUFF4;
    int result4;
    printf("************************* MENU *************************\n\n\n");
    printf("Enter 1 to edit  profit in year 1. \n");
    printf("Enter 2 to edit  profit in year 2. \n");
    printf("Enter 3 to edit  profit in year 3. \n");
    printf("Enter 4 to edit  profit in year 4. \n");
    printf("Enter 5 to edit  profit in year 5. \n");
    scanf("%d",&result4);
    switch (result4)
    {
    case 1:
    {
        printf("enter profit ");
        fflush(stdin);
        scanf("%d",&newBUFF4);
        temp25->profitYEAR1 = newBUFF4;
        break;
    }
    case 2:
    {
        printf("enter profit: ");
        fflush(stdin);
        scanf("%d",&newBUFF4);
        temp25->profitYEAR2 = newBUFF4;
        break;
    }
    case 3:
    {
        printf("enter profit: ");
        fflush(stdin);
        scanf("%d",&newBUFF4);
        temp25->profitYEAR3 = newBUFF4;
        break;
    }
    case 4:
    {
        printf("enter profit: ");
        fflush(stdin);
        scanf("%d",&newBUFF4);
        temp25->profitYEAR4 = newBUFF4;
        break;
    }

    case 5:
    {
        printf("enter profit: ");
        fflush(stdin);
        scanf("%d",&newBUFF4);
        temp25->profitYEAR5 = newBUFF4;
        break;
    }
        // default:
        //break;

    }

}

void EDITprofit3(business *temp26)
{


    int newBUFF5;
    printf("enter profit: ");
    fflush(stdin);
    scanf("%d",&newBUFF5);
    temp26->profitYEAR1 = newBUFF5;

    printf("enter profit: ");
    fflush(stdin);
    scanf("%d",&newBUFF5);
    temp26->profitYEAR2 = newBUFF5;

    printf("enter profit: ");
    fflush(stdin);
    scanf("%d",&newBUFF5);
    temp26->profitYEAR3 = newBUFF5;

    printf("enter profit: ");
    fflush(stdin);
    scanf("%d",&newBUFF5);
    temp26->profitYEAR4 = newBUFF5;

    printf("enter profit: ");
    fflush(stdin);
    scanf("%d",&newBUFF5);
    temp26->profitYEAR5 = newBUFF5;
    printf("done \n");
}

void EDITdate(business *temp27)
{
    int legit=0;
    char newBUFF6[40];
    int daysinmonth1[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("enter new date : ");
    fflush(stdin);
    scanf("%s",newBUFF6);
    DATE(newBUFF6);
    if((year % 400 == 0 ) || (year %4 == 0 ))
        daysinmonth1[1]=29;

    if (month<13 && month>0)
    {
        if( day <= daysinmonth1[(month)-1] )
            legit=1;
    }
    if (legit==0)
    {
        printf("It's not a legitimate date! \n");
        printf("Please again. ");

    }
    else
        strcpy(temp27->date , newBUFF6);
}


void DATE(char *buffDATE)
{
    char mas1DATE[10],mas2DATE[10],mas3DATE[10];
    int i=0,j=0;
    while( (buffDATE[i]!='.'))
    {
        mas1DATE[j] = buffDATE[i];
        i++;
        j++;

    }
    i++;
    j=0;
    while( (buffDATE[i]!='.'))
    {
        mas2DATE[j] = buffDATE[i];
        i++;
        j++;
    }
    i++;
    j=0;
    while(buffDATE[i]!='\0')
    {
        mas3DATE[j] = buffDATE[i];
        i++;
        j++;

    }

    year=atoi(mas1DATE);
    day=atoi(mas2DATE);
    month=atoi(mas3DATE);
}

business *INTERVAL(business **head)
{
    if(*head!=NULL)
    {
        double x,y,sum=0;
        double sum5;
        int true10=0;
        printf("Enter interval x :");
        fflush(stdin);
        scanf("%lf" ,&x);
        printf("Enter interval y :");
        fflush(stdin);
        scanf("%lf" ,&y);
        business *temp41;
        for(temp41=*head; temp41 != NULL ; temp41 = temp41->pointer)
        {
            sum=temp41->profitYEAR1+temp41->profitYEAR2+temp41->profitYEAR3+temp41->profitYEAR4+temp41->profitYEAR5;
            sum5=sum/5;
            if((sum5 > x) && (sum5 < y))
            {
                printf("ID: %li name: %s profit current %0.2lf another years %0.2lf \n  %0.2lf  %0.2lf  %0.2lf  date of registration %s \n\n", temp41->code,temp41->name,temp41->profitYEAR1,temp41->profitYEAR2,temp41->profitYEAR3,temp41->profitYEAR4,temp41->profitYEAR5,temp41->date);
                true10=1;
            }


        }
        if(true10==0)
            printf("there is not any business in the interval \n");

    }
    else
        printf("the list is empty");

}

void printLIST(business **head)
{
    if(*head!=NULL)
    {


        business *temp0;
        long IDD;
        int true00=0;
        printf("Enter EIK: ");
        fflush(stdin);
        scanf("%li",&IDD);


        for( temp0=*head; temp0!=NULL; temp0=temp0->pointer)
        {
            if(IDD == temp0->code)
            {
                printf("ID: %li name: %s profit current %0.2lf another years %0.2lf \n  %0.2lf  %0.2lf  %lf  date of registration %s \n\n", temp0->code,temp0->name,temp0->profitYEAR1,temp0->profitYEAR2,temp0->profitYEAR3,temp0->profitYEAR4,temp0->profitYEAR5,temp0->date);
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

void writeFILE(business **head)
{
    FILE *fp2;
    fp2=fopen("businessInfo.txt","wb");
    business *temp44;
    if(*head != NULL)
    {
        for (temp44 = *head; temp44!=NULL; temp44=temp44->pointer)
        {


            if((fwrite(&(temp44->code),sizeof(long),1,fp2))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            if((fwrite(temp44->name,sizeof(char),40,fp2))!=40)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            if((fwrite(&(temp44->profitYEAR1),sizeof(double),1,fp2))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            if((fwrite((&temp44->profitYEAR2),sizeof(double),1,fp2))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            if((fwrite((&temp44->profitYEAR3),sizeof(double),1,fp2))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            if((fwrite((&temp44->profitYEAR4),sizeof(double),1,fp2))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }

            if((fwrite((&temp44->profitYEAR5),sizeof(double),1,fp2))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }

            if((fwrite(temp44->date,sizeof(char),30,fp2))!=30)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
        }

        fclose(fp2);
        printf("list saved!! \n\n");
    }
    else
        printf("Error with the list \n");

}

void MEMORYfree(business **head)
{
    if(*head!=NULL)
    {
        business *temp77;
        while( temp77 != NULL)
        {
            *head=temp77->pointer;
            free(temp77);
            temp77 = *head;
        }
        *head=NULL;
    }

}
