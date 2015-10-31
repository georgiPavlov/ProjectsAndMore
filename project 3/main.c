#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct marketT
{
    int ID;
    char name [20];
    char adress[20];
    int number;
    double price;
} market;


void readFILE(int a,int num,double priceT);
void input();
int compare(int b,int numTemp,double priceTT,market temp);
void WRITEfile(market t[],int u);

int main(int argc, char* argv[])
{
    int c = atoi(argv[1]);
    int nn = atoi(argv[2]);
    double pr = atof(argv[3]);
    readFILE(c,nn,pr);
}

void readFILE(int a,int num,double priceT)
{
    market *mfile=(market*)sizeof(market);
    market tt;
    FILE* fp;
    int i=1;
    int true1=0;
  x=string[o];
  int v=0;

    fp=fopen("client.dat","rb");
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
            fread(&(mfile[v].ID),sizeof(int),1,fp);
            fread((mfile[v].name),sizeof(char),20,fp);
            fread((mfile[v].adress),sizeof(char),20,fp);
            fread(&(mfile[v].number),sizeof(int),1,fp);
            fread(&(mfile[v].price),sizeof(double),1,fp);
            tt=mfile[v];
            compare(a,num,priceT,tt);



            i++;
            v++;
            mfile=(market*)realloc(mfile,sizeof(market)*i );

        }
        WRITEfile(mfile,v);


    }
    else
        printf("ERROR");
    fclose(fp);
}

int compare(int b,int numTemp,double priceTT, market temp)
{
    if(!strcmp(b,temp.ID))
    {
        if(temp.price>=1000 && temp.price<=5000)
        {
            int temp1=priceTT*5/100;
            priceTT=priceTT -temp1;
            printf("THE NEW PRICE IS %0.2lf",priceTT);
            temp.price=temp.price+priceTT;
        }
        else if(temp.price>=5000)
        {
            int temp2=priceTT*10/100;
            priceTT=priceTT-temp2;
            printf("THE NEW PRICE IS %lf",priceTT);
            temp.price=temp.price+priceTT;
        }
        else
        {
            temp.price=temp.price+priceTT;
            printf("THE PRICE IS %lf",priceTT);
        }
        return 1;
    }
    return 0;
}

void WRITEfile(market t[],int u)
{

    FILE* fp;
    fp=fopen("client.dat","wb");
       if(fp!=NULL)
    {
        int j=0;
        for(j=0; j<u; j++)
        {
            fwrite(&(t[j].ID),sizeof(int),1,fp);
            fwrite((t[j].name),sizeof(char),20,fp);
            fwrite((t[j].adress),sizeof(char),20,fp);
            fwrite(&(t[j].number),sizeof(int),1,fp);
            fwrite(&(t[j].price),sizeof(double),1,fp);

        }
    }
}

