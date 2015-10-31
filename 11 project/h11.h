#ifndef H11_H_INCLUDED
#define H11_H_INCLUDED
typedef struct ft
{
    long code;
    char name[40];
    double profitYEAR1;
    double profitYEAR2;
    double profitYEAR3;
    double profitYEAR4;
    double profitYEAR5;
    char date[30];
} businessTEMP;

typedef struct f
{
    long code;
    char name[40];
    double profitYEAR1;
    double profitYEAR2;
    double profitYEAR3;
    double profitYEAR4;
    double profitYEAR5;
    char date[30];
    struct f *pointer;
} business;


int menu();
void readFile(business **head);
business *insertLAST(business **head, businessTEMP info);
business *last(business **head);
business *ADDinLAST(business **head);
business *EDIT(business **head);
int menu2();
void EDITeik(business *temp21);
void EDITname(business *temp22);
int EDITprofit(business *temp23);
int menu3();
void EDITprofit1(business *temp24);
void EDITprofit2(business *temp25);
void EDITprofit3(business *temp26);
void EDITdate(business *temp27);
void DATE(char *buffDATE);
business *INTERVAL(business **head);
void printLIST(business **head);
void writeFILE(business **head);
void MEMORYfree(business **head);


#endif // H11_H_INCLUDED
