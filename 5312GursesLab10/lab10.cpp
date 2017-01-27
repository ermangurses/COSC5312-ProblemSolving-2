/***********************************************************************
* File Name:  Lab10.cpp
*
* Author:     Erman Gurses
*
* Course:     COSC 5312 - Foundations in Programming and Problem 
*			  Solving II,  
* 
* Date:       April 16, 2012
*
* Purpose:  The program reads  employee records from file and then 
			puts those records into a linkedList. 
			The program prompt the user a menu in order to operate 
			some operations:
			
			Press 1- View Records for Disaster Callback
			Press 2- View Records for Budgetary Planning
			Press 3- Display one record based on Employee's Last Name
			Press 4- Add entry to the list
			Press 5- Remove entry from the list
			Press 6- Display the number of employees regarding the job 
					 code
		    Press Q- Quit Program
			
			After the user does some operations on the records, the 
			program writes back these records into same file. 
			
*          
*
* Input:    The user enters, via the keyboard, new record. The program
			reads records from file.  
*
* Output:	The menu is displayed on the screen in order to choose type 
			of operation. 
			After the user choose type of operation the program 
			displays;
				Records for Disaster Callback or
				Records for Budgetary Planning or
				One record based on Employee's Last Name or 
			adds; 
				entry to the list or 
			removes;
				entry from the list or 				
			displays;
				The number of employees regarding the job code
			quits;
				The program.
			After the user chooses the quit option, the program 
			re-writes records into the lab9input.txt file.
					
***********************************************************************/


#include "LinkedList.h"
#include "LinkedList.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;

const int CURRENTYEAR = 2012;

 struct Data
 {
	 string departmentCode,
			jobCode,
			lastName,
			firstName,
			phoneNumber,
			dateHired;

	 char supervisoryCode,
		  shiftCode,
		  payCode;

	 float hourlyPayRate;
	      
};

bool openInputFile(ifstream & inFile);
bool openOutputFile(ofstream & outFile); 
void readFile(ifstream & inFile, LinkedList<string,Data> &List);
void recordsForDisasterCallback(LinkedList<string,Data> & List);
void recordsForBudgetaryPlanning(LinkedList<string,Data> & List);
void search (LinkedList<string,Data> & List);
void addRecord (LinkedList<string,Data> & List);
void removeRecord(LinkedList<string,Data> & List);
void countEmployeesForJobCode(LinkedList<string,Data> & List);
void writeOutputFile(LinkedList<string,Data> & List, ofstream & outFile);
char menu (LinkedList<string,Data> & List);


int main()
{

	LinkedList<string,Data> List;

	Data data;

	ifstream inFile;
	ofstream outFile;
	
	char decision;

	
	

	if(!openInputFile(inFile))
	{	
	   return 0;   
	}
	
	 readFile(inFile,List);
	

	do
	{
		decision = menu(List);
	
	}while(decision!='Q' &&  decision!='q');
	

	if(!openOutputFile(outFile))
	{	
	   return 0;   
	}

	writeOutputFile(List,outFile);

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
   inFile.open("LabEmpData.txt");
   
   if (!inFile)
   {
      cout << "The input File cannot be opened!!!\n";

	  return false;
   }
   return true;
}


/***********************************************************************
*            openOutputFile
*                 
* Purpose		: Try to open an output file for use by the program.
*                    
* Pre-condition	: None.
*
* Post-condition: If output file has not been opened print error message 
				  and 
*				  	return false
*				  If output file has been opened  
*					return true.
*
************************************************************************/
bool openOutputFile(ofstream & outFile) 
{
   outFile.open("LabEmpData.txt");
   if (!outFile)
   {
      cout << "The Output File cannot be opened!!!";

	  return false;
   }
   return true;
}


/**********************************************************************
*             readFile
*
* Purpose: This function reads records from an input file then puts
		   these records into LinkedList.
*
* Pre-condition:   The input file stream has been successfully opened.
*
* Post-condition: The data have been loaded into LinkedList 
				  from the input file.
**********************************************************************/

void readFile(ifstream& inFile, LinkedList<string,Data> &List)
{
 
   Data	  data;
   string oneRecord;

   while (getline(inFile, oneRecord))
   {
	   data.departmentCode   =  oneRecord.substr(0,3);
	   data.supervisoryCode  =  oneRecord[3];
	   data.jobCode			 =  oneRecord.substr(4,3);
	   data.lastName         =  oneRecord.substr(8,12);
	   data.firstName        =  oneRecord.substr(20,9);
	   data.phoneNumber      =  oneRecord.substr(30,8);
	   data.shiftCode  	     =  oneRecord[39];	   
	   data.payCode			 =  oneRecord[40];
	   data.dateHired        =  oneRecord.substr(41,8);
	   data.hourlyPayRate    =  atof(oneRecord.substr(50,5).data());
	      
	   List.insertInOrder(data.lastName,data);
	  
   }

}


/**********************************************************************
*             menu
*
* Purpose: The purpose is that prompt the user menu. After the user
		   choose option, this function calls another function in order
		   to implement menu's option.
*
* Pre-condition: The LinkedList has been initialized.
*
* Post-condition: The calling function has been implemented and decision
				   returned to the main function. 
*
**********************************************************************/

char menu (LinkedList<string,Data> & List)
{
	Data data;
	char decision;


	do
	{
	   cout<<"\nPress 1: Records for Disaster Callback "<<endl;
	   cout<<"Press 2: Records for Budgetary Planning "<<endl;
	   cout<<"Press 3: Display one record based on Employee's Last Name"
	   <<endl;
	   cout<<"Press 4: Add entry to the list"<<endl;
	   cout<<"Press 5: Remove entry from the list"<<endl;
	   cout<<"Press 6: Display the number of employees regarding the job"
	   " code"<<endl;
	   cout<<"Press Q: Quit Program"<<endl;
	   cin>>decision;
		
		switch(decision)
		{
			case '1': 

				recordsForDisasterCallback(List);
				
				return decision;

			case '2':

				recordsForBudgetaryPlanning(List);


				return decision;

			case '3': 
				
				search (List);

				return decision;

			case '4':
				
				 addRecord(List);
		
				return decision;

			case '5':

				removeRecord(List);

				return decision;

			case '6':

				countEmployeesForJobCode(List);

				return decision;

			case 'Q':


			case 'q':


				return decision;

			default:

				cout<<"You must enter 1, 2, 3, 4 or Q-q"<<endl;
		
		}

	}while(decision!='1' && decision!='2' && 
		   decision!='3' && decision!='4');


}

/**********************************************************************
*             recordsForDisasterCallback
*
* Purpose: The purpose is that List all employees in alphabetical order
		   based on Last Name.
		   This list  includes the following data for each employee: 
		   Employee's last and first name, employee's phone number 
		   (if present), the department name the supervisory code, 
		   the job code, and the shift code.
*
* Pre-condition: The menu has been prompted the user and  the user has
				 made his/her choice.
*
* Post-condition: The records have been displayed on the screen. 
*
**********************************************************************/

void recordsForDisasterCallback(LinkedList<string,Data> & List)
{
	Data data;

	string departments[]= {"Bood Bank", "Chemistry",
						  "Hematology","Microbiology"};

	char decision='y';
	int j=0;
	int i=1;

	cout<<"-Last Name-\t-First Name-\t-Phone Number-\t-Department Name-"
		<<"   -Supervisory Code-\t-Job Code-    -Shift Code-\n"<<endl;

	do
	{
		

		data=List.retrieve(i);

		if (data.departmentCode=="BLB")
		{
			j=0;
		}
		else if (data.departmentCode=="CHE")
		{
			j=1;
		}
		else if (data.departmentCode=="HEM")
		{	
			j=2;
		}
		else
		{
			j=3;
		
		}
	

		cout<<"  "<<data.lastName<<"\t  "<<data.firstName<<"\t   "
		    <<data.phoneNumber<<"\t   "
			<<departments[j]<<"\t\t   "<<data.supervisoryCode<<"\t\t   "
			<<data.jobCode<<"\t\t  "<<data.shiftCode<<endl;


		if( (i) % 20 == 0 && List.sizeOf() != (i) )
		{
			cin.get();

			cout << "\nDo you want to continue listing(Y/N):";
			cin>> decision;
		}
			
		i++;

	}while( i <= List.sizeOf() && (decision =='Y' || decision == 'y') );

}

/**********************************************************************
*             recordsForBudgetaryPlanning
*
* Purpose:  The purpose is that List all employees in alphabetical order. 
			This list includes the following data for each employee: 
			Employee's last and first name, the number of years each 
			employee has worked in the lab (based on the year hired), 
			the date hired in the format of mm/dd/yyyy, the job code, 
			and the hourly pay rate.
*
* Pre-condition: The menu has been prompted the user and  the user has
				 made his/her choice.
*
* Post-condition: The records have been displayed on the screen. 
*
**********************************************************************/
void recordsForBudgetaryPlanning(LinkedList<string,Data> & List)
{
	Data    data;
	char    decision='y';
	int     yearInt,
		    i=1;
	string  month,
		    day,
		    year,
		    dateHired;

	cout<<"-Last Name-\t-First Name-\t-The Worked Years-\t-Date Hired-\t"
	    <<"-Job Code-\t-Hourly Pay Rate-\n"<<endl;


	do
	{

		data=List.retrieve(i);

		yearInt = atoi(data.dateHired.substr(0,4).data());
		
		year  = data.dateHired.substr(0,4);

		month = data.dateHired.substr(4,2);

		day   = data.dateHired.substr(6,2); 


		dateHired  = month+'/'+day+'/'+year;

		cout<<"  "<<data.lastName<<"\t  "<<data.firstName<<"\t\t "
			<<CURRENTYEAR-yearInt<<"\t\t "
			<<dateHired<<"\t    "<<data.jobCode<<"\t\t     "<<"$"
			<<fixed<< setprecision(2)<<data.hourlyPayRate<<endl;

		if( (i) %20==0 && List.sizeOf() != (i) )
		{
			cin.get();

			cout << "\nDo you want to continue listing(Y/N):";
			cin>> decision;
		}

		i++;

	}while( i <= List.sizeOf() && (decision =='Y' || decision == 'y') );



}

/**********************************************************************
*             search
*
* Purpose: The purpose is to implement search operation on LinkedList 
		   by using lastName.
*
* Pre-condition:  The menu has been prompted the user and the user has
				  made his/her choice.
*
* Post-condition: The record has been displayed on the screen. 
*
**********************************************************************/
void search(LinkedList<string,Data> & List)
{
	Data   data;
	string lastName;
	int    location;

	

	cout<<"Enter Last Name of Employee:";
	cin>>lastName;

	lastName[0]=toupper(lastName[0]);
	
	lastName.resize(12,' ');



	if(List.search(lastName,location))
	{

		data = List.retrieve(location);

		cout<<"-Department Code-  -Supervisory Code-  -Job Code-  "
		    <<"-Last Name-  -First Name-  -Phone Number-  -Shift Code-  "
			<<"-Pay Code-  -Date Hired-  -Pay Rate-\n"<<endl;
	 
		cout<<"\t"<<data.departmentCode<<"\t\t  "<<data.supervisoryCode
		    <<"\t\t  "<<data.jobCode<<"\t      "
		    <<data.lastName<<" "<<data.firstName<<"\t"
		    <<data.phoneNumber<<"\t    "
		    <<data.shiftCode<<"\t\t"<<data.payCode<<"\t  "
			<<data.dateHired<<"\t"
		    <<"$"<<fixed<< setprecision(2)<<data.hourlyPayRate<<endl;

	}
	else
	{
	
		cout<<"The record cannot be found!"<<endl;
	
	}

}

/**********************************************************************
*             addRecord
*
* Purpose: The purpose is to add record into the LinkedList
*
* Pre-condition:  The menu has been prompted the user and the user has
				  made his/her choice.
*
* Post-condition: The new record has been added into the LinkList.
*
**********************************************************************/
void addRecord (LinkedList<string,Data> & List)
{
	Data data;
	char decisionForPhoneNumber;	

	cout<<"Enter Your First Name:";
	cin.ignore();
	getline(cin,data.firstName);
	data.firstName.resize(9,' ');
	data.firstName[0] = toupper(data.firstName[0]);
	
	cout<<"Enter Your Last Name:";
	getline(cin,data.lastName);
	data.lastName.resize(12,' ');
	data.lastName[0] = toupper(data.lastName[0]);

	do
	{
		cout<<"Enter Your Department Code:";
	
		cin>>data.departmentCode;
		data.departmentCode.resize(3);

		for(int i=0; i<3; i++)
		{	
			data.departmentCode[i] = toupper(data.departmentCode[i]);
		}

		if(data.departmentCode!="BLB" && data.departmentCode!="CHE"  && 
		   data.departmentCode!="HEM" && data.departmentCode!="MIC")
		{
		
		     cout<<"Department Code must be BLB or CHE or HEM or MIC\n";
		
		
		}

	}while(data.departmentCode!="BLB" && data.departmentCode!="CHE"  && 
		   data.departmentCode!="HEM" && data.departmentCode!="MIC");


	do
	{

		cout<<"Enter Your Supervisory Code:";
		cin.ignore();
		cin>>data.supervisoryCode;
		data.supervisoryCode = toupper(data.supervisoryCode);

		
		if(data.supervisoryCode!='B' && data.supervisoryCode!='S')
		{
			cout<<"Supervisory Code must be B or S"<<endl;
		}

	}while(data.supervisoryCode!='B' && data.supervisoryCode!='S');


	do
	{
		cout<<"Enter Your Job Code:";
		cin.ignore();
		cin>>data.jobCode;
	
		data.jobCode.resize(3,' ');
	
		for(int i=0; i<3; i++)
		{	
			data.jobCode[i] = toupper(data.jobCode[i]);
		}

		if(data.jobCode!="MT " && data.jobCode!="MLT" && 
		   data.jobCode!="CLA")
		{
			cout<<"Job Code must be MT or CLA or MLT"<<endl;
			
		}
		else
		{
			if(data.jobCode=="MT ")
			{
					for(int i=1; i>=0; i--)
					{
						data.jobCode[i+1] = data.jobCode[i];
					}

					data.jobCode[0]=' ';
			}
		}

	}while(data.jobCode!=" MT" && data.jobCode!="MLT" && 
		  data.jobCode!="CLA");

	
	cout<<"Do you want to enter phone number (Y/N):";
	cin>>decisionForPhoneNumber;

	decisionForPhoneNumber=toupper(decisionForPhoneNumber);

	if(decisionForPhoneNumber=='Y')
	{
		cout<<"Enter Your Phone Number(Format is xxx-xxxx):";
		cin.ignore();
		cin>>data.phoneNumber;
		
	}

	data.phoneNumber.resize(8,' ');

	do
	{
		cout<<"Enter Your Shift Code:";
		cin.ignore();
		cin>>data.shiftCode;
		
		if(data.shiftCode!='1' && data.shiftCode!='2' && 
		   data.shiftCode!='3')
		{
			cout<<"Shift Code must be 1 or 2 or 3"<<endl;
		}

	}while(data.shiftCode!='1' && data.shiftCode!='2' && 
	       data.shiftCode!='3');

	do
	{	
		cout<<"Enter Your Pay Code:";
		cin.ignore();
		cin>>data.payCode;
		data.payCode=toupper(data.payCode);

		if(data.payCode!='F' && data.payCode!='P')
		{
			cout<<"Pay Code must be F or P"<<endl;
		}


	}while(data.payCode!='F' && data.payCode!='P');
	
	data.payCode=toupper(data.payCode);

	cout<<"Enter Your Hired Date(Format is yyyymmdd):";
	cin.ignore();
	cin>>data.dateHired;
	data.dateHired.resize(8); 

	cout<<"Enter Your Hourly Pay Rate:";
	cin.ignore();
	cin>>data.hourlyPayRate;


	List.insertInOrder(data.lastName,data);
}

/**********************************************************************
*             removeRecord
*
* Purpose: The purpose is to remove a record from the LinkedList
*
* Pre-condition:  The menu has been prompted the user and the user has
				  made his/her choice.
*
* Post-condition: if there is a record related to lastName
					The record has been removed from the LinkList.
*				  else
					Prompt "The record cannot be found!"
*
**********************************************************************/
void removeRecord(LinkedList<string,Data> & List)
{

	string keyOut;
	Data dataOut;

	cout<<"Enter Your Last Name:";
	cin.ignore();

	getline(cin,keyOut);


	keyOut.resize(12,' ');

	keyOut[0]=toupper(keyOut[0]);

	if(!List.remove(keyOut,dataOut))
	{
		cout<<"The record cannot be found!"<<endl;
	}

}

/**********************************************************************
*             countEmployeesForJobCode
*
* Purpose: The purpose is to rcount employees regarding their job code.
*
* Pre-condition:  The menu has been prompted the user and the user has
				  made his/her choice.
*
* Post-condition: if the user enters proper job code 
					shows the user number of employees related to jobcode
*				  else
					Prompt "Job Code must be MT or MLT or CLA"
**********************************************************************/
void countEmployeesForJobCode(LinkedList<string,Data> & List)
{

	LinkedList<string,Data> tempList = List;

	string keyOut,
		   jobCode;
	Data   dataOut;
	int    counter=0,
		   label,
		   i=0;

	string Jobs[]= {"Medical Technologist",
	                "Medical Laboratory Technicians",
					"Certificated Lab Assistants"};

	
	do
	{
		
		
			cout<<"Enter the Job Code:";
			cin>>jobCode;

			for(int i=0; i < jobCode.size(); i++)
			{
				jobCode[i]=toupper(jobCode[i]);
				
			}

			if(jobCode=="MT" || jobCode=="MLT" || jobCode=="CLA")
			{
					if(jobCode=="MT")
					{
						label=0;
					}
					else if(jobCode=="MLT")
					{
	
						label=1;
	
					}
					else if (jobCode=="CLA")
					{
						label=2;
	
					}

					while(tempList.removeFront(keyOut,dataOut))
					{

						if(dataOut.jobCode==" MT")
						{	
							
							for(int i=0; i<2; i++)
							{
							  dataOut.jobCode[i] = dataOut.jobCode[i+1];
							}

							dataOut.jobCode.resize(2);
						}

						if(dataOut.jobCode==jobCode)
						{
							 counter++;
						}

					}
			}
			else
			{
				cout<<"Job Code must be MT or MLT or CLA"<<endl;
			
			}

	}while(jobCode!="MT" && jobCode!="MLT" && jobCode!="CLA" );

	cout<<"There are "<<counter<<" "<<Jobs[label]<<" in the hospital\n";


}

/**********************************************************************
*            writeOutputFile
*                 
* Purpose		: Takes records from the main function and writes them 
				  into outputfile.
*                    
* Pre-condition	: The OutputFile file has successfully opened. &&
				  The menu has been prompted the user and the user has
				  made his/her choice.
*
* Post-condition: Records has been written into the file. 
**********************************************************************/

void writeOutputFile(LinkedList<string,Data> & List, ofstream & outFile)
{

	Data data;
	string frontKey; 

	while(List.removeFront(frontKey,data))
	{
		outFile<<data.departmentCode<<data.supervisoryCode<<data.jobCode
			   <<" "<<data.lastName<<data.firstName<<" "
			   <<data.phoneNumber<<" "<<data.shiftCode
			   <<data.payCode<<data.dateHired<<" "
			   <<fixed<< setprecision(2)<<data.hourlyPayRate<<endl;

	}
}

