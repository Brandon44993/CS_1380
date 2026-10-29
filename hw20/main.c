/*
 * main.c - Demonstrates the console picture functions.
 * Author: Brandon Allen
 */

#include <stdio.h>
#include "picture.h"

int main(void)
{
    int pic[][COLS] = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    int nrows = (int)(sizeof(pic) / sizeof(pic[0]));

    printf("Original picture:\n");
    print_picture(pic, nrows);

    printf("\nfind 1 -> %d\n", find_code(pic, nrows, 1));
    printf("find 9 -> %d\n", find_code(pic, nrows, 9));

    set_cell(pic, nrows, 2, 2, 1);
    printf("\nAfter set_cell(2, 2, 1):\n");
    print_picture(pic, nrows);

    set_cell(pic, nrows, 9, 0, 1);
    printf("\nset_cell(9, 0, 1) ignored\n");
    print_picture(pic, nrows);

    printf("\nTesting null pointer:\n");
    print_picture(nullptr, 4);
    printf("find_code(nullptr, 4, 1) -> %d\n",
           find_code(nullptr, 4, 1));

    return 0;
}