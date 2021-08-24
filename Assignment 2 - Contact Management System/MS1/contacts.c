//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NPP
// Date:           March 26, 2020        
//==============================================
// Assignment:     2
// Milestone:      1
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function definitions below...            |
// +-------------------------------------------------+


// getName:
void getName(struct Name* name) { //function to obtain and store the first, middle (optional) and last name from user input
    char YesNo = 0; //Decision variable
    int valid = 0; //Validation variable

    printf("Please enter the contact's first name: ");
    scanf(" %[^\n]", name->firstName); //allows for spaces to be inputted into char

    do {
        printf("Do you want to enter a middle initial(s)? (y or n): ");
        scanf(" %c", &YesNo); //space before specifier to avoid overflow

        if (YesNo == 'y' || YesNo == 'Y') { //Accepts both capitalize or uncapitalize letter
            printf("Please enter the contact's middle initial(s): ");
            scanf(" %[^\n]", name->middleInitial);
            valid = 1;
        }
        else if (YesNo == 'n' || YesNo == 'N')
            valid = 1;
        else
            printf("Invalid entry, please try again.\n");
    } while (valid == 0);

    valid = 0;
    YesNo = 0;

    printf("Please enter the contact's last name: ");
    scanf(" %[^\n]", name->lastName);
}

// getAddress:
void getAddress(struct Address* addr) { //function to obtain and store the contact's full address through user input
    char YesNo = 0; //Decision variable
    int valid = 0; //Validation variable

    printf("Please enter the contact's street number: ");
    scanf("%d", &addr->streetNumber);

    printf("Please enter the contact's street name: ");
    scanf(" %[^\n]", addr->street);

    do {
        printf("Do you want to enter an apartment number? (y or n): ");
        scanf(" %c", &YesNo);

        if (YesNo == 'y' || YesNo == 'Y') {
            printf("Please enter the contact's apartment number: ");
            scanf(" %d", &addr->apartmentNumber);
            valid = 1;
        }
        else if (YesNo == 'n' || YesNo == 'N')
            valid = 1;
        else
            printf("Invalid entry, please try again.\n");
    } while (valid == 0);

    valid = 0;

    printf("Please enter the contact's postal code: ");
    scanf(" %[^\n]", addr->postalCode);

    printf("Please enter the contact's city: ");
    scanf(" %[^\n]", addr->city);
}

// getNumbers:
void getNumbers(struct Numbers* num) { //function to obtain and store the phone numbers (all optional) of the contact through user input
    char YesNo = 0; //Decision variable
    int valid = 0; //Validation variable

    do {
        printf("Do you want to enter a cell phone number? (y or n): ");
        scanf(" %c", &YesNo);

        if (YesNo == 'y' || YesNo == 'Y') {
            printf("Please enter the contact's cell phone number: ");
            scanf(" %[^\n]", num->cell);
            valid = 1;
        }
        else if (YesNo == 'n' || YesNo == 'N')
            valid = 1;
        else
            printf("Invalid entry, please try again.\n");
    } while (valid == 0);

    valid = 0;

    do {
        printf("Do you want to enter a home phone number? (y or n): ");
        scanf(" %c", &YesNo);

        if (YesNo == 'y' || YesNo == 'Y') {
            printf("Please enter the contact's home phone number: ");
            scanf(" %[^\n]", num->home);
            valid = 1;
        }
        else if (YesNo == 'n' || YesNo == 'N')
            valid = 1;
        else
            printf("Invalid entry, please try again.\n");
    } while (valid == 0);

    valid = 0;

    do {
        printf("Do you want to enter a business phone number? (y or n): ");
        scanf(" %c", &YesNo);

        if (YesNo == 'y' || YesNo == 'Y') {
            printf("Please enter the contact's business phone number: ");
            scanf(" %[^\n]", num->business);
            valid = 1;
        }
        else if (YesNo == 'n' || YesNo == 'N')
            valid = 1;
        else
            printf("Invalid entry, please try again.\n");
    } while (valid == 0);

    valid = 0;
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contact) {

}