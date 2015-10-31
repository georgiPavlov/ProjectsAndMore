#include <stdio.h>
#include <stdlib.h>

typedef struct T
{
    double cena;
    int size;
    char producer[20];
} TTV;

typedef struct TVList
{
    double cena;
    int size;
    char producer[20];
    struct TVList *next;
} TTVList;

TTList * readFromFile(char  *fname)
{
    FILE *f;
    TTV temp;
    TTVList *head=NULL,*tList;
    if((f=fopen(fname,"rb"))==NULL)
    {
        printf("ERR \n");
        exit(1);
    }
    while(!feof(f))
    {
        if(fread(&temp,sizeof(TTV),1,f)!=1)
        {
            printf("ERROR \n");
            exit(1);
        }
        tList=(TTVList*)malloc(sizeof(TTVList));
        if(tList==NULL)
        {
            printf("err \n");
            head=delList(head);
            exit(1);
        }
        tList->cena=temp.cena;
        tList->size=temp.size;
        strcpy(tList->produser,temp.producer);
        if(head==NULL)
        {
            head=tList;
            tLIst->next=NULL;
        }
        else
        {
            tLIst->next=head;
            head=tList;
        }
    }
    return *head;
}

double minPriceTV(TTVList *head)
{
    TTVList *p;
    double min=head->cena;
    for(p=head->next;p!=NULL;p=p->next)
    {
        if(p->cena<min)
            min=p->cena;
    }
    return min;
}

int getCount(TTVList *head,int sz)
{
    int cnt=0;
    double price=minPriceTV(head);
    TTVList *p;

    for(p=head;p!=NULL;p=p->next)
    {
        if(p->cena<price && p->size==sz)
            cnt++;
    }
    return cnt;
}

void createTVList(TTVList *head,char *prod)
{
    TTVList *prodTV=NULL;
    TTVList *p;

    for(p=head;p!=NULL;p=p->next)
    {
        if(!strcmp(prod,p->produser))
        {
        temp=malloct(sizeo)
        }
    }



}


int main()
{
    printf("Hello world!\n");
    return 0;
}
