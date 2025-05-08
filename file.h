/* Name:-C.P.Ravi
   Date:-18/10/2024
   Description :-An Address Book project in C allows users to add, search, modify, 
   and delete contact information, including names, phone numbers, and addresses. 
   It utilizes file handling for data persistence and efficient memory management.*/
#ifndef FILE_H
#define FILE_H

#include "contact.h"

void saveContactsToFile(AddressBook *addressBook);
void loadContactsFromFile(AddressBook *addressBook);

#endif
