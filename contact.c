/* Name:-C.P.Ravi
   Date:-18/10/2024
   Description :-An Address Book project in C allows users to add, search, modify, 
   and delete contact information, including names, phone numbers, and addresses. 
   It utilizes file handling for data persistence and efficient memory management.*/

#include <stdio.h>
int is_valid_name(char *name);
int is_valid_phone(char *phone);
int is_valid_email(char *email);
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook, int sortCriteria)   //int sortCriteria
{
    // Sort contacts based on the chosen criteria
    for(int i=0;i<addressBook->contactCount;i++)
    {
        printf("%20s\t",addressBook->contacts[i].name);
        printf("%20s\t",addressBook->contacts[i].phone);
        printf("%20s\n",addressBook->contacts[i].email);
    }
    
}

void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;
   // populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) 
{
    //saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}
void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    char name[50];
    char phone[50];
    char email[50];
    int c,c1,check;
    printf("Enter the Name: ");
    do
    {
        //__fpurge(stdin);
        scanf(" %[^\n]",name);
    } while (is_valid_name(name) == 0);
    printf("Name is valid\n");
    printf("Enter the phone number: ");
    do
    {
       // __fpurge(stdin);
        loop1:scanf("%s",phone);
    } while (is_valid_phone(phone) == 0);
    //To check phone number is present in data base or not
    // --------------------------------------------------------------
    int flag=0,count=0;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        c1 = strcmp(phone,addressBook->contacts[i].phone);
        if(c1 == 0)
        {
            flag++;
            break;
        }
        else
        {
            count++;
        }
    }
    if(flag == 1)
    {
        printf("Enter uquine phone number\n");
        goto loop1;
    }
    else if(flag == count)
    {
        printf("Enter phone is not there in the data base\n");
    }    
   printf("Phone number is valid\n");
   printf("Enter the email: ");
    do
    {
        //__fpurge(stdin);
        loop2:scanf("%s",email);
    } while (is_valid_email(email) == 0);
    //To check the email is prsent in data base or not
    //----------------------------------------------------------------
    int flag1=0,c3;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        c3 = strcmp(email,addressBook->contacts[i].email);
        if(c3 == 0)
        {
            flag1++;
            break;
        }
    }
    if(flag1 == 1)
    {
        printf("This email is already in the database plz enter uquine email\n");
        goto loop2;
    }
// To save the all detailes in the database
//----------------------------------------------------------------------
   printf("email is valid");
   strcpy( addressBook->contacts[addressBook->contactCount].name,name);
   strcpy( addressBook->contacts[addressBook->contactCount].phone,phone);
   strcpy( addressBook->contacts[addressBook->contactCount].email,email);
   addressBook->contactCount++;
}
//Function to validate the name 
// ------------------------------------------------------------------------
int is_valid_name(char *name)
{
    int len,count=0,c;
    len = strlen(name);
    for(int i=0;name[i] != '\0';i++)
    {
        if((name[i] >= 'A'&& name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || (name[i] == ' '))
        {
            count++;
        }
        else
        {
            printf("Enter correct Name\n");
            return 0;
        }
    }
    if(len == count)
    {
        return 1;
    }
    else
    {
        printf("Enter correct Name\n");
        return 0;
    }
//Name to validate the phone number
//------------------------------------------------------------------------
}
int is_valid_phone(char *phone)
{
    int len,count=0;
    len = strlen(phone);
    if(len == 10)
    {
        for(int i=0;phone[i] != '\0';i++)
        {
            if(phone[i] >= '0' && phone[i] <= '9')
            {
                count++;
            }
            else
            {
                printf("Enter correct Phone number\n");
                return 0;
            }
        }
        if(len == count)
        {
            return 1;
        }
    }
    else
    {
        printf("Enter correct phone number\n");
        return 0;
    }
}
//Funcrion to validate email is validete or not
//------------------------------------------------------
int is_valid_email(char *email)
{
    char sub1[5] = "@";
    char sub2[5] = ".com";
    char *result1;
    char *result2;
    char email2[50];
    int ind1=0,ind2=0;
    for(int i=0;email[i] != '\0';i++)
    {
        if((email[i] >= 'a' && email[i] <= 'z') || (email[i] == '@' || email[i] == '.' || email[i] == 'c' || email[i] == 'o' || email[i] == 'm' ))
        {
            email2[i] = email[i];
        }
        else
        {
            printf("Enter correct Email\n");
            return 0;
        }
    }
    email2[strlen(email)] = '\0'; 
    result1 = strstr(email2,sub1);
    result2 = strstr(email2,sub2);
    if(result1)
    {
        if(result2)
        {
            for(int i=0;email2[i] != '\0';i++)
            {
                if(email2[i] == '@')
                {
                    ind1 = i;
                }
                else if(email2[i] == '.')
                {
                    ind2 = i;
                }
            }
            ind1 = ind1 + 1;
            if(email2[ind1] >= 'a' && email2[ind1] <= 'z')
            {
                ind1 = ind1 - 2;
                if(email2[ind1] >= 'a' && email2[ind1] <= 'z')
                {
                    ind2 = ind2 + 4;
                    if(email2[ind2] == '\0')
                    {
                        return 1;
                    }
                    else
                    {
                        printf("Enter correct Email\n");
                    return 0;
                    }
                }
                else
                {
                    printf("Enter correct Email\n");
                return 0;
                }
            }
            else
            {
                printf("Enter correct Email\n");
            return 0;
            }
        }
        else
        {
            printf("Enter correct Email\n");
            return 0;
        }
    }
    else
    {
        printf("Enter correct Email\n");
        return 0;
    }
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int n,j=0;
    int arr[100];
    char phone[16];
    printf("Enter the choice\n");
    printf("1.Name\n2.Phone number\n3.Email\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1 :
        char elon[10];
        int c,count=0,flag=0;
        //int arr[j];
        printf("Enter the name:\n");
        getchar();
        scanf("%[^\n]",elon);
        //Loop for checking the the enter name is present in data base or not
        //-----------------------------------------------------------------------------
        for(int i=0;i<addressBook->contactCount;i++)
        {
            c = strcmp(elon,addressBook->contacts[i].name);
            if(c == 0)
            {
                flag++;
                arr[j]=i;
                j++;
            }
            else
            {
                count++;
            }

        }
        //If name is present in the data base print the all detail
        //----------------------------------------------------------------------------------------------------
        if(flag > 1)
        {
            for(int k=0;k<j;k++)
            {
                printf("%s\t%s\t%s\n",addressBook->contacts[arr[k]].name,addressBook->contacts[arr[k]].phone,addressBook->contacts[arr[k]].email);
            }
            int ex,ex1=0,inx;
            printf("Same names are there plz");
            printf("Enter the phone number:\n");
            scanf("%s",phone);

            // Loop to check the phone number is present in the database or not
            //------------------------------------------------------------------------------------------
            for(int i=0;i<addressBook->contactCount;i++)
            {
                ex = strcmp(phone,addressBook->contacts[i].phone);
                if(ex == 0)
                {

                    inx=i;
                    ex1++;
                    break;
                }
            }
            //If name is there at that time print all deatils
            //------------------------------------------------------------------------------------------
            if(ex1 == 1)
            {
                printf("%s\t%s\t%s\n",addressBook->contacts[inx].name,addressBook->contacts[inx].phone,addressBook->contacts[inx].email);

            }
        }
        else if(flag == 1)
        {
            j =j-1;
            printf("%s\t%s\t%s\n",addressBook->contacts[arr[j]].name,addressBook->contacts[arr[j]].phone,addressBook->contacts[arr[j]].email);
             
        }
        else if (count == addressBook->contactCount)
        {
            printf("Not found enter correct details\n");
        }
        else
        {
            printf("Not found enter correct details\n");

        }
        break;
        case 2:
        int c1,a1,count1=0,flag1=0;
        char tesla[20];
        printf("Enter the phone number:\n");
        if (addressBook == NULL) {
        printf("AddressBook is not initialized.\n");
        return;  // Exit the function to avoid a NULL pointer access
    }
        scanf("%s",tesla);
        //Checking the phone number is present in data base or not
        //-------------------------------------------------------------------------------------------
        for(int i=0;i<addressBook->contactCount;i++)
        {
            c1=strcmp(tesla,addressBook->contacts[i].phone);
            if(c1 == 0)
            {
              a1=i;
              flag1++;
              break;  
            }
            else
            {
                count1++;
            }
        }
        //If phone number is present in the database at that time print the all deatils
        //-------------------------------------------------------------------------------------------------------------
        if(flag1 == 1)
        {
            printf("%s\t%s\t%s\n",addressBook->contacts[a1].name,addressBook->contacts[a1].phone,addressBook->contacts[a1].email);   
        }
        else if(count1 == addressBook->contactCount)
        {
            printf("Not found enter correct details:\n");
        }
        else
        {
            printf("Not found enter correct details:\n");
        }
        break;
         case 3:
        int c2,a2,count2=0,flag2=0;
        char nikola[50];
        printf("Enter the email:\n");
        if (addressBook == NULL) {
        printf("AddressBook is not initialized.\n");
        return;  // Exit the function to avoid a NULL pointer access
    }
        scanf("%s",nikola);
        //Checking the email is present in the data base or not 
        //----------------------------------------------------------------------------------------------
        for(int i=0;i<addressBook->contactCount;i++)
        {
            c2=strcmp(nikola,addressBook->contacts[i].email);
            if(c2 == 0)
            {
              a2=i;
              flag2++;
              break;  
            }
            else
            {
                count2++;
            }
        }
        //If it is there printf all the contant
        //------------------------------------------------------------------------------
        if(flag2 == 1)
        {
            printf("%s\t%s\t%s\n",addressBook->contacts[a2].name,addressBook->contacts[a2].phone,addressBook->contacts[a2].email);   
        }
        else if(count2 == addressBook->contactCount)
        {
            printf("Not found enter correct details:\n");
        }
        else
        {
            printf("Not found enter correct details:\n");
        }
    }


}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int n;
    printf("Enter your choice\n");
    printf("1.Name\n2.Phone\n3.Email\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        {
            int c1,flag1=0,count1=0,j=0,n1;
            int arr[100];
            char name[20];
            char Newname[20];
            printf("Enter the name\n");
            getchar();
            scanf("%[^\n]",name);
            //Checking the name is present in the data  base or not if it is there read the all the index value
            //----------------------------------------------------------------------------------------------------------------
            for(int i=0;i<addressBook->contactCount;i++)
            {
                c1 = strcmp(name,addressBook->contacts[i].name);
                if(c1 == 0)
                {
                    flag1++;
                    arr[j] = i;
                    j++;
                }
                else
                {
                    count1++;
                }
            }
            //If only one name is present in the at that time print the all details
            //---------------------------------------------------------------------------------------
            if(flag1 == 1)
            {
                printf("Enter the Newname:\n");
                do
                {
                    getchar();
                    scanf("%[^\n]",Newname);
                }while(is_valid_name(Newname) == 0);
                strcpy(addressBook->contacts[arr[0]].name,Newname);
                printf("Newname saved successfully\n");
            }
            //If more than one name there at that time print the value based on the inndiax value stored in the array
            //---------------------------------------------------------------------------------------------------------
            else if(flag1 > 1)
            {
                for(int k=0;k<j;k++)
                {
                        printf("%s\t%s\t%s\n",addressBook->contacts[arr[k]].name,addressBook->contacts[arr[k]].phone,addressBook->contacts[arr[k]].email);
                }
                        printf("More than 1 Same names are there plz select which one\n");
                        scanf("%d",&n1);
                        printf("Enter the Newname\n");
                        do
                        {
                            getchar();
                            scanf("%[^\n]",Newname);
                        }while(is_valid_name(Newname) == 0);
                        strcpy(addressBook->contacts[arr[n1]].name,Newname);
                        printf("Newname saved successfully\n");                
            }
            //If count == addressbook contactcount name is not there in the database
            //--------------------------------------------------------------------------------
            else if(count1 == addressBook->contactCount)
            {
                printf("Name not found enter correct name\n");
            }
            else
            {
                printf("Name not found enter correct name\n");
            }

        }
        break;

        case 2 :
        {
        char phone[20];
        char Newphone[20];
        int c2,flag2=0,count2=0,a,c3;
        printf("Enter the Phone number\n");
        scanf("%s",phone);
        // Checking the phone number is present in the data base or not
        //-------------------------------------------------------------------------------------
        for(int i=0;i<addressBook->contactCount;i++)
        {
            c2 = strcmp(phone,addressBook->contacts[i].phone);
            if(c2 == 0)
            {
                flag2++;
                a=i;
                break;
            }
            else
            {
                count2++;
            }
        }
        //if it is there read the new phone
        if(flag2 == 1)
        {
                printf("Enter the Newnumber\n");
                do 
                {
            loop10:scanf("%s",Newphone);
                }while(is_valid_phone(Newphone) == 0);
                for(int j=0;j<addressBook->contactCount;j++)
                {
                    c3 = strcmp(Newphone,addressBook->contacts[j].phone);
                    if(c3 == 0)
                    {
                        printf("Enter Uquine phonenumber\n");
                        goto loop10;
                    }
                }
                strcpy(addressBook->contacts[a].phone,Newphone);
                printf("Newphone number saved successfully\n");
        }
        else if(count2 == addressBook->contactCount)
        {
            printf("Phone not found enter correct name\n"); 
        }
        else
        {
            printf("Phone not found enter correct name\n");
        }
        }
        break;

        case 3 :
        {
        int c10,flag10=0,count10=0,c11,flag11=0,a20;
        char email[20];
        char Newemail[20];
        printf("Enter the email\n");
        scanf("%s",email);
        //Cheking the email is present in the data base or not 
        for(int i=0;i<addressBook->contactCount;i++)
        {
            c10 = strcmp(email,addressBook->contacts[i].email);
            if(c10 == 0)
            {
                flag10++;
                a20 = i;
                break;
            }
            else
            {
                count10++;
            }
        }
        //If email is there read the newemail
        if(flag10 == 1)
        {
            printf("Enter the Newemail\n");
            do 
            {
                loop20:scanf("%s",Newemail);
            }while(is_valid_email(Newemail) == 0);
            for(int i=0;i<addressBook->contactCount;i++)
            {
                c11 = strcmp(Newemail,addressBook->contacts[i].email);
                if(c11 == 0)
                {
                    flag11++;
                    break;
                }
            }
            //if it is in the data base print the messge like enter the uquine email 
            if(flag11 == 1)
            {
                printf("Plz enter the uquine email\n");
                goto loop20;
            }
            strcpy(addressBook->contacts[a20].email,Newemail);
            printf("Newemail saved successfully\n");
        }
        else if(count10 == addressBook->contactCount)  // if count == contactcount it means the email not there in the database
        {
            printf("Email is not found plz enter the correct email\n");
        }
        else
        {
           printf("Email is not found plz enter the correct email\n"); 
        }
        }
        break;


    }
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int n,c,a,count=0,flag=0;
    printf("Enter your choice\n");
    printf("1.Name\n2.Phone\n3.Email\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        {
        char name[20];
        printf("Enter the name\n");
        getchar();
        scanf("%[^\n]",name);
        for(int i=0;i<addressBook->contactCount;i++)  //Checking the name is present in the database or not
        {
            c = strcmp(name,addressBook->contacts[i].name);
            if(c == 0)
            {
                a=i;
                addressBook->contacts[a].name[0] = '\0';
                addressBook->contacts[a].phone[0] = '\0';
                addressBook->contacts[a].email[0] = '\0';
                flag++;
            }
            else
            {
                count++;
            }
        }
        if(flag == 1)   //   If it is there next index value will be shifted to the present index value
        {
             printf("Are you conform to delete the contact\n");
            for(int i=a;i<addressBook->contactCount-1;i++)
            {
                addressBook->contacts[i] = addressBook->contacts[i+1];
            }
            addressBook->contactCount--;
            printf("Details Delete successfully\n");

        }
        }
        break;

        case 2:
        {
        int c1,a1,count1=0,flag1=0;
        char tesla[20];
        printf("Enter the phone\n");
        scanf("%s",tesla);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            c1 = strcmp(tesla,addressBook->contacts[i].phone);
            if(c1 == 0)
            {
                a1=i;
                addressBook->contacts[i].name[0] = '\0';
                addressBook->contacts[i].phone[0] = '\0';
                addressBook->contacts[i].email[0] = '\0';
                flag1++;
            }
            else
            {
                count++;
            }
        }
        if(flag1 == 1)
        {
            printf("Are you conform to delete the contact\n");  //   If it is there next index value will be shifted to the present index value
            for(int i=a1;i<addressBook->contactCount-1;i++)
            {
                addressBook->contacts[i] = addressBook->contacts[i+1];
            }
            addressBook->contactCount--;
            printf("Details Delete successfully\n");

        }
        }
        break;

        case 3:
        {
        int c2,a2,count2=0,flag2=0;
        char elon[20];
        printf("Enter the Email\n");
        scanf("%s",elon);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            c2 = strcmp(elon,addressBook->contacts[i].email);
            if(c2 == 0)
            {
                a2=i;
                addressBook->contacts[i].name[0] = '\0';
                addressBook->contacts[i].phone[0] = '\0';
                addressBook->contacts[i].email[0] = '\0';
                flag2++;
            }
            else
            {
                count++;
            }
        }
        if(flag2 == 1)   //   If it is there next index value will be shifted to the present index value
        {
            printf("Are you conform to delete the contact\n");
            for(int i=a2;i<addressBook->contactCount-1;i++)
            {
                addressBook->contacts[i] = addressBook->contacts[i+1];
            }
            addressBook->contactCount--;
            printf("Details Delete successfully\n");

        }
        }
        break;

    }
}
