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
  double highestTemp = 0;
  double lowestTemp = 0;
  int highestDay;
  int lowestDay;
  double TDV = 0;
  int avgDay;
  double avg;

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

    if (highTemp[i] >= highestTemp) {    //If temperature of this current day is lower it will not execute if statement.
      highestTemp = highTemp[i];
      highestDay = i + 1;               //Also records the current day of the high temperature.
    }

    if (lowTemp[i] <= lowestTemp) {      //If temperature of this current day is higher it will not execute if statement.
      lowestTemp = lowTemp[i];
      lowestDay = i + 1;                //Also records the current day of the low temperature.
    }

  }


  printf("\nDay  Hi  Low"); // Prints all the temps.
  for (i = 0; i < day; i++) {
    printf("\n%d %4d %5d", i + 1, highTemp[i], lowTemp[i]);
  }

  putchar('\n'); //Necessary formatting

  printf("\nThe highest temperature was %.0lf, on day %d\n", highestTemp, highestDay);
  printf("The lowest temperature was %.0lf, on day %d\n", lowestTemp, lowestDay);

  printf("\nEnter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
  scanf("%d", &avgDay);

  while (avgDay > day || avgDay == 0) { // Only runs if value is over number of days or equals 0.
    printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", day);
    scanf("%d", &avgDay);
  }

  while (avgDay > 0) { // Only runs if value entered is greater than zero.
    for (i = 0; i < avgDay; i++) { // Loops for the amount of days, getting average temps for each day.
      TDV = TDV + lowTemp[i] + highTemp[i];              // Records the total temperature values.
    }
    avg = TDV / (avgDay * 2); // Calculate the average.
    printf("\nThe average temperature up to day %d is: %.2lf\n", avgDay, avg);
    printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", day);
    scanf("%d", &avgDay);
    TDV = 0; // Reset value back to zero.
  }
  printf("\nGoodbye!\n");
  return 0;
}