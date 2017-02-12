/***********************************************************************
* Author: Gurses, Erman
* Date:   April 16, 2012                                                          
*                                                                            
* Purpose:  This file implements the Queue class using templates in 
            a Queue abstract data type using pointers.                          
***********************************************************************/
#include "Queue.h"


/***********************************************************************
* Constructor                                                                
*                                                                            
* Purpose: This function creates an empty Queue.                       
*                                                                            
* Pre-condition:  The calling function has declared a Queue object.           
*                                                                            
* Post-condition: An empty Queue object has been created.                     
***********************************************************************/
template <class Type>
Queue<Type>::Queue()
{
    head = NULL;
    tail = NULL;
    size = 0;

}

/***********************************************************************
* Destructor                                                                 
*                                                                            
* Purpose: This function destroys a Queue object.                            
*                                                                            
* Pre-condition:  The previously-declared Queue object is no longer           
*                 needed.                                                    
*                                                                            
* Post-condition: The Queue object has been destroyed.                        
***********************************************************************/
template <class Type>
Queue<Type>::~Queue()
{
    
    Type tempType;

    while(dequeue(tempType));
}


/***********************************************************************
* isEmpty                                                                    
*                                                                            
* Pre-condition:  Class property “size” contains a known value.              
*                                                                            
* Post-condition: If the Queue is empty                                       
*            a boolean value of true is returned                      
*              Else                                           
*            a boolean value of false is returned.                    
***********************************************************************/
template <class Type>
bool Queue<Type>::isEmpty()
{
    return (size==0);
}

/***********************************************************************
* sizeOf                                                                     
*                                                                            
* Pre-condition:  Class property “size” contains a known value.              
*                                                                            
* Post-condition: The length of the Queue has been returned to the 
                  calling function.                                                  
***********************************************************************/
template <class Type>
int  Queue<Type>::sizeOf()
{
    return size;
}


/***********************************************************************
* enqueue                                                                 
*                                                                            
* Purpose: This function inserts a new set of data at the rear of the 
           Queue.  
*                                                                            
* Pre-condition:  The calling function has requested a new set of data 
                  be placed at the end of the Queue.                             
*                                                                            
* Post-condition:  The new data have been place at the end of the 
                   Queue       
***********************************************************************/
template <class Type>
void Queue<Type>::enqueue(Type dataIn)
{
    QNode *newPtr = new QNode;
    newPtr->nodeData = dataIn;
    newPtr->next = NULL;

    if(isEmpty())
    {
        head = newPtr;
    
    }
    else
    {
        tail->next=newPtr;
    
    }

    tail = newPtr;
    size++;

}


/***********************************************************************
* dequeue                                                                
*                                                                            
* Purpose: This function removes the first set of data at the 
           beginning of the Queue.        
*                                                                            
* Pre-condition:  The calling function has requested the data at the         
*                 beginning of the Queue be removed.                          
*                                                                            
* Post-condition: If the Queue is empty                                       
*                   false is returned                                        
*                 Else                                                      
*                   the data at the front of the Queue has been 
                    removed 
                    and is available for use by the calling function &&      
*                   true is returned.                                       
***********************************************************************/
template <class Type>
bool Queue<Type>::dequeue(Type & dataOut)
{
    if(isEmpty())
    {
        return false;
    }

    QNode *temp = head;
    dataOut = temp -> nodeData;
    head = head -> next;
    
    if(tail == temp)
    {
        tail = NULL;
    }
    
    delete temp;
    
    size--;

    return true;
}


/***********************************************************************
* queueFront                                                 
*                                                                            
* Purpose: This function returns the data at the beginning of the Queue
*                                                                            
* Pre-condition: The calling function has requested a copy of the data 
                 at the beginning of the Queue be retrieved.                                 
*                                                                            
* Post-condition: A copy of at the beginning of the Queue has been      
*                 returned to the calling function.                          
***********************************************************************/
template <class Type>
bool Queue<Type>::queueFront(Type & copyData)
{
    if(isEmpty())
    {
        return false;
    }
    
    copyData = head->nodeData;

}


/***********************************************************************
* copyQueue                                                                   
*                                                                            
* Purpose: This function makes a "deep" copy of an existing Queue.            
*                                                                            
* Pre-condition:  A copy of an existing Queue is needed.                      
*                                                                            
* Post-condition: A copy of an existing Queue has been made.                  
***********************************************************************/
template <class Type>
void Queue<Type>::copyQueue(const Queue & otherQueue)
{
    QNode *toPtr;
    QNode *fromPtr;

    size = otherQueue.size;
    if(otherQueue.head==NULL)
    {
        head = NULL;
        tail = NULL;
        return;
    }

    fromPtr = otherQueue.head;
    head = new QNode;
    toPtr = head;

    head -> nodeData = fromPtr -> nodeData;
    fromPtr = fromPtr -> next;
    while(fromPtr != NULL)
    {
        toPtr -> next = new QNode;
        toPtr = toPtr -> next;
        toPtr -> nodeData = fromPtr -> nodeData;
        fromPtr = fromPtr -> next;
    }
    tail = toPtr;
    tail->next = NULL;
}


/***********************************************************************
* Queue                                                          
*                                                                            
* Purpose: This function makes a "deep" copy of an existing Queue.            
*                                                                            
* Pre-condition:  A copy of an existing Queue is needed.                      
*                                                                            
* Post-condition: A copy of an existing Queue has been made.                  
***********************************************************************/
template <class Type>
Queue<Type>::Queue(const Queue & otherQueue )
{

    copyQueue(otherQueue);

}

/***********************************************************************
* overloaded assignment operator (=)
*
* Purpose: This function allows the driver file to assign the contents of
*          one Queue object to a second, different Queue object.
*
* Pre-condition: "otherQueue" exists.
*
* Post-condition: The contents of "otherQueue" have been copied into the
*                 Queue beginning at 'this' address.
***********************************************************************/
template <class Type>
const Queue<Type>& Queue<Type>::operator=(const Queue & otherQueue)
{
    if(this != &otherQueue)// checking for self-aasignment
    {
        Type tempT;

        while(dequeue( tempT));
        
        copyQueue(otherQueue);
        
    }

    return *this;
}

