//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NPP
// Workshop:       4 (in-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(void) {

	int avrdaynum = 0; //initialize avrdaynum to 0
	int days, i, ih, il; //day number, highest temp day, lowest temp day
	double sumTemp = 0, dayavrTemp, avrTemp;
	int th[11] = { 0 }; //picking the size of + 1 of maximum days [10] allowed, array represents high temperatures, initialized to 0
	int tl[11] = { 0 }; //array represents low temperature

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);
	printf("\n");

	while (days < 3 || days > 10) { //infinite loops until a number between 3 to 10 is picked
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &days);
		printf("\n");
	}
	
	for (i = 1;i <= days; i++) { //loop to obtain high and low temperature for each day through user input
		printf("Day %d - High: ", i);
		scanf("%d", &th[i]);
		printf("Day %d - Low: ", i);
		scanf("%d", &tl[i]);
	}

	for (i = 1; i <= days; i++) { //stores the highest temperature in 0 slot in high temperature array, lowest temperature in 0 slot in low temperature array, take days into own variable
		if (th[0] < th[i]) {
			th[0] = th[i];
			ih = i;
		}
		if (tl[0] > tl[i]) {
			tl[0] = tl[i];
			il = i;
		}
	}

	printf("\nDay  Hi  Low\n");
	for (i = 1; i <= days; i++) //loops to show a table of the day with its corresponding high and low temperature
		printf("%d    %d    %d\n", i, th[i], tl[i]);

	printf("\nThe highest temperature was %d, on day %d\n", th[0], ih);
	printf("The lowest temperature was %d, on day %d\n\n", tl[0], il);

	do {
		printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", days);
		scanf("%d", &avrdaynum);
		printf("\n");

		while (avrdaynum > days || avrdaynum == 0) { //loops until user input a number that is not a 0 or higher than the amount of days
			printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", days);
			scanf("%d", &avrdaynum);
			printf("\n");
		}

		for (i = 1; i <= avrdaynum; i++) { //obtain sum of days 1 to the avrdaynum inputted
			dayavrTemp = (double)(th[i] + tl[i]) / 2; //cast temperatures to double
			sumTemp += dayavrTemp;
		}
		
		if (avrdaynum > 0) { //prints only when avrdaynum is not a negative number
			avrTemp = sumTemp / avrdaynum;
			printf("The average temperature up to day %d is: %.2lf\n\n", avrdaynum, avrTemp);

			dayavrTemp = 0; //resets dayavrTemp to 0
			sumTemp = 0; //resets sumTemp to 0
		}

	} while (avrdaynum >= 0); // loops until avrdaynum entered is a negative number

	printf("Goodbye!\n");

	return 0;
}