#ifndef H24FINAL_H_INCLUDED
#define H24FINAL_H_INCLUDED
typedef struct input
{
    char path[50];
    char name[20];
    double sizef;
    char dateMAKE[20];
    int dateMOD[20];
    char flag [20];

} fileTEMP;


typedef struct f
{
    char path[50];
    char name[20];
    double sizef;
    char dateMAKE[20];
    int dateMOD[30];
    char flag [20];
    struct f *pointer;
} fileMEMORY;

void DATE(char *buffDATE);
int year,month,day;
fileMEMORY *ADDinLAST(fileMEMORY **head);
fileMEMORY *last(fileMEMORY **head);
void readFile(fileMEMORY **head);
fileMEMORY *insertLAST(fileMEMORY **head, fileMEMORY info);
void writeFILE(fileMEMORY **head);
void printLIST(fileMEMORY **head);
void MEMORYfree(fileMEMORY **head);
void printPATH(fileMEMORY **head);
int menu();



#endif // H24FINAL_H_INCLUDED
