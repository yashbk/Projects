#ifndef header
#define header
#include <stdio.h>

typedef struct {
    char name[30];
    int roll_no;
    char gender;
}details;

void enter_details(details *student,int);
void menu();
void print_details(int num);

#endif

