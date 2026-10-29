
/*
 * main.c - Demonstrates the team roster string functions.
 * Author: Brandon Allen
 */

#include <stdio.h>
#include "roster.h"

int main(void)
{
    char wolves[] = "Wolves";
    char hawks[] = "Hawks";
    char full_copy[20];
    char tiny[4];
    char upper_copy[20];

    printf("%s len=%d first=%c\n",
           wolves, team_len(wolves), wolves[0]);
    printf("%s len=%d\n", hawks, team_len(hawks));

    team_copy(full_copy, (int)sizeof(full_copy), wolves);
    printf("copy: %s\n", full_copy);

    team_copy(tiny, (int)sizeof(tiny), wolves);
    printf("tiny: %s\n", tiny);

    printf("same Wolves Wolves -> %d\n",
           team_same(wolves, full_copy));
    printf("same Wolves Hawks -> %d\n",
           team_same(wolves, hawks));

    team_copy(upper_copy, (int)sizeof(upper_copy), wolves);
    shout(upper_copy);
    printf("shout: %s\n", upper_copy);
    printf("original: %s\n", wolves);

    print_team(NULL);
    printf("NULL length: %d\n", team_len(NULL));

    return 0;
}
