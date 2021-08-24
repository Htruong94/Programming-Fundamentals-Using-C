//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NPP
// Workshop:       3 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#define NUMS 3
// Put your code below:

#include<stdio.h>

int main(void)
{
	int th, tl; //variable for high temperature and low temperature
	int i; //represent day number
	
	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 1; i <= NUMS; i++) //for loop for when day is 1 and iterates until day 3
	{
		printf("Enter the high value for day %d: ", i);
		scanf("%d", &th);
		printf("\n");

		printf("Enter the low value for day %d: ", i);
		scanf("%d", &tl);
		printf("\n");
	
		while (th < tl || th > 40 || tl < -40) //loop until user inputs a tl that is lower than th and th and tl is within the range of -40 to 40. 
		{
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low. \n\n");
		
			printf("Enter the high value for day %d: ", i); //same statement as before the while loop
			scanf("%d", &th);
			printf("\n");

			printf("Enter the low value for day %d: ", i);
			scanf("%d", &tl);
			printf("\n");
		}
	}
	
	
	return 0;
}