//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NPP
// Date:           March 12, 2020
//==============================================
// Assignment:     1
// Milestone:      3
//==============================================

// Structure type Name declaration
struct Name {
    char firstName[31]; //char requires +1 size as last is assigned \0
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
// Place your code from Milestone #2 here...
struct Address {
    unsigned int streetNumber; //unsigned int enforces values greater than 0
    char street[41];
    unsigned int apartmentNumber;
    char postalCode[8];
    char city[41];
};

// Structure type Numbers declaration
// Place your code from Milestone #2 here...
struct Numbers {
    char cell[11];
    char home[11];
    char business[11];
};

// Structure type Contact declaration
// Place your code here...
struct Contact { //struct containing the structs declared above
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};