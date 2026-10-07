/*
 * main.c
 * Demonstrates the campus cafe register helper functions.
 * Author: Brandon ALlen
 */

#include "cafe.h"

#include <stdio.h>

int main(void)
{
    int price = 400;

    printf("starting price: %d cents\n", price);

    preview_discount(price, 10);
    printf("after preview: %d cents\n", price);

    apply_discount(&price, 10);
    printf("after apply_discount: %d cents\n", price);

    int new_balance = 0;
    int charge_code = charge(1000, price, &new_balance);

    if (charge_code == CAFE_OK) {
        printf("charge ok: balance 1000 - %d -> %d\n",
               price, new_balance);
    } else {
        printf("charge failed: code %d\n", charge_code);
    }

    int failed_balance = 0;
    int failed_code = charge(200, 500, &failed_balance);

    printf("charge fail: code %d\n", failed_code);

    int change = 0;

    if (make_change(500, price, &change)) {
        printf("change for 500 on %d: %d cents\n",
               price, change);
    } else {
        printf("make_change failed\n");
    }

    if (!make_change(300, price, &change)) {
        printf("change failure: paid amount is too small\n");
    }

    int prices[] = {350, 250, 450, 360};
    int min_price = 0;
    int max_price = 0;

    if (price_span(prices, 4, &min_price, &max_price)) {
        printf("price span: min=%d max=%d\n",
               min_price, max_price);
    }

    if (!price_span(prices, 0, &min_price, &max_price)) {
        printf("price span failure: invalid number of prices\n");
    }

    print_line_item("latte", price);

    return 0;
}
