#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void writeFILE(carMEMORY **head)
{
    FILE *fp1;
  fp1=fopen("carAuto.txt","wb");
  carMEMORY *temp4;
  if(*head != NULL)
  {
   for (temp4 = *head;temp4!=NULL;temp4=temp4->pointer)
    {
   fwrite(temp4->code,sizeof(char)*20,1,fp1);
   fwrite(temp4->color,sizeof(char)*20,1,fp1);
   fwrite(&(temp4->engine),sizeof(double),1,fp1);
   fwrite(temp4->mark,sizeof(char)*20,1,fp1);
   fwrite(&(temp4->price),sizeof(double),1,fp1);
   }
  fclose(fp1);
  printf("list saved!! \n\n");
  }
  else
  printf("Error with the list \n");
}
