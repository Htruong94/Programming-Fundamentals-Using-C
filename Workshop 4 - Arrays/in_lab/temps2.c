//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NPP
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(void) {
	
	int days;
	int i;
	int th[11]; //picking the size of + 1 of maximum days allowed, array represents high temperatures
	int tl[11]; // array represents low temperature

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);
	printf("\n");

	while (days < 3 || days > 10) { //infinite loops until a number between 3 to 10 is picked
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &days);
		printf("\n");
	}

	for (i = 1; i <= days; i++) { //loop to obtain high and low temperature for each day through user input
		printf("Day %d - High: ", i);
		scanf("%d", &th[i]);
		printf("Day %d - Low: ", i);
		scanf("%d", &tl[i]);
	}

	printf("\nDay  Hi  Low\n");
	for (i = 1; i <= days; i++) //loops to show a table of the day with its corresponding high and low temperature
		printf("%d    %d    %d\n", i, th[i], tl[i]);

	return 0;
}