#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct input
{
    char code1[20];
    char color1[20];
    double engine1;
    char mark1[20];
    double price1;
}carIN;

typedef struct caro
{
    char code[20];
    char color[20];
    double engine;
    char mark[20];
    double price;
    struct car *pointer;
}carMEMORY;

int menu();
carMEMORY *insertLAST(carMEMORY **head,carIN info);
carMEMORY *last(carMEMORY **head);
carMEMORY *ADDinLAST(carMEMORY **head);
void readFILE(carMEMORY **head,carIN infoTEMP);
void removeCAR(carMEMORY **head);
carMEMORY *PRINTcarSEARCH(carMEMORY **head,double priceT);
double PRICEcar(carMEMORY **head);
void writeFILE(carMEMORY **head);
void MEMORYfree(carMEMORY **head);

#endif // HEADER_H_INCLUDED
