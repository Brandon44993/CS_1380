#include <stdio.h>

int main(void)
{
    int age;
    int day;
    char category;
    char status;
    int price;

    /* Validate age. */
    while (1) {
        printf("Age: ");

        if (scanf("%d", &age) != 1) {
            printf("Not an integer. Try again: ");

            while (getchar() != '\n') {
            }

            continue;
        }

        if (age < 0 || age > 120) {
            printf("Age must be 0-120. Try again: ");
            continue;
        }

        break;
    }

    /* Under 13 is not eligible. */
    if (age < 13) {
        printf("Not eligible: under 13\n");
        return 0;
    }

    /* Validate day. */
    while (1) {
        printf("Day (1-7): ");

        if (scanf("%d", &day) != 1) {
            printf("Not an integer. Try again: ");

            while (getchar() != '\n') {
            }

            continue;
        }

        if (day < 1 || day > 7) {
            printf("Day must be 1-7. Try again: ");
            continue;
        }

        break;
    }

    /* Validate category. */
    while (1) {
        printf("Category (G/S/F): ");

        if (scanf(" %c", &category) != 1) {
            printf("Invalid category. Try again: ");

            while (getchar() != '\n') {
            }

            continue;
        }

        if (category != 'G' && category != 'S' && category != 'F') {
            printf("Invalid category. Try again: ");
            continue;
        }

        break;
    }

    /* Determine adult/minor status. */
    if (age >= 18) {
        status = 'A';
    } else {
        status = 'M';
    }

    /* Base price by category. */
    if (category == 'G') {
        price = 13;
    } else if (category == 'S') {
        price = 10;
    } else {
        price = 15;
    }

    /* Weekend surcharge. */
    if (day == 6 || day == 7) {
        price += 3;
    }

    /* Senior Wednesday discount. */
    if (age >= 65 && day == 3) {
        price -= 5;

        if (price < 0) {
            price = 0;
        }
    }

    printf("Status: %s\n", status == 'A' ? "adult" : "minor");
    printf("Price: $%d\n", price);

    return 0;
}
