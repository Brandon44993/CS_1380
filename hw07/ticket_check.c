/*
    ticket_check.c
    UVU Campus Box Office ticket eligibility and pricing program.
    Author: Brandon Allen
    Date: September 2026
*/

#include <stdio.h>

int main(void)
{
    int age;
    int day;
    char category;
    int price = 0;

    printf("Age: ");
    if (scanf("%d", &age) != 1) {
        printf("Not an integer\n");
        return 1;
    }

    return 0;
}