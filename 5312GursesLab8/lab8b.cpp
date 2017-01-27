/************************************************************************
* File Name:  Lab8b.cpp
*
* Author:     Erman Gurses
*
* Course:     COSC 5312 - Foundations in Programming and Problem 
*			  Solving II,  
* 
* Date:       March 19, 2012
*
* Purpose:    The purpose is that read records from data and then
				put these data into struct array which is name 
				addressBook. One element of array holds one record. 
				After file operations finishes, The user can view 
				all records or one record by using last name of 
				the record.
*          
*
* Input:      The inputs are records from the file.
*			  
*
* Output:	  First the menu prompt the user then 
			  if the user choose 1 it shows all records.
			  if the user chhose 2 it shows one record regarding 
			  entered last name.
************************************************************************/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>



using namespace std; 

const int MAX_SIZE  = 30;

struct AddressBook
{

		string lastName,
			   firstName,
			   streetAddress,
			   city,
			   state,
			   zipCode;
};


bool openInputFile(ifstream & inFile);
int readFile(ifstream & inFile, AddressBook addressBook[]);
void showAll( AddressBook addressBook[], int i);
void showOne(AddressBook addressBook[],int recordNumber);
char userOperations(AddressBook addressBook[], int recordNumber);
void doPause(); 


int main()
{

	AddressBook addressBook [MAX_SIZE];

	ifstream inFile;

	int recordNumber = 0;
	char decision;


   if(!openInputFile(inFile))
   {	
	   return 0;   
   }

    recordNumber=readFile(inFile,addressBook);

	do
	{
		decision=userOperations(addressBook,recordNumber);

	}while(decision != 'Q' && decision != 'q');
	
	inFile.close();
	
  return 0;
}

/************************************************************************
*            openInputFile
*                 
* Purpose		: Try to open an input file for use by the program.
*                    
* Pre-condition	: None.
*
* Post-condition: If output file has not been opened print error message 
					and return false
*				  If output file has been opened  
*					return true.
*
************************************************************************/

bool openInputFile(ifstream & inFile) 
{
   inFile.open("lab8input.txt");
   
   if (!inFile)
   {
      cout << "The input File cannot been opened!!!\n";

	  return false;
   }
   return true;
}

/**********************************************************************
*             readFile
*
* Purpose: This function reads up to 30 records from an input file.
*
* Pre-condition:   The input file stream has been successfully opened.
*
* Post-condition: The data have been loaded into Addressbook array
				  from the input file.
**********************************************************************/

int readFile(ifstream& inFile, AddressBook addressBook[])
{
   int    i=0;
   string oneRecord;
          
   while (getline(inFile, oneRecord) &&  i < MAX_SIZE)
   {
	   addressBook[i].lastName      = oneRecord.substr(0,11);
	   addressBook[i].firstName     = oneRecord.substr(12,17);
	   addressBook[i].streetAddress = oneRecord.substr(30,21);
	   addressBook[i].city          = oneRecord.substr(52,14);
	   addressBook[i].state         = oneRecord.substr(67,2);
	   addressBook[i].zipCode       = oneRecord.substr(70,5);

      i++;
   }
   return i;
}

/************************************************************************
*             showAll
*
* Purpose: The purpose is that to show all records in the struct array
			to the user. After 10 records has been shown, the user 
			must enter return key view next 10 records. 
*
* Pre-condition: Addressbook struct array has been initialized.  
*
* Post-condition: All records has been shown the user.
************************************************************************/
void showAll( AddressBook addressBook[], int recordNumber)
{
   
   
          
   for(int counter=0; counter<recordNumber; counter++)
   {
	   cout<<addressBook[counter].lastName<<" "<<
	    addressBook[counter].firstName<<" "<<
	    addressBook[counter].streetAddress<<" "<<
	    addressBook[counter].city<<" "<<
	    addressBook[counter].state<<" "<<
	    addressBook[counter].zipCode<<" "<<endl; 


		if( (counter + 1) % 10 == 0)
		{
			doPause();
		}

   }
 
}

/************************************************************************
*             showOne
*
* Purpose: The purpose is that get last name from the user and then 
			show the record(s) which contains the last name.
*
* Pre-condition: addressBook array has been initialized.  
*
* Post-condition: The record(s) has been shown.
************************************************************************/
void showOne(AddressBook addressBook[],int recordNumber)
{
	
	string lastNameUserInput,
		   lastNameInRecordArray;
	bool   flag=false;


	cin.ignore();

	cout<<"\nEnter Last Name:";
	
	getline(cin,lastNameUserInput);

	lastNameUserInput.resize(11,' ');

	for(int i=0; i<11; i++)
	{
		lastNameUserInput[i]=toupper(lastNameUserInput[i]);
	}


    for( int counter=0;  counter < recordNumber; counter++ )
    {
		
		lastNameInRecordArray=addressBook[counter].lastName;
		
		for(int i=0; i<11; i++)
	    {
		   lastNameInRecordArray[i]=toupper(lastNameInRecordArray[i]);
	    
	    }

	    if(lastNameInRecordArray==lastNameUserInput)
		{
			cout<<addressBook[counter].lastName<<" "<<
			addressBook[counter].firstName<<" "<<
			addressBook[counter].streetAddress<<" "<<
			addressBook[counter].city<<" "<<
			addressBook[counter].state<<" "<<
			addressBook[counter].zipCode<<" "<<endl;

			flag=true;
	   
		}

    }

	cout<<endl;

	if(flag==false)
	{
		cout<<"\nThe record cannot be found!\n"<<endl;
	}

}

/************************************************************************
*             userOperations
*
* Purpose: The purpose is that prompt the user the menu in order to 
			have operations on records
*
* Pre-condition: addressBook array has been initialized.  
*
* Post-condition: if decision is equal 1 
					call to showAll function
					return decision
				  if decision is equal 2 
					call to showOne function
					return decision
				  if decision is equal Q or q
					return decision
************************************************************************/
char userOperations(AddressBook addressBook[], int recordNumber)
{
	char decision;
	
	do
	{
		cout<<"Press 1: Display all records"<<endl;
		cout<<"Press 2: Display one record based on Last Name"<<endl;
		cout<<"Press Q: Quit Program"<<endl;

		cin>>decision;
		
		switch(decision)
		{
			case '1': 
			
				showAll(addressBook,recordNumber);
				return decision;
				
			case '2': 
			
				showOne(addressBook,recordNumber);
				return decision;

			case 'Q':

			case 'q':

				return decision;

			default:

				cout<<"You must enter 1, 2 or Q-q"<<endl;
		
		}

	}while(decision != '1' && decision != '2');
}

/************************************************************************
*            pause
*                 
* Purpose		: It does pause operation.
*                    
* Pre-condition	: None.
*
* Post-condition: Prompt  "Press [ Enter ] to continue..."
*
************************************************************************/
void doPause()  
{
	static int counter = 0;

	if(counter % 2 == 0)
	{
		cin.ignore();
		counter++;
	}
	else
	{
		counter++;
	
	}
    cout << "Press [Enter] to continue...\n";
	
	cin.ignore();
}

