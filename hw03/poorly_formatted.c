#include <stdio.h>

int main(void) {
  int firstNumber = 10;
  int secondNumber = 20;
  int total = firstNumber + secondNumber;

  if (total > 20) {
    printf("The total is greater than 20.\n");
  } else {
    printf("The total is 20 or less.\n");
  }

  return 0;
}