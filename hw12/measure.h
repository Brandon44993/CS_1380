#ifndef MEASURE_H
#define MEASURE_H
#include <stdbool.h>
int square(int x);
int min2(int a, int b);
int max2(int a, int b);
int clamp(int value, int lo, int hi);
bool is_even(int n);
double celsius_to_fahrenheit(double c);
int rectangle_area(int length, int width);
int rectangle_perimeter(int length, int width);
int box_volume(int length, int width, int height);
void print_rectangle(int length, int width);
#endif