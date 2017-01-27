/************************************************************************
* Author: Erman Gurses
* Date:   March 26, 2012
* 
*
* Purpose: This file is the implementation file for the  class.  
*          It contains all the function definitions for the class.
************************************************************************/


#include "movie.h" 



/************************************************************************
*                 Default Constructor
*
* Purpose: The constructor of a class instantiates one instance of the
*          class when a declaration is made by the program using the
*          class ("driver" or "client" program). It uses the clear 
		   function (in the string class) to clear any residual data 
		   out of the string-type attributes movieName, 
		   lastNameOfDirector, firstNameOfDirector, and 
		   fullNameOfDirector.
		   It also dynamically allocates memory for the release year,
		   critics' rating, and running time variables and set the 
		   values of those variables to zero.
*
* Precondition:  An instance of the class has been declared.
*
* Postcondition: The yearOfRelease, ratingOfCritics, and runningTime 
				 attributes have been set to zero. The String-type 
				 attributes movieName, lastNameOfDirector, 
				 firstNameOfDirector, fullNameOfDirector are cleared. 
************************************************************************/


Movie::Movie()
{

	movieName.clear();
	lastNameOfDirector.clear();
	firstNameOfDirector.clear();
	fullNameOfDirector.clear();


	yearOfRelease   = new int;
	ratingOfCritics = new float;
	runningTime     = new int;


	* yearOfRelease   = 0;
	* ratingOfCritics = 0;
	* runningTime     = 0;



}

/************************************************************************
*                 Destructor
*
* Purpose: The destructor of a class automatically destroys an instance
*          of the class when it is no longer needed.  Destructors are NOT
*          explicitly invoked by the programmer.  They are implicitly
*          called when the instance has reached the end of its scope
*          within the driver program using it.
*
* Precondition:  An instance of the class has been declared.
*
* Postcondition: The instance of the object has been destroyed.
************************************************************************/
Movie::~Movie()
{
   
	delete  yearOfRelease;
	delete	ratingOfCritics;
	delete	runningTime;


}

/************************************************************************
*                       addMovieName
*
* Purpose: This function accepts a string as an argument and assigns it 
		    to the movieName attribute. The movieName resized
			to a length of 40 and padded with spaces.
*
* Precondition: An instance of the class has been declared &&
				movieName has been cleared.
				
*
* Postcondition: movieName has been assigned the value of "movieNameF" 
				 && The movieName resized to a length of 40 and padded 
				 with spaces.
************************************************************************/
void Movie::addMovieName (string movieNameF)
{

	movieName = movieNameF; 
    movieName.resize(40,' ');

}
/************************************************************************
*                       addLastName
*
* Purpose: This function accepts a string as an argument and assigns it 
		    to the lastNameOfDirector attribute. The lastNameOfDirector
			resized to a length of 13 and padded with spaces.
*
* Precondition:  An instance of the class has been declared &&
				 lastNameOfDirector has been cleared.
*
* Postcondition: lastNameOfDirector has been assigned the value of 
				 "lastNameOfDirectorF" && 
				 The lastNameOfDirector resized to a length of 13 and 
				 padded with spaces.
************************************************************************/
void Movie::addLastName(string lastNameOfDirectorF )
{
	
		

    lastNameOfDirector =lastNameOfDirectorF;

	lastNameOfDirector.resize(13,' ');

}

/************************************************************************
*                       addFirstName
*
* Purpose:  This function accepts a string as an argument and assigns it 
		    to the firstNameOfDirector attribute. The firstNameOfDirector
			resized to a length of 10 and padded with spaces.
*
* Precondition:   An instance of the class has been declared &&
				  firstNameOfDirector has been cleared.
*
* Postcondition:  firstNameOfDirector has been assigned the value of 
				  "firstNameOfDirectorF" && 
				  The firstNameOfDirector resized to a length of 10 
				  and padded with spaces.
************************************************************************/
void Movie::addFirstName( string firstNameOfDirectorF)
{
   firstNameOfDirector=firstNameOfDirectorF;
   
   firstNameOfDirector.resize(10,' ');
   
}

/************************************************************************
*                       addYearReleased
*
* Purpose: This function accepts an integer as an argument and assign it 
		    to the *yearOfRelease attribute.
*
* Precondition:  An instance of the class has been declared.
*
* Postcondition: If yearOfReleaseF is less than 1900 or 
				 yearOfReleaseF is more than 2012 
*                   false is returned
*                Else
					*yearOfRelease has been assigned the value of 
					'yearOfReleaseF' then 
*                   true is returned
************************************************************************/
bool Movie::addYearReleased( int   yearOfReleaseF)
{
	if(yearOfReleaseF < 1900 || yearOfReleaseF > 2012 )
	{
		return false;
	}
	else
	{			
		*yearOfRelease= yearOfReleaseF;

		return true;	
	}
	
}

/************************************************************************
*                       addCriticRating
*
* Purpose: This function accepts a float as an argument and assign it 
		    to the *ratingOfCritics attribute.
*
* Precondition: An instance of the class has been declared.
*
* Postcondition: If ratingOfCriticsF is less than 1.0 or 
				    ratingOfCriticsF is more than 4.0 
*                   false is returned
*                Else
					*ratingOfCritics has been assigned the value of 
					"ratingOfCriticsF" then 
*                   true is returned
************************************************************************/
bool Movie::addCriticRating( float  ratingOfCriticsF )
{
   if( ratingOfCriticsF < 1.0 ||  ratingOfCriticsF > 4.0)
   {
		return false;
   }
   else
   {
		* ratingOfCritics = ratingOfCriticsF;
		
		return true;
   }
}
/************************************************************************
*                       addRunTime
*
* Purpose: This function accepts a integer as an argument and assign it 
		   to the *runningTime attribute.
*
* Precondition: An instance of the class has been declared.
*
* Postcondition: If runningTimeF is less than 10 or 
				 runningTimeF is more than 300 
*                   false is returned
*                Else
					"*runningTime has been assigned the value of 
					"runningTimeF" then 
*                   true is returned
************************************************************************/ 
 bool Movie::addRunTime(int  runningTimeF )
{
   if(  runningTimeF < 10 ||   runningTimeF > 300)
   {
		return false;
   }
   else
   {
		*runningTime = runningTimeF;
		
		return true;
   }
}

/************************************************************************
*                       retrieveMovieName
*
* Purpose: This function provides  the driver program  with the 
		   current string of movieName
*
* Precondition: An instance of the class has been declared.
*
* Postcondition: The variable movieName has been returned.
************************************************************************/
string Movie::retrieveMovieName()
{
   return movieName;
}

/************************************************************************
*                       retrieveDirectorsLastName
*
* Purpose: This function provides  the driver program  with the 
		   current string of lastNameOfDirector
*
* Precondition: An instance of the class has been declared.
*
* Postcondition: The variable lastNameOfDirector has been returned.
************************************************************************/
string Movie::retrieveDirectorsLastName()
{
   return lastNameOfDirector;
}

/************************************************************************
*                       retrieveDirectorsFirstName
*
* Purpose: This function provides  the driver program  with the 
		   current string of firstNameOfDirector
*
* Precondition: An instance of the class has been declared.
*
* Postcondition: The variable firstNameOfDirector has been returned.
************************************************************************/
string Movie::retrieveDirectorsFirstName()
{
   return firstNameOfDirector;
}


/************************************************************************
*                       retrieveDirectorsFullName
*
* Purpose: This function provides  the driver program  with the 
		   current string of fullNameOfDirector
*
* Precondition: An instance of the class has been declared.
*
* Postcondition: The variable fullNameOfDirector has been returned.
************************************************************************/
string Movie::retrieveDirectorsFullName()
{
   makeDirectorsFullName();
   
   return fullNameOfDirector;
   
}


/************************************************************************
*                       retrieveReleaseYear
*
* Purpose: This function provides  the driver program  with the 
		   current value of *yearOfRelease 
*
* Precondition: An instance of the class has been declared.
*
* Postcondition: The variable *yearOfRelease has been returned.
************************************************************************/
int Movie::retrieveReleaseYear()
{
	return *yearOfRelease;
}

/************************************************************************
*                       retrieveRating
*
* Purpose: This function provides  the driver program  with the 
		   current value of *ratingOfCritics 
*
* Precondition: An instance of the class has been declared.
*
* Postcondition: The variable *ratingOfCritics has been returned.
************************************************************************/
float  Movie::retrieveRating()
{

	return *ratingOfCritics;

}


/************************************************************************
*                       retrieveRunTime
*
* Purpose: This function provides  the driver program  with the 
		   current value of *runningTime
*
* Precondition: An instance of the class has been declared.
*
* Postcondition: The variable *runningTime has been returned.
************************************************************************/
 int Movie::retrieveRunTime()
{

	return  *runningTime;

}


/************************************************************************
*                       makeDirectorsFullName
*
* Purpose:      This function concatenates lastNameOfDirector and 
			    firstNameOfDirector string variables then assigns them 
				into string fullNameOfDirector variable
*
* Precondition: An instance of the class has been declared. 
				LastNameOfDirector and firstNameOfDirector string 
				variables initialized by driver program.
*
* Postcondition: LastNameOfDirector and firstNameOfDirector string 
				 variables have been concatenated then assigned into
				 fullNameOfDirector. fullNameOfDirector variable 
				 resized 25 characters space and padded at the end 
				 of the field with spaces.

************************************************************************/
 void Movie::makeDirectorsFullName()
{
	int i=12;
	string tempLastNameOfDirector;

	// Copy Last Name into tempLastNameOfDirector variable
	tempLastNameOfDirector = lastNameOfDirector;


	// Find index of last letter in the  tempLastNameOfDirector
	while(tempLastNameOfDirector[i] == ' ')
	{
		i--;
	}
		
	// Resize tempLastNameOfDirector with respect to index i 
	//(pad with spaces)	
	tempLastNameOfDirector.resize(i+3,' ');
	
	// Put comma after the last letter of  tempLastNameOfDirector
	tempLastNameOfDirector[i+1] = ',';

	// Concatenate two strings 
	fullNameOfDirector= tempLastNameOfDirector+firstNameOfDirector;

	// Resize fullNameOfDirector 25 and pad with spaces
	fullNameOfDirector.resize(25,' ');


}






