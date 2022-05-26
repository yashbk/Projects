#include "../header/header.h"

void enter_details(details *student, int i)
{

    printf("Enter the name of student:");
    scanf("%s", (student + i - 1)->name);
    printf("Enter the gender of student:");
    scanf(" %c", &(student + i - 1)->gender);
    (student + i - 1)->roll_no = i;
    // printf("Enter the roll number:");
    // scanf("%d", &(student + i)->roll_no);
    putchar('\n');
}