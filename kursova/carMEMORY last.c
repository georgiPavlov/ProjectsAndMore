#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

carMEMORY *last(carMEMORY **head)
{
   carMEMORY *temp;

    for (temp = *head;temp->pointer!=NULL;temp=temp->pointer)
        ;

    return temp;
}
