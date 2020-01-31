//--------------------------------------------------
// Name: Sharan Shanmugaratnam
// Student Number: 153601174
// Email: sshanmugaratnam2@myseneca.ca
// Section: IPC144QQ
// Workshop: 4
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Put your code below:

int main(void) {
  int day;
  int highTemp[10] = { 0 };
  int lowTemp[10] = { 0 };
  int i;

  printf("---=== IPC Temperature Calculator V2.0 ===---"); // Prints title.

  printf("\nPlease enter the number of days, between 3 and 10, inclusive: ");
  scanf("%d", &day);

  while (day > 10 || day < 3) { // Only runs if value is over 10 or under 3.
    printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
    scanf("%d", &day);

  }
  putchar('\n'); //Necessary formatting
  for (i = 0; i < day; i++) { // Loops for the amount of days, getting temps for each day.
    printf("Day %d - High: ", i + 1);
    scanf("%d", &highTemp[i]);
    printf("Day %d - Low: ", i + 1);
    scanf("%d", &lowTemp[i]);
  }

  printf("\nDay  Hi  Low"); // Prints all the temps.
  for (i = 0; i < day; i++) {
    printf("\n%d %4d %5d", i + 1, highTemp[i], lowTemp[i]);
  }
  putchar('\n'); //Necessary formatting
  return 0;
}