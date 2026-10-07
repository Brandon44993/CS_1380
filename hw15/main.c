/*
 * main.c
 * Demonstrates pointers, addresses, dereferencing, arrays, and
 * pointer-to-pointer retargeting using cafe drink prices.
 * Author: Brandon Allen
 */

#include <stdio.h>

#include "prices.h"

int main(void)
{
    int latte = 350;
    int mocha = 450;
    int tea = 250;

    int *tag = &latte;

    printf("Pointer demonstration\n");
    printf("----------------------\n");
    printf("latte=%d\n", latte);
    printf("&latte=%p\n", (void *)&latte);
    printf("tag=%p\n", (void *)tag);
    printf("*tag=%d\n", *tag);

    set_price(tag, 400);
    printf("after set_price: latte=%d\n", latte);

    printf("\nSwap demonstration\n");
    printf("------------------\n");
    printf("before swap: latte=%d mocha=%d\n", latte, mocha);

    swap_cents(&latte, &mocha);

    printf("after swap: latte=%d mocha=%d\n", latte, mocha);

    printf("\nNULL demonstration\n");
    printf("------------------\n");
    print_price("missing tag", NULL);
    set_price(NULL, 999);

    printf("\nRetarget demonstration\n");
    printf("----------------------\n");

    int *special = &mocha;

    printf("special was mocha %d\n", *special);

    retarget(&special, &tea);

    printf("after retarget, special is tea %d\n", *special);

    printf("\nArray demonstration\n");
    printf("-------------------\n");

    int board[] = {latte, mocha, tea};
    int *p = board;

    printf("board: %d %d %d\n", *(p + 0), *(p + 1), *(p + 2));

    return 0;
}