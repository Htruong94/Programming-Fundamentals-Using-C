//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NPP
// Workshop:       2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications
#include<stdio.h>

int main(void)
{
	double amountOwing;
	double GST;
	int Loonies, Quarters, Dimes, Nickels, Pennies, balance100; //balance100 represents the integer value of amountOwing

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amountOwing); //user input on how much money is needed to be paid

	GST=amountOwing*.13+0.005; //calculates the amount of GST associated with the amount the user inputs while rounding up the value due to truncated in C
	amountOwing += GST; //calculates the amount of money owed with GST

	printf("GST: %.2lf\n", GST);
	printf("Balance owing: $%.2lf\n", amountOwing);

	Loonies = amountOwing / 1; //Taking the integer amount of coins from amountOwing according to the value of the coin
	balance100 = amountOwing*100; //integer amount of amountOwing in cents
	amountOwing = balance100 % 100;  // modulus of the cent value of the balance using the cent value of the coin
	amountOwing /= 100; //converting back to dollar cent format after calculations

	printf("Loonies required: %d, balance owing $%.2lf\n", Loonies, amountOwing);

	Quarters = amountOwing / 0.25; //same as above with value adjusted to fit to the according value of coins [for quarters, dimes, nickels, pennies]
	balance100 = amountOwing * 100;
	amountOwing = balance100 % 25; 
	amountOwing /= 100;

	printf("Quarters required: %d, balance owing $%.2lf\n", Quarters, amountOwing);
	Dimes = amountOwing / 0.1;
	balance100 = amountOwing * 100;
	amountOwing = balance100 % 10; 
	amountOwing /= 100;

	printf("Dimes required: %d, balance owing $%.2lf\n", Dimes, amountOwing);

	Nickels = amountOwing / 0.05;
	balance100 = amountOwing * 100;
	amountOwing = balance100 % 5; 
	amountOwing /= 100;

	printf("Nickels required: %d, balance owing $%.2lf\n", Nickels, amountOwing);

	Pennies = amountOwing / 0.01;
	balance100 = amountOwing * 100;
	amountOwing = balance100 % 1; 
	amountOwing /= 100;

	printf("Pennies required: %d, balance owing $%.2lf\n", Pennies, amountOwing);

	return 0;
}