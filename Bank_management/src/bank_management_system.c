#include "../header/header.h"

int i, j;
int main_exit;

int main()
{
    char pass[10], password[10] = "yash";
    int i = 0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s", pass);

    if (strcmp(pass, password) == 0)
    {
        printf("\n\nPassword Match!\nLOADING");
        for (i = 0; i <= 6; i++)
        {
            fordelay(100000000);
            printf(". ");
        }
        system("cls");
        menu();
    }
    else
    {
        printf("\n\nWrong password!!\a\a\a");
    login_try:
        while (1)
        {
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d", &main_exit);
            if (main_exit == 1)
            {
                system("cls");
                main();
                break;
            }

            else if (main_exit == 0)
            {
                system("cls");
                close();
                break;
            }
            else
            {
                printf("\nInvalid!");
                fordelay(1000000000);
                system("cls");
                break;
            }
        }
    }
    return 0;
}
