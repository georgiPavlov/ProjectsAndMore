#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void readFILE(carMEMORY **head,carIN infoTEMP)
{
  FILE *fp;
  fp=fopen("carAuto.txt","rb");
  if(fp != NULL)
  {
   while(!feof(fp))
    {
   fread(infoTEMP.code1,sizeof(char)*20,1,fp);
   fread(infoTEMP.color1,sizeof(char)*20,1,fp);
   fread(&(infoTEMP.engine1),sizeof(double),1,fp);
   fread(infoTEMP.mark1,sizeof(char)*20,1,fp);
   fread(&(infoTEMP.price1),sizeof(double),1,fp);
   insertLAST(head,infoTEMP);
    }
  }
  fclose(fp);
}
