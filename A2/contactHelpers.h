/* A2
 * a2ms4.c
 * contactHelpers.c
 * contacts.c
 * Ivy Leano
 */

#include "contacts.h"

// Prototype:
// Clear the standard input buffer
// clearKeyboard

void clearKeyboard(void);

// Prototype:
// pause

void pause(void);

// Prototype:
// getInt

int getInt(void);

// Prototype:
// getIntInRange

int getIntInRange(int upper, int lower);

// Prototype:
// yes

int yes(void);

// Prototype:
// menu

int menu(void);

// Prototype:
// ContactManagerSystem

void ContactManagerSystem(void);

// Prototype:
// Gets a ten-digit phone number
// getTenDigitPhone

void getTenDigitPhone(char telNum[]);

// Prototype:
// findContactIndex

int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);

// Prototype:
// displayContactHeader

void displayContactHeader(void);

// Prototype:
// displayContactFooter

void displayContactFooter(int totalCon);

// Prototype:
// displayContact

void displayContact(const struct Contact* contacts);

// Prototype:
// displayContacts

void displayContacts(const struct Contact contacts[], int size);

// Prototype:
// searchContacts

void searchContacts(const struct Contact contacts[], int size);

// Prototype:
// addContact

void addContact(struct Contact contacts[], int size);

// Prototype:
// updateContact

void updateContact(struct Contact contacts[], int size);

// Prototype:
// deleteContact

void deleteContact(struct Contact contacts[], int size);

// Prototype:
// sortContacts

void sortContacts(struct Contact contacts[], int size);