/*
 * station.c
 * Implements heap-based temperature log helpers.
 * Author: Brandon Allen
 */

#include "station.h"

#include <stdio.h>
#include <stdlib.h>

int *make_log(int n)
{
    int *log;

    if (n <= 0) {
        return NULL;
    }

    log = malloc((size_t)n * sizeof(int));

    if (log == NULL) {
        return NULL;
    }

    return log;
}

int *make_zero_log(int n)
{
    int *log;

    if (n <= 0) {
        return NULL;
    }

    log = calloc((size_t)n, sizeof(int));

    if (log == NULL) {
        return NULL;
    }

    return log;
}

void print_log(const int *log, int n)
{
    int i;

    if (log == NULL || n <= 0) {
        return;
    }

    for (i = 0; i < n; i++) {
        printf("%d", log[i]);

        if (i < n - 1) {
            printf(" ");
        }
    }

    printf("\n");
}

int reading_at(const int *log, int n, int index)
{
    if (log == NULL || n <= 0 || index < 0 || index >= n) {
        return 0;
    }

    return log[index];
}

int max_reading(const int *log, int n)
{
    int maximum;
    int i;

    if (log == NULL || n <= 0) {
        return 0;
    }

    maximum = log[0];

    for (i = 1; i < n; i++) {
        if (log[i] > maximum) {
            maximum = log[i];
        }
    }

    return maximum;
}

void free_log(int **log)
{
    if (log != NULL && *log != NULL) {
        free(*log);
        *log = NULL;
    }
}