#include <stdio.h>
#include <stdlib.h>

typedef struct one
{
    int data;
    struct ine *pointer;
}onetwo;

void add(onetwo **head);
void readF(onetwo **head);
void W(onetwo **head);

int main()
{
    onetwo *head=NULL;
    add(&head);
    add(&head);

    readF(&head);
    readF(&(head->pointer));

     W(&head);


    printf("Hello world!\n");
    return 0;
}

void add(onetwo **head)
{
    onetwo *temp = (onetwo*)malloc(sizeof(onetwo));
    printf("enter data \n");
    scanf("%d",&(temp->data));
    if(*head==NULL)
    {
        temp->pointer=NULL;
        *head=temp;
    }
    else
    {
        temp->pointer=*head;
        *head=temp;
    }


}

void readF(onetwo **head)
{
    onetwo *temp = *head;
    FILE *fp=fopen("11111textdfg44g4fvggffgdfffgkghwee1","ab");
    fwrite(&temp->data,sizeof(int),1,fp);
    fclose(fp);

}

void W(onetwo **head)
{
   onetwo *temp = (onetwo*)malloc(sizeof(onetwo));
   int i=0;
   FILE *fp1=fopen("11111textdfg44g4fvggffgdfffgkghwee1","rb");
   while(1)
   {
     if(feof(fp1))
        break;
     fread(&temp->data,sizeof(int),1,fp1);
     printf("%d \n",temp->data);
     i++;

   }
   fclose(fp1);
}

