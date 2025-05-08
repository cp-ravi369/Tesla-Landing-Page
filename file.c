#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{
  FILE *fptr=fopen("Tesla.csv","w");
  if (fptr==NULL)
  {
        return ;
  }
  fprintf(fptr,"%d\n",addressBook->contactCount);
  for (int i=0;i<addressBook->contactCount;i++)
  {
    fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
  }
  
}

void loadContactsFromFile(AddressBook *addressBook) 
{
     FILE *fptr=fopen("Tesla.csv","r");
  if (fptr== NULL)
  {
    return;
  }
  int count;
  fscanf(fptr,"%d",&count);
  
  addressBook->contactCount=count;

  for (int i=0;i<addressBook->contactCount;i++)
  {
    fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
  }
    
}



