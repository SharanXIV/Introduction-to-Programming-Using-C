/* -------------------------------------------
Name: Sharan Shanmugaratnam
Student number: 153601174
Email: sshanmugaratnam2@myseneca.ca
Section: IPC144QQ
Date: 4/5/2018
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "contactHelpers.h"


// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void) {
  while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void) {
  printf("(Press Enter to Continue)");
  clearKeyboard();
}


// getInt function definition goes here:
int getInt(void) {
  char check = 'x';
  int value;
  do {
    scanf("%d%c", &value, &check);
    if (check != '\n') {
      clearKeyboard();
      printf("*** INVALID INTEGER *** <Please enter an integer>: ");
    }
  } while (check != '\n');
  return value;
}

// getIntInRange function definition goes here:
int getIntInRange(int param1, int param2) {
  int value;
  do {
    value = getInt();
    if (value < param1 || value > param2) {
      printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", param1, param2);
    }
  } while (value < param1 || value > param2);
  return value;
}

// yes function definition goes here:
int yes(void) {
  char entry, check;
  int value = 0;

  do {
    scanf(" %c%c", &entry, &check);
    if (check != '\n') {
      printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
      clearKeyboard();
    }
    else {
      if (entry == 'Y' || entry == 'y') {
        value = 1;
      }
    }
  } while (check != '\n');

  return value;
}


// menu function definition goes here:
int menu(void) {
  printf("Contact Management System\n");
  printf("-------------------------\n");
  printf("1. Display contacts\n");
  printf("2. Add a contact\n");
  printf("3. Update a contact\n");
  printf("4. Delete a contact\n");
  printf("5. Search contacts by cell phone number\n");
  printf("6. Sort contacts by cell phone number\n");
  printf("0. Exit\n");
  printf("\n");
  printf("Select an option:> ");
  return getIntInRange(0, 6);
}

// ContactManagerSystem function definition goes here:
void ContactManagerSystem(void) {
  char choice = 0;
  int option;

  do {
    option = menu();

    switch (option) {
    case 1:
      printf("\n<<< Feature 1 is unavailable >>>\n\n");
      pause();
      printf("\n");
      break;
    case 2:
      printf("\n<<< Feature 2 is unavailable >>>\n\n");
      pause();
      printf("\n");
      break;
    case 3:
      printf("\n<<< Feature 3 is unavailable >>>\n\n");
      pause();
      printf("\n");
      break;
    case 4:
      printf("\n<<< Feature 4 is unavailable >>>\n\n");
      pause();
      printf("\n");
      break;
    case 5:
      printf("\n<<< Feature 5 is unavailable >>>\n\n");
      pause();
      printf("\n");
      break;
    case 6:
      printf("\n<<< Feature 6 is unavailable >>>\n\n");
      pause();
      printf("\n");
      break;
    case 0:
      printf("\nExit the program? (Y)es/(N)o: ");
      if (yes() == 1) {
        choice = 1;
      }
      printf("\n");
      break;
    }
  } while (choice != 1);
  printf("Contact Management System: terminated\n");
}