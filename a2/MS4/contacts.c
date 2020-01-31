/* -------------------------------------------
Name: Sharan Shanmugaratnam
Student number: 153601174
Email: sshanmugaratnam2@myseneca.ca
Section: IPC144QQ
Date: 4/5/2018
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+

#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name * name) {
  printf("Please enter the contact's first name: ");
  scanf(" %[^\n]30s", name->firstName);

  printf("Do you want to enter a middle initial(s)? (y or n): ");
  
  if (yes()) {
    printf("Please enter the contact's middle initial(s): ");
    scanf(" %[^\n]6s", name->middleInitial);
  }

  printf("Please enter the contact's last name: ");
  scanf(" %[^\n]35s", name->lastName);
}

// getAddress:
void getAddress(struct Address * address) {

  printf("Please enter the contact's street number: ");
  address->streetNumber = getInt();

  printf("Please enter the contact's street name: ");
  scanf("%[^\n]", address->street);

  printf("Do you want to enter an apartment number? (y or n): ");
  
  if (yes()) {
    printf("Please enter the contact's apartment number: ");
    scanf("%d", &address->apartmentNumber);
  }
  else {
    address->apartmentNumber = '\0';
  }

  printf("Please enter the contact's postal code: ");
  scanf(" %7[^\n]", address->postalCode);

  printf("Please enter the contact's city: ");
  scanf(" %40[^\n]", address->city);
}

// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable
void getNumbers(struct Numbers * numbers) {

  printf("Please enter the contact's cell phone number: ");
  getTenDigitPhone(numbers->cell);

  printf("Do you want to enter a home phone number? (y or n): ");
  
  if (yes()) {
    printf("Please enter the contact's home phone number: ");
    getTenDigitPhone(numbers->home);
  }
  else {
    numbers->home[0] = '\0';
  }
  printf("Do you want to enter a business phone number? (y or n): ");
 
  if (yes()) {
    printf("Please enter the contact's business phone number: ");
    getTenDigitPhone(numbers->business);
  }
  else {
    numbers->business[0] = '\0';
  }
}

// getContact
void getContact(struct Contact * contact) {
  getName(&contact->name);
  getAddress(&contact->address);
  getNumbers(&contact->numbers);
}