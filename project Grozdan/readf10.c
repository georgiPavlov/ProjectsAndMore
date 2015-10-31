#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"h10.h"

void readFile(wareHOUSE **head)
{
    warehouseTEMP infoTEMP;
    FILE *fp = fopen("warehouseInfo","rb");
    if(fp != NULL)
    {
        while(!feof(fp))
        {
            if((fread(&(infoTEMP.code),sizeof(long),1,fp))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            if((fread(infoTEMP.name,sizeof(int)*50,1,fp))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            if((fread((&infoTEMP.price),sizeof(int),1,fp))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            if((fread((&infoTEMP.amount),sizeof(int),1,fp))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            if((fread(infoTEMP.date,sizeof(double)*30,1,fp))!=1)
            {
                printf("file error \n");
                MEMORYfree(head);
                exit(1);
            }
            insertLAST(head,infoTEMP);

        }
    }
    fclose(fp);
}
