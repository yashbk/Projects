#include "../header/header.h"

void print_details(details *ptr, int num)
{
    while (1)
    {
        if(num == 0)
        {
            printf("There are no students in the list. Plese add student details\n");
            return;
        }
        int roll = 0;
        printf("Select roll number from below to get details of respective student:\nEnter -1 to exit\n");
        for (int i = 0; i < num; i++)
        {
            printf("%d)Student name is %s\n",(ptr + i)->roll_no,(ptr + i)->name);
        }
        scanf("%d", &roll);
        if (roll>0 && roll <=num)
        {
            printf("The details of the selected student are:\n");
            printf("Name: %s\n",(ptr+roll-1)->name);
            printf("Gender: %c\n",(ptr+roll-1)->gender);
            printf("Roll_no: %d\n\n",(ptr+roll-1)->roll_no);
        }
        else if(roll == -1)
        {
            return;
        }
        else
        {
            printf("Your input is wrong please check and re-enter properly\n");
        }
    }
}