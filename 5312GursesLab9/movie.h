/************************************************************************
* Author: Gurses, Erman
* Date:   March 26, 2012

*
* Purpose: This file is the header file for the "Movie" class.It contains
*          all the function prototypes for the class and defines the
*          private attributes of the class. All the attributes are
*          dynamically allocated.
************************************************************************/




#ifndef MOVIE_H
#define MOVIE_H

#include <string>

using namespace std;

class Movie
{

   public:

      Movie();       // Default constructor
      ~Movie();      // Destructor

      void addMovieName( string movieNameF );
	  void addLastName(string lastNameOfDirectorF );
	  void addFirstName( string firstNameOfDirectorF );
	  bool addYearReleased( int yearOfReleaseF);
	  bool addCriticRating( float ratingOfCriticsF );
	  bool addRunTime(int runningTimeF );

	  string retrieveMovieName();
	  string retrieveDirectorsLastName();
	  string retrieveDirectorsFirstName();
	  string retrieveDirectorsFullName();

	  int    retrieveReleaseYear();
	  float  retrieveRating();
	  int    retrieveRunTime();


   private:
      string movieName;
	  string lastNameOfDirector;
	  string firstNameOfDirector;
	  string fullNameOfDirector;
	  int   * yearOfRelease;
	  float * ratingOfCritics;
	  int   * runningTime;
	  void makeDirectorsFullName();

};
#endif


