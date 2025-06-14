/* Name:-C.P.Ravi
   Date:-18/10/2024
   Description :-An Address Book project in C allows users to add, search, modify, 
   and delete contact information, including names, phone numbers, and addresses. 
   It utilizes file handling for data persistence and efficient memory management.*/

#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct 
{
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);

void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

#endif
