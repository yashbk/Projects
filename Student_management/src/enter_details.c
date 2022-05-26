#include "../header/header.h"

void enter_details(details *student, int i)
{
    if (i > 0)
    {
        printf("Previously entered student name is %s and roll no is %d \n", (student + i - 1)->name, (student + i - 1)->roll_no);
    }
    printf("Enter the name of student:");
    scanf("%s", (student + i)->name);
    printf("Enter the gender of student:");
    scanf(" %c", &(student + i)->gender);
    printf("Enter the roll number:");
    scanf("%d", &(student + i)->roll_no);
    putchar('\n');
}