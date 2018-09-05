/* A2
 * a2ms4.c
 * contactHelpers.c
 * contacts.c
 * Ivy Leano
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

// Contact getName function: 
// Get and store from standard input the values for Name

void getName(struct Name *name)
{
	int answer;

	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]s", name->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	answer = yes();

	if (answer == 1) 
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\n]s", name->middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]s", name->lastName);
	clearKeyboard();
}

// Contact getAddress function:
// Get and store from standard input the values for Address

void getAddress(struct Address *address)
{
	int answer;

	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();

	printf("Please enter the contact's street name: ");
	scanf("%[^\n]s", address->street);
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	answer = yes();

	if (answer == 1) 
	{
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
	}
	
	else
	{
		address->apartmentNumber = '\0';
	}
	
	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]s", address->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf(" %[^\n]s", address->city);
	clearKeyboard();

}

// Contact getNumbers function:
// Get and store from standard input the values for Numbers

void getNumbers(struct Numbers *numbers)
{
	int answer;

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	answer = yes();

	if (answer == 1) 
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}
	
	else
	{
		numbers->home[0] = '\0';
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	answer = yes();

	if (answer == 1) 
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
	
	else
	{
		numbers->business[0] = '\0';
	}
}

// The getContact function:
// Get and store from standard input the values for Contact

void getContact(struct Contact *contacts)
{
	getName(&contacts->name);
	getAddress(&contacts->address);
	getNumbers(&contacts->numbers);
}
