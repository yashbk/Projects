#ifndef header_h
#define header_h


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


struct date
{
    int month, day, year;
};
struct
{

    char name[60];
    int acc_no, age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

} add, upd, check, rem, transaction;

//Function declarations

void close(void);

void edit(void);
void erase(void);
void fordelay(int j);
float interest(float t, float amount, int rate);
void menu();
void new_acc();
void see(void);
void transact(void);
void view_list();

#endif