/*
 * Program: commenting_demo.c
 * Purpose: Demonstrate effective comments in C.
 * Author: Brandon Allen
 */

#include <stdio.h>

int main(void)
{
    double first_score = 85.0;
    double second_score = 95.0;

    // Calculate the average of the two scores.
    double average = (first_score + second_score) / 2.0;

    printf("First score: %.1f\n", first_score);
    printf("Second score: %.1f\n", second_score);
    printf("Average score: %.1f\n", average);

    return 0;
}