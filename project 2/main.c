#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
1. Създайте структура студент, съдържаща име, фак.номер и среден успех.
 exit  Създайте елемент на списък от тази структура. Създайте функция за изтриване на списъка.
2. Създайте функция за четене на списъка от текстов файл с параметър име на файла.
3. Създайте функция, връщаща средния успех на студентите в списъка.
4. Създайте функция за добавяне на един студент към списъка.
5. Създайте функция за запис на информационната част на списъка в текстов файл.
6. Напишете main като дефинирате главата на списъка в нея и напишете меню за избор на функциите.

Всяка функция трябва да проверява за коректност и отпечатва съобщения за грешки,
а main да въвежда необходимите данни за тестване от екрана.
*/

typedef struct studentT
{
    char name[30];
    int number;
    double grade;


}studentIN;

typedef struct student
{
    char name[30];
    int number;
    double grade;
    struct student *pointer;

}studentM;

char nameT[200];

int menu();
void input();
void readFILE(studentM **head,char name[30]);
studentM *insertFILE(studentIN temp1,studentM **head);
float gradeM(studentM**head);
void message(double av);
studentM* ADD(studentM  **head);
void fileWRITE(studentM **head);
studentM *FREE(studentM **head);


int main()
{
   studentM *head=NULL;
   int key;
   double ave;
   do
    {
    key=menu();
    switch(key)
    {
    case 1:
        {
          input();
         readFILE(&head,nameT);
         break;
        }
    case 2:
        {
          ave=gradeM(&head);
          message(ave);
          break;
        }
    case 3:
        {
        ADD(&head);
        break;
        }
    case 4:
        {
        fileWRITE(&head);
        break;
        }
    case 5:
        {
         FREE(&head);
         break;
        }
    }

    } while(key>0 && key<6);
    return 0;
}

int menu()
{
    int result;
           printf("List menu\n");
        printf("1. Read Student List from File\n");
        printf("2. Find average mark of all student marks\n");
        printf("3. Insert a student data into List\n");
        printf("4. Write Student List into Text File\n");
        printf("0. Exit\n");
        printf("Your choice: ");
    scanf("%d",&result);
    return result;

}
void input()
{
   printf("ENTER name of FILE \n");
   scanf("%s",nameT) ;
}
void readFILE(studentM **head,char name[30])
{

   studentIN temp;


   FILE* fp;
   fp = fopen("name22.txt","r+");
if(fp!=NULL){
   while(!feof(fp))
   {

   fread(temp.name,sizeof(char),10,fp);
   fread(&(temp.number),sizeof(int),1,fp);
   fread(&(temp.grade),sizeof(double),1,fp);
   insertFILE(temp,head);


   }}
   else
    printf("no file \n\n");
    fclose(fp);

}

studentM *insertFILE(studentIN temp1,studentM **head)
{

  studentM *tempM = (studentM*)malloc(sizeof(studentM));

  strcpy( tempM->name,temp1.name);
  tempM->number = temp1.number;
  tempM->grade = temp1.grade;

  if(*head == NULL)
  {

    *head=tempM;
    tempM->pointer = NULL;
  }
  else
  {
    tempM->pointer = *head;
    *head=tempM;
  }
  return *head;

}

float gradeM(studentM **head)
{
  int true=0;
  double sum=0;
  int count1=0;
  studentM *temp2;
  for(temp2=*head;temp2!=NULL;temp2=temp2->pointer)
  {

      sum=sum+ temp2->grade;
      count1++;
      true=1;
  }
    if(true==0)
    {
        printf("error \n");
        return 0;
    }

  return sum/count1;

}
void message(double av)
{
    printf("average is : %lf \n ",av);

}

studentM* ADD(studentM **head)
{
    studentM* temp4=(studentM*)malloc(sizeof(studentM));


    printf("enter name \n");
    scanf("%s",temp4->name);
    printf("enter number \n");
    scanf("%d",&(temp4->number));
    printf("enter grade \n");
    scanf("%lf",&(temp4->grade));

     if(*head == NULL)
  {

    temp4->pointer = NULL;
    *head=temp4;
  }
  else
  {

    temp4->pointer = *head;
    *head=temp4;

  }


   return *head;

}

void fileWRITE(studentM **head)
{

   studentM *temp3;
   char buffer[30];
   int true3=0;
   FILE *fp;
   temp3=*head;
   fp = fopen("name22.txt","w");
   printf("enter name \n");
   scanf("%s",buffer);
   //for(temp3=*head;temp3!=NULL;temp3=temp3->pointer)
   //{
       //if(!strcmp(buffer,temp3->name))
       // {




           fwrite(temp3->name,sizeof(char),30,fp);
          fwrite(&temp3->number,sizeof(int),1,fp);
        fwrite(&temp3->grade,sizeof(double),1,fp);
           printf("job done!!\n\n");




        //}
   // }



fclose(fp);
}

studentM *FREE(studentM **head)
{
    studentM* temp4;
    studentM* temp5;
    if(head=!NULL)
    {
     for(temp4=*head;temp4!=NULL;)
       {
       temp5=temp4;
       temp4=temp4->pointer;
       free(temp5);
       }
    }
    else
    printf("list is empty \n");


}


