#include "../header/header.h"

void menu()
{
    int menu;
    int num = 0;
    details *student = NULL;
    while (1)
    {
        printf("Menu:\n");
        printf("1.Enter details\n2.Print details\n3.Exit\n");
        scanf("%d", &menu);
        if (menu == 1)
        {
            printf("Enter the number of students: ");
            scanf("%d", &num);
            student = (details *)malloc(sizeof(details) * num);
            for (int i = 1; i <= num; i++)
            {
                if (i > 1)
                {
                    printf("Previously entered student name is %s and roll no is %d \n", (student + i - 2)->name, (student + i - 2)->roll_no);
                }
                enter_details(student, i);
            }
        }
        else if (menu == 2)
        {
            if (student == NULL)
            {
                printf("Student is null\n");
            }
            print_details(student, num);
        }
        else if (menu == 3)
        {
            printf("Exited\n");
            if (student != NULL)
            {
                free(student);
            }
            break;
        }
        else
        {
            printf("Wrong input, Enter again:)\n");
        }
    }
}