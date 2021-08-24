//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NPP
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:

#include<stdio.h>

int main(void)
{
	double money, balance; //balance represents the money left after taking in account of loonies and then quarters
	int Loonies, Quarters;

	printf("Please enter the amount to be paid: $");
	scanf_s("%lf", &money); //user input on how much money is needed to be paid

	Loonies = money; //converting money [double variable] into an int variable while keeping money variable
	balance = money - Loonies; //obtain the cent balance after taking out the dollar amount
	Quarters = balance / 0.25;
	printf("Loonies required: %d, balance owing $%.2lf\n", Loonies, balance);
	balance -= ((double)Quarters * 0.25); //casting intg variable quarters into a double
	printf("Quarters required: %d, balance owing $%.2lf\n", Quarters, balance);
	
	return 0;
}