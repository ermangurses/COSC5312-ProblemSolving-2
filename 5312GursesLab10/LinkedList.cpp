/***********************************************************************
* Author: Gurses, Erman
* Date:   April 16, 2012                                                          
*                                                                            
* Purpose:  This file implements the LinkedList class using templates in 
            a LinkedList abstract data type using pointers.                          
***********************************************************************/

#include "LinkedList.h"


/***********************************************************************
* Constructor                                                                
*                                                                            
* Purpose: This function creates an empty LinkedList.                       
*                                                                            
* Pre-condition:  The calling function has declared a LinkedList object.           
*                                                                            
* Post-condition: An empty LinkedList object has been created.                     
***********************************************************************/
template <class Key, class Type>
LinkedList<Key, Type>::LinkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;

}

/***********************************************************************
* Destructor                                                                 
*                                                                            
* Purpose: This function destroys a LinkedList object.                            
*                                                                            
* Pre-condition:  The previously-declared LinkedList object is no longer           
*                 needed.                                                    
*                                                                            
* Post-condition: The LinkedList object has been destroyed.                        
***********************************************************************/

template <class Key, class Type>
LinkedList<Key, Type>::~LinkedList()
{
    Key tempKey;
    Type tempType;

    while(removeFront(tempKey, tempType));
}

/***********************************************************************
* isEmpty                                                                    
*                                                                            
* Pre-condition:  Class property “size” contains a known value.              
*                                                                            
* Post-condition: If the LinkedList is empty                                       
*            a boolean value of true is returned                      
*              Else                                           
*            a boolean value of false is returned.                    
***********************************************************************/
template <class Key, class Type>
bool LinkedList<Key, Type>::isEmpty()
{
    return (size==0);
}


/***********************************************************************
* sizeOf                                                                     
*                                                                            
* Pre-condition:  Class property “size” contains a known value.              
*                                                                            
* Post-condition: The length of the LinkedList has been returned to the 
                  calling function.                                                  
***********************************************************************/
template <class Key, class Type>
int  LinkedList<Key, Type>::sizeOf()
{

    return size;
}

/***********************************************************************
* insertFront 
*                                                                            
* Purpose: This function inserts a new set of data at the front of 
           the LinkedList. 
*                                                                            
* Pre-condition:  The calling function has requested a new set of data 
                  be placed at the beginning of the LinkedList.                       
*                                                                            
* Post-condition:  The new data have been place at the beginning of the 
                   LinkedList 
***********************************************************************/

template <class Key, class Type>
void LinkedList <Key, Type>::insertFront(Key keyIn, Type dataIn)

{
    LNode * newPtr = new LNode;
    newPtr->nodeKey = keyIn;
    newPtr->nodeData = dataIn;
    newPtr->next = head;
    head = newPtr;

    if(newPtr->next==NULL)
    {    
        tail=newPtr;
    }

    size++;
}

/***********************************************************************
* insertRear                                                                 
*                                                                            
* Purpose: This function inserts a new set of data at the rear of the 
           LinkedList.  
*                                                                            
* Pre-condition:  The calling function has requested a new set of data 
                  be placed at the end of the LinkedList.                             
*                                                                            
* Post-condition:  The new data have been place at the end of the 
                   LinkedList       
***********************************************************************/

template<class Key, class Type>
void LinkedList<Key, Type>::insertRear(Key keyIn, Type dataIn)
{
    LNode *newPtr = new LNode;
    newPtr->nodeKey = keyIn;
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
* insertInOrder                                                              
*                                                                            
* Purpose: This function adds a new set of data to the LinkedList 
           in ascending order.                                                            
*                                                                            
* Pre-condition:  The calling function has requested a set of data be 
                  placed in the LinkedList in ascending order.                            
*                                                                            
* Post-condition: The new data have been added to the LinkedList in 
                  ascending order
***********************************************************************/
template<class Key, class Type>
void LinkedList<Key, Type>::insertInOrder(Key keyIn, Type dataIn)
{
    /* When we insert in Order, there are 4 cases
     * 1. LinkedList is empty
     * 2. goes at front
     * 3. goes at end
     * 4. goes in the middle */

    if(isEmpty()) 
    {
        insertFront(keyIn, dataIn);
        return;
    }

    LNode *currPtr= head,
          *prevPtr= head;

    /* must check if !NULL FIRST to avoid seg faults */
    while( currPtr!= NULL && currPtr->nodeKey < keyIn)
    {
        prevPtr = currPtr;
        currPtr = currPtr->next;
    }

    /* see if LEADER didn't move */
    if(currPtr == head)
    {
        insertFront(keyIn, dataIn);
        return;
    }

    /* leader isn't at the end of LinkedList, so we insert in middle */
    if(currPtr != NULL)
    {
        LNode *newPtr = new LNode;
        newPtr -> nodeKey = keyIn;
        newPtr -> nodeData = dataIn;
        newPtr -> next = currPtr;
        prevPtr -> next = newPtr;
        size++;

        return;
    }

    /* all options covered, only thing left is... */
    insertRear(keyIn, dataIn);
}

/***********************************************************************
* removeFront                                                                
*                                                                            
* Purpose: This function removes the first set of data from the 
           LinkedList.        
*                                                                            
* Pre-condition:  The calling function has requested the data at the         
*                 beginning of the LinkedList be removed.                          
*                                                                            
* Post-condition: If the LinkedList is empty                                       
*                   false is returned                                        
*                 Else                                                      
*                   the data at the front of the LinkedList has been 
                    removed 
                    and is available for use by the calling function &&      
*                   true is returned.                                       
***********************************************************************/

template <class Key, class Type>
bool LinkedList<Key, Type>::removeFront(Key &keyOut, Type & dataOut)
{
    if(isEmpty())
    {
        return false;
    }

    LNode *temp = head;
    keyOut = temp -> nodeKey;
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
* removeRear                                                                 
*                                                                            
* Purpose: This function removes the last set of data from the 
           LinkedList.         
*                                                                            
* Pre-condition:  The calling function has requested the data at the 
                  end of the LinkedList be removed.                                       
*                                                                            
* Post-condition: If the LinkedList is empty                                       
*                   false is returned                                        
*                 Else                                                       
*                   the data at the rear of the LinkedList has been 
                    removed and is available for use by the calling 
                    function && true is returned.                                          
***********************************************************************/

template <class Key, class Type>
bool LinkedList<Key, Type>::removeRear(Key & keyOut, Type & dataOut)
{
    if(isEmpty())
    {
        return false;
    }

    LNode *temp = head;
    keyOut = tail -> nodeKey;
    dataOut = tail -> nodeData;

    for(int i=1; i < size-1; i++)
    {
        temp=temp->next;
    }

    delete tail;
    
    if(size==1) 
    {
        tail = NULL;
        head = NULL;
    }
    else
    {
        tail = temp;
        tail->next = NULL;
    }

    size--;
    return true;
   
}
/***********************************************************************
* remove                                                                     
*                                                                            
* Purpose: This function removes a specified set of data from the 
           LinkedList.      
*                                                                            
* Pre-condition:  The calling function has requested a specified set of 
                  data be removed from the LinkedList.                                  
*                                                                            
* Post-condition: If the specified data are found in the LinkedList                
*                    that data are removed and is available to the 
                     calling function &&        
*                    true is returned                                        
*                 Else                                                       
*                    false is returned.                                      
***********************************************************************/

template <class Key, class Type>
bool LinkedList<Key, Type>::remove(Key & keyOut, Type & dataOut)
{
    if(isEmpty())
    {
        return false;
    }

    int location;

    if(search(keyOut, location))
    {
        if(location == 1)
        {
            return removeFront(keyOut, dataOut);
        }

        if(location == size)
        {
            return removeRear(keyOut, dataOut);
        }

        LNode *curr = head,
              *prev = head;

        for(int i=1; i<location; i++)
        {
            prev = curr;
            curr = curr->next;
        
        }

        keyOut = curr->nodeKey;
        dataOut = curr->nodeData;
        prev->next = curr->next;
        delete curr;
        size--;
        return true;
    }

    return false;
}

/***********************************************************************
* search                                                                
*                                                                            
* Purpose: This function searches the LinkedList for specific data .               
*                                                                            
* Pre-condition:  The calling function has requested a specific key be       
*          found and, if present, its location be noted.      
*                                                                            
* Post-condition: If the specified key is in the LinkedList                
*                    True is returned  &&              
*                    The key's location is available to the 
                    calling function. 
*                    Else                                                  
*                    False is returned.                                      
***********************************************************************/

template <class Key, class Type>
bool LinkedList<Key, Type>::search(Key findThis, int & location)
     
{

    if(isEmpty())
    {
        return false;
    }

     LNode * temp = head;

     location = 1;
     
     while(location <= size) 
     {
         if(findThis == temp->nodeKey)  
         {
            return true;
         
         }

         location++;

         temp=temp->next;
     }

     return false;
    
}

/***********************************************************************
* retrieve                                                 
*                                                                            
* Purpose: This function returns the data found at the requested 
           location.   
*                                                                            
* Pre-condition: The location of the desired data has been determined &&    
*                the calling function has requested a copy of the data 
                 at that location be retrieved.                                 
*                                                                            
* Post-condition: A copy of the data at the specified location has been      
*                 returned to the calling function.                          
***********************************************************************/

template <class Key, class Type>
Type LinkedList<Key, Type>::retrieve(int location)
{
    LNode * temp = head;

    for(int i=1; i<location; i++)
    {
        temp = temp->next;        
    }

    return temp->nodeData;

}

/***********************************************************************
* copyLinkedList                                                                   
*                                                                            
* Purpose: This function makes a "deep" copy of an existing LinkedList.            
*                                                                            
* Pre-condition:  A copy of an existing LinkedList is needed.                      
*                                                                            
* Post-condition: A copy of an existing LinkedList has been made.                  
***********************************************************************/

template<class Key, class Type>
void LinkedList<Key, Type>::copyLinkedList
                                    (const LinkedList & otherLinkedList)
{
    LNode *toPtr;
    LNode *fromPtr;

    size = otherLinkedList.size;
    if(otherLinkedList.head==NULL)
    {
        head = NULL;
        tail = NULL;
        return;
    }

    fromPtr = otherLinkedList.head;
    head = new LNode;
    toPtr = head;

    head -> nodeKey = fromPtr -> nodeKey;
    head -> nodeData = fromPtr -> nodeData;
    fromPtr = fromPtr -> next;
    
    while(fromPtr != NULL)
    {
        toPtr -> next = new LNode;
        toPtr = toPtr -> next;
        toPtr -> nodeKey = fromPtr -> nodeKey;
        toPtr -> nodeData = fromPtr -> nodeData;
        fromPtr = fromPtr -> next;
    }
    tail = toPtr;
    tail->next = NULL;
}


/***********************************************************************
* Copy Constructor                                                           
*                                                                            
* Purpose: This function makes a "deep" copy of an existing LinkedList.            
*                                                                            
* Pre-condition:  A copy of an existing LinkedList is needed.                      
*                                                                            
* Post-condition: A copy of an existing LinkedList has been made.                  
***********************************************************************/

template <class Key, class Type>
LinkedList<Key,Type>::LinkedList(const LinkedList & otherLinkedList )
{

    copyLinkedList(otherLinkedList);

}

/***********************************************************************
* overloaded assignment operator (=)
*
* Purpose: This function allows the driver file to assign the contents of
*          one LinkedList object to a second, different LinkedList 
          object.
*
* Pre-condition: "otherLinkedList" exists.
*
* Post-condition: The contents of "otherList" have been copied into the
*                 LinkedList beginning at 'this' address.
***********************************************************************/

template <class Key, class Type>
const LinkedList<Key,Type>& LinkedList<Key,Type>::operator=
                                    (const LinkedList& otherLinkedList)
{
    if(this != &otherLinkedList)// checking for self-aasignment
    {
        Key tempK;
        Type tempT;

        while(removeFront(tempK, tempT));

        copyLinkedList(otherLinkedList);      
    }

    return *this;
}

