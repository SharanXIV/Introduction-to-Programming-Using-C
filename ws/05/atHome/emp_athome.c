/*
Name: Sharan Shanmugaratnam
Student number: 153601174
Email: sshanmugaratnam2@myseneca.ca
Workshop: 5 (in Lab)
Section: IPC144QQ
Date: 2/20/2018
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 4  // Define Number of Employees "SIZE" to be 2


// Declare Struct Employee 
struct Employee {
  int id;
  int age;
  double salary;
};

/* main program */
int main(void) {

  int option = 0;
  int i;
  int validEmployees = 0;
  int updateID;
  int exit;

  printf("---=== EMPLOYEE DATA ===---\n");

  // Declare a struct Employee array "emp" with SIZE elements 
  // and initialize all elements to zero
  struct Employee emp[SIZE] = { { 0 } };


  do {
    // Print the option list
    printf("\n1. Display Employee Information\n");
    printf("2. Add Employee\n");
    printf("3. Update Employee Salary\n");
    printf("4. Remove Employee\n");
    printf("0. Exit\n\n");
    printf("Please select from the above options: ");

    // Capture input to option variable
    scanf("%d", &option);
    printf("\n");

    switch (option) {
    case 0:	// Exit the program
      printf("Exiting Employee Data Program. Good Bye!!!\n");

      break;
    case 1: // Display Employee Data

      printf("EMP ID  EMP AGE EMP SALARY\n");
      printf("======  ======= ==========\n");

      for (i = 0; i < SIZE; i++) {
        if (emp[i].id > 0)
          printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
      }

      break;
    case 2:	// Adding Employee

      printf("Adding Employee\n");
      printf("===============\n");

      if (validEmployees < SIZE) {
        printf("Enter Employee ID: ");
        scanf("%d", &emp[validEmployees].id);
        printf("Enter Employee Age: ");
        scanf("%d", &emp[validEmployees].age);
        printf("Enter Employee Salary: ");
        scanf("%lf", &emp[validEmployees].salary);
        validEmployees++;
      }
      else {
        printf("ERROR!!! Maximum Number of Employees Reached\n");
      }


      break;
    case 3: // Update Employee Salary

      printf("Update Employee Salary\n");
      printf("======================\n");
      exit = 0; // Flag

      do {
        printf("Enter Employee ID: ");
        scanf("%d", &updateID);

        for (i = 0; i < SIZE; i++) { // Checks all the values in the array
          if (emp[i].id == updateID) { // If employee is found
            printf("The current salary is %.2lf\n", emp[i].salary);
            printf("Enter Employee New Salary: ");
            scanf("%lf", &emp[i].salary);
            exit = 1; // Flag is changed to allow exit from do while loop
          }
        }

        if (exit != 1) { // If employee is not found
          printf("Employee ID does not exist!\n");
        }
      } while (exit == 0);

      break;
    case 4: // Remove Employee

      printf("Remove Employee\n");
      printf("===============\n");

      do {
        printf("Enter Employee ID: ");
        scanf("%d", &updateID);
        exit = 0; // Flag

        for (i = 0; i < SIZE; i++) { // Checks all the values in the array
          if (emp[i].id == updateID) { // If employee is found
            printf("Employee %d will be removed\n", emp[i].id);
            emp[i].id = 0;
            validEmployees = validEmployees - 1; // Reduces valid # of employees by 1
            exit = 1; // Flag is changed to allow exit from do while loop
          }
        }

        if (exit != 1) { // If employee is not found
          printf("Employee ID does not exist!\n");
        }

      } while (exit == 0);

      break;

    default:
      printf("ERROR: Incorrect Option: Try Again\n");
    }

  } while (option != 0);


  return 0;
}






// PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 113
Enter Employee Age: 53
Enter Employee Salary: 120345.78

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 114
Enter Employee Age: 25
Enter Employee Salary: 46780

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   65000.00
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 112
The current salary is 65000.00
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   99999.99
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 112
Employee 112 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!
*/