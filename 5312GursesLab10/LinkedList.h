/***********************************************************************
* Author: Gurses, Erman
* Date:   April 16, 2012                                                 
*
* Purpose: Specification file for LinkedList.h to demonstrate the use of        
*          templates with a LinkedList abstract data type using 
		   pointers.
************************************************************************/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <cstdlib>
using namespace std;

template <class Key, class Type>

class LinkedList
{

   public:

      LinkedList();       // Default constructor
      ~LinkedList();      // Destructor
	  LinkedList(const LinkedList & otherList); // Copy constructor

	  // Overloaded operator "=" 
      const LinkedList <Key,Type> & operator=
										(const LinkedList & otherList);

	  int  sizeOf();
	  bool isEmpty();
	  void insertFront(Key keyIn, Type dataIn); // Insert data at front
	  void insertRear(Key keyIn, Type dataIn);// Insert data at end
	  void insertInOrder(Key keyIn, Type dataIn);// Insert data in order
	  bool removeFront(Key & frontKey, Type & front);//Remove front data
	  bool removeRear(Key & rearKey, Type & rear);// Remove rear data
	  bool remove(Key & keyOut, Type & dataOut);//Remove specific data
	  Type retrieve (int location);// Retrieve copy of data
	  bool search(Key findThis, int & location);// Search LinkedList


   private:

      struct LNode
	  {
		  Key nodeKey;
		  Type nodeData;
		  LNode *next;
	  };

	  LNode *head,
			*tail;

	  int size;

	  void copyLinkedList(const LinkedList & otherList);
};
#endif



