 
 /*
 * menu.c
 * Implements pointer arithmetic helpers for cafe menu prices
 * and drink names.
 * Author: bradnon allen
*/
#include <stdio.h>
#include "menu.h"

void print_menu(const int *prices, int n)
{
    if (prices == NULL || n <= 0) {
        return;
    }

    for (const int *p = prices; p < prices + n; p++) {
        if (p != prices) {
            printf(" ");
        }
        printf("%d", *p);
    }

    printf("\n");
}

int price_at(const int *prices, int n, int index)
{
    if (prices == NULL || n <= 0 || index < 0 || index >= n) {
        return 0;
    }

    return *(prices + index);
}

int max_price(const int *prices, int n)
{
    if (prices == NULL || n <= 0) {
        return 0;
    }

    int largest = *prices;

    for (const int *p = prices + 1; p < prices + n; p++) {
        if (*p > largest) {
            largest = *p;
        }
    }

    return largest;
}

void reverse_menu(int *prices, int n)
{
    if (prices == NULL || n <= 1) {
        return;
    }

    int *start = prices;
    int *end = prices + n - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int items_between(const int *start, const int *end)
{
    if (start == NULL || end == NULL) {
        return 0;
    }

    return (int)(end - start);
}

int drink_length(const char *name)
{
    if (name == NULL) {
        return 0;
    }

    const char *p = name;

    while (*p != '\0') {
        p++;
    }

    return (int)(p - name);
}



