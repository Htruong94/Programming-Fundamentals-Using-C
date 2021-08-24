//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NPP
// Date:           March 28, 2020        
//==============================================
// Assignment:     2
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

// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these function to use the helper 
//        functions where applicable (ex: yes() and getInt() )

// getName:
void getName(struct Name* name) { //function to obtain and store the first, middle (optional) and last name from user input
    int YesNo = 0; //Decision variable

    printf("Please enter the contact's first name: "); 
    scanf(" %30[^\n]", name->firstName); //allows for spaces to be inputted into char
    
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    YesNo = yes(); //Streamline yes/no through calling yes function

    if (YesNo == 1) {
        printf("Please enter the contact's middle initial(s): ");
        scanf(" %6[^\n]", name->middleInitial); //arrow points to the address
        clearKeyboard();
    }
    else
        name->middleInitial[0] = '\0'; //sets string to null

    printf("Please enter the contact's last name: ");
    scanf(" %35[^\n]", name->lastName);
}

// getAddress:
void getAddress(struct Address* address) { //function to obtain and store the contact's full address through user input
    int YesNo = 0; //Decision variable

    printf("Please enter the contact's street number: ");
    address->streetNumber = getInt(); //streamlines obtaining an integer
    
    while (address->streetNumber < 0) { //asks until a positive number is inputted
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        address->streetNumber = getInt();
    }

    printf("Please enter the contact's street name: ");
    scanf(" %40[^\n]", address->street);

    printf("Do you want to enter an apartment number? (y or n): ");
    YesNo = yes();

    if (YesNo == 1) {
        printf("Please enter the contact's apartment number: ");
        address->apartmentNumber = getInt();

        while (address->apartmentNumber < 0) {
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            address->apartmentNumber = getInt();
        }
    }
    else
        address->apartmentNumber = 0;

    printf("Please enter the contact's postal code: ");
    scanf(" %7[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf(" %40[^\n]", address->city);
}

// getNumbers:
void getNumbers(struct Numbers* numbers) { //function to obtain and store the phone numbers (all optional except cellphone) of the contact through user input
    int YesNo = 0; //Decision variable

    printf("Please enter the contact's cell phone number: ");
    scanf(" %10[^\n]", numbers->cell);


    printf("Do you want to enter a home phone number? (y or n): ");
    YesNo = yes();

    if (YesNo == 1) {
        printf("Please enter the contact's home phone number: ");
        scanf(" %10[^\n]", numbers->home);
    }
    else
        numbers->home[0] = '\0';
    YesNo = 0;

    printf("Do you want to enter a business phone number? (y or n): ");
    YesNo = yes();

    if (YesNo == 1) {
        printf("Please enter the contact's business phone number: ");
        scanf(" %10[^\n]", numbers->business);
    }
    else
        numbers->business[0] = '\0';
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+


// getContact:
void getContact(struct Contact* contact) { //get data from cont and points it to contacts
    struct Contact Cont;

    getName(&Cont.name);
    getAddress(&Cont.address);
    getNumbers(&Cont.numbers);

    *contact = Cont;
}