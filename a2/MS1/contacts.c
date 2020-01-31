/* -------------------------------------------
Name: Sharan Shanmugaratnam
Student number: 153601174
Email: sshanmugaratnam2@myseneca.ca
Section: IPC144QQ
Date: 4/5/2018
----------------------------------------------
Assignment: 2
Milestone:  1
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

#include "contacts.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function definitions below...            |
// +-------------------------------------------------+

// getName:
void getName(struct Name * name) {
  printf("Please enter the contact's first name: ");
  scanf("%30s", name->firstName);

  printf("Do you want to enter a middle initial(s)? (y or n): ");
  scanf("%1s", check);

  if (check[0] != 'n') {
    printf("Please enter the contact's middle initial(s): ");
    scanf("%6s", name->middleInitial);
  }

  printf("Please enter the contact's last name: ");
  scanf("%35s", name->lastName);
}

// getAddress:
void getAddress(struct Address * address) {

  printf("Please enter the contact's street number: ");
  scanf("%d", &address->streetNumber);

  printf("Please enter the contact's street name: ");
  scanf("%40s", address->street);

  printf("Do you want to enter an apartment number? (y or n): ");
  scanf("%1s", check);

  if (check[0] != 'n') {
    printf("Please enter the contact's apartment number: ");
    scanf("%d", &address->apartmentNumber);
  }

  printf("Please enter the contact's postal code: ");
  scanf(" %7[^\n]", address->postalCode);

  printf("Please enter the contact's city: ");
  scanf("%40s", address->city);
}

// getNumbers:
void getNumbers(struct Numbers * numbers) {
  printf("Do you want to enter a cell phone number? (y or n): ");
  scanf("%1s", check);

  if (check[0] != 'n') {
    printf("Please enter the contact's cell phone number: ");
    scanf("%20s", numbers->cell);
  }

  printf("Do you want to enter a home phone number? (y or n): ");
  scanf("%1s", check);

  if (check[0] != 'n') {
    printf("Please enter the contact's home phone number: ");
    scanf("%20s", numbers->home);
  }

  printf("Do you want to enter a business phone number? (y or n): ");
  scanf("%1s", check);

  if (check[0] != 'n') {
    printf("Please enter the contact's business phone number: ");
    scanf("%20s", numbers->business);
  }
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact * contact){
  // Use an open and close curly brace with a blank line
}
