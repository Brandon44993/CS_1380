/*
 * main.c
 * Demonstrates the functions in the measure library.
 * Author: Brandon Allen
 */
#include "measure.h"
#include <stdio.h>

int main(void)
{
    printf("square(5) = %d\n", square(5));

    printf("min2(3, 8) = %d  max2(3, 8) = %d\n",
           min2(3, 8),
           max2(3, 8));

    printf("clamp(150, 0, 100) = %d\n", clamp(150, 0, 100));
    printf("clamp(-10, 0, 100) = %d\n", clamp(-10, 0, 100));

    printf("is_even(7) = %s\n", is_even(7) ? "true" : "false");

    printf("20.0 C = %.1f F\n", celsius_to_fahrenheit(20.0));

    print_rectangle(4, 3);

    printf("box 4 x 3 x 2: volume=%d\n", box_volume(4, 3, 2));

    printf("3-4-5 check: %d + %d = %d\n",
           square(3),
           square(4),
           square(3) + square(4));

    printf("negative sides: area=%d\n", rectangle_area(-4, 3));

    return 0;
}
