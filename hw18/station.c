/*
 * station.c
 * Implements memory management helpers for a weather station log.
 * Author: Brandon Allen
 */

#include "station.h"

#include <stdio.h>
#include <stdlib.h>

int *make_log(int n)
{
    if (n <= 0) {
        return NULL;
    }

    int *log = malloc((size_t)n * sizeof(*log));

    if (log == NULL) {
        return NULL;
    }

    return log;
}

void print_log(const int *log, int n)
{
    if (log == NULL || n <= 0) {
        return;
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }

        printf("%d", log[i]);
    }

    printf("\n");
}

int max_reading(const int *log, int n)
{
    if (log == NULL || n <= 0) {
        return 0;
    }

    int maximum = log[0];

    for (int i = 1; i < n; i++) {
        if (log[i] > maximum) {
            maximum = log[i];
        }
    }

    return maximum;
}

int *grow_log(int *log, int old_n, int new_n)
{
    if (new_n <= old_n) {
        return log;
    }

    if (new_n <= 0) {
        return log;
    }

    if (log == NULL) {
        return make_log(new_n);
    }

    int *temporary = realloc(
        log,
        (size_t)new_n * sizeof(*log)
    );

    if (temporary == NULL) {
        return NULL;
    }

    return temporary;
}

int *append_reading(int *log, int *n, int value)
{
    if (n == NULL || *n < 0 || *n == __INT_MAX__) {
        return NULL;
    }

    if (log == NULL && *n != 0) {
        return NULL;
    }

    int old_n = *n;
    int *temporary = grow_log(log, old_n, old_n + 1);

    if (temporary == NULL) {
        return NULL;
    }

    temporary[old_n] = value;
    *n = old_n + 1;

    return temporary;
}

void free_log(int **log)
{
    if (log == NULL) {
        return;
    }

    free(*log);
    *log = NULL;
}