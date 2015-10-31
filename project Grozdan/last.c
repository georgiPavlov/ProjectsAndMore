#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"h10.h"

wareHOUSE *last(wareHOUSE **head)
{
    wareHOUSE * temp;
    for (temp = *head; temp->pointer!=NULL; temp=temp->pointer)
        ;
    return temp;
}
