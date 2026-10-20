#include <stdio.h>

int main(void)
{
    int n;
    int age;
    int day;
    char category;
    int price;
    int eligible = 0;
    int ineligible = 0;
    int revenue = 0;

    /* Validate number of customers. */
    while (1) {
        printf("How many customers (1-10): ");

        if (scanf("%d", &n) != 1) {
            printf("Not an integer. Try again: ");

            while (getchar() != '\n') {
            }

            continue;
        }

        if (n < 1 || n > 10) {
            printf("Number must be 1-10. Try again: ");
            continue;
        }

        break;
    }

    /*
     * Use a for loop from 1 through n because the number of
     * customers to process is known before the loop begins.
     */
    for (int customer = 1; customer <= n; customer++) {
        printf("--- Customer %d of %d ---\n", customer, n);

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

        /* Under 13 is ineligible and contributes $0. */
        if (age < 13) {
            printf("Not eligible: under 13\n");
            ineligible++;
            continue;
        }

        /* Determine base price. */
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

        if (age >= 18) {
            printf("Status: adult\n");
        } else {
            printf("Status: minor\n");
        }

        printf("Price: $%d\n", price);

        eligible++;
        revenue += price;
    }

    printf("Eligible tickets: %d\n", eligible);
    printf("Ineligible: %d\n", ineligible);
    printf("Total revenue: $%d\n", revenue);

    return 0;
}
