
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"h10.h"

void writeFILE(wareHOUSE **head)
{
    FILE *fp2;
    fp2=fopen("warehouseInfo.txt","wb");
    wareHOUSE *temp44;
    if(*head != NULL)
    {
        for (temp44 = *head; temp44!=NULL; temp44=temp44->pointer)
        {


            if((fwrite(&(temp44->code),sizeof(char)*20,1,fp2))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            if((fwrite(temp44->name,sizeof(int)*50,1,fp2))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            if((fwrite((&temp44->price),sizeof(int),1,fp2))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            if((fwrite((&temp44->amount),sizeof(int),1,fp2))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            if((fwrite(temp44->date,sizeof(double)*30,1,fp2))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }

        }
        fclose(fp2);
        printf("list saved!! \n\n");
    }
    else
        printf("Error with the list \n");

}
