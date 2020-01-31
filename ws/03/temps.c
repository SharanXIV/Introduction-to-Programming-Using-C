#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUMS 3


int main(void) {
  int day;
  double highTemp;
  double lowTemp;
  double TLV = 0;
  double THV = 0;
  double avg;

  printf("---=== IPC Temperature Analyzer ===---"); //print title

  for (day = 1; day < NUMS + 1; day++) {
    printf("\nEnter the high value for day %d: ", day);
    scanf("%lf", &highTemp);
    printf("\nEnter the low value for day %d: ", day);
    scanf("%lf", &lowTemp);

    while (highTemp <= lowTemp || highTemp >= 41 || lowTemp <= -41) {
      printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");

      printf("\nEnter the high value for day %d: ", day);
      scanf("%lf", &highTemp);
      printf("\nEnter the low value for day %d: ", day);
      scanf("%lf", &lowTemp);
    }

    TLV = TLV + lowTemp;
    THV = THV + highTemp;

  }

  avg = (TLV + THV) / (NUMS * 2);
  printf("\nThe average (mean) temperature was: %.2lf\n", avg);

  return 0;
}