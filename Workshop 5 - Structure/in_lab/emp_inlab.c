
//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NPP
// Workshop:       5 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 2 //Defined maximum size of amount of employees

#include <stdio.h>

struct Employee { //Declared Struct Employee
	int id, age;
	double salary;
};

int main(void) {
	int option = 0;
	int totemp = 0;
	int i = 0; //total number of employee initialized to 0


	struct Employee Emp[SIZE] = { {0} }; //delcared employee struct of size "SIZE" with initialized elements to 0

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do { // Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		scanf("%d", &option); // Capture input to option variable
		printf("\n");

		switch (option) {
		case 0:	// Exit the program

			break;

		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			
			for (i = 0; i < SIZE; i++) {
				if (Emp[i].id > 0) { //print only when id is greater than 0
					printf("%6d%9d%11.2lf\n", Emp[i].id, Emp[i].age, Emp[i].salary); //prints id, age and salary of employees of id > 0 on a graph
				}
			}
			printf("\n");

			break;

		case 2:	// Adding Employee

			printf("Adding Employee\n");
			printf("===============\n");
			if (totemp == SIZE) //check if the employee count is equal or less than the maximum size
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			else { //input employee id, age and salary and store them in the struct array
				printf("Enter Employee ID: ");
				scanf("%d", &Emp[totemp].id);
				printf("Enter Employee Age: ");
				scanf("%d", &Emp[totemp].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &Emp[totemp].salary);
				printf("\n");
				totemp++;
			}
			break;

		default: //prints error message if input is not 0, 1, 2 or 3
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	printf("Exiting Employee Data Program. Good Bye!!!\n");

	return 0;
}
