/********************************************************************
* File Name:  Lab4a.cpp
*
* Author:     Erman Gurses
*
* Course:     COSC 5312 - Foundations in Programming and Problem 
*			  Solving II,  A03539870
* 
* Date:       March 22, 2012
*
* Purpose:    The purpose is that read student records from 
*			  file and put them into 5 different arrays.
*			  There are 3 arrays that contain students's
*			  test grades. After finds average of these grades,
*			  estimates letter grade for each student and puts
*			  into grade array.Then user can choose 3 different 
*			  option to see this little database. User can see 
*			  all records, by last name and by letter grade.
*			  After user quit program 6 array is written
*			  in to new file. File name is specified by user. 
*          
*
* Input:      The Inputs are formatted file which is named 
*			  lab4ainput.txt 
*			  
*
* Output:	  The output is a formatted record into a file which is
*			  defined by user.
********************************************************************/


#include <iostream>
#include <fstream>
#include <string>    
#include <cstring>
#include <ctype.h>

using namespace std;


// Function prototypes
bool openInputFile(ifstream & inFile);

void readInputFile(ifstream & inFile, string lastName[], 
				   string firstName[], int score1[], int score2[],
				   int score3[], char grade[]);

 
void writeOutputFile(ofstream & outfile, string lastName[], 
					string firstName[], int  score1[], int  score2[],
					int  score3[], char grade[]);

bool openOutputFile(ofstream & outFile); 

void calculateGrade(int score1[], int score2[], int score3[], 
					char grade[]);

void displaySpecificLetter(char lGrade, string lastName[], 
						  string firstName[], int score1[], 
						  int score2[], int score3[], char grade[]);

char implementMenu(string lastName[], string firstName[], int score1[], 
					int score2[], int score3[], char grade[]);

void displayAll(string lastName[], string firstName[], int score1[], 
				int score2[], int score3[], char grade[]);

void displaySpecificName(string lName, string lastName[], 
						 string firstName[], int score1[], int score2[], 
						 int score3[], char grade[]);

void display(string lastName, string firstName, int score1, int score2, 
			 int score3, char grade);

void DoPause(); 


const int SIZE=25;

int main()
{
   ifstream inFile;
   ofstream outFile;
   

   string lastName[SIZE],
		  firstName[SIZE];
   int    score1[SIZE],
	      score2[SIZE],
          score3[SIZE];
   char   grade[SIZE],
		  decision;


   if(!openInputFile(inFile))
   {	
	  
	   return 0;
	   
   }


   if(!openOutputFile(outFile))
	{		
		return 0;
	}
	
   readInputFile(inFile,lastName,firstName,score1,score2,score3,grade);

  

   do
   {
	   decision=implementMenu(lastName,firstName,score1,score2,score3,
	   grade);
			  
   }while(decision!='Q' && decision!='q');


   writeOutputFile(outFile,lastName,firstName,score1,
					score2,score3,grade);
   
   cout <<"\nProgram finished!\n";

 
  return 0;
}

/************************************************************************
*            pause
*                 
* Purpose		: It does pause operation.
*                    
* Pre-condition	: None.
*
* Post-condition: Prompt  "Press [ Enter ] to continue...
*
************************************************************************/
void doPause()  
{
	static int counter = 0;

	if(counter%2==0)
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
   inFile.open("lab4aInput.txt");
   
   if (!inFile)
   {
      cout << "The input File cannot been opened!!!\n";

	  return false;
   }
   return true;
}

/************************************************************************
*            readInputFile
*                 
* Purpose		: Reads data from an input as a substring then puts them
*				  into 5 different arrays.
*                    
* Pre-condition : The input file has successfully opened.
*
* Post-condition: All the data have been read from file and have sent to 
				  calculate function.
************************************************************************/
void readInputFile(ifstream & inFile, string lastName[], 
				   string firstName[], int score1[], int score2[], 
				   int score3[], char grade[])
{
	int    i=0;
	string oneRecord,
		   score1S,
		   score2S,
		   score3S;

	
	while(getline(inFile, oneRecord))
	{
		lastName[i]	   = oneRecord.substr(0,10);
		firstName[i]   = oneRecord.substr(11,17);
		score1S        = oneRecord.substr(29,2);	
		score2S        = oneRecord.substr(32,2);
		score3S        = oneRecord.substr(35,2);

		
		score1[i]    = atoi(score1S.data());
		score2[i]    = atoi(score2S.data());
		score3[i]    = atoi(score3S.data());
		
		i++;

	}
	
	calculateGrade(score1,score2,score3,grade);
	
	inFile.close();	
}

/************************************************************************
*            calculateGrade
*                 
* Purpose		: It takes 3 score array and finds each elements of 
				  average. 
				  Then according to syllabus, it converts these scores to 
				  letter grade and puts these letters into grade array.
*                    
* Pre-condition	: score1, score2 and score3 arrays have been loaded. 
				  Grade array has been defined.
*
* Post-condition: Grade array has been loaded by letter grades.
************************************************************************/
void calculateGrade(int score1[], int score2[], int score3[], 
					char grade[])
{
	double average=0; 

	for(int i=0; i<SIZE; i++)
	{
		average=(score1[i]+score2[i]+score3[i])/3.0;
		
		if(average>=90.0)
		{
			grade[i]='A';
		}
		else if (average>=80.0)
		{
			grade[i]='B';
		}
		else if (average>=70.0)
		{
			grade[i]='C';
		}
		else if (average>=60.0)
		{
			grade[i]='D';
		}
		else 
		{
			grade[i]='F';
		}		
	
	}

}



/************************************************************************
*            implementMenu
*                 
* Purpose		: It takes decision from user and takes student 
				  information. According to decision it sends these 
				  information to decided functions. Also it has user
				  choice restrictions.
*                    
* Pre-condition	: Decision has to have value and student information has
				  been loaded into 6 arrays.
*
* Post-condition: if decision equals 1
						call displayAll function
				  if decision equals 2
						call displaySpecificName function
				  if decision equals 3
				  		check letter
						call displaySpecificLetter function
************************************************************************/
char implementMenu(string lastName[], string firstName[], int score1[], 
					int score2[], int score3[], char grade[])
{		
	char lGrade;
	int  flag=0;
	string lName;



	char decision;
	

	cout<<"\nPress 1: Display the names, scores, and grades for all the"
	<<"students."<<endl;
	
	cout<<"Press 2: Display specific student. "<<endl;
	cout<<"Press 3: Display a list of everyone who made a specific "
	<<"letter grade ,"<<endl;
	cout<<"Press Q: Quit."<<endl;
	
	do
	{
	   cin>>decision;
	
	   switch(decision)
	   {
		  case '1': 
				
			    displayAll(lastName,firstName,score1,
						 score2,score3,grade);
					
					  return decision;
					  
	      case '2': 
			    cin.ignore();

			    cout<<"Enter Last Name:";
			    getline(cin,lName);

				displaySpecificName(lName,lastName,firstName,
				                 score1,score2,score3,grade);
					
				return decision;
					  
					
		   case '3':
				
			    cout<<"Enter Grade Letter:";
			    cin>>lGrade;
				
			    lGrade=toupper(lGrade);

				 while (lGrade != 'A' && lGrade != 'B' && 
				 lGrade != 'C' && lGrade != 'D' && lGrade != 'F')
				 {
						
					cout<<"You must enter A or B or "
							"C or D or F"<<endl;

					cout<<"Enter Grade Letter:";
					cin>>lGrade;

					lGrade=toupper(lGrade);
				 }

				
				 displaySpecificLetter(lGrade,lastName,
				 firstName,score1,score2,score3,grade);

					  return decision;	

			case 'q':
			case 'Q':
					  return decision;	

			default:  cout<<"\nYou must enter 1 or 2 or 3 or Q or q\n";
			
					  cout<<"\nPress 1: Display the names, scores," 
					  <<" and grades for all the students."<<endl;
					  
					  cout<<"Press 2: Display specific student. "<<endl;
					  
					  cout<<"Press 3: Display a list of everyone who "
					  <<"made a specific letter grade ,"<<endl;
					  
				      cout<<"Press Q: Quit."<<endl;
		}// switch

	  }while(decision!='1' && decision!='2' && decision!='3' &&
			 decision!='Q' && decision!='q');

}

/***********************************************************************
*            displayAll
*                 
* Purpose		: It sends all student records to another function which 
				  is display funtion. After each 10 records showed, user 
				  has to press return key for see other 10 ones.
*                    
* Pre-condition	: Student information has been loaded  into  6 arrays.
*
* Post-condition: Display function has been called.
************************************************************************/
void displayAll(string lastName[], string firstName[], int score1[], 
				int score2[], int score3[], char grade[])
{
	for(int i=0; i<SIZE; i++)
	{
		if((i+1) % 10==0)
		{
		    doPause(); 
		}
		
		display(lastName[i],firstName[i],score1[i],score2[i],
				score3[i],grade[i]);
	}
}

/************************************************************************
*            displaySpecificName
*                 
* Purpose		: It takes specific last name of student and the other 
                  information about student. 
				  Shows this student's information
*                    
* Pre-condition	: Student information has been loaded  into  6 arrays.
*
* Post-condition: If last name of student is available it shows its info
				  otherwise it shows this student does not exist.
************************************************************************/
void displaySpecificName(string lName1, string lastName[], 
						string firstName[], int score1[], 
						int score2[], int score3[], char grade[])
{		

	int	   flag=0;
	string lName2;
	// Resize string variable and put for 
	// last element space delimeter.
	lName1.resize(10,' ');
	
	// It converts all letters in the lName1 to
	// upper case so it does not matter the 
	// user entered whether upper case or not.
	for(int i=0; i<10; i++)
	{
		lName1[i]=toupper(lName1[i]);
	}
	
	// It converts all letters in the lName2 to
	// upper case so it does not matter the 
	// user entered whether upper case or not.
	for(int i=0; i<SIZE; i++)
	{

		lName2=lastName[i];
		
		for(int j=0; j<10; j++)
		{
			lName2[j]=toupper(lName2[j]);
		}

		if(lName1.compare(lName2)==0)
		{
			flag=1;
			display(lastName[i],firstName[i],score1[i],score2[i],
				    score3[i],grade[i]);
		}
				
	}	

	if(flag==0)
	{
	   cout<<"Sorry! "<<lName1<<"does not exist in this class. "<<endl;
	}
}

/************************************************************************
*            displaySpecificLetter
*                 
* Purpose		: It takes student's letter grade and find which student 
				  has this letter grade and shows these students all 
				  information.
*                    
* Pre-condition	: Student information has been loaded  into  6 arrays.
*
* Post-condition: Shows students who has a this specific letter grade.
				  If any student does not have this letter grade it says 
				  no student has this letter grade
************************************************************************/
void displaySpecificLetter(char lGrade, string lastName[], 
						  string firstName[], int score1[], int score2[],
						  int score3[], char grade[])
{
	int	 i=0,
		 flag=0;

	while(i<25)
	{
		if(lGrade==grade[i])
		{
			display(lastName[i],firstName[i],score1[i],score2[i],
				    score3[i],grade[i]);

			flag=1;
		}

		i++;
	}

	if(flag==0)
	{
		cout<<"There is no student who got this letter grade."<<endl;
	}
}

/************************************************************************
*            display
*                 
* Purpose		: It displays last name, first name, score1, score2, 
				  score3 and grade.
*                    
* Pre-condition	: last name, first name, score1, score2, score3 read from 
				  file and grade calculad.
*
* Post-condition: It displayed last name, first name, score1, score2, 
				  score3 and grade.
*
************************************************************************/
void display(string lastName, string firstName, int score1, int score2, 
			 int score3, char grade)
{

	cout<<lastName<<" "<<firstName<<" "<<score1<<" "<<score2<< 
	" "<<score3<<" "<<grade<<endl;
	
}

/************************************************************************
*            openOutputFile
*                 
* Purpose		: Try to open an output file for using by the program. 
				  The file name specified by user.
*                    
* Pre-condition	: None.
*
* Post-condition: If output file has not been opened print error message 
				    and return false
*				  If output file has been opened  
*					return true.
*
************************************************************************/
bool openOutputFile(ofstream & outFile) 
{
	char fileName[30];
	cout<<"Enter file name:";

	cin>>fileName;
   
	outFile.open(fileName);

   if (!outFile)
   {
      cout << "The Output File cannot been opened!!!";

	  return false;
   }
   return true;
}

/************************************************************************
*            writeOutputFile
*                 
* Purpose		: Takes records from another function and write them into
				  outputfile.
*                    
* Pre-condition	: The OutputFile file has successfully opened.
*
* Post-condition: Record has been written into file. 
************************************************************************/
void writeOutputFile(ofstream & outfile, string lastName[], 
					 string firstName[], int  score1[], int  score2[],
					 int  score3[], char grade[])
{
	for(int i=0; i<25; i++)
	{
		outfile<<lastName[i]<<" "<<firstName[i]<<" "<<score1[i]<<" "
		<<score2[i]<<" "<<score3[i]<<" "<<grade[i]<<endl;
	}
	outfile.close();

}
