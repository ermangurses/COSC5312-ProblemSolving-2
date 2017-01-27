/***********************************************************************
* File Name:  Lab9.cpp
*
* Author:     Erman Gurses
*
* Course:     COSC 5312 - Foundations in Programming and Problem 
*			  Solving II,  
* 
* Date:       March 26, 2012
*
* Purpose:  The program reads movie records from file and then put those 
			records into an array. The user can do some operations
			on those records such as view all records, search one 
			record by entering movie name or director's last name, 
			and add entry. After the user decides quit the program,
			the program includes new records into same file.
				
*          
*
* Input:    The user enters, via the keyboard, new record. The program
			reads records from file.
*
* Output:	The menu is displayed on the screen in order to choose type
			of operation. 
			After the user choose type of operation the 
			program displays;
				all records or
				one record based on Movie Name or
				one record based on Director's Last Name or 
			adds; 
				entry to the movie list or 
			quits;
				the program.				
					
			After the user chooses quit option, the program appends new 
			records into the lab9input.txt file if the user has 
			added new records.
***********************************************************************/

#include "movie.h" 
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>    

using namespace std;

const int MAX_SIZE  = 50;


bool openInputFile(ifstream & inFile);

int readFile(Movie * movieArray, ifstream & inFile);

void displayOne(Movie & movieOne);

void displayAll(Movie * movieArray, int totalRecords);

void searchMovieName(Movie * movieArray, string movieNameUserInput, 
					 int totalRecords);

void searchDirectorsLastName(Movie * movieArray, 
							 string InputDirectorsLastName, 
							 int totalRecords);
							 
char userOperations(Movie * movieArray, int firstRecords);

void doPause(int counter, int c); 

void addEntry(Movie * movieArray, int totalRecords);

bool openOutputFileAppend(ofstream & outFile); 

void writeOutputFile(Movie * movieArray, ofstream & outFile, 
					 int firstRecords , int totalRecords );

int main()
{
	char decision;
	
	int firstRecords,
		totalRecords;
	

	ifstream inFile;
	ofstream outFile;

	if(!openInputFile(inFile))
	{	
	   return 0;   
	}
	
	if(!openOutputFileAppend(outFile))
	{	
	   return 0;   
	}
	
	Movie * movieArray = new Movie [MAX_SIZE];
	
	firstRecords=readFile(movieArray,inFile);
	
	totalRecords = firstRecords;

	do
	{
		decision = userOperations(movieArray, firstRecords);
	
		
		if(decision=='4' && MAX_SIZE > totalRecords)
		{
			totalRecords++;
		}

	}while(decision!='Q' &&  decision!='q');


	writeOutputFile(movieArray,outFile, firstRecords, totalRecords); 

	delete [] movieArray;
	
	inFile.close();
	outFile.close();

  return 0;
}

/***********************************************************************
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
***********************************************************************/

bool openInputFile(ifstream & inFile) 
{
   inFile.open("lab9input.txt");
   
   if (!inFile)
   {
      cout << "The input File cannot been opened!!!\n";

	  return false;
   }
   return true;
}

/***********************************************************************
*            openOutputFileAppend
*                 
* Purpose :Try to open an output file for use by the program in append
*			   mode.
*                    
* Pre-condition	: None.
*
* Post-condition: If output file has not been opened 
					  print error message and return false
*				  If output file has been opened  
*					  return true.
*				  
***********************************************************************/
bool openOutputFileAppend(ofstream &outFile)
{
	outFile.open("lab9input.txt",ios::app);
	if (!outFile)
    {
      cout << "The Output File cannot been opened!!!";

	  return false;
	}
   return true;


}


/***********************************************************************
*             readFile
*
* Purpose: 		   This function reads up to 50 records from an input 
				   file.
*
* Pre-condition:   The input file stream has been successfully opened &&
				   Array of a Movie object has been declared    &&
*                  the Movie attributes have been cleared or set to 
				   known values
*
* Post-condition:  The data have been loaded into movieArray 
				   from the input file.
***********************************************************************/

int readFile(Movie * movieArray, ifstream & inFile)
{
   int    i=0;

   string oneRecord,
	      ratingStr,
		  yearOfReleaseStr,
		  runningTimeStr;

   
   
    int   yearOfReleaseInt;
    float ratingFloat;
    int   runningTimeInt;
	
          
   while (getline(inFile, oneRecord) &&  i < MAX_SIZE)
   {
	   movieArray[i].addMovieName(oneRecord.substr(0,40));
	   movieArray[i].addFirstName(oneRecord.substr(41,10));
	   movieArray[i].addLastName(oneRecord.substr(52,13));

	   
	   yearOfReleaseStr  = oneRecord.substr(65,4);
	   yearOfReleaseInt  = atoi(yearOfReleaseStr.data());   
	   movieArray[i].addYearReleased(yearOfReleaseInt);

	   ratingStr    = oneRecord.substr(70,3);
	   ratingFloat  = atof(ratingStr.data());
	   movieArray[i].addCriticRating(ratingFloat);

	   runningTimeStr = oneRecord.substr(74,3);
	   runningTimeInt = atoi(runningTimeStr.data());
	   movieArray[i].addRunTime(runningTimeInt);
	  
      i++;
   }
   return i;
}

/***********************************************************************
*            writeOutputFile
*                 
* Purpose		: Takes records from the main function and writes them 
				  into outputfile.
*                    
* Pre-condition	: The OutputFile file has successfully opened.
*
* Post-condition: Records has been written into the file. 
***********************************************************************/
void writeOutputFile(Movie * movieArray, ofstream & outFile, 
					 int firstRecords, int totalRecords) 
{


	string oneRecord;

	for(int i=firstRecords; i<totalRecords; i++)
	{

	   outFile<<"\n"
		<<movieArray[i].retrieveMovieName()<<" "
		<<movieArray[i].retrieveDirectorsFirstName()<<" "
		<<movieArray[i].retrieveDirectorsLastName()
		<<movieArray[i].retrieveReleaseYear()<<" "
		<<fixed<< setprecision(1)<<movieArray[i].retrieveRating()<<" "
		<<setw(3)<<movieArray[i].retrieveRunTime();
	
	}


}

/***********************************************************************
*             displayOne
*
* Purpose: 		  The purpose is that display one record.
*
* Pre-condition:  The movieArray has been initialized. 
*
* Post-condition: One record from movieArray has been displayed.
***********************************************************************/
void displayOne(Movie & movieOne)
{

	cout<<movieOne.retrieveMovieName()<<" "
		<<movieOne.retrieveDirectorsFullName()<<" "
		<<movieOne.retrieveReleaseYear()<<" "
		<<fixed<< setprecision(1)<< movieOne.retrieveRating()<<" "
		<<setw(3)<<movieOne.retrieveRunTime()<<endl;
		
}


/***********************************************************************
*             displayAll
*
* Purpose: 		  This function displays all records from movieArray.
				  
*
* Pre-condition:  The movieArray has been initialized.
*
* Post-condition: All records from movieArray has been displayed.
***********************************************************************/
void displayAll(Movie * movieArray, int totalRecords)
{
	char decision='y';		
	int i=0;
	
	do
	{
		displayOne(movieArray[i]);


		if( (i+1) %10==0 && totalRecords != (i+1) )
		{
		   cin.get();

		   cout << "\nDo you want to continue listing(Y/N):";
		   cin>> decision;
			
		}
		
		i++;
			
	}while( i < totalRecords && (decision =='Y' || decision == 'y') );

	
	 
	cout<<endl;
		
}


/***********************************************************************
*             userOperations
*
* Purpose: The purpose is that prompt the user menu. After the user
			choose option, this function calls, another function in order
			to implement menu's option.
*
* Pre-condition:  The movieArray has been initialized. 
*
* Post-condition: After regarding function has been called,  decision 
				  of the user has been returned.
***********************************************************************/
char userOperations(Movie * movieArray, int firstRecords)
{
	char decision;

	string InputMovieName,
		   InputDirectorsLastName;


	static int totalRecords=firstRecords;

	do
	{
	   cout<<"\nPress 1: Display all records"<<endl;
	   cout<<"Press 2: Display one record based on Movie Name"<<endl;
	   cout<<"Press 3: Display one record based on Director's Last Name"
	   <<endl;
	   cout<<"Press 4: Add entry to the movie list"<<endl;
	   cout<<"Press Q: Quit Program"<<endl;

		cin>>decision;
		
		switch(decision)
		{
			case '1': 

				
				displayAll(movieArray,totalRecords);
				return decision;

			case '2':
				cin.ignore();
				cout<<"Enter Movie Name:";
				getline(cin,InputMovieName);
				searchMovieName(movieArray,InputMovieName,totalRecords);
				return decision;
			
			case '3': 
				cin.ignore();
				cout<<"Enter Directors Last Name:";
				getline(cin, InputDirectorsLastName);
				searchDirectorsLastName(movieArray,
				InputDirectorsLastName, totalRecords);

				return decision;
			case '4':
				
				cin.ignore();
				if(totalRecords >= MAX_SIZE)
				{
					cout<<"\nNo further additions permitted"<<endl;
					return decision;
				}
				else
				{
					addEntry(movieArray, totalRecords);
					totalRecords++;

					return decision;
				}

			case 'Q':

			case 'q':

				return decision;

			default:

				cout<<"You must enter 1, 2, 3, 4 or Q-q"<<endl;
		
		}

	}while(decision!='1' && decision!='2' && decision!='3' && 
		   decision!='4');


}

int getTotalRecords( int totalRecords)
{

	return totalRecords;
}


/***********************************************************************
*             searchMovieName
*
* Purpose: The purpose is that find the record by using movie name. 
*
* Pre-condition:    The movieArray has been initialized and movie name
					has been entered by the user.
*
* Post-condition: if the movie name exists
					call displayOne function in order to show record
				  else
					prompt "The record cannot be found!"
***********************************************************************/

void searchMovieName(Movie * movieArray, string movieNameUserInput, 
					 int totalRecords)
{
	string movieNameRecordArray;

	bool   flag=false;

	movieNameUserInput.resize(40,' ');

	for( int counter=0;  counter < totalRecords; counter++ )
    {
		
		movieNameRecordArray = movieArray[counter].retrieveMovieName();
		
	    if(movieNameRecordArray==movieNameUserInput)
		{
			
			displayOne(movieArray[counter]);
	
			flag=true;
	   
		}
		   
    }

	cout<<endl;

	if(flag==false)
	{
		cout<<"The record cannot be found!"<<endl;
	}

}

/***********************************************************************
*             searchDirectorsLastName
*
* Purpose: The purpose is that find the record by using Director's 
			LastName. 
*
* Pre-condition:  The movieArray has been initialized and Director's 
					LastName has been entered by the user.
*
* Post-condition: if the Director's LastName exists
					call displayOne function in order to show record
				  else
					prompt "The record cannot be found!"
***********************************************************************/
void searchDirectorsLastName(Movie * movieArray, 
							 string InputDirectorsLastName, 
							 int totalRecords)
{

	string LastNameRecordArray;

	bool   flag=false;
	
	InputDirectorsLastName.resize(13,' ');
	
	for( int counter = 0;  counter < totalRecords; counter++ )
    {
		
		LastNameRecordArray = 
						movieArray[counter].retrieveDirectorsLastName();
		
	
	    if(LastNameRecordArray == InputDirectorsLastName)
		{		 
			displayOne(movieArray[counter]);
	
			flag=true;
		}
    }
	cout<<endl;

	if(flag==false)
	{
		cout<<"The record cannot be found!"<<endl;


	}

}

/***********************************************************************
*             addEntry
*
* Purpose: The purpose is that add new record to the movieArray
*
* Pre-condition:   The movieArray has been initialized.
*
* Post-condition: The new record has been added by the user.
***********************************************************************/
void  addEntry(Movie * movieArray, int totalRecords)
{
	string movieName,
		   lastNameOfDirector,
		   firstNameOfDirector;

    int    yearOfReleasePtr;
    float  ratingPtr;
    int    runningTimePtr;
	
	bool flagForRunTime = false,
		 flagForCriticRating = false,
		 flagForYearReleased = false;
		 
	


	cout<<"\nEnter Movie Name:";
	getline(cin, movieName);
	movieArray[totalRecords].addMovieName(movieName);


	cout<<"\nEnter Director's Last Name:";
	getline(cin, lastNameOfDirector);
	movieArray[totalRecords].addLastName(lastNameOfDirector);


	cout<<"\nEnter Director's First Name:";
	getline(cin, firstNameOfDirector);
	movieArray[totalRecords].addFirstName(firstNameOfDirector);


	do
	{
		cout<<"\nEnter Year of Release betweeen 1900 and 2012:";
		
		cin>>yearOfReleasePtr;

		if( movieArray[totalRecords].addYearReleased(yearOfReleasePtr)
		   == false )
		{
			cout<<"Year of Release must be betweeen 1900 and 2012 "
			<<"inclusive!\n";
			
		}
		else
		{
			flagForYearReleased = true;
		
		}
		
	}while(!flagForYearReleased );

	do
	{
		cout<<"\nEnter Critic Rating between 1.0 and 4.0:";
		cin>>ratingPtr;

		if( movieArray[totalRecords].addCriticRating(ratingPtr)==false )
		{
		     cout<<"Critic Rating must be betweeen 1.0 and 4.0 "
			 <<"inclusive:\n";
			
		}
		else
		{
			flagForCriticRating = true;
		
		}
		
	}while(!flagForCriticRating);


	do
	{
	   cout<<"\nEnter Run Time between 10 and 300 inclusive:";
	   cin>>runningTimePtr;

	   if( movieArray[totalRecords].addRunTime(runningTimePtr) == false)
	   {
		   cout<<"Critic Rating must be betweeen 10 and 300 "
		   <<"inclusive:\n";
			
	   }
	   else
	   {
			flagForRunTime = true;
		
	   }
	   
		
	}while(!flagForRunTime);

 
}

