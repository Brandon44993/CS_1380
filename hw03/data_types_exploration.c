#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    int whole_number = 10;
    char letter = 'A';
    float decimal_number = 3.14f;
    double precise_number = 3.1415926535;

    printf("Integer: %d\n", whole_number);
    printf("Character: %c\n", letter);
    printf("Float: %.2f\n", decimal_number);
    printf("Double: %.10f\n", precise_number);

    printf("\nType sizes:\n");
    printf("int: %zu bytes\n", sizeof(int));
    printf("char: %zu byte\n", sizeof(char));
    printf("float: %zu bytes\n", sizeof(float));
    printf("double: %zu bytes\n", sizeof(double));

    printf("\nInteger division: %d\n", 7 / 2);
    printf("Floating-point division: %.2f\n", 7.0 / 2.0);

    printf("\nInteger limits:\n");
    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);

    printf("\nFloating-point limits:\n");
    printf("FLT_MAX: %e\n", FLT_MAX);
    printf("DBL_MAX: %e\n", DBL_MAX);

    return 0;
}