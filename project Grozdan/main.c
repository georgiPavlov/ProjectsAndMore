
/*�� �� ��������� �������� ��� ������  �� ���������� �� �������� ���������� ��� �������� ����������:
1.	������������ � ���������� �� ���������� � ������� �������. �� ����� ����� � ������ �� ����� �������� �����:
�	������������� �����  -  �������� 12 ������� �����;
�	������������ �� �������  -  �� 50 �������� ���;
�	�������� ����  -  ������ �����;
�	����������  -  ���� �����;
�	���� �� ������������ �� �������  -  �������� ��� ������� ��.��.����.

2.	�� �� ��������� �������� ���������:
�)  ������ ���� ����� � ������.
�)  ��������� �� ������������ �� �������� ����� ( �������� ��� ��������� ���������� �� ������ ). ��� ��������� ��� �������� � �� ������ �������������� ���������� - �� �� �� ���������. ��� ������������ ������ ����� �� 0 ������� �� �� ������� �� ������.
�)  ��������� ���������� �� ������ ����� �� ������ � ������� ���� �� ������� (�������� ���� �� ������ �� �����������).
�)  �� ������� ���������������� ����� �� �� ���������� ������������ �� ��������� �����.
3.	������� �� �� ��������� � ��������� ��������� - ����������� ������ � ������������ ����� �� ��.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"h10.h"




int main()
{
    wareHOUSE * head = NULL;

    readFile (&head);
    int key;


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
            EDIT(&head);
            break;
        }
        case 3:
        {
            old(&head);
            break;
        }
        case 4:
        {
            printLIST(&head);
            break;
        }
        case 5:
        {
            writeSEARCH(&head);
            break;
        }
        case 6:
        {
            writeFILE(&head);
            MEMORYfree(&head);
            printf("\n\n           _-_-Goodbye!-_-_\n\n");
            break;
        }
        }
    }
    while (key != 7);
    return 0;
}
















