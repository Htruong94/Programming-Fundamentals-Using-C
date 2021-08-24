
//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NPP
// Workshop:       5 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 4 //Defined maximum size of amount of employees

#include <stdio.h>

struct Employee { //Declared Struct Employee
	int id, age;
	double salary;
};

int main(void) {
	int option = 0, idtrue = 0, idsearch = 0, idelement = 0, i = 0, totemp = 0; //initialize each variable to 0
	//id* used in idsearches, totemp == total amount of employees

	struct Employee Emp[SIZE] = { {0} }; //delcared employee struct of size "SIZE" with initialized elements to 0

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do { // Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
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
				for (i = SIZE-1; i >= 0; i--) { //loops until lowest element value with the id value of 0
					if (Emp[i].id == 0)
						idelement = i;//take the lowest i value of id equal to 0
				}
				printf("Enter Employee ID: ");
				scanf("%d", &Emp[idelement].id);
				printf("Enter Employee Age: ");
				scanf("%d", &Emp[idelement].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &Emp[idelement].salary);
				printf("\n");
				totemp++;//increase total employee amount by 1
				idelement = 0;//resets idelement to 0
			}
			break;

		case 3: //Update Employee Salary
			printf("Update Employee Salary\n");
			printf("======================\n");
			printf("Enter Employee ID: ");
			scanf("%d", &idsearch);
			do { //search through each employee and see if ID matches and employee
				for (i = 0; i < SIZE; i++) {
					if (idsearch == Emp[i].id) {
						idtrue = 1;
						idelement = i;
					}
				}
				if (idtrue == 0) { //situation when no employee has that id
					printf("*** ERROR: Employee ID not found! ***\n");
					printf("Enter Employee ID: ");
					scanf("%d", &idsearch);
				}
				else { //found the employee with the id and now updates inputted salary
					printf("The current salary is %.2lf\n", Emp[idelement].salary);
					printf("Enter Employee New Salary: ");
					scanf("%lf", &Emp[idelement].salary);
				}
			} while (idtrue == 0);
			idtrue = 0; //resets idtrue and idelement to 0
			idelement = 0;
			printf("\n");
			break;

		case 4: //Remove Employee
			printf("Remove Employee\n");
			printf("===============\n");
			
			printf("Enter Employee ID: ");//from here to end of if(idtrue == 0) is same as case 3
			scanf("%d", &idsearch);
			do {
				for (i = 0; i < SIZE; i++) {
					if (idsearch == Emp[i].id) {
						idtrue = 1;
						idelement = i;
					}
				}
				if (idtrue == 0) {
					printf("*** ERROR: Employee ID not found! ***\n");
					printf("Enter Employee ID: ");
					scanf("%d", &idsearch);
				}
				else {
					printf("Employee %d will be removed\n", Emp[idelement].id);
					Emp[idelement].id = 0; //set id value to 0
					totemp--; //reduce total amount of employees by 1
				}
			} while (idtrue == 0);
			idtrue = 0;
			idelement = 0; //resets idtrue and idelement to 0
			printf("\n");
			break;

		default: //prints error message if input is not 0, 1, 2 or 3
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	printf("Exiting Employee Data Program. Good Bye!!!\n");

	return 0;
}
