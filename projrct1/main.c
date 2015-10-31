#include <stdio.h>

#include <stdlib.h>



/*
1. Създайте структура студент, съдържаща име, фак.номер и среден успех.
   Създайте елемент на списък от тази структура. Създайте функция за изтриване на списъка.
2. Създайте функция за четене на списъка от текстов файл с параметър име на файла.
3. Създайте функция, връщаща средния успех на студентите в списъка.
4. Създайте функция за добавяне на един студент към списъка.
5. Създайте функция за запис на информационната част на списъка в текстов файл.
6. Напишете main като дефинирате главата на списъка в нея и напишете меню за избор на функциите.

Всяка функция трябва да проверява за коректност и отпечатва съобщения за грешки,
а main да въвежда необходимите данни за тестване от екрана.
*/


#include <stdio.h>

typedef struct
{
    char name[50];
    unsigned long fnom;
    float avmark;
} student;
typedef struct node
{
    char name[50];
    unsigned long fnom;
    float avmark;
    struct node* next;
} studentList;

typedef enum { false, true } bool;

bool readFromFile(char *fname, studentList** head);
float averageMark(studentList* head);
bool insertStudent(studentList** head, student data);
bool writeIntoFile(char *fname, studentList* head);
void deleteList(studentList**head);




int main(int argc, char *argv[])
{
    char fname[30];
    studentList *head=NULL;
    student temp;
    int choice;

    while(1)
    {
        system("cls");
        printf("List menu\n");
        printf("1. Read Student List from File\n");
        printf("2. Find average mark of all student marks\n");
        printf("3. Insert a student data into List\n");
        printf("4. Write Student List into Text File\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Input text file name: ");
            scanf("%s",fname);
            if (!readFromFile(fname,&head))
            {
                deleteList(&head);
                exit(1);
            }
            printf("Done\n");
            break;
        case 2:
            printf("Average mark of all student marks is %f\n",averageMark(head));
            break;
        case 3:
            printf("Student name: ");
            scanf("%s",temp.name);
            printf("Student fnumber: ");
            scanf("%ld",&temp.fnom);
            printf("Student average mark: ");
            scanf("%f", &temp.avmark);
            if (!insertStudent(&head,temp))
            {
                deleteList(&head);
                exit(1);
            }
            printf("Done\n");
            break;
        case 4:
            printf("Input file name: ");
            scanf("%s",fname);
            if (!writeIntoFile(fname,head))
            {
                deleteList(&head);
                exit(1);
            }
            printf("Done\n");
            break;
        case 0:
            deleteList(&head);
            exit(0);
        default:
            printf("Wrong choice\n");
        }
        fflush(stdin);
        system("PAUSE");
    }
    return 0;
}

bool readFromFile(char *fname, studentList** head)
{
    FILE *file;
    student temp;

    if ((file = fopen(fname,"r")) == NULL)
    {
        printf("Can't open file\n");
        return false;
    }
    while (fscanf(file,"%s%ld%f",temp.name,&temp.fnom,&temp.avmark) != EOF)
    {
        insertStudent(head,temp);
    }
    fclose(file);
    return true;
}

float averageMark(studentList* head)
{
    float avmark=0;
    int cnt=0;
    studentList *p=head;

    for ( ; p!=NULL; p=p->next)
    {
        avmark += p->avmark;
        cnt++;
    }
    return (cnt>0 ? avmark/cnt : 0);
}

bool insertStudent(studentList** head, student data)
{
    studentList *temp = malloc(sizeof(studentList));

    if (temp == NULL)
    {
        printf ("Not enough memory\n");
        return false;
    }
    strcpy(temp->name,data.name);
    temp->fnom = data.fnom;
    temp->avmark = data.avmark;

    if (*head==NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = *head;
    }
    *head = temp;
    return true;
}

bool writeIntoFile(char *fname, studentList* head)
{
    FILE *file;
    studentList *p;

    if (head == NULL)
    {
        printf ("The list is empty\n");
        return false;
    }
    if ((file = fopen(fname,"w")) == NULL)
    {
        printf("Can't open file\n");
        return false;
    }
    for (p=head; p!=NULL; p=p->next)
    {
        fprintf(file,"%s\t%ld\t%f\n",p->name,p->fnom,p->avmark);
    }
    fclose(file);
    return true;
}

void deleteList(studentList**head)
{
    studentList *p, *temp;

    for (p=*head; p!=NULL; )
    {
        temp = p;
        p=p->next;
        free(temp);
    }
    *head = NULL;
}


