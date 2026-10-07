#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int age;
    int day;
    char category;
    char status;
    int price;

    /* Display the base-price table. */
    printf("%-10s %5s\n", "Category", "Base");
    printf("%-10s $%4d\n", "General", 13);
    printf("%-10s $%4d\n", "Student", 10);
    printf("%-10s $%4d\n", "Faculty", 15);

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

    /*
     * Read category with getchar.
     * Skip whitespace left in the input buffer by scanf.
     */
    while (1) {
        int ch;

        printf("Category (G/S/F): ");

        do {
            ch = getchar();
        } while (ch != EOF && isspace((unsigned char)ch));

        if (ch == EOF) {
            printf("Invalid category. Try again: ");
            continue;
        }

        category = (char)ch;

        /* Remove anything else remaining on this input line. */
        while ((ch = getchar()) != '\n' && ch != EOF) {
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

    /* Determine base price by category. */
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

    /* Print formatted receipt. */
    printf("\n======= TICKET =======\n");
    printf("%-12s %8d\n", "Age:", age);
    printf("%-12s %8s\n", "Status:",
           status == 'A' ? "adult" : "minor");

    if (category == 'G') {
        printf("%-12s %8s\n", "Category:", "General");
    } else if (category == 'S') {
        printf("%-12s %8s\n", "Category:", "Student");
    } else {
        printf("%-12s %8s\n", "Category:", "Faculty");
    }

    printf("%-12s %8d\n", "Day:", day);
    printf("%-12s $%7d\n", "Price:", price);
    printf("======================\n");

    return 0;
}