#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int menu();
double engine(double l,double g ,int PART);//функцията приема дължина на нишката,притегляне на съответната планета,част от полукръг(180)

int main()
{
   int key=0;
   int part;
   double L;//същите две променливи от горе ,които обаце се въвеждат от потребителя и изпращат до съответната функция
   double speed;//тази променлива съдържа върнатата стойност от функция engine
do
 {
    printf("ENTER THE LENGHT OF THREAD: \n");
    scanf("%lf",&L);
    printf("ENTER THE PART 1,2,3,4,5 of movement: \n");
    scanf("%d",&part);

       key = menu();//не е необходим коментар !!!
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
        printf("THE  SPEED IN THIS PART: %lf \n\n",speed);// За мое учудване се оказа ,че притеглянето на марс и меркури е с разлика един процент и 1/3 от земното ,но ме домързя да сменя планетата.
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
    return result;// тук всичко е ясно във функцията
}

double engine(double l,double g,int PART)
{
  double minSPEED = 0;//максимална потенциална енергия 0 или 180 градуса
  double maxSPEED;//максимална кинетична енергия 90 градуса
  double max = 2*l*g;// максимална скорост обаче на квадрат общата енергия в системата се запазва Ек+Еп=const ,при нула градуса Ек е нула а при 90 Еп е нула ,приравняваме и получаваме формула не зависеща от масата!
  maxSPEED = sqrt(max);// махаме квадрата
  double averageSPEED = maxSPEED/2;//скорост при 45 градуса
  double averageSPEED2=averageSPEED/2;//скоростта при 22.5 градуса
  double averageSPEED3=averageSPEED2/2;//скоростта при 11.25 градеса квадрант 1 и 5

  if(PART == 1 || 5)
   return averageSPEED3;
  else if(PART == 2||4)
   return averageSPEED;
  else if(PART == 3)
   return maxSPEED;//тук всичко е ясно

}
//ТА ДАААААА!!!!!!
