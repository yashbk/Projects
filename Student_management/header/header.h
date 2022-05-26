#ifndef header
#define header
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[30];
    int roll_no;
    char gender;
}details;

int num;

void enter_details(details *student,int);
void menu();
void print_details(details *ptr, int num);

#endif

