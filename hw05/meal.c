
#include <stdio.h>

int main(void) {
    int meal_cents = 5000;

    int tax_cents = meal_cents * 75 / 1000;
    int total_cents = meal_cents + tax_cents;

    int tip_10_cents = total_cents * 10 / 100;
    int tip_15_cents = total_cents * 15 / 100;
    int tip_20_cents = total_cents * 20 / 100;

    printf("Meal amount:    $%d.%02d\n",
           meal_cents / 100, meal_cents % 100);

    printf("Tax:            $%d.%02d\n",
           tax_cents / 100, tax_cents % 100);

    printf("Total with tax: $%d.%02d\n",
           total_cents / 100, total_cents % 100);

    printf("10%% tip:        $%d.%02d\n",
           tip_10_cents / 100, tip_10_cents % 100);

    printf("15%% tip:        $%d.%02d\n",
           tip_15_cents / 100, tip_15_cents % 100);

    printf("20%% tip:        $%d.%02d\n",
           tip_20_cents / 100, tip_20_cents % 100);

    return 0;
}

