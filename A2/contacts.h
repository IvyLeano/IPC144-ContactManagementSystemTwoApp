/* A2
 * a2ms4.c
 * contactHelpers.c
 * contacts.c
 * Ivy Leano
 */

#ifndef CONTACTS_H_
#define CONTACTS_H_
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Structure type Name declaration

struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration

struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration

struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};

// Structure type Contact declaration

struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};

// Prototype:
// getName

void getName(struct Name *name);

// Prototype:
// getAddress

void getAddress(struct Address *address);

// Prototype:
// getNumbers

void getNumbers(struct Numbers *numbers);

// Prototype:
// getContact

void getContact(struct Contact *contacts);

#endif // !CONTACTS_H_
