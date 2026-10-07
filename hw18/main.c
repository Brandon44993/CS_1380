/*
 * main.c
 * Demonstrates creating, growing, appending to, and freeing a station log.
 * Author: Brandon Allen
 */

#include "station.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 3;
    int *log = make_log(n);

    if (log == NULL) {
        fprintf(stderr, "Could not allocate the initial log.\n");
        return EXIT_FAILURE;
    }

    log[0] = 68;
    log[1] = 71;
    log[2] = 64;

    printf("start n=%d: ", n);
    print_log(log, n);

    int *grown = grow_log(log, n, 6);

    if (grown == NULL) {
        fprintf(stderr, "Could not grow the log.\n");
        free_log(&log);
        return EXIT_FAILURE;
    }

    log = grown;
    log[3] = 72;
    log[4] = 70;
    log[5] = 67;
    n = 6;

    printf("after grow n=%d: ", n);
    print_log(log, n);
    printf("max = %d\n", max_reading(log, n));

    int *appended = append_reading(log, &n, 69);

    if (appended == NULL) {
        fprintf(stderr, "Could not append the first reading.\n");
        free_log(&log);
        return EXIT_FAILURE;
    }

    log = appended;

    appended = append_reading(log, &n, 65);

    if (appended == NULL) {
        fprintf(stderr, "Could not append the second reading.\n");
        free_log(&log);
        return EXIT_FAILURE;
    }

    log = appended;

    printf("after append n=%d: ", n);
    print_log(log, n);
    printf("max = %d\n", max_reading(log, n));

    printf("NULL log test: ");
    print_log(NULL, 3);
    printf("NULL maximum = %d\n", max_reading(NULL, 3));

    free_log(&log);

    if (log == NULL) {
        printf("after free_log, pointer is NULL\n");
    }

    free_log(&log);

    return EXIT_SUCCESS;
}