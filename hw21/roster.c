
/*
 * roster.c - String helper functions for team names.
 * Author: Brandon Allen
 */

#include <stdio.h>
#include "roster.h"

void print_team(const char name[])
{
    if (name != NULL) {
        printf("%s", name);
    }
}

int team_len(const char name[])
{
    int length = 0;

    if (name == NULL) {
        return 0;
    }

    while (name[length] != '\0') {
        length++;
    }

    return length;
}

void team_copy(char dest[], int dest_size, const char src[])
{
    int i = 0;

    if (dest == NULL || dest_size <= 0) {
        return;
    }

    if (src == NULL) {
        dest[0] = '\0';
        return;
    }

    while (i < dest_size - 1 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

int team_same(const char a[], const char b[])
{
    int i = 0;

    if (a == NULL || b == NULL) {
        return 0;
    }

    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 0;
        }

        i++;
    }

    return a[i] == b[i];
}

void shout(char name[])
{
    int i = 0;

    if (name == NULL) {
        return;
    }

    while (name[i] != '\0') {
        if (name[i] >= 'a' && name[i] <= 'z') {
            name[i] = (char)(name[i] - 'a' + 'A');
        }

        i++;
    }
}
