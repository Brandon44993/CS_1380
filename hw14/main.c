#include <stdio.h>
#include "specials.h"

int main(void)
{
    const int order[] = {250, 350, 450};
    const int order_count = 3;

    int order_total = sum_order(order, order_count);
    int factorial_zero = factorial(0);
    int factorial_five = factorial(5);
    int power_2_8 = power(2, 8);
    int power_5_0 = power(5, 0);

    int added_total = apply_op(order_total, 0, add_cents);
    int discount = apply_op(order_total, 10, percent_off_amount);

    printf("order 250+350+450 = %d\n", order_total);
    printf("factorial(0) = %d\n", factorial_zero);
    printf("factorial(5) = %d\n", factorial_five);
    printf("power(2,8) = %d\n", power_2_8);
    printf("power(5,0) = %d\n", power_5_0);
    printf("add_cents via apply_op: %d\n", added_total);
    printf("10%% of %d via apply_op: %d\n", order_total, discount);

    return 0;
}
