#include <stdio.h>

int global_value = 100;

void show_scopes(void);

int main(void)
{
    int local_value = 200;

    show_scopes();

    printf("main local value: %d\n", local_value);

    return 0;
}

void show_scopes(void)
{
    int local_value = 300;

    printf("global value: %d\n", global_value);
    printf("show_scopes local value: %d\n", local_value);

    {
        int block_value = 400;

        printf("block-scoped value: %d\n", block_value);
    }
}