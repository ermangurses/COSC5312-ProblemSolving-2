/********************************************************************
* File Name:  Lab3.cpp
*
* Author:     Erman Gurses
*
* Course:     COSC 5312 - Foundations in Programming and Problem 
*				   Solving II,  A03539870
* 
* Date:       February 1, 2012
*
* Purpose:    The purpose is that read unformatted records from (lab3input.txt)
*	      file put them into the other file (lab3output.txt) as a formatted 
*	      style. Then let to user enter new record After user enters record
*	      the program formats this recors and append in to lab3output.txt 
*	      which is formatted file. Dublicate records are allowed in this 
*	      program. Until user want to exit program, the program will work.
*          
*
* Input:      The Inputs are unformatted file which is named lab3input.txt 
*	      and user can enter input from keyboard a record.   
*
* Output:     The output is a formatted record into a lab3out.txt file 
********************************************************************/
#include <iostream>
#include <fstream>
#include <string>    
#include <cstring>
using namespace std;

void openInputFile(ifstream &inFile);
void readInputFile(ifstream &inFile);
bool openOutputFile(ofstream & outFile);
bool openOutputFileAppend(ofstream &outFile);
void writeOutputFile(ofstream & outfile, string lastName, string firstName, string streetAddress, string city,string state, string zip);
void userTransactions();
int  checkLength(string, int, int);
int  existAlpha(string word);
int  existDigit(string word);

int main()
{
   ifstream inFile;
  

   openInputFile(inFile);
   readInputFile(inFile);

   userTransactions();


  
   cout <<"\nProgram finished!\n";


  return 0;
}

/***************************************************************************
*            readInputFile
*                 
* Purpose		: Reads data from an input file field by field and  
				  format them. After that it sends these records another
				  function.
*                    
* Pre-condition : The input file has successfully opened.
*
* Post-condition: All the data have been read from file and have sent to 
				  writeOutputFile function. The last one is inFile and 
				  outFile have been closed. 
***************************************************************************/
void readInputFile(ifstream &inFile)
{
   ofstream outFile;
   string   lastName,
            firstName,
            streetAddress,
            city,
            state,
            zip;
   bool     flag = false;

   //Read first field from file
   while (getline(inFile, lastName, '^')) 
   {
      // Read rest of fields in this record
      getline(inFile, firstName, '^');
      getline(inFile, streetAddress, '^');
      getline(inFile, city, '^');
      getline(inFile, state, '^');
      getline(inFile, zip);        

    

      // Resize the strings.
      lastName.resize(30,' ');
      firstName.resize(20,' ');
      streetAddress.resize(30, ' ');
      city.resize(30, ' ');

	  if(flag==false)
	  {
		   flag=openOutputFile(outFile);
	  }

	   writeOutputFile(outFile,lastName,firstName,streetAddress,city,state,zip);
   }  

   outFile.close();
   inFile.close();
   
}

/***************************************************************************
*            writeOutputFile
*                 
* Purpose		: Takes records from another function and write them into
				  outputfile.
*                    
* Pre-condition	: The OutputFile file has successfully opened.
*
* Post-condition: Record has been written into file. 
***************************************************************************/
void writeOutputFile(ofstream & outfile, string lastName, string firstName, string streetAddress, string city,string state, string zip)
{
	string combinedString;
	combinedString=lastName+firstName+streetAddress+city+state+zip;
	outfile<<combinedString<<endl;

}

/***************************************************************************
*            userTransactions
*                 
* Purpose		: It takes records from user and checks them whether or nor
				  they are proper. After that it formats fields and sends
				  them to another function. The function allows user to enter
				  new record until user exits the program. 
*                    
* Pre-condition	: none.
*
* Post-condition: The record which has been taken from user sends another function
				  for appending operation.
				
***************************************************************************/
void userTransactions()
{
   ofstream outFile;
   bool     flag = false;
   char		decision;
   int		flagLastName=0,
            flagFirstName=0,
            flagStreetAddress=0,
            flagCity=0,
            flagState1=0,
			flagState2=0,
			flagState3=0,
            flagZip1=0,
			flagZip2=0,
			flagZip3=0,
			counter=0;

   string   lastName,
			firstName,
			streetAddress,
			city,
			state,
			zip;

	// for open the file one time
	if(flag==false)
	{
		flag=openOutputFileAppend(outFile);
	}

	do
	{
		if(counter!=0)
		{
			cin.ignore();
		}
		
		//Prompt and get last name from user and check it whether or not it is proper
		cout<<"Enter Last Name:";
		getline(cin,lastName);
		flagLastName=checkLength(lastName,1,30);
		while(flagLastName==0)
		{
			cout<<"\nLast Name must be at least 1 character at most 30 character.\n";
			cout<<"Enter Last Name:";
			getline(cin,lastName);
			flagLastName=checkLength(lastName,1,30);
		}
		
		//Prompt and get first name from user and check it whether or not it is proper
		cout<<"\nEnter First Name:";
		getline(cin,firstName);
		flagFirstName=checkLength(firstName,1,20);
		while(flagFirstName==0)
		{
			cout<<"\nFirst Name must be at least 1 character at most 20 character.\n";
			cout<<"Enter First Name:";
			getline(cin,firstName);
			flagFirstName=checkLength(firstName,1,20);
		}
		//Prompt and get street address from user and check it whether or not it is prope.r
		cout<<"\nEnter Street Address :";
		getline(cin,streetAddress);
		flagStreetAddress=checkLength(streetAddress,1,30);
		while(flagStreetAddress==0)
		{
			cout<<"\nStreet Address must be at least 1 character at most 30 character.\n";
			cout<<"Enter Street Address:";
			getline(cin,streetAddress);
			flagStreetAddress=checkLength(streetAddress,1,30);
		}
		
		//Prompt and get City from user and check it whether or not it is proper
		cout<<"\nEnter City:";
		getline(cin,city);
		flagCity=checkLength(city,1,30);
		while(flagCity==0)
		{
			cout<<"\nCity must be at least 1 character at most 30 character.\n";
			cout<<"Enter City:";
			getline(cin,city);
			flagCity=checkLength(city,1,30);

		}
		//Prompt and get State from user and check it whether or not it is proper
		cout<<"\nEnter State:";
		cin>>state;
		flagState1=checkLength(state,2,2);
		flagState2=existAlpha(state);
		while(flagState1==0 || flagState2==0 )
		{
			
			
			while(flagState1==0)
			{
				cout<<"\nState must be 2 character.\n";
				cout<<"Enter State :";
				cin>>state;
				flagState1=checkLength(state,2,2);
				flagState2=existAlpha(state);
			}

			while(flagState2==0)
			{
				cout<<"\nState must be alphabetic character.\n";
				cout<<"Enter State :";
				cin>>state;
				flagState1=checkLength(state,2,2);
				flagState2=existAlpha(state);
	
			}
			

		}
		
		//Prompt and get Zip from user and check it whether or not it is proper
		cout<<"\nEnter Zip Code:";
		cin>>zip;
		
		flagZip1=checkLength(zip,5,5);
		flagZip2=existDigit(zip);
		
		while(flagZip1==0 || flagZip2==0 )
		{
			
			
			while(flagZip1==0)
			{
				cout<<"\nZip must be  5 character.\n";
				cout<<"Enter Zip Code:";
				cin>>zip;
	
				flagZip1=checkLength(zip,5,5);
				flagZip2=existDigit(zip);
			}
			
			while(flagZip2==0)
			{
				cout<<"\nZip must be digit.\n";
				cout<<"Enter Zip Code:";
				cin>>zip;
				
				flagZip1=checkLength(zip,5,5);
				flagZip2=existDigit(zip);

			}	
			
		}
		
		// Reformat fields
		lastName.resize(30,' ');
        firstName.resize(20,' ');
        streetAddress.resize(30, ' ');
        city.resize(30, ' ');
		 
        // Send reformatted fields to function
		writeOutputFile(outFile,lastName,firstName,streetAddress,city,state,zip);

		// Prompt and get user's decision
		cout<<"Do you want to insert record again? Y/N:";
		cin>>decision;


		flagLastName=0,
        flagFirstName=0,
        flagStreetAddress=0,
        flagCity=0,
        flagState1=0,
		flagState2=0,
        flagZip1=0,
		flagZip2=0,
		counter++;
	
	}while(decision=='Y'||decision=='y');

	outFile.close();


}
/***************************************************************************
*            openInputFile
*          
* Purpose: Try to open an input file for use by the program.
* 
* Pre-condition: None.
*          
* Post-condition: If the input file has opened 
*					do nothing
*				  if the input file has not opened 
*					printed error message then exited program.
*        
***************************************************************************/
void openInputFile(ifstream & inFile) 
{
   inFile.open("lab3input.txt");
   if (!inFile)
   {
      cout << "The InputFile cannot been opened!!!";
	
	  exit(0);
   }
   
}

/***************************************************************************
*            openOutputFile
*                 
* Purpose		: Try to open an output file for use by the program.
*                    
* Pre-condition	: None.
*
* Post-condition: If output file has not been opened print error message and 
*				  	return false
*				  If output file has been opened  
*					return true.
*
***************************************************************************/
bool openOutputFile(ofstream & outFile) 
{
   outFile.open("lab3output.txt");
   if (!outFile)
   {
      cout << "The Output File cannot been opened!!!";

	  return false;
   }
   return true;
}

/***************************************************************************
*            openOutputFileAppend
*                 
* Purpose		: Try to open an output file for use by the program in append
*				  mode.
*                    
* Pre-condition	: None.
*
* Post-condition: If output file has not been opened print error message and 
*				  	return false
*				  If output file has been opened  
*					return true.
*				  
***************************************************************************/
bool openOutputFileAppend(ofstream &outFile)
{
	outFile.open("lab3output.txt",ios::app);
	if (!outFile)
    {
      cout << "The Output File cannot been opened!!!";
	  system("PAUSE");

	  return false;
	}
   return true;


}

/***************************************************************************
*            checkLength
*                 
* Purpose		: It checks length of string variable and decides whether it
				  is proper or not.
*                    
* Pre-condition	: String variable had to been initialized
*
* Post-condition: If length is not proper 
					returns 0
				  else
				  	returns 1
***************************************************************************/
int checkLength(string word, int min, int max)
{
	int length,
		flag=0;

	length=word.length();
	
	if(length<min || length>max)
	{
		return flag;
	}
	else
	{
		flag=1;
		
		return  flag;
	}
}

/***************************************************************************
*            existDigit
*                 
* Purpose		: It checks the string completely exists as a digit 
*                    
* Pre-condition	: string variable has to initilized.
*
* Post-condition: If string is completely digit, it returns 1
				  otherwise it returns 0
***************************************************************************/
int existDigit(string word)
{
	int i=0;
	int flag=1;

	while(word[i])
	{
		if(!isdigit(word[i]))
		{	
			flag=0;

			return flag;
		}

		i++;
	}

	return flag;
}

/***************************************************************************
*            existAlpha
*                 
* Purpose		: It checks the string completely exists as a alhabetical 
				  character. 
*                    
* Pre-condition	: string variable has to initilized.
*
* Post-condition: If string is completely alphabetical, it returns 1
				  otherwise it returns 0
***************************************************************************/
int existAlpha(string word)
{
	int i=0;
	int flag=1;

	while(word[i])
	{
		if(!isalpha(word[i]))
		{	
			flag=0;

			return flag;
		}

		i++;
	}

	return flag;
	
}

