#include <stdio.h>
#include <stdlib.h>

void subirane();// ot 4-ti do 9ti red deklarirame razlichnite funkcii
void izvajdane();
void umnojenie();
void delenie();
void izhod();
int menu();//9-ti i 10-ti globalni promenlivi
float c, sht;


int main()
{

    int izbor1;//promenlica za sluchaite

    do
    {
        izbor1=menu();//prisvoqvame vurnatata sloinost ot menu na izbor1
        switch (izbor1)
        {
        case 1:
        {
            subirane();
            break;

        }
        case 2:
        {
            izvajdane();
            break;
        }
        case 3:
        {
            umnojenie();
            break;
        }
        case 4:
        {
            delenie();
            break;
        }
        case 5:
            {
                izhod();
                break;
            }
        default:
            printf("greshka");
            break;
        }
    }
    while (izbor1 != 5);
    return 0;
}

void subirane()
{
    float b=0;
    b= c + sht ;
    printf("rezultata e %0.2f \n",b);



}
void izvajdane()
{
    float a=0;
    if(c>sht)//proverka za polojitelen rezultata v protiven sluchai vrushta nerealni stoinosti
        a=c-sht;
    else
        a=sht-c;
    printf("rezultata e %0.2f \n",a);//printira rezultata s tochnost do 0.1

}
void umnojenie()
{
    float y=0;
    y=c*sht;
    printf("rezultata e %0.2f \n",y);

}
void delenie()
{
    float r=0;
    r=c/sht;
    printf("rezultata e %0.2f \n",r);

}
void izhod()
{
    printf("Buy buy :) \n");
    exit(1);
}

int menu()
{

    int izbor;
    printf("Programa Za Presmqtane\n\n");

    printf("Izberete purvoto chislo\n");
    scanf("%f", &c);                     //prisvoqvame stoinostite vuvedeni ot klaviaturata na globalnite promenlivi
    printf("izberete vtoroto chislo\n");
    scanf("%f", &sht);


    printf("MENU\n\n");
    printf("1.Subirane\n");
    printf("2.Izvajdane\n");
    printf("3.Umnojenie\n");//
    printf("4.Delenie\n");
    printf("5.izhod\n");
    scanf("%d", &izbor);
    return izbor;
}
