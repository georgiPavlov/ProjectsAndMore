#ifndef H10_H_INCLUDED
#define H10_H_INCLUDED
typedef struct wt
{
    long code;
    char name[50];
    double price;
    int amount;
    char date[30];
} warehouseTEMP;

typedef struct w
{
    long code;
    char name[50];
    double price;
    int amount;
    char date[30];
    struct w *pointer;
} wareHOUSE;

int menu();
void readFile(wareHOUSE **head);
wareHOUSE *insertLAST(wareHOUSE **head, warehouseTEMP info);
wareHOUSE *last(wareHOUSE **head);
wareHOUSE *ADDinLAST(wareHOUSE **head);
wareHOUSE *EDIT(wareHOUSE **head);
wareHOUSE *remove1(wareHOUSE *temp33,wareHOUSE *p,wareHOUSE **head);
wareHOUSE *old(wareHOUSE **head);
void printLIST(wareHOUSE **head);
void writeSEARCH(wareHOUSE **head);
void writeFILE(wareHOUSE **head);
void MEMORYfree(wareHOUSE **head);
void DATE(char *buffDATE);
int year,month,day;


#endif // H10_H_INCLUDED
