

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"h10.h"

void MEMORYfree(wareHOUSE **head)
{
    if(*head!=NULL)
    {
        wareHOUSE *temp77;
        for(; temp77 != NULL ; temp77 = *head)
        {
            *head=temp77->pointer;
            free(temp77);
        }
    }
    *head=NULL;
}
