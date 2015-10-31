
/*Да се разработи програма с меню  тип файлов индексатор. Индексатор на файлове пази списък с файловете на компютъра за по-бързото им търсене, вместо да ги чете папка по папка от хард-диска. Той трябва да има:
1.	Данните за индексираните файловете се съхраняват в двоични файл. Файла започва с броя файлове следван от файловете. За всеки индексиран файл се пазят следните данни:
•	Пълен път (без файла);
•	Име на файл;
•	Размер на файла;
•	Дата на създаване на файла - записана във формата ДД.ММ.ГГГГ.;
•	Дата на модифициране на файла - записана във формата ДД.ММ.ГГГГ.;
•	Флагове: hidden, read-only, system file, executable
2.	Да се извършват следните обработки:
а)  Добавяне на нов файл;
б)  Намиране на даден файл и извеждане на неговите данни;
в) По зададена от потребителя папка, показва колко файла има в нея и колко място заема тя на хардиска (файловете и рекурсивно папките в нея).
3.	Данните да се поддържат в динамична структура – динамично заделен масив или едносвързан списък в оперативната памет на ПК.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "h24final.h"
#define MEMORY 500



int main()
{
    fileMEMORY * head = NULL;

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
            printLIST(&head);
            break;
        }
        case 3:
        {
            printPATH(&head);
            break;
        }

        case 4:
        {
            writeFILE(&head);
            MEMORYfree(&head);
            printf("\n\n           _-_-Goodbye!-_-_\n\n");
            return 0;
        }
        }
    }
    while (key >0 && key <5);
    return 0;
}


int menu()
{
    int result;
    printf("************************* MENU *************************\n\n\n");
    printf("Enter 1 to add path of new file. \n");
    printf("Enter 2 to find file \n");
    printf("Enter 3 to view information about folder. \n");
    printf("Enter 4 to EXIT\n");
    scanf("%d",&result);
    return result;
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

    day=atoi(mas1DATE);
    month=atoi(mas2DATE);
    year=atoi(mas3DATE);
}

fileMEMORY *ADDinLAST(fileMEMORY **head)
{

    fileMEMORY *temp=(fileMEMORY*) malloc(sizeof(fileMEMORY));
    fileMEMORY *lastp;
    fileMEMORY *tempID1;
    int trueID1=0;
    char tc[30];
    int daysinmonth[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int legit = 0;
    int legitdate1 = 0;
    int legitdate2 = 0;



    char buffdate1[30];
    char buffdate2[30];


    printf("Enter path: ");
    fflush(stdin);
    scanf("%s",tc);
    strcpy(temp->path,tc);
    printf("Enter name: ");
    fflush(stdin);
    scanf("%s",temp->name);
    printf("Enter size in megabytes: ");
    fflush(stdin);
    scanf("%lf",&temp->sizef);
    printf("Enter creation date with format !! day.month.year !!: ");
    fflush(stdin);
    scanf("%s",buffdate1);
    printf("Enter the last modified  date with format !! day.month.year !! : ");
    fflush(stdin);
    scanf("%s", buffdate2);


    DATE(buffdate1);

    if((year % 400 == 0 ) || (year %4 == 0 ))
        daysinmonth[1]=29;

    if (month<13 && month>0)
    {
        if( day <= daysinmonth[(month)-1] )
            legitdate1=1;
    }
    if (legitdate1==0)
    {
        printf("It's not a legitimate date! \n");
        printf("Please again. ");

    }

    DATE(buffdate1);

    if((year % 400 == 0 ) || (year %4 == 0 ))
        daysinmonth[1]=29;

    if (month<13 && month>0)
    {
        if( day <= daysinmonth[(month)-1] )
            legitdate2=1;
    }
    if (legitdate2==0)
    {
        printf("It's not a legitimate date! \n");
        printf("Please again. ");
        free(temp);

    }
    if(legitdate1 ==1 && legitdate2==1)
        legit=1;

    if(legit==1)
    {
        int flaglegit=0;
        char b[20];
        strcpy(temp->dateMAKE,buffdate1);
        strcpy(temp->dateMOD,buffdate2);
        printf("Enter flag (hidden, read-only, system-file, executable): ");
        fflush(stdin);
        scanf("%s", b);
        if(!strcmp(b,"hidden"))
        {
            flaglegit=1;
        }
        else if(!strcmp(b,"read-only"))
        {
          flaglegit=1;
        }
        else if(!strcmp(b,"system-file"))
        {
            flaglegit=1;
        }
        else if(!strcmp(b,"executable"))
        {
            flaglegit=1;
        }

        if(flaglegit==1)
        {


            strcpy(temp->flag,b);
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
        else
        {
            printf("flag error \n");
            free(temp);
        }
    }



    return *head;

}

fileMEMORY *last(fileMEMORY **head)
{
    fileMEMORY * temp;
    for (temp = *head; temp->pointer!=NULL; temp=temp->pointer)
        ;
    return temp;
}

void readFile(fileMEMORY **head)
{
    fileMEMORY infoTEMP;
    FILE *fp = fopen("fileInfo","rb");
    if(fp != NULL)
    {
        while(!feof(fp))
        {
            fread(&(infoTEMP.path),sizeof(char)*50,1,fp);
            fread(infoTEMP.name,sizeof(char)*20,1,fp);
            fread((&infoTEMP.sizef),sizeof(double),1,fp);
            fread((&infoTEMP.dateMAKE),sizeof(char)*20,1,fp);
            fread((&infoTEMP.dateMOD),sizeof(char)*20,1,fp);
            fread((&infoTEMP.flag),sizeof(char)*20,1,fp);
            insertLAST(head,infoTEMP);

        }
    }
    fclose(fp);
}

fileMEMORY *insertLAST(fileMEMORY **head, fileMEMORY info)
{
    fileMEMORY *temp1=(fileMEMORY*)malloc(sizeof(fileMEMORY));
    fileMEMORY *lastp1;


    strcpy(temp1->path     ,   info.path);
    strcpy(temp1->name ,  info.name);
    temp1->sizef   =   info.sizef;
    strcpy(temp1->dateMAKE, info.dateMAKE);
    strcpy(temp1->dateMOD, info.dateMOD);
    strcpy(temp1->flag, info.flag);

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

void writeFILE(fileMEMORY **head)
{
    FILE *fp2;
    fp2=fopen("fileInfo","wb");
    fileMEMORY *temp44;
    if(*head != NULL)
    {
        for (temp44 = *head; temp44!=NULL; temp44=temp44->pointer)
        {


            if((fwrite((temp44->path),sizeof(char)*50,1,fp2))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            if((fwrite(temp44->name,sizeof(char)*20,1,fp2))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            if((fwrite((&temp44->sizef),sizeof(double),1,fp2))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }

            if((fwrite(temp44->dateMAKE,sizeof(char)*20,1,fp2))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            if((fwrite(temp44->dateMOD,sizeof(char)*20,1,fp2))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            if((fwrite(temp44->flag,sizeof(char)*20,1,fp2))!=1)
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

void printLIST(fileMEMORY **head)
{
    if(*head!=NULL)
    {


        fileMEMORY *temp0=*head;
        char IDD [20];
        int true00=0;
        printf("Enter name: ");
        fflush(stdin);
        scanf("%s",IDD);


        for( temp0=*head; temp0!=NULL; temp0=temp0->pointer)
        {
            if(!strcmp(IDD , temp0->name))
            {
                printf(" path: %s name: %s size: %lf \n date create: %s  date mod: %s \n flag: %s\n ",temp0->path,temp0->name,temp0->sizef,temp0->dateMAKE,temp0->dateMOD,temp0->flag);
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

void MEMORYfree(fileMEMORY **head)
{
    if(*head!=NULL)
    {
        fileMEMORY *temp77;
        for(; temp77 != NULL ; temp77 = *head)
        {
            *head=temp77->pointer;
            free(temp77);
        }
    }
    *head=NULL;
}

void printPATH(fileMEMORY **head)
{
    if(*head!=NULL)
    {


        fileMEMORY *temp0=*head;
        char PATH1 [20];
        int true00=0;
        printf("Enter path: ");
        fflush(stdin);
        scanf("%s",PATH1);
        int i=0;
        int j=0;
        int c=0;
        double sizeF;
        char pathbuff[50];
        double megabytePART;



        for( temp0=*head; temp0!=NULL; temp0=temp0->pointer)

        {
            strcpy(pathbuff,temp0->path );
            while(PATH1[i]!='\0')
            {
                if(PATH1[i]== pathbuff[j])
                {
                    true00=1;
                }
                else
                {
                    true00=0;
                    break;
                }

                i++;
                j++;
            }
            if(true00==1)
            {
                c++;
                sizeF = sizeF + temp0->sizef;
                i=0;
                j=0;
            }


        }
        if(true00=0)
        {
            printf("there are no files in that path \n");
        }
        else
        {
            megabytePART= (sizeF/(MEMORY*1024))*100;

            printf(" size part (in percents) %0.3lf \n number of files %d \n \n ",megabytePART,c);
        }


    }
    else
    {
        printf("list is empty \n");
    }
}






