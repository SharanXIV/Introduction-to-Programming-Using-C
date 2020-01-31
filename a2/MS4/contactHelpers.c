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

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:
void clearKeyboard(void) {
  while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void) {
  printf("(Press Enter to Continue)");
  clearKeyboard();
}

// getInt:
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

// getIntInRange:
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

// yes:
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

// menu:
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

// ContactManagerSystem:
void ContactManagerSystem(void) {
  char choice = 0;
  int option;
  struct Contact contacts[MAXCONTACTS] = {
  { { "Rick",{ '\0' }, "Grimes" },
  { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
  { "4161112222", "4162223333", "4163334444" } },
{
  { "Maggie", "R.", "Greene" },
  { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
  { "9051112222", "9052223333", "9053334444" } },
{
  { "Morgan", "A.", "Jones" },
  { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
  { "7051112222", "7052223333", "7053334444" } },
{
  { "Sasha",{ '\0' }, "Williams" },
  { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
  { "9052223333", "9052223333", "9054445555" } },
  };

  do {
    option = menu();

    switch (option) {
    case 1: // Display Contacts
      printf("\n");
      displayContacts(contacts, MAXCONTACTS);
      pause();
      printf("\n");
      break;
    case 2: // Add a contact
      printf("\n");
      addContact(contacts, MAXCONTACTS);
      pause();
      printf("\n");
      break;
    case 3: // Update a contact
      printf("\n");
      updateContact(contacts, MAXCONTACTS);
      pause();
      printf("\n");
      break;
    case 4: // Delete a contact
      printf("\n");
      deleteContact(contacts, MAXCONTACTS);
      pause();
      printf("\n");
      break;
    case 5: // Search for contact
      printf("\n");
      searchContacts(contacts, MAXCONTACTS);
      pause();
      printf("\n");
      break;
    case 6: // Sort contacts
      printf("\n");
      sortContacts(contacts, MAXCONTACTS);
      pause();
      printf("\n");
      break;
    case 0: // Exit
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


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10 chars entered)
void getTenDigitPhone(char telNum[]) {
  int needInput = 1;

  while (needInput == 1) {
    scanf("%10s", telNum);
    clearKeyboard();

    // (String Length Function: validate entry of 10 characters)
    if (strlen(telNum) == 10)
      needInput = 0;
    else
      printf("Enter a 10-digit phone number: ");
  }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]) {
  int i;
  int value = -1;
  for (i = 0; i < size; i++) {
    if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
      value = i;
    }
  }
  return value; // Index assigned to value; negative integer if unassigned
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void) {
  printf("+-----------------------------------------------------------------------------+\n");
  printf("|                              Contacts Listing                               |\n");
  printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int total) {
  printf("+-----------------------------------------------------------------------------+\n");
  printf("Total contacts: %d\n\n", total);
}

// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact *contact) {
  if (strcmp((*contact).name.middleInitial, "") == 0) { // No middle name value found
    printf(" %s %s\n", (*contact).name.firstName, (*contact).name.lastName);
  }
  else { // Middle name value > 0
    printf(" %s %s %s\n", (*contact).name.firstName, (*contact).name.middleInitial, (*contact).name.lastName);
  }

  printf("    C: %-10s   H: %-10s   B: %-10s\n", (*contact).numbers.cell, (*contact).numbers.home, (*contact).numbers.business); //Print numbers

  if ((*contact).address.apartmentNumber > 0) { // Apartment number valid
    printf("       %d %s, Apt# %d, %s, %s\n", (*contact).address.streetNumber, (*contact).address.street, (*contact).address.apartmentNumber, (*contact).address.city, (*contact).address.postalCode);
  }
  else { // No apartment number
    printf("       %d %s, %s, %s\n", (*contact).address.streetNumber, (*contact).address.street, (*contact).address.city, (*contact).address.postalCode);
  }
}

// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size) {
  int total = 0;
  int i;
  displayContactHeader();
  for (i = 0; i < size; i++) {
    if (strlen(contacts[i].numbers.cell) > 0) {
      displayContact(&contacts[i]);
      total = total + 1;
    }
  }
  displayContactFooter(total);
}

// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size) {
  int result;
  char cell[11];

  printf("Enter the cell number for the contact: ");
  getTenDigitPhone(cell);
  result = findContactIndex(contacts, size, cell); // Assign match to result

  if (result > -1) { // If match is valid
    printf("\n");
    displayContact(&contacts[result]);
    printf("\n");
  }
  else { // Match invalid
    printf("*** Contact NOT FOUND ***\n");
  }
}

// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size) {
  int empty = -1;
  int i;
  for (i = 0; i < size; i++) {
    if (strlen(contacts[i].numbers.cell) == 0) { // Find empty slot
      empty = i; // Assign to index
    }
  }
  if (empty > -1) { // If index has an assigned free slot
    getContact(&contacts[empty]);
    printf("--- New contact added! ---\n");
  }
  else { // No available slots; index still unassigned
    printf("*** ERROR: The contact list is full! ***");
    printf("\n");
  }
}

// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size) {
  char cell[11];
  int index;
  printf("Enter the cell number for the contact: ");
  getTenDigitPhone(cell);
  index = findContactIndex(contacts, size, cell); // Value assigned to index; negative integer if not found

  if (index > -1) { // If index is assigned and valid
    printf("\nContact found:\n");
    displayContact(&contacts[index]);

    printf("\nDo you want to update the name? (y or n): ");
    if (yes()) {
      getName(&contacts[index].name);
    }
    printf("Do you want to update the address? (y or n): ");
    if (yes()) {
      getAddress(&contacts[index].address);
    }
    printf("Do you want to update the numbers? (y or n): ");
    if (yes()) {
      getNumbers(&contacts[index].numbers);
    }
    printf("--- Contact Updated! ---\n");
  }
  else {// Negative integer for index
    printf("*** Contact NOT FOUND ***\n");
  }
}

// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size) {
  char cell[11];
  int index;
  printf("Enter the cell number for the contact: ");
  getTenDigitPhone(cell);
  index = findContactIndex(contacts, size, cell);

  if (index > -1) {
    printf("\nContact found:\n");
    displayContact(&contacts[index]);
    printf("\nCONFIRM: Delete this contact? (y or n): ");
    if (yes()) {
      contacts[index].numbers.cell[0] = '\0';
      printf("--- Contact deleted! ---\n");
    }
  }
  else {
    printf("*** Contact NOT FOUND ***\n");
  }
}

// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size) {
  int total = 0;
  int i, j;
  struct Contact hold;

  for (i = 0; i < size; i++) {
    if (strlen(contacts[i].numbers.cell) > 0) { // Finding total of indices with info
      total = total + 1;
    }
  }

  for (i = 0; i < total - 1; i++) { // String Bubble Sort 
    for (j = i; j < total; j++) {
      if (strcmp(contacts[i].numbers.cell, contacts[j].numbers.cell) > 0) { // Sorting by 'contacts[i]'s cell number > contact[j]'s cell number'
        hold = contacts[i]; // Placeholder for swap
        contacts[i] = contacts[j];
        contacts[j] = hold;
      }
    }
  }

  printf("--- Contacts sorted! ---\n");
}