#include "../header/header.h"

void menu()
{
    int menu;
    int num;
    while (1)
    {
        printf("Menu:\n");
        printf("1.Enter details\n2.Print details\n");
        scanf("%d", &menu);
        if (menu == 1)
        {
            printf("Enter the number of students: ");
            scanf("%d", &num);
            details student[num];
            for(int i = 0; i < num; i++)
            {
                enter_details(student,i);
            }
        }
        else if (menu == 2)
        {
            print_details(num);
        }
        else
        {
            printf("Wrong input, Enter again\n");
        }
    }
}