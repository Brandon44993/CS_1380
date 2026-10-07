
/*
 * main.c
 * Demonstrates pointer arithmetic using cafe menu prices
 * and a drink name.
 * Author: brandon allen
 */

#include <stdio.h>
#include "menu.h"

int main(void)
{
    int prices[] = {250, 350, 450, 199, 500};
    int n = (int)(sizeof(prices) / sizeof(prices[0]));

    printf("menu: ");
    print_menu(prices, n);

    printf("price_at 2 = %d\n", price_at(prices, n, 2));
    printf("price_at 4 = %d\n", price_at(prices, n, 4));
    printf("max = %d\n", max_price(prices, n));

    printf("addr[0] = %p\n", (void *)&prices[0]);
    printf("addr[1] = %p\n", (void *)&prices[1]);
    printf("byte gap = %td\n",
           (char *)&prices[1] - (char *)&prices[0]);

    printf("items 0..4 = %d\n",
           items_between(&prices[0], &prices[4]));

    reverse_menu(prices, n);

    printf("reversed: ");
    print_menu(prices, n);

    const char *drink = "latte";

    printf("drink_length(\"latte\") = %d\n",
           drink_length(drink));
    printf("drink_length(NULL) = %d\n", drink_length(NULL));

    printf("pointer walk: ");
    for (const int *p = prices; p < prices + n; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    return 0;
}