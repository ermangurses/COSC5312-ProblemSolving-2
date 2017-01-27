/*************************************************************************
* File Name:  Lab4b.cpp
*
* Author:     Erman Gurses
*
* Course:     COSC 5312 - Foundations in Programming and Problem 
*			  Solving II,  A03539870
* 
* Date:       March 22, 2012
*
* Purpose:    The purpose is that read data from file put them into 2-D
*			  array then calculates sum of data, average of data, sum of 
*			  specific row's, sum of specific columns's, biggest value of 
*			  specific row's and smallest value of specific row's. After
*			  that show these values to user.         
*
* Input:      The Inputs are data from file which is named lab4binput.txt 
*			 
*
* Output:	  The outputs are sum of data, average of data, sum of 
			   specific row's, sum of specific columns's, biggest value
			   of specific row's and smallest value of specific row's
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>



using namespace std;

const int ROW    = 20;
const int COLUMN = 15;
const int NUMBER = 300;

bool   openInputFile(ifstream & inFile);
void   readInputFile(int [][COLUMN], ifstream & inFile );
int    sumData(int data[][COLUMN]);
double averageData(int data[][COLUMN]);
int    sumRowData(int data[][COLUMN], int i);
int    sumColumnData(int data[][COLUMN], int j);
int	   findRowMax(int data[][COLUMN], int i);
int    findRowMin(int data[][COLUMN], int i);
int    menuRow();
int	   menuColumn();




int main()
{
   ifstream	 inFile;
   int		 data[ROW][COLUMN], 
			 rowNumber,
			 columnNumber;
   char		 decision;

   if(!openInputFile(inFile))
   {	
	   return 0;
   }

   readInputFile(data, inFile);
   
   inFile.close();
   
   do
   {
	   //Function calls for get row's and column's number.
	   rowNumber=menuRow();
	   columnNumber=menuColumn();

	   // Function Calls and prompt user results 
	   cout<<"\nSum of array is            : "<<sumData(data)<<endl;
	   cout<<"Average of array is        : "<<averageData(data)<<endl;
	   
	   cout<<rowNumber+1<<". row's sum is            : "
	   <<sumRowData(data,rowNumber)<<endl;
	   
	   cout<<columnNumber+1<<". column's sum is         : "
	   <<sumColumnData(data,columnNumber)<<endl;
	   
	   cout<<rowNumber+1<<". row's largest datum is  : "
	   << findRowMax(data,rowNumber)<<endl;
	   
	   cout<<rowNumber+1<<". row's smallest datum is : "
	   << findRowMin(data,rowNumber)<<endl;  

	   cout<<"\nDo you want to do again? Y/N:";
	   cin>>decision;


   }while(decision=='Y' || decision== 'y');

  
   cout <<"\nProgram finished!\n";

   
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
   inFile.open("lab4bInput.txt");
   if (!inFile)
   {
      cout << "The input File cannot been opened!!!\n";

	  return false;
   }
   return true;
}

/***********************************************************************
*            readInputFile
*                 
* Purpose		: Reads data from an input file than puts them into 2-D 
					array
*                    
* Pre-condition : The input file has successfully opened.
*
* Post-condition: All the data that have been read from file put into 2-D
				  array.
***********************************************************************/
void readInputFile(int data[][COLUMN], ifstream & inFile )
{
	for(int i=0; i<ROW; i++)
	{
		for(int j=0; j<COLUMN; j++)
		{
				inFile>>data[i][j];
						
		}
	}

}

/***********************************************************************
*            sumData
*                 
* Purpose		: It adds all data from 2-D array to sum variable.
*                    
* Pre-condition	: Data has to been available in the 2-D array.
*
* Post-condition: It returns summation of data.
*
***********************************************************************/
int sumData(int data[][COLUMN])
{
	int sum=0;

			for(int i=0; i<ROW; i++)
			{
				for(int j=0; j<COLUMN; j++)
				{
					sum+=data[i][j];
					
				}
			}

 return sum;
}


/***********************************************************************
*            averageData
*                 
* Purpose		: It adds all data from 2-D array to sum variable then
				  divides by number of elements in the 2-D array.
*                    
* Pre-condition	: Data has to been available in the 2-D array.
*
* Post-condition: It returns avarage of data in the array.
*
***********************************************************************/
double averageData(int data[][COLUMN])
{
	int	   sum    = 0;
			
			for(int i=0; i<ROW; i++)
			{
				for(int j=0; j<COLUMN; j++)
				{
					sum+=data[i][j];				
				}
			}

 return (double)sum/NUMBER;
}

/***********************************************************************
*            sumRowData
*                 
* Purpose		: It adds specific row data into the sum variable. The 
				  row number specified by user.				  
*                    
* Pre-condition	: Data has to been available in the 2-D array.
*
* Post-condition: It returns summation of data from specific row.
*
***********************************************************************/

int sumRowData(int data[][COLUMN], int i)
{
	int sum=0;
	
	for(int j=0; j<COLUMN; j++)
	{
		sum+=data[i][j];
					
	}
			
 return sum;
}

/************************************************************************
*            sumColumnData
*                 
* Purpose		: It adds specific column data into the sum variable. 
*				  The column number specified by user.				  
*                    
* Pre-condition	: Data has to been available in the 2-D array.
*
* Post-condition: It returns summation of data from specific column.
*
************************************************************************/  
int sumColumnData(int data[][COLUMN], int j)
{
	int sum=0;
	
	for(int i=0; i<ROW; i++)
	{
		sum+=data[i][j];
					
	}

 return sum;

}

/************************************************************************
*            findRowMax
*                 
* Purpose		: It finds the largest number in the specified row.
*                    
* Pre-condition	: Data has to been available in the 2-D array.
*
* Post-condition: Returns the largest number in the specified row.
*
************************************************************************/
int findRowMax(int data[][COLUMN], int i)
{
	int max=data[i][0];
	
	for(int j=1; j<COLUMN; j++)
	{
			if(data[i][j]>max)
			{
				max=data[i][j];			
			}					
	}
			
 return max;

}

/***********************************************************************
*            findRowMin
*                 
* Purpose		: It finds the smallest number in the specified row.
*                    
* Pre-condition	: Data has to been available in the 2-D array.
*
* Post-condition: Returns the smallest number in the specified row.
*
************************************************************************/
int findRowMin(int data[][COLUMN], int i)
{
	int min=data[i][0];
	
	for(int j=1; j<COLUMN; j++)
	{
			if(data[i][j]<min)
			{
				min=data[i][j];			
			}					
	}
			
 return min;

}

/************************************************************************
*            menuRow
*                 
* Purpose		: It gets row's number from user and checks it whether is 
				  proper or not. If it is not proper it will ask again
				  until user enter proper number.
*                    
* Pre-condition	: Data has to been available in the 2-D array.
*
* Post-condition: Returns row's number.
*
************************************************************************/
int menuRow()
{
	int row;
	
	cout<<"\nThere are 300 numbers in the 2-D array."<<endl;
	cout<<"This array has 20 rows and 15 columns"<<endl;
	cout<<"The program will do some calculations on this 2-D array's "
	"data such as;"<<endl;
	
	cout<<"It will find:\n\nArray's Sum\nArray's Average\nSpecified "
	<<"Row's sum\n"
	<<"Specified Column's sum\nSpecified Row's largest datum\n"
	"Specified Row's smallest datum"<<endl;
	
	cout<<"Before these calculations you have to specify row's and "
	" column's numbers"<<endl;

	do{
		
		cout<<"\nEnter Row's number:";
		
		cin>>row;

		if(row < 1 || row > 20)
		{
			cout<<"Row number must be between 1-20 inclusive"<<endl;
		}

	  }while(row < 1 || row > 20);

	return row-1;

}

/************************************************************************
*            menuColumn
*                 
* Purpose		: It gets column's number from user and checks it whether 
				  is 
				  proper or not. If it is not proper it will ask again
				  until user enter proper number.
*                    
* Pre-condition	: Data has to been available in the 2-D array.
*
* Post-condition: Returns column's number.
*
************************************************************************/
int menuColumn()
{
	int column;

	do{
		
		cout<<"Enter Column's number:";
		cin>>column;

		if(column < 1 || column > 15)
		{
			cout<<"Column number must be between 1-15 inclusive"<<endl;
		}

	  }while(column<1 || column>15);

	return column-1;
}
