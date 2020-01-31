/*
Name:      Sharan Shanmugaratnam
Student#:  153601174
Section:   IPC144SQQ
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Start your code below:

int main(void) {
  int loon;
  int quart;
  int dime;
  int nick;
  int pen;
  int intBalance;
  float balance;
  float gst;

  printf("Please enter the amount to be paid: $");
  scanf("%f", &balance);

  gst = balance * .13 + .005;         //calculate GST for balance
  
  printf("GST: %1.2f\n", gst);       //prints the GST seperately

  balance = gst + balance;             //add GST to balance

  printf("Balance owing: $%1.2f\n", balance);

  loon = balance;
  balance = balance - loon;           //removing the loonies from balance

  printf("Loonies required: %d, balance owing $%1.2f\n", loon, balance);

  balance = balance * 100;             //make balance integer friendly
  intBalance = balance;                //store balance as int

  quart = intBalance / 25;                 //will give us number of quarters
  intBalance = intBalance % 25;            //will give us modulus for balance
  
  printf("Quarters required: %d, balance owing $%1.2f\n", quart, (float)intBalance/100);

  dime = intBalance / 10;
  intBalance = intBalance % 10;
  printf("Dimes required: %d, balance owing $%1.2f\n", dime, (float)intBalance/100);

  nick = intBalance / 5;
  intBalance = intBalance % 5;
  printf("Nickels required: %d, balance owing $%1.2f\n", nick, (float)intBalance/100);

  pen = intBalance;
  intBalance = intBalance - pen;
  printf("Pennies required: %d, balance owing $%1.2f\n", pen, (float)intBalance/100);

  return 0;
}