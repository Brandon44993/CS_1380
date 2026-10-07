/*
 * modified basic.c
 *
 *  at least the one i made for this assinment because i could not find the original basic.c that we where suposed to have done preavesoly
 */

#include <stdio.h>

int global_number = 10;

int main(void)
{
    int first_number = 10;
    int second_number = 5;
    int sum = first_number + second_number;
    int total = sum + global_number;
    int uninitialized_number;

    printf("First number: %d\n", first_number);
    printf("Second number: %d\n", second_number);
    printf("Sum: %d\n", sum);
    printf("Global number: %d\n", global_number);
    printf("Total using local and global variables: %d\n", total);
    printf("Uninitialized number: %d\n", uninitialized_number);

    return 0;
}
