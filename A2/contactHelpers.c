/* A2
 * a2ms4.c
 * contactHelpers.c
 * contacts.c
 * Ivy Leano
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"

#define MAXCONTACTS 5

// Function definition for:
// clearKeyboard

void clearKeyboard(void)
{
	while (getchar() != '\n'); 
}

// Function definition for:
// pause

void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// Function definition for:
// getInt

int getInt(void)
{
	char NL = 'x';
	int x = 0;

	while (NL != '\n')
	{
		scanf("%d%c", &x, &NL);

		if (NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	}
	return x;
}

// Function definition for:
// getIntInRange

int getIntInRange(int upper, int lower)
{
	int c;
	c = getInt();

	while (c < upper || c > lower)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", upper, lower);
		c = getInt();
	}

	return c;
}

// Function definition for:
// yes

int yes(void)
{
	char yes_no;
	char enter;
	int value = 0;
	int x = 0;

	do 
	{
		scanf(" %c%c", &yes_no, &enter);

		if ((yes_no == 'y' || yes_no == 'Y') && (enter == '\n')) 
		{
			value = 1;
			x = 1;
		}

		else if ((yes_no == 'n' || yes_no == 'N') && (enter == '\n')) 
		{
			value = 0;
			x = 1;
		}
		
		else 
		{
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
	} while (x == 0);

	return value;
}

// Function definition for:
// menu

int menu(void)
{
	int intValue = 0;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");

	intValue = getIntInRange(0, 6);
	return intValue;
}

// Function definition for:
// ContactManagerSystem

void ContactManagerSystem(void)
{
	struct Contact contacts[MAXCONTACTS] =
	{ { { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
	  {
		  { "Maggie", "R.", "Greene" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },
	  {
		  { "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	{ "7051112222", "7052223333", "7053334444" } },
	  {
		  { "Sasha",{ '\0' }, "Williams" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } },
	};

	int menuOp = 0;
	int yes_no = 0;

	do 
	{
		menuOp = menu();
		switch (menuOp)
		{

		// Exit the program

		case 0: 
			printf("\n");
			printf("Exit the program? (Y)es/(N)o: ");
			yes_no = yes();
			printf("\n");

			if (yes_no == 1)
			{
				printf("Contact Management System: terminated");
				printf("\n");
			}
			break;

		// Display contacts

		case 1: 
			printf("\n");
			displayContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		// Add contact

		case 2: 
			printf("\n");
			addContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		// Update contact

		case 3: 
			printf("\n");
			updateContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		// Delete contact

		case 4: 
			printf("\n");
			deleteContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		// Search contact by cell number

		case 5: 
			printf("\n");
			searchContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		// Sort contacts by cell number

		case 6: 
			printf("\n");
			sortContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		}
	} while (yes_no != 1);
}

// Function definition for:
// getTenDigitPhone

void getTenDigitPhone(char telNum[])
{
	int needInput = 1;

	while (needInput == 1) 
	{
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validates entry of 10 characters)

		if (strlen(telNum) == 10)
		{
			needInput = 0;
		}

		else
		{
			printf("Enter a 10-digit phone number: ");
		}
	}
}

// Function definition for:
// findContactIndex

int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int x;
	int r = -1;
	int compare;

	for (x = 0; x < size; x++) 
	{
		compare = strcmp(contacts[x].numbers.cell, cellNum);

		if (compare == 0) 
		{
			r = x;
		}
	}
	return r;
}

// Function definition for:
// displayContactHeader

void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// Function definition for:
// displayContactFooter

void displayContactFooter(int totalCon)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", totalCon);
}

// Function definition for:
// displayContact

void displayContact(const struct Contact* contacts)
{
	int len = 0;

	printf(" %s ", contacts->name.firstName);

	len = strlen(contacts->name.middleInitial);

	if (len > 0)
	{
		printf("%s ", contacts->name.middleInitial);
	}

	printf("%s\n", contacts->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contacts->numbers.cell, contacts->numbers.home, contacts->numbers.business);
	printf("       %d %s, ", contacts->address.streetNumber, contacts->address.street);

	if (contacts->address.apartmentNumber > 0)
	{
		printf("Apt# %d, ", contacts->address.apartmentNumber);
	}
	printf("%s, %s\n", contacts->address.city, contacts->address.postalCode);
}

// Function definition for:
// displayContacts

void displayContacts(const struct Contact contacts[], int size)
{
	int x;
	int contact_Count = 0;
	int len = 0;

	displayContactHeader();

	for (x = 0; x < size; x++)
	{
		len = strlen(contacts[x].numbers.cell);

		if (len > 0)
		{
			displayContact(&contacts[x]);
			contact_Count = contact_Count + 1;
		}
	}
	displayContactFooter(contact_Count);
}

// Function definition for:
// searchContacts

void searchContacts(const struct Contact contacts[], int size)
{
	char num[11] = { "\n" };
	int FCI;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(num);

	FCI = findContactIndex(contacts, size, num);

	if (FCI != -1)
	{
		printf("\n");
		displayContact(&contacts[FCI]);
		printf("\n");
	}

	else
	{
		printf("*** Contact NOT FOUND ***\n");
	}
}

// Function definition for:
// addContact

void addContact(struct Contact contacts[], int size)
{
	int x;
	int key = -1;
	int len;

	for (x = 0; x < size; x++)
	{
		len = strlen(contacts[x].numbers.cell);
		
		if (len == 0)
		{
			key = x;
		}
	}
	
	if (key>-1)
	{
		getContact(&contacts[key]);// uses key for contact index
		printf("--- New contact added! ---\n");
	}
	
	else
	{
		printf("*** ERROR: The contact list is full! ***\n");
	}
}

// Function definition for:
// updateContact

void updateContact(struct Contact contacts[], int size)
{
	int found;
	char updateCheck[11] = { '\n' };

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(updateCheck);
	found = findContactIndex(contacts, size, updateCheck);

	if (found != -1)
	{
		printf("\n");
		printf("Contact found:\n");
		displayContact(&contacts[found]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");

		if (yes() == 1) 
		{
			getName(&contacts[found].name);
		}

		printf("Do you want to update the address? (y or n): ");

		if (yes() == 1) 
		{
			getAddress(&contacts[found].address);
		}
		printf("Do you want to update the numbers? (y or n): ");

		if (yes() == 1) 
		{
			getNumbers(&contacts[found].numbers);
		}
		printf("--- Contact Updated! ---\n");
	}

	else
	{
		printf("*** Contact NOT FOUND ***\n");
	}
}

// Function definition for:
// deleteContact

void deleteContact(struct Contact contacts[], int size)
{
	char telNum[11] = { '\n' };
	int found;
	int choice;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(telNum);
	found = findContactIndex(contacts, size, telNum);

	if (found != -1)
	{
		printf("\n");
		printf("Contact found:\n");
		displayContact(&contacts[found]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		choice = yes();

		if (choice == 1)
		{
			contacts[found].numbers.cell[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
	}

	else
	{
		printf("*** Contact NOT FOUND ***\n");
	}
}

// Function definition for:
// sortContacts

void sortContacts(struct Contact contacts[], int size) {

	int e;
	int f;
	struct Contact temp;

	for (e = 0; e < size; e++)
	{
		for (f = 0; f < size - 1; f++)
		{
			if (strcmp(contacts[f].numbers.cell, contacts[f + 1].numbers.cell) > 0)
			{
				temp = contacts[f];
				contacts[f] = contacts[f + 1];
				contacts[f + 1] = temp;
			}
		}
	}
	printf("--- Contacts sorted! ---\n");
}
