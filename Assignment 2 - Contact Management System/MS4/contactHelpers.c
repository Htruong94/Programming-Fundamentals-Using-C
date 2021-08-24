//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NPP
// Date:           April 2, 2020 
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// -------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:
void clearKeyboard(void) {
    while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void) { //pauses the program until user presses enter
    printf("\n(Press Enter to Continue)");
    clearKeyboard();
}

// getInt:
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

// getIntInRange:
int getIntInRange(int min, int max) { //obtains integer within a given range and displays error when integer is out of range until integer within range is obtained
    int rangeNum = 0;
    rangeNum = getInt();

    while (rangeNum < min || rangeNum > max) {
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        rangeNum = getInt();
    }

    return rangeNum;
}

// yes:
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

// menu:
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

// contactManagerSystem:
void contactManagerSystem(void) { //prints the menu option obtained from menu function until user decides to exit
    int featureNum = 7; //menu option number
    int exit = 0;
    //intializing array with given contacts
    struct Contact contacts[MAXCONTACTS] = { { { "Rick", {'\0'}, "Grimes" }, { 11, "Trailer Park", 0, "A7A 2J2", "King City" }, { "4161112222", "4162223333", "4163334444" } }, {{ "Maggie", "R.", "Greene" }, { 55, "Hightop House", 0, "A9A 3K3", "Bolton" }, { "9051112222", "9052223333", "9053334444" } }, {{ "Morgan", "A.", "Jones" }, { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" }, { "7051112222", "7052223333", "7053334444" } }, { { "Sasha", {'\0'}, "Williams" }, { 55, "Hightop House", 0, "A9A 3K3", "Bolton" }, { "9052223333", "9052223333", "9054445555" } }, };
    
    do {
        featureNum = menu();

        while (featureNum < 0 || featureNum > 6) {
            printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
            featureNum = getInt();
        }

        if (featureNum == 1) {
            displayContacts(contacts, MAXCONTACTS); //gives function the struct contacts and the define size MAXCONTACTS
            pause();
            printf("\n");
        }

        else if (featureNum == 2) {
            addContact(contacts, MAXCONTACTS);
            pause();
            printf("\n");
        }

        else if (featureNum == 3) {
            updateContact(contacts, MAXCONTACTS);
            pause();
            printf("\n");
        }

        else if (featureNum == 4) {
            deleteContact(contacts, MAXCONTACTS);
            pause();
            printf("\n");
        }

        else if (featureNum == 5) {
            searchContacts(contacts, MAXCONTACTS);
            pause();
            printf("\n");
        }

        else if (featureNum == 6) {
            sortContacts(contacts, MAXCONTACTS);
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


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone: Obtains a 10 character long numeric string
void getTenDigitPhone(char phoneNum[]) {
    int needInput = 1;
    char* chr;  //stores non-int value from strtol
    int num = 0; //c-string conversion into num as a integer

    long int strtol(const char *num, char **nonint, int base); //strtol declaration

    while (needInput == 1) {
        scanf("%10s", phoneNum);
        clearKeyboard();

        num = strtol(phoneNum, &chr, 10); //converts string into long int and puts non-numeric character into ptr

        // (String Length Function: validate entry of 10 characters)
        if (strlen(phoneNum) == 10 && (*chr == '\0') && num != 0) //if input is 10 characters long or ptr has taken \0 in the end due to no non-numeric characters inputted.
            needInput = 0;
        else
            printf("Enter a 10-digit phone number: ");
        
        num = 0;
    }
    
}

// findContactIndex: Takes one phone number and compares to other strings to find a match and returns the index number if found, otherwise -1 representing false
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]) {
    int i; //index number
    int match = -1; //if no match, function returns -1

    for (i = 0; i < size && match == -1 ; i++) {
        if (strcmp(contacts->numbers.cell, cellNum) == 0) { //compares two strings if they match or not
            match = i;
        }
        else
            contacts++; //contacts index increase
    }
    return match;
}

// displayContactHeader:Gives header to contacts listing
void displayContactHeader(void) {
    printf("\n+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter:Gives footer to contacts listing and shows total amount of contacts
void displayContactFooter(int count) {
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n", count);
}

// displayContact: Gives detailed information of a contact that are stored in the struct
void displayContact(const struct Contact* contact) {
    
    printf(" %s", contact->name.firstName);
    if (*contact->name.middleInitial != '\0') { //ignores if the user didnt input the string
        printf(" %s", contact->name.middleInitial);
    }
    printf(" %s\n", contact->name.lastName);

    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
    if (contact->address.apartmentNumber != 0) {
        printf("Apt# %d, ", contact->address.apartmentNumber);
    }
   
    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts: Detailed information of all contacts that are stored in the struct
void displayContacts(const struct Contact contacts[], int size) {
    int i;
    int numCount = 0; //number of contacts

    displayContactHeader();
    for (i = 0; i < size; i++) { 
        if (strlen(contacts[i].numbers.cell) != 0) { //returns number of the cell string if the cell string is not equal to 0
            displayContact(&contacts[i]);
            numCount++;
        }
    }
    displayContactFooter(numCount);
}

// searchContacts: Takes user input phone number and sees if there is a match and show that contact's information if found
void searchContacts(const struct Contact contacts[], int size) {
    int match;
    char enterNum[11];//accepts phone number from user 
    
    printf("\nEnter the cell number for the contact: ");
    getTenDigitPhone(enterNum);
    match = findContactIndex(contacts, size, enterNum);

    if (match != -1) { //returned a value is true(!= -1)
        printf("\n");
        displayContact(&contacts[match]);
    }
    else { //return value is false (== -1)
        printf("*** Contact NOT FOUND ***\n");
    }
}

// addContact: Adds a new contact if it is not max contacts 
void addContact(struct Contact contacts[], int size) {
    int i;
    int done = 0; //if empty index is available, end loop
    
    printf("\n");
    
    for (i = 0; i < size && done == 0 ; i++) { //iterates until size is max or added a new contact
        if (strlen(contacts[i].numbers.cell) == 0) { //searches for empty contact by seeing if a cell number is 0
            getContact(&contacts[i]); //adds new contact information
            printf("--- New contact added! ---\n");
            done = 1;
        }
        else if (i == size - 1) {
            printf("*** ERROR: The contact list is full! ***\n");
        }
    }
}

// updateContact: Changes information of a contact
void updateContact(struct Contact contacts[], int size) {
    char enterNum[11];
    int match;
    int yn = 0; //takes yn value

    printf("\nEnter the cell number for the contact: ");
    getTenDigitPhone(enterNum);
    match = findContactIndex(contacts, size, enterNum);

    if (match != -1) { //updates contact information if match found
        printf("\nContact found:\n");
        displayContact(&contacts[match]);
        printf("\nDo you want to update the name? (y or n): ");
        yn = yes();
        if (yn == 1) {
            getName(&contacts[match].name);
            yn = 0;
        }

        printf("Do you want to update the address? (y or n): ");
        yn = yes();
        if (yn == 1) {
            getAddress(&contacts[match].address);
            yn = 0;
        }

        printf("Do you want to update the numbers? (y or n): ");
        yn = yes();
        if (yn == 1) {
            getNumbers(&contacts[match].numbers);
            yn = 0;
        }

        printf("--- Contact Updated! ---\n");
    }
    else {
        printf("*** Contact NOT FOUND ***\n");
    }
}

// deleteContact: User inputs a phonenumber and gives a choice to either delete the contact or not
void deleteContact(struct Contact contacts[], int size) {
    struct Contact null = { {"\0"} }; //null structure of contact
    char enterNum[11];
    int match;
    int yn; //takes yn value
    
    printf("\nEnter the cell number for the contact: ");
    getTenDigitPhone(enterNum);
    match = findContactIndex(contacts, size, enterNum);

    if (match != -1) {
        printf("\nContact found:\n");
        displayContact(&contacts[match]);
        printf("\nCONFIRM: Delete this contact? (y or n): ");
        yn = yes();
        if (yn == 1) {
            contacts[match] = null; //takes null structure to reset
            printf("--- Contact deleted! ---\n");
        }
    }
    else {
        printf("*** Contact NOT FOUND ***\n");
    }
}

// sortContacts: Sorts the contact list [leave unavailable]
void sortContacts(struct Contact contacts[], int size) {
    printf("\n<<< Feature to sort is unavailable >>>\n");
}
