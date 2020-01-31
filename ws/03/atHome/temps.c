// Name: Sharan Shanmugaratnam
// Student Number: 153601174
// Email: sshanmugaratnam2@myseneca.ca
// Section: IPC144QQ
// Workshop: 3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUMS 4                          //The single change to add an extra day.

// Put your code below:

int main(void) {
  int day;
  double highTemp;
  double lowTemp;
  double TLV = 0;
  double THV = 0;
  double avg;
  int highestDay;
  int lowestDay;
  double highestTemp = 0;
  double lowestTemp = 0;

  printf("---=== IPC Temperature Analyzer ===---"); //print title

  for (day = 1; day < NUMS + 1; day++) {
    printf("\nEnter the high value for day %d: ", day);
    scanf("%lf", &highTemp);
    printf("\nEnter the low value for day %d: ", day);
    scanf("%lf", &lowTemp);

    while (highTemp <= lowTemp || highTemp >= 41 || lowTemp <= -41) { // Only runs if value is invalid.
      printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");

      printf("\nEnter the high value for day %d: ", day);
      scanf("%lf", &highTemp);
      printf("\nEnter the low value for day %d: ", day);
      scanf("%lf", &lowTemp);

    }

    if (highTemp >= highestTemp) {    //If temperature of this current day is lower it will not execute if statement.
      highestTemp = highTemp;
      highestDay = day;               //Also records the current day of the high temperature.
    }

    if (lowTemp <= lowestTemp) {      //If temperature of this current day is higher it will not execute if statement.
      lowestTemp = lowTemp;
      lowestDay = day;                //Also records the current day of the low temperature.
    }

    TLV = TLV + lowTemp;              //Records the total low temperature values.
    THV = THV + highTemp;             //Records the total high temperature values.

  }

  avg = (TLV + THV) / (NUMS * 2);     //Finds the mean temperature.
  printf("\nThe average (mean) temperature was: %.2lf\n", avg);
  printf("The highest temperature was %.0lf, on day %d\n", highestTemp, highestDay);
  printf("The lowest temperature was %.0lf, on day %d\n", lowestTemp, lowestDay);

  return 0;
}