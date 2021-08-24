//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NPP
// Date:           March 12, 2020
//==============================================
// Assignment:     1
// Milestone:      4
//==============================================

// Structure type Name declaration (Milestone 1)
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration 
// Place your code here... (from Milestone 1)
struct Address {
    unsigned int streetNumber; //unsigned int enforces values greater than 0
    char street[41];
    unsigned int apartmentNumber;
    char postalCode[8];
    char city[41];
};

// Structure type Numbers declaration
// Place your code here... (from Milestone 1)
struct Numbers {
    char cell[11];
    char home[11];
    char business[11];
};

// Structure type Contact declaration
// Place your code here... (from Milestone 3)
struct Contact { //struct containing the structs declared above
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// ====== Milestone 4 =======

// Get and store from standard input the values for Name
// Place your code here...

void getName(struct Name* name); //Prototype function of getName in contacts.c file

// Get and store from standard input the values for Address
// Place your code here...

void getAddress(struct Address* address); //Prototype function of getAddress in contacts.c file

// Get and store from standard input the values for Numbers
// Place your code here...

void getNumbers(struct Numbers* numbers); //Prototype function of getNumbers in contacts.c file