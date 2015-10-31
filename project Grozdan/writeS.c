#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"h10.h"

void writeSEARCH(wareHOUSE **head)
{
    if(*head!=NULL)
    {
        FILE* fp2;
        char buffFILE[20];
        long buffID;
        printf("enter file name: ");
        fflush(stdin);
        scanf("%s",buffFILE);
        fp2=fopen( buffFILE,"wb");
        printf("ENTER  ID: ");
        fflush(stdin);
        scanf("%li",&buffID);
        wareHOUSE *tempW;
        for(tempW=*head; tempW!=NULL; tempW=tempW->pointer)
        {
            if(buffID == tempW->code)
            {


                if((fwrite(&(tempW->code),sizeof(char)*20,1,fp2))!=1)
                {
                    printf("file error \n");
                    MEMORYfree(head);
                    exit(1);
                }
                if((fwrite(tempW->name,sizeof(int)*50,1,fp2))!=1)
                {
                    printf("file error \n");
                    MEMORYfree(head);
                    exit(1);
                }
                if((fwrite((&tempW->price),sizeof(int),1,fp2))!=1)
                {
                    printf("file error \n");
                    MEMORYfree(head);
                    exit(1);
                }
                if((fwrite((&tempW->amount),sizeof(int),1,fp2))!=1)
                {
                    printf("file error \n");
                    MEMORYfree(head);
                    exit(1);
                }
                if((fwrite(tempW->date,sizeof(double)*30,1,fp2))!=1)
                {
                    printf("file error \n");
                    MEMORYfree(head);
                    exit(1);
                }

                fclose(fp2);
                printf("recorded \n");
                break;
            }
        }

    }
    else
        printf("the list is empty \n");
}
