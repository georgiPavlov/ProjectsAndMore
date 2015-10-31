#include <stdio.h>
#include <stdlib.h>
struct test1

{
    long  b;
};

struct test
{
    long  a;
};

int main()
{
    FILE *fp;
    int i;
    struct test1 das[1000];
    struct test asd[1000];
    fp=fopen("test","wb");
    if(fp==NULL)
    {
        printf("ne otvori");
        exit(1);
    }
    asd[0].a=1000;

    for(i=1; i<1001; i++)
    {


        asd[i].a=(asd[i-1].a)+1;
        printf("%li \n", asd[i].a);
        if(fwrite(&asd[i].a,sizeof(long),1,fp)!=1)
        {
            printf("Ne zapisva deba");
            exit(2);
        }
    }
    fclose(fp);
    fp=fopen("test","rb");
    i=0;
    for(i=0; i<1000; i++)
    {
        fread(&das[i].b,sizeof(long),1,fp);
        printf("%li \n", das[i].b);
    }

    fclose(fp);
}
