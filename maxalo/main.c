#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int menu();
double engine(double l,double g ,int PART);//��������� ������ ������� �� �������,���������� �� ����������� �������,���� �� ��������(180)

int main()
{
   int key=0;
   int part;
   double L;//������ ��� ���������� �� ���� ,����� ����� �� �������� �� ����������� � �������� �� ����������� �������
   double speed;//���� ���������� ������� ��������� �������� �� ������� engine
do
 {
    printf("ENTER THE LENGHT OF THREAD: \n");
    scanf("%lf",&L);
    printf("ENTER THE PART 1,2,3,4,5 of movement: \n");
    scanf("%d",&part);

       key = menu();//�� � ��������� �������� !!!
       switch (key)
       {
         case 1:
        {
          speed = engine(L,9.8,part);
          printf("THE  SPEED IN THIS PART: %lf \n\n",speed);
          break;
        }

        case 2:
        {
        speed = engine(L,3.26,part);
        printf("THE  SPEED IN THIS PART: %lf \n\n",speed);
        break;
        }

        case 3:
        {
        speed = engine(L,3.23,part);
        printf("THE  SPEED IN THIS PART: %lf \n\n",speed);// �� ��� �������� �� ����� ,�� ������������ �� ���� � ������� � � ������� ���� ������� � 1/3 �� ������� ,�� �� ������� �� ����� ���������.
        break;
        }
      }
  }while(key>0 && key<4 );
  return 0;
}

int menu()
{
    int result;
    printf("planet EARTH:1 \n");
    printf("planet MARS:2 \n");
    printf("planet MERCURY:3 \n");
    printf("ENTER 1,2 or 3 \n");
    scanf("%d",&result);
    return result;// ��� ������ � ���� ��� ���������
}

double engine(double l,double g,int PART)
{
  double minSPEED = 0;//���������� ����������� ������� 0 ��� 180 �������
  double maxSPEED;//���������� ��������� ������� 90 �������
  double max = 2*l*g;// ���������� ������� ����� �� ������� ������ ������� � ��������� �� ������� ��+��=const ,��� ���� ������� �� � ���� � ��� 90 �� � ���� ,������������ � ���������� ������� �� �������� �� ������!
  maxSPEED = sqrt(max);// ������ ��������
  double averageSPEED = maxSPEED/2;//������� ��� 45 �������
  double averageSPEED2=averageSPEED/2;//��������� ��� 22.5 �������
  double averageSPEED3=averageSPEED2/2;//��������� ��� 11.25 ������� �������� 1 � 5

  if(PART == 1 || 5)
   return averageSPEED3;
  else if(PART == 2||4)
   return averageSPEED;
  else if(PART == 3)
   return maxSPEED;//��� ������ � ����

}
//�� �������!!!!!!
