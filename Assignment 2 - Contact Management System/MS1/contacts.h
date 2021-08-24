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


//--------------------------------
// Structure Types
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        structures here...                       |
// +-------------------------------------------------+

// Structure type Name declaration
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
// Place your code here...
struct Address {
    unsigned int streetNumber; //unsigned int enforces values greater than 0
    char street[41];
    unsigned int apartmentNumber;
    char postalCode[8];
    char city[41];
};


// Structure type Numbers declaration
// Place your code here...
struct Numbers {
    char cell[11];
    char home[11];
    char business[11];
};

// Structure type Contact declaration
// NOTE:  Make sure the structure name does not have an 's' on the end!
// Place your code here...
struct Contact { //struct containing the structs declared above
    struct Name name;
    struct Address addr;
    struct Numbers num;
};


//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function prototypes here...              |
// +-------------------------------------------------+

// Get and store from standard input the values for Name
// Place your code here...
void getName(struct Name* name);

// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address* addr);

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers* num);

// Get and store from standard input the values for a Contact (NOT: Contacts)
// NOTE:  Make sure the structure Contact does not have an 's' on the end!
// Put function prototype below:
void getContact(struct Contact* contact);