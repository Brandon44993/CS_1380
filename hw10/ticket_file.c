
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
    FILE *input;
    FILE *report;
    char line[256];
    char name[100];
    char category;
    int age;
    int day;
    int price;
    int customers = 0;
    int eligible = 0;
    int ineligible = 0;
    int revenue = 0;
    int customer_number = 0;

    input = fopen("ticket_customers.txt", "r");

    if (input == NULL) {
        fprintf(stderr, "Error opening ticket_customers.txt: %s\n",
                strerror(errno));
        return 1;
    }

    report = fopen("ticket_report.txt", "w");

    if (report == NULL) {
        fprintf(stderr, "Error opening ticket_report.txt: %s\n",
                strerror(errno));

        if (fclose(input) != 0) {
            fprintf(stderr, "Error closing input file: %s\n",
                    strerror(errno));
        }

        return 1;
    }

    while (fgets(line, sizeof(line), input) != NULL) {
        int fields;

        fields = sscanf(line, "%99s %d %d %c",
                        name, &age, &day, &category);

        if (fields != 4) {
            fprintf(stderr, "Skipping malformed line: %s", line);
            continue;
        }

        if (age < 0 || age > 120) {
            fprintf(stderr, "Skipping %s: age must be 0-120.\n", name);
            continue;
        }

        if (day < 1 || day > 7) {
            fprintf(stderr, "Skipping %s: day must be 1-7.\n", name);
            continue;
        }

        if (category != 'G' && category != 'S' && category != 'F') {
            fprintf(stderr, "Skipping %s: invalid category.\n", name);
            continue;
        }

        customers++;
        customer_number++;

        printf("--- Customer %d: %s ---\n", customer_number, name);
        fprintf(report, "--- Customer %d: %s ---\n",
                customer_number, name);

        if (age < 13) {
            printf("Not eligible: under 13\n");
            fprintf(report, "Not eligible: under 13\n");

            ineligible++;
            continue;
        }

        if (category == 'G') {
            price = 13;
        } else if (category == 'S') {
            price = 10;
        } else {
            price = 15;
        }

        if (day == 6 || day == 7) {
            price += 3;
        }

        if (age >= 65 && day == 3) {
            price -= 5;

            if (price < 0) {
                price = 0;
            }
        }

        if (age >= 18) {
            printf("Status: adult\n");
            fprintf(report, "Status: adult\n");
        } else {
            printf("Status: minor\n");
            fprintf(report, "Status: minor\n");
        }

        printf("Price: $%d\n", price);
        fprintf(report, "Price: $%d\n", price);

        eligible++;
        revenue += price;
    }

    if (ferror(input)) {
        fprintf(stderr, "Error reading ticket_customers.txt: %s\n",
                strerror(errno));

        if (fclose(report) != 0) {
            fprintf(stderr, "Error closing report file: %s\n",
                    strerror(errno));
        }

        if (fclose(input) != 0) {
            fprintf(stderr, "Error closing input file: %s\n",
                    strerror(errno));
        }

        return 1;
    }

    printf("Customers: %d\n", customers);
    printf("Eligible tickets: %d\n", eligible);
    printf("Ineligible: %d\n", ineligible);
    printf("Total revenue: $%d\n", revenue);

    fprintf(report, "Customers: %d\n", customers);
    fprintf(report, "Eligible tickets: %d\n", eligible);
    fprintf(report, "Ineligible: %d\n", ineligible);
    fprintf(report, "Total revenue: $%d\n", revenue);

    if (fclose(input) != 0) {
        fprintf(stderr, "Error closing input file: %s\n",
                strerror(errno));

        if (fclose(report) != 0) {
            fprintf(stderr, "Error closing report file: %s\n",
                    strerror(errno));
        }

        return 1;
    }

    if (fclose(report) != 0) {
        fprintf(stderr, "Error closing report file: %s\n",
                strerror(errno));
        return 1;
    }

    return 0;
}
