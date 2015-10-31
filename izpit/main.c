/*1. Създайте структура студент, съдържаща информация за име, фак. номер и среден успех на студента.
Създайте елемент на списък със същата информация. Напишете функция, която изтрива всички елементи на списъка. */

typedef struct student
{
    char name[];
    long number;
    float mark;
} str;


typedef struct student2
{
    char name[];
    long number;
    float mark;
    struct student2 *next;
} st;


st *del(**head)
{
    if(*head!=NULL)
    {
        st *p;
        st *temp;
        p=*head;
        while(p!=NULL)
        {

            temp=p;
            p=p->next;
            free(temp);
        }
    }
    return *head;
}




