//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NPP
// Workshop:       3 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#define NUMS 4
// Put your code below:

#include<stdio.h>

int main(void) {
	int th, tl; //variables for high temperature and low temperature
	int i; //represent day number
	//below variables represents the additional variables required to obtain highest/lowest temp on its day and the average temperature
	int highestTemp = 0;
	int	lowestTemp = 0;
	int ih = 0; //highest temperature day
	int il = 0; //lowest temperature day
	int sumTempH = 0;
	int	sumTempL = 0;
	double avrTempH, avrTempL, avrTemp;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 1; i <= NUMS; i++) {//for loop for when day is 1 and iterates until day 3
		printf("Enter the high value for day %d: ", i);
		scanf("%d", &th);
		printf("\n");

		printf("Enter the low value for day %d: ", i);
		scanf("%d", &tl);
		printf("\n");

		while (th < tl|| th > 40 || tl < -40) {//loop until user inputs a tl that is lower than th and th and tl is within the range of -40 to 40. 
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");

			printf("Enter the high value for day %d: ", i); //same statement as before the while loop
			scanf("%d", &th);
			printf("\n");

			printf("Enter the low value for day %d: ", i);
			scanf("%d", &tl);
			printf("\n");
		}
		sumTempH += th; //Taking the sum of all correctly inputed high temperature
		sumTempL += tl; //Taking the sum of all correctly inputed low temperature
		
		if (th > highestTemp) {//Taking the highest input temperature and its corresponding day, replaces old highest record
			highestTemp = th;
			ih = i;
		}
	

		if (tl < lowestTemp) {//Taking the lowest input temperature and its corresponding day, replace old lowest recorc
			lowestTemp = tl;
			il = i;
		}
	}

	avrTempH = (double)sumTempH / NUMS; //Taking the sum temperature and divided by the number of days listed as NUMS, same as line below
	avrTempL = (double)sumTempL / NUMS;
	avrTemp = (avrTempH + avrTempL) / 2; //Taking the sum of two averages and divided by 2 for the overall average
	
	printf("The average (mean) LOW temperature was: %.2lf\n", avrTempL);
	printf("The average (mean) HIGH temperature was: %.2lf\n", avrTempH);
	printf("The average (mean) temperature was: %.2lf\n", avrTemp);
	printf("The highest temperature was %d, on day %d\n", highestTemp, ih);
	printf("The lowest temperature was %d, on day %d\n", lowestTemp, il);

	return 0;
}