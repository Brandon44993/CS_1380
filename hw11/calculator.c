#include <stdio.h>


int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(double a, double b);
void display_menu(void);
int get_choice(void);

int main() {
  int choice, num1, num2;
  double result;

  do {
    display_menu();
    choice = get_choice();

    if (choice >= 1 && choice <= 4) {
      printf("Enter two numbers: ");
      scanf("%d %d", &num1, &num2);

      switch (choice) {
      case 1:
        result = add(num1, num2);
        break;
      case 2:
        result = subtract(num1, num2);
        break;
      case 3:
        result = multiply(num1, num2);
        break;
      case 4:
        result = divide(num1, num2);
        break;
      }
      printf("Result: %.2f\n", result);
    }
  } while (choice != 5);

  return 0;
}