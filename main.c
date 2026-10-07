/*
 * main.c
 * Demonstrates dynamic memory allocation for a campus weather station.
 * Author:  Brandon ALlen
 */

#include "station.h"

#include <stdio.h>

int main(void)
{
    int n = 5;
    int *log = make_log(n);
    int *zero_log = NULL;

    if (log == NULL) {
        printf("Could not allocate temperature log.\n");
        return 1;
    }

    log[0] = 68;
    log[1] = 71;
    log[2] = 64;
    log[3] = 72;
    log[4] = 70;

    printf("log n=%d: ", n);
    print_log(log, n);

    printf("reading_at 2 = %d\n", reading_at(log, n, 2));
    printf("reading_at 4 = %d\n", reading_at(log, n, 4));
    printf("max = %d\n", max_reading(log, n));

    zero_log = make_zero_log(n);

    if (zero_log == NULL) {
        printf("Could not allocate zero-filled log.\n");
        free_log(&log);
        return 1;
    }

    printf("calloc zeros: ");
    print_log(zero_log, n);

    /* Invalid-input paths should not crash. */
    printf("invalid reading = %d\n", reading_at(NULL, 5, 0));
    print_log(NULL, 5);

    free_log(&log);

    if (log == NULL) {
        printf("after free_log, pointer is NULL\n");
    }

    /* Safe to call again after the pointer has been nulled. */
    free_log(&log);

    free_log(&zero_log);

    if (zero_log == NULL) {
        printf("zero-filled log freed; pointer is NULL\n");
    }

    return 0;
}