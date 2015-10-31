/*Група А.
1. (10 точки). Създайте структура телевизор, съдържаща информация за цена, големина на екрана и производител.
 Създайте елемент на списък със същата информация. Напишете функция, която чете информация за телевизори от
двоичен файл и ги добавя в списъка. Името на файла е параметър на функцията.
2. (10 точки). Напишете функция minPriceTV, която намира телевизора с минимална цена и я връща.............г
Напишете функция, която връща броя на телевизорите с цена, по-малка от 3*min (min е минималната цена в
списъка като използвате написаната функция minPriceTV) и големина на екрана, предадена като параметър.
3. (10 точки). Дефинирайте функция, която създава списък на телевизори от зададен,
като параметър, производител. Запишете списъка в двоичен файл посредством функция.
4. (10 точки). Напишете функция, която изтрива всички телевизори, които имат зададени,
като параметри, производител и цена.*/


#include <stdio.h>
#include <stdlib.h>

typedef struct tv1
{
    double price;
    int inch;
    char mnf[20];
} TVt;

typedef struct tv2
{
    double price;
    int inch;
    char mnf[20];
    struct tv2 *pointer;
} TV;

main()
{
    TV *headFINAL=readFILE("fileANGEL");
}


TV *readFILE(char *fname)
{
    TV *head=NULL;
    TV *temp1=(TV*)malloc(TV*);
    FILE *fp;
    if((fp=fopen(fname,"rb"))==NULL);
    printf("THE file is empty \n");
    else
    {
        while(!feof(fp))
        {
            fread(temp1->price,sizeof(double),1,fp);
            fread(temp1->inch,sizeof(int),1,fp);
            fread(temp1->mnf,sizeof(char)*20,1,fp);
            if(head==NULL)
            {
                temp1->pointer=NULL;
                head=temp1;
            }
            else
            {
                temp1->pointer=head;
                head=temp1;
            }
        }

    }
    fclose(fp);

    return head;
}

double minPriceTV(TV *head)
{
    if(head!=NULL)
    {
        TV *temp2;
        double Tprice;
        Tprice=head->price;
        for(temp2 = head; temp3!=NULL; temp2=temp2->pointer)
        {
            if(Tprice>temp2->price)
                Tprice=temp2->price;
        }
        return Tprice;

    }
    else
    {
        printf("list is empty");
        return 0;
    }
}

int minPriceCount(TV *head,int Tinch)
{
    if(head!=NULL)
    {
        TV *temp3;
        double min = minPriceTV(head);
        int count=0;
        for(temp3 = head; temp3!=NULL; temp3=temp2->pointer)
        {
            if(Tinch == temp3 &&  temp3-price<(min*3))
                count++;
        }
        return count;


    }
    else
    {
        printf("list is empty");
        return 0;
    }
}

TV *alternativeLIST(TV *head,char *sname)
{

    if(head!=NULL)
    {
        TV *head1=NULL;
        TV *temp4;

        for(temp4 = head; temp4!=NULL; temp4=temp4->pointer)
        {
            if(!strcmp(sname,temp4->mnf))
            {
                if(head1==NULL)
                {
                    temp4->pointer=NULL;
                    head1=temp4;
                }
                else
                {
                    temp4->pointer=head1;
                    temp4=head1;
                }
                WRITEfile(head1);
            }



        }
        return head1;


    }
    else
    {
        printf("list is empty");
        return 0;
    }


}


void WRITEfile(TV *temp4)
{


    FILE *fp;
    fp=fopen("temp","ab")

        write(temp4->price,sizeof(double),1,fp);
        write(temp4->inch,sizeof(int),1,fp);
        write(temp4->mnf,sizeof(char)*20,1,fp);
        fclose(fp);



}

TV *remove(TV *head,char *mnfTEMP,char *priceTEMP)
{
    if(head!=NULL)
    {
        TV *temp5,*temp6;
        for(temp5=head; temp5!=NULL; temp5=temp5->pointer)
        {

            if(!strcmp(mnfTEMP,temp5->mnf) && priceTEMP==temp5->price)
            {
                if(temp5==head)
                {
                    if(temp5->pointer!=NULL)
                    {
                        head=head->pointer;
                        free(temp5);
                        temp5=head;
                    }
                    else
                    {
                        head=NULL;
                        free(temp5);

                    }
                }
                else if(temp5->pointer==NULL)
                {
                    head=NULL;
                    free(temp5);

                }
                else
                {
                    temp6->pointer=temp5->pointer;
                    free(temp5);
                    temp5=temp6;

                }
            }
            temp6=temp5;

        }

        return head;


    }
    else
    {
        printf("list is empty");
        return 0;
    }

}






int main()
{
    printf("Hello world!\n");
    return 0;
}
