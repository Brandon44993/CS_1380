#include <stdio.h>

int main(void)
{
    int ch;
    int count = 0;

    printf("Type a line:\n");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        putchar(ch);
        count++;
    }

    putchar('\n');
    printf("Characters: %d\n", count);

    return 0;
}