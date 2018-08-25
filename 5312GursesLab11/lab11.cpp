/***********************************************************************
* File Name:  Lab11.cpp
*
* Author:     Erman Gurses
*
* Course:     COSC 5312 - Foundations in Programming and Problem 
*			  Solving II,  
* 
* Date:       April 21, 2012
*
*Purpose: The purpose of this program is to convert a base-10 integer 
		  into its equivalent base-2 or base-16 number, depending on 
		  the user’s menu choice. 
*
* Input:  The user will input a menu choice and the number to be 
		  converted. Only positive integers will be accepted.  
		  The user will also decide when he/she is done converting 
		  numbers. 
*
* Output: A menu will be displayed with three options: Convert a base-10 
*         integer to its base-2 equivalent, convert a base-10 integer to 
*         its base-16 equivalent, quit the program.  The results of the
*         number conversions will also be displayed along with 
		  appropriateinformational messages.

************************************************************************/


#include "Stack.h" 
#include "Stack.cpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>    

using namespace std;

int BASE_2  = 2,
	BASE_16 = 16;


char displayMenu();
void processMenuChoice(char choice);
int  getNumber();
string convertTobase2(int base10number);
string convertTobase16(int base10number);
string getResults(Stack<string> theStack);
void displayResults(bool isBase2, int base10number, string result);

int main()
{
	char choice;

	do
	{
		choice=displayMenu();
		processMenuChoice(choice);

	}while(choice!='3');


  return 0;
}

/***********************************************************************
* display menu function
*
* Purpose:	This function will display a 3-option menu.  The options are:
*						1. Convert base-10 integer to a base-2 integer
*						2. Convert base-10 integer to a base-16 integer
*						3. Quit the program
*
* Pre-condition: None.
*
* Post- condition: The user has a character via the keyboard; input has 
				   been returned.  
************************************************************************/
char displayMenu()
{
	char option;

	cout<<"\nPlease choose from the following options:\n";
	cout<<"1. Convert base-10 integer to a base-2 integer\n";
	cout<<"2. Convert base-10 integer to a base-16 integer\n";
	cout<<"3. Quit the program\n";
	cin>>option;


	return option;
}
/************************************************************************
* process menu choice function
* 
* Purpose: Call the appropriate functions to get the number to be 
		   converted, convert the number to the requested base, and 
		   display the results. 
*		   If the user entered an invalid menu choice, an error message 
           will be displayed and control will return to main.
*
* Pre:	   Choice contains the input from the user from the menu 
*
* Post:	 If the user entered a valid menu choice
*			the function to get the number from the user was called &&
*			the appropriate function to convert the number was called &&
*			the function to display the results was called
*	     Else
*		    an error message about invalid menu choice was displayed
************************************************************************/
void processMenuChoice(char choice)
{
	int base10number;
	string convertResult;
	bool isBase2;

	switch(choice)
	{
		case '1': isBase2 = true;
				  base10number = getNumber();
				  convertResult = convertTobase2(base10number);
				  displayResults(isBase2,base10number,convertResult);
				  break;

		case '2': isBase2 = false;
				  base10number = getNumber();
				  convertResult = convertTobase16(base10number);
				  displayResults(isBase2,base10number,convertResult);
				  break;

		case '3': cout<<"Good-Bye\n";
				  break;

		default: cout<<"Invalid menu choice\n";

	}

}


/***********************************************************************
* get number function
*
* Purpose:	Prompts the user to enter a positive integer; accepts and 
*				validates input; returns integer to calling function.
*
* Pre:		None.
*
* Post:		A positive integer has been entered and returned.
***********************************************************************/
int getNumber()
{
	int number;

	cout<<"\nPlease enter the number you want converted:";
	cin>>number;

	while(number < 0)
	{
		cout<<"I’m sorry, but no negative numbers allowed\n";
		cout<<"Please enter another number:";
		cin>>number;	
	}

	return number;
}

/***********************************************************************
* convert to base-2
*
* Purpose:	Converts a base-10 positive integer to a string containing 
			the base-2 equivalent; returns the string to the calling 
			function.
*
* Pre:		base10number contains a non-zero value.
*
* Post:		result contains the base-2 equivalent of the number sent 
			into the function.
***********************************************************************/
string convertTobase2(int base10number)
{
	int remainder;

	Stack<string> binStack;


	if(base10number == 0)
	{
		return 0;
	
	}

	while(base10number > 0)
	{
		remainder = base10number % 2;

		if(remainder == 1)
		{
			binStack.push("1");
		}
		else
		{
			binStack.push("0");
		}

		base10number = base10number / 2;

	}

	return getResults(binStack);
}

/***********************************************************************
* convert to base-16
*
* Purpose:	Converts a base-10 positive integer to a string containing 
			the base-16 equivalent; returns the string to the calling 
			function.
*
* Pre:		base10number contains a non-zero value.
*
* Post:		result contains the base-16 equivalent of the number sent 
			into the function.
***********************************************************************/
string convertTobase16(int base10number)
{
	int remainder;

	Stack<string> hexStack;

	
	if (base10number == 0)
	{
		return 0;
	}

	while (base10number > 0)	
	{
		remainder = base10number % 16;
		switch (remainder)
		{
			case 0:   hexStack.push("0");
			          break;
			case 1:   hexStack.push("1");
			          break;
			case 2:   hexStack.push("2");
			          break;
			case 3:   hexStack.push("3");
			          break;
			case 4:   hexStack.push("4");
			          break;
			case 5:   hexStack.push("5");
			          break;
			case 6:   hexStack.push("6");
			          break;
			case 7:   hexStack.push("7");
			          break;
			case 8:   hexStack.push("8");
			          break;
			case 9:   hexStack.push("9");
			          break;
			case 10:  hexStack.push("A");
			          break;
			case 11:  hexStack.push("B");
			          break;
			case 12:  hexStack.push("C");
			          break;
			case 13:  hexStack.push("D");
			          break;
			case 14:  hexStack.push("E");
			          break;
			case 15:  hexStack.push("F");
			          break;
		}

		base10number = base10number / 16;
	}

	return getResults(hexStack);
}

/***********************************************************************
* get results function
*
* Purpose:	This function will retrieve the results of the conversion 
			from a stack and return the resulting string to the calling 
			function.
*
* Pre-condition: theStack contains known values.
*
* Post: The results of the conversion have been retrieved from the stack,
*       assigned to result, and returned.  
***********************************************************************/

string getResults(Stack<string> theStack)
{
	 string result,
		    temp;


	 result.clear();


	 while(theStack.isEmpty()!=true)
	 {
		theStack.pop(temp);
		result=result+temp;
	 }


	 return result;

}

/***********************************************************************
* display results function
*
* Purpose:	This function will display the result of the conversion 
			along with an appropriate message.
*
* Pre-condition: base10Number, result, and isBase2 contain known values.
*
* Post: The results of the conversion have been displayed.  
***********************************************************************/

void displayResults(bool isBase2, int base10number, string result)
{

	if(isBase2 == true)
	{
		cout<<"The base-2 ";
	}
	else
	{
		cout<<"The base-16 ";
	
	}

	
	cout<<"equivalent of "<<base10number<< " is "<<result<<endl;
	
}

