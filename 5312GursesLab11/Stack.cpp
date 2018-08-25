/***********************************************************************
* Author: Gurses, Erman
* Date:   April 21, 2012                                                          
*                                                                            
* Purpose:  This file implements the Stack class using templates in 
			a Stack abstract data type using pointers.                          
***********************************************************************/
#include "Stack.h"


/***********************************************************************
* Constructor                                                                
*                                                                            
* Purpose: This function creates an empty Stack.                       
*                                                                            
* Pre-condition:  The calling function has declared a Stack object.           
*                                                                            
* Post-condition: An empty Stack object has been created.                     
***********************************************************************/
template <class Type>
Stack<Type>::Stack()
{
    top = NULL;
    size = 0;

}


/***********************************************************************
* Destructor                                                                 
*                                                                            
* Purpose: This function destroys a Stack object.                            
*                                                                            
* Pre-condition:  The previously-declared Stack object is no longer           
*                 needed.                                                    
*                                                                            
* Post-condition: The Stack object has been destroyed.                        
***********************************************************************/
template <class Type>
Stack<Type>::~Stack()
{
  
    Type tempType;

    while(pop(tempType));
}

/***********************************************************************
* isEmpty                                                                    
*                                                                            
* Pre-condition:  Class property “size” contains a known value.              
*                                                                            
* Post-condition: If the Stack is empty                                       
*		    a boolean value of true is returned	                  
*	          Else	                                       
*		    a boolean value of false is returned.                    
***********************************************************************/
template <class Type>
bool Stack<Type>::isEmpty()
{
    return (size==0);
}


/***********************************************************************
* sizeOf                                                                     
*                                                                            
* Pre-condition:  Class property “size” contains a known value.              
*                                                                            
* Post-condition: The length of the Stack has been returned to the 
				  calling function.                                                  
***********************************************************************/
template <class Type>
int  Stack<Type>::sizeOf()
{
	return size;
}

/***********************************************************************
* push 
*                                                                            
* Purpose: This function inserts a new set of data at the top of 
		   the Stack. 
*                                                                            
* Pre-condition:  The calling function has requested a new set of data 
				  be placed at the top of the Stack.                       
*                                                                            
* Post-condition:  The new data have been place at the top of the 
				   Stack 
***********************************************************************/
template <class Type>
void Stack<Type>::push(Type dataIn)

{
	SNode * newPtr = new SNode;
	newPtr->nodeData = dataIn;
	newPtr->next = top;
	top = newPtr;

	size++;
}


/***********************************************************************
* pop                                                                
*                                                                            
* Purpose: This function removes the first set of data from the 
		   Stack.        
*                                                                            
* Pre-condition:  The calling function has requested the data at the         
*                 top of the Stack be removed.                          
*                                                                            
* Post-condition: If the Stack is empty                                       
*                   false is returned                                        
*                 Else                                                      
*                   the data at the top of the Stack has been removed 
					and is available for use by the calling function &&      
*                   true is returned.                                       
***********************************************************************/

template < class Type>
bool Stack<Type>::pop(Type & dataOut)
{
    if(isEmpty())
    {
        return false;
    }

    SNode *temp = top;
    dataOut = temp -> nodeData;
    top = top -> next;
   
	delete temp;
    
	size--;

    return true;
}

/***********************************************************************
* stackTop                                                 
*                                                                            
* Purpose: This function returns the data top of the Stack without 
		    deleting tha data.
*                                                                            
* Pre-condition: The calling function has requested a copy of the data 
				 at top of the Stack                                
*                                                                            
* Post-condition: If isEmpty is true
					  return true
				  else
					 copy data from top of the stack to dataOut variable
					 && return true
***********************************************************************/
template <class Type>
bool Stack<Type>::stackTop(Type &dataOut)
{

	if(isEmpty())
    {
        return false;
    }

	dataOut = *top;

	return true;

}

/***********************************************************************
* copyStack                                                                   
*                                                                            
* Purpose: This function makes a "deep" copy of an existing Stack.            
*                                                                            
* Pre-condition:  A copy of an existing Stack is needed.                      
*                                                                            
* Post-condition: A copy of an existing Stack has been made.                  
***********************************************************************/
template< class Type>
void Stack<Type>::copyStack(const Stack & otherStack)
{
    SNode *toPtr;
    SNode *fromPtr;

    size = otherStack.size;
	if(otherStack.top==NULL)
    {
        top = NULL;
        return;
    }

    fromPtr = otherStack.top;
    top = new SNode;
    toPtr = top;

    top -> nodeData = fromPtr -> nodeData;
    fromPtr = fromPtr -> next;

    while(fromPtr != NULL)
    {
        toPtr -> next = new SNode;
        toPtr = toPtr -> next;
		toPtr -> nodeData = fromPtr -> nodeData;
        fromPtr = fromPtr -> next;
    }
    
}

/***********************************************************************
* Copy Constructor                                                           
*                                                                            
* Purpose: This function makes a "deep" copy of an existing Stack.            
*                                                                            
* Pre-condition:  A copy of an existing Stack is needed.                      
*                                                                            
* Post-condition: A copy of an existing Stack has been made.                  
***********************************************************************/

template <class Type>
Stack<Type>::Stack(const Stack & otherStack )
{

	copyStack(otherStack);

}

/***********************************************************************
* overloaded assignment operator (=)
*
* Purpose: This function allows the driver file to assign the contents of
*          one Stack object to a second, different Stack object.
*
* Pre-condition: "otherStack" exists.
*
* Post-condition: The contents of "otherStack" have been copied into the
*                 Stack beginning at 'this' address.
***********************************************************************/
template <class Type>
const Stack<Type>& Stack<Type>::operator=(const Stack& otherStack)
{
    if(this != &otherStack)// checking for self-aasignment
    {
      
        Type tempT;

        while(pop(tempT));
        
        copyStack(otherStack);
        
    }

    return *this;
}

