//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NPP
// Date:           
//==============================================
// Assignment:     1
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

int main(void)
{
    // Declare variables here:
    struct Name Name = { {" "} }; //declaring structures and initializing char to empty value and int to 0
    struct Address Address = { 0,"",0,"","" };
    struct Numbers Numbers = { {" "} };
    char YesNo = 0; //Decision variable
    int valid = 0; //Validation variable

    // Display the title
    printf("Contact Management System\n");
    printf("-------------------------\n");


    // Contact Name Input:
    printf("Please enter the contact's first name: ");
    scanf(" %[^\n]", Name.firstName); //allows for spaces to be inputted into char

    do {
        printf("Do you want to enter a middle initial(s)? (y or n): ");
        scanf(" %c", &YesNo); //space before specifier to avoid overflow

        if (YesNo == 'y' || YesNo == 'Y') { //Accepts both capitalize or uncapitalize letter
            printf("Please enter the contact's middle initial(s): ");
            scanf(" %[^\n]", Name.middleInitial);
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
    scanf(" %[^\n]", Name.lastName);

    // Contact Address Input:
    printf("Please enter the contact's street number: ");
    scanf("%d", &Address.streetNumber);

    printf("Please enter the contact's street name: ");
    scanf(" %[^\n]", Address.street);

    do {
        printf("Do you want to enter an apartment number? (y or n): ");
        scanf(" %c", &YesNo);

        if (YesNo == 'y' || YesNo == 'Y') {
            printf("Please enter the contact's apartment number: ");
            scanf(" %d", &Address.apartmentNumber);
            valid = 1;
        }
        else if (YesNo == 'n' || YesNo == 'N')
            valid = 1;
        else
            printf("Invalid entry, please try again.\n");
    } while (valid == 0);

    valid = 0;

    printf("Please enter the contact's postal code: ");
    scanf(" %[^\n]", Address.postalCode);

    printf("Please enter the contact's city: ");
    scanf(" %[^\n]", Address.city);

    // Contact Numbers Input:

    do {
        printf("Do you want to enter a cell phone number? (y or n): ");
        scanf(" %c", &YesNo);

        if (YesNo == 'y' || YesNo == 'Y') {
            printf("Please enter the contact's cell phone number: ");
            scanf(" %[^\n]", Numbers.cell);
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
            scanf(" %[^\n]", Numbers.home);
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
            scanf(" %[^\n]", Numbers.business);
            valid = 1;
        }
        else if (YesNo == 'n' || YesNo == 'N')
            valid = 1;
        else
            printf("Invalid entry, please try again.\n");
    } while (valid == 0);

    valid = 0;

    printf("\n");
    // Display Contact Summary Details

    printf("Contact Details\n");
    printf("---------------\n");
    printf("Name Details:\n");
    printf("First name: %s\n", Name.firstName);
    printf("Middle initial(s): %s\n", Name.middleInitial);
    printf("Last name: %s\n\n", Name.lastName);

    printf("Address Details:\n");
    printf("Street number: %d\n", Address.streetNumber);
    printf("Street name: %s\n", Address.street);
    printf("Apartment: %d\n", Address.apartmentNumber);
    printf("Postal code: %s\n", Address.postalCode);
    printf("City: %s\n\n", Address.city);

    printf("Phone Numbers:\n");
    printf("Cell phone number: %s\n", Numbers.cell);
    printf("Home phone number: %s\n", Numbers.home);
    printf("Business phone number: %s\n\n", Numbers.business);

    // Display Completion Message
    printf("Structure test for Name, Address, and Numbers Done!\n");


    return 0;
}

/*  SAMPLE OUTPUT:

    Contact Management System
    -------------------------
    Please enter the contact's first name: Tom
    Do you want to enter a middle initial(s)? (y or n): y
    Please enter the contact's middle initial(s): L. A.
    Please enter the contact's last name: Wong Song
    Please enter the contact's street number: 20
    Please enter the contact's street name: Keele Street
    Do you want to enter an apartment number? (y or n): y
    Please enter the contact's apartment number: 40
    Please enter the contact's postal code: A8A 4J4
    Please enter the contact's city: North York
    Do you want to enter a cell phone number? (y or n): Y
    Please enter the contact's cell phone number: 9051116666
    Do you want to enter a home phone number? (y or n): Y
    Please enter the contact's home phone number: 7052227777
    Do you want to enter a business phone number? (y or n): Y
    Please enter the contact's business phone number: 4163338888

    Contact Details
    ---------------
    Name Details:
    First name: Tom
    Middle initial(s): L. A.
    Last name: Wong Song

    Address Details:
    Street number: 20
    Street name: Keele Street
    Apartment: 40
    Postal code: A8A 4J4
    City: North York

    Phone Numbers:
    Cell phone number: 9051116666
    Home phone number: 7052227777
    Business phone number: 4163338888

    Structure test for Name, Address, and Numbers Done!
*/