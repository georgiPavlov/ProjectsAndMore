#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void MEMORYfree(carMEMORY **head)
{
 carMEMORY *temp7;
 for(;temp7 != NULL ; temp7 = *head)
 {
     *head=temp7->pointer;
     free(temp7);
 }
 *head=NULL;
}
