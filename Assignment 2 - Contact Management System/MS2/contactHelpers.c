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

// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void) {
    while (getchar() != '\n'); // empty execution code block on purpose
}


// pause function definition goes here:
void pause(void) { //pauses the program until user presses enter
    printf("(Press Enter to Continue)");
    clearKeyboard();
}


/// getInt function definition goes here:
int getInt(void) { //obtains an integer value from the user and displays error if a non-integer value is inputted and ask until integer is obtained
    int igr = 0;
    char NL = ' '; //takes the enter key when obtaining the integer so the enter does not stay in the buffer

    scanf(" %d%c", &igr, &NL);

    while (NL != '\n') {
        clearKeyboard();
        printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        scanf(" %d%c", &igr, &NL);
    }

    return igr;
}


/// getIntInRange function definition goes here:
int getIntInRange(int min, int max) { //obtains integer within a given range and displays error when integer is out of range until integer within range is obtained
    int rangeNum = 0;
    rangeNum = getInt();

    while (rangeNum < min || rangeNum > max) {
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        rangeNum = getInt();
    }

    return rangeNum;
}


// yes function definition goes here:
int yes(void) { //Obtains a Y, y, N, n response from the user and convert it to 1 (y,Y) or 0 (n,N) which is returned
    char yesNo = ' ';
    char extraChar = ' ';
    int y = 0;
    scanf(" %c%c", &yesNo, &extraChar);

    while (!((extraChar == '\n') && (yesNo == 'Y' || yesNo == 'y' || yesNo == 'N' || yesNo == 'n'))) {
        clearKeyboard();
        printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        scanf(" %c%c", &yesNo, &extraChar);
    }
    
    if (yesNo == 'Y' || yesNo == 'y')
        y = 1;

    return y;
}


// menu function definition goes here:
int menu(void) { //displays the menu choices and obtains a value which corresponds to the listed menu option
    int menuChoice = 7;

    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n\n");
    printf("Select an option:> ");

    menuChoice = getInt();

    return menuChoice;
}



// contactManagerSystem function definition goes here:
void contactManagerSystem(void) { //prints the menu option obtained from menu function until user decides to exit
    int featureNum = 7; //menu option number
    int exit = 0;

    do {
        featureNum = menu();

        while (featureNum < 0 || featureNum > 6) {
            printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
            featureNum = getInt();
        }

        if (featureNum == 1) {
            printf("\n<<< Feature 1 is unavailable >>>\n\n");
            pause();
            printf("\n");
        }

        else if (featureNum == 2) {
            printf("\n<<< Feature 2 is unavailable >>>\n\n");
            pause();
            printf("\n");
        }

        else if (featureNum == 3) {
            printf("\n<<< Feature 3 is unavailable >>>\n\n");
            pause();
            printf("\n");
        }

        else if (featureNum == 4) {
            printf("\n<<< Feature 4 is unavailable >>>\n\n");
            pause();
            printf("\n");
        }
            
        else if (featureNum == 5) {
            printf("\n<<< Feature 5 is unavailable >>>\n\n");
            pause();
            printf("\n");
        }
            
        else if (featureNum == 6) {
            printf("\n<<< Feature 6 is unavailable >>>\n\n");
            pause();
            printf("\n");
        }
            
        else {
            printf("\nExit the program? (Y)es/(N)o: ");
            exit = yes();
            printf("\n");
            if (exit == 1)
                printf("Contact Management System: terminated\n");
        }

        featureNum = 7;

    } while (exit == 0);
}