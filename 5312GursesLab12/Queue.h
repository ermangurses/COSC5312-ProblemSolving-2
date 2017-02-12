/***********************************************************************
* Author: Gurses, Erman
* Date:   April 21, 2012                                                 
*
* Purpose: Specification file for Queue.h to demonstrate the use of        
*          templates with a LinkedList abstract data type using 
           pointers.
************************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <cstdlib>
using namespace std;

template <class Type>
class Queue
{

   public:

      Queue();       // Default constructor
      ~Queue();      // Destructor
      Queue(const Queue & otherQueue); // Copy constructor

      // Overloaded operator "="
      const Queue <Type> & operator=(const Queue & otherQueue);

      int  sizeOf();
      bool isEmpty();
      void enqueue(Type dataIn);
      bool dequeue(Type & front);
      bool queueFront (Type & copyData);

   private:

      struct QNode
      {
         
          Type nodeData;
          QNode *next;
      };

      QNode *head,
            *tail;

      int size;
      void copyQueue(const Queue & otherQueue);
};
#endif



