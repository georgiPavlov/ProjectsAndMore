#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int a;
    struct Node* next;
};

struct Node* head;
struct Node* current;
void Insert (int x);
void Printf ();
void iztrivane();

int main()
{
    int n,i,x,m;
    head=NULL;
    printf("kolko chisla\n");
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {

        printf("vuvedete chislo");
        scanf("%d",&x);
        Insert (x);
        Printf();

    }
   printf("koi elemnt iskash da se iztrie");
   scanf("%d",&m);
   iztrivane(m);
    return 0;
}

void Insert (int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    if (head==NULL)
    {
        head=temp;
        current=head;
        current->a=x;
        current->next=NULL;
    }
    else
    {
        current->next=temp;
        current=temp;
        current->a=x;
        current->next=NULL;
    }
}

void Printf()
{
    struct Node * p =head;
    printf("list is: ");
    while(p!=NULL)
    {
        printf("%d",p->a);
        p=p->next;
    }
    printf("\n");
}

void iztrivane( int m)
{
    int i;
    struct Node*temp;

    for(i=0; i<m; i++)
    {

        current=temp;
        temp=temp->next;
        current->next=temp->next;
        free(temp);

          //temp->next=NULL;




    }


}
