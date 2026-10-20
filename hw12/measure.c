/*
 * measure.c
 * Implements the measurement and calculation functions.
 * Author: Brandon Allen
 */
#include "measure.h"
#include <stdio.h>

int square(int x)
{
    return x * x;
}

int min2(int a, int b)
{
    if (a < b) {
        return a;
    }

    return b;
}

int max2(int a, int b)
{
    if (a > b) {
        return a;
    }

    return b;
}

int clamp(int value, int lo, int hi)
{
    int lower = min2(lo, hi);
    int upper = max2(lo, hi);

    return max2(lower, min2(value, upper));
}

bool is_even(int n)
{
    return n % 2 == 0;
}

double celsius_to_fahrenheit(double c)
{
    return c * 9.0 / 5.0 + 32.0;
}

int rectangle_area(int length, int width)
{
    if (length < 0 || width < 0) {
        return 0;
    }

    return length * width;
}

int rectangle_perimeter(int length, int width)
{
    if (length < 0 || width < 0) {
        return 0;
    }

    return 2 * (length + width);
}

int box_volume(int length, int width, int height)
{
    if (length < 0 || width < 0 || height < 0) {
        return 0;
    }

    return rectangle_area(length, width) * height;
}

void print_rectangle(int length, int width)
{
    printf("rectangle %d x %d: area=%d perimeter=%d\n",
           length,
           width,
           rectangle_area(length, width),
           rectangle_perimeter(length, width));
}
