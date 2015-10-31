#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


int main()
{
  int key;
  carMEMORY *head = NULL;
  carIN carTemp;
  readFILE( &head ,carTemp);
  double SUMcar=0;
  do
	{
		key = menu();
		switch (key)
		{
		case 1:
		{
        ADDinLAST(&head);
				  break;
		}
		case 2:
		{
        PRINTcarSEARCH(&head,0);
				  break;
		}
		case 3:
		{
        removeCAR(&head);
				  break;
		}
		case 4:
		{
		SUMcar = PRICEcar(&head);
		PRINTcarSEARCH(&head,SUMcar);
		          break;
		}
		case 5:
		{
        writeFILE(&head);
        MEMORYfree(&head);
        printf("\n\n           _-_-Goodbye!-_-_\n\n");
				  break;
		}
		}
	} while (key != 5);
  return 0;
}
















