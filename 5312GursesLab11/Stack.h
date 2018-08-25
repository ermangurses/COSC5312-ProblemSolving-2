/***********************************************************************
* Author: Gurses, Erman
* Date:   April 21, 2012                                                 
*
* Purpose: Specification file for Stack.h to demonstrate the use of        
*          templates with a Stack abstract data type using 
		   pointers.
************************************************************************/
#include <string>
#include <cstdlib>

#ifndef STACK_H
#define STACK_H


using namespace std;

template <class Type>
class Stack
{

   public:

      Stack();       // Default constructor
      ~Stack();      // Destructor
	  Stack(const Stack & otherStack); // Copy constructor
	  // Overloaded operator "="
      const Stack<Type>& operator=(const Stack& otherStack);
	  int  sizeOf();
	  bool isEmpty();
	  void push(Type dataIn);
	  bool pop(Type & dataOut);
	  bool stackTop(Type & dataOut);

   private:
      struct SNode
	  {
		  Type nodeData;
		  SNode *next;
	  };

	  SNode *top;

	  int size;

	  void copyStack(const Stack & otherStack);
};
#endif



