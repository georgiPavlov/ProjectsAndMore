#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    char string[] = argv[1];
    char string2[] = argv[2];
    int *a;
    char *string3;
    double *b;
    float *c;
    int i=1;
    char t=0;
    int f=1;
    a=(int*)malloc(sizeof(int));
    b=(double*)malloc(sizeof(double)*i);
    c=(float*)realloc(c,sizeof(float)*i);
    string3=(char*)malloc(sizeof(char)*a);




    FILE* fp;

    if(fp=fopen(string,"rb")==NULL)
    {
        printf("err");
        exit (1);
    }
    while(!feof(fp))
    {
        a=(int*)realloc(a,sizeof(int)*i+1);
        fread(&a[i],sizeof(int),1,fp);

        fread(string3[t],sizeof(char)*a,1,fp);
        t=t+a[i];
        string3=(char*)realloc(string3,sizeof(char)*t);
        b=(double*)realloc(b, sizeof(double)*i);
        fread(&b[i],sizeof(double),1,fp);
        c=(float*)realloc(c,sizeof(float)*i);
        fread(&c[i],sizeof(float),1,fp);
        i++;
    }
    fclose(fp);
    int temp=i;
    remove(string);
    FILE* fp1;
    int o=0;

    char x;
    for(;x=string[o];o++)
    {


        f++;
        if(x=='.' )
        {

            if(!strcmp(string2,"abc"))
            {
                string[f]='/0'
                strcat(string,"abc");


                t=0;
                fp1=fopen(string,"wb");
                for(i=0; i<temp; i++)
                {

                    c=(float*)realloc(c,sizeof(float)*i);
                    write(&c[i],sizeof(float),1,fp);
                    b=(double*)realloc(b,sizeof(double)*i);
                    fwrite(&b[i],sizeof(double),1,fp);
                    a=(int*)realloc(a,sizeof(int)*i);
                    fwrite(&a[i],sizeof(int),1,fp);
                    string3=(char*)realloc(string3,sizeof(char)*t);
                    t=t+a[i];
                    fwrite(string3[t],sizeof(char)*a,1,fp);


                }

                if(!strcmp(string2,"xyz"))
                {
                    ;
                    string[f]='/0'
                    strcat(string,"xyz");
                    //strcpy(string+h, "xyz");

                    t=0;
                    fp1=fopen(string,"wb");
                    for(i=0; i<temp; i++)
                    {

                        c=(float*)realloc(c,sizeof(float)*i);
                        fwrite(&c[i],sizeof(float),1,fp);
                        a=(int*)realloc(a,sizeof(int)*i);
                        fwrite(&a[i],sizeof(int),1,fp);
                        t=t+strlen(string3);
                        string3=(char*)realloc(string3,sizeof(char)*t);
                        fwrite(string3[t],sizeof(char)*a,1,fp);
                        b=(double*)realloc(b,sizeof(double)*i);
                        fwrite(&b[i],sizeof(double),1,fp);

                    }



                }

            }


}
