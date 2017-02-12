/******************************************************************************
* File Name:  Lab6.cpp
*
* Author:     Erman Gurses
*
* Course:     COSC 5312 - Foundations in Programming and Problem 
*             Solving II,  A03539870
* 
* Date:       February 22, 2012
*
* Purpose:    The purpose is that implementation of three different sort 
              algorithm which are bubble sort, insertion sort, and seletion
              sort. Program reads descending order numbers from file and 
              puts them into 3 differen arrays then send one array to one
              sorting function. In sorting functions there are 2 counters
              one is counting comparison operation the other one is counting 
              move operations. After that, It prompts user how many 
              comparisons and how many move operations occured in functions.
*          
*
* Input:      The Inputs descending order 700 numbers 
*              
*
* Output:     It prompts user how many comparisons
              and how many move operations occured in functions.

******************************************************************************/

#include <fstream>
#include <iostream>


using namespace std; 

bool openInputFile(ifstream & inFile); 
void readInputFile( ifstream & inFile, int bubbleSortArray[], int SIZE);
void distribute(int bubbleSortArray[], int insertionSortArray[], 
                int selectionSortArray[], int SIZE);
void bubbleSort(int bubbleArray[], int SIZE);
void selectionSort(int selectionArray[], int SIZE);
void insertionSort(int insertionArray[], int SIZE);

int main()
{

    const int SIZE = 700;
    ifstream inFile;

    int bubbleSortArray[SIZE]={0},
        insertionSortArray[SIZE]={0},
        selectionSortArray[SIZE]={0};

    if(!openInputFile(inFile))
    {
        return 0;
    }
    readInputFile(inFile,bubbleSortArray,SIZE);
    inFile.close();
    distribute( bubbleSortArray,insertionSortArray,selectionSortArray,SIZE);
    selectionSort(selectionSortArray,SIZE);
    bubbleSort(bubbleSortArray,SIZE);
    insertionSort(insertionSortArray,SIZE);

  return 0;
}

/***************************************************************************
*            openInputFile
*                 
* Purpose       : Try to open an input file for use by the program.
*                    
* Pre-condition : None.
*
* Post-condition: If input file has not been opened print error message and 
*                      return false
*                  If input file has been opened  
*                    return true.
*
***************************************************************************/
bool openInputFile(ifstream & inFile) 
{
   inFile.open("lab6input.txt");
   
   if (!inFile)
   {
      cout << "The input File cannot been opened!!!\n";

      return false;
   }
   return true;
}

/***************************************************************************
*            readInputFile
*                 
* Purpose       : Try to assign data from inFile to bubbleSortArray
*                    
* Pre-condition : InputFile had to been opened.
*
* Post-condition: All 700 data in inputArray.
*
***************************************************************************/
void readInputFile( ifstream & inFile, int bubbleSortArray[], int SIZE)
{
    
    for(int i=0; i<SIZE; i++)
    {
        inFile>>bubbleSortArray[i];
    }

}

/***************************************************************************
*            distribute
*                 
* Purpose       : The purpose is that assign raw data from bubbleSortArray
                  to insertionSortArray and selectionSortArray,
*                    
* Pre-condition : All 700  data is assigned to bubbleSortArray.
*
* Post-condition: All 700  data is assigned to insertionSortArray and
                  selectionSortArray.
*
***************************************************************************/
void distribute( int bubbleSortArray[], int insertionSortArray[], 
                 int selectionSortArray[], int SIZE)
{
    for(int i=0; i<SIZE; i++)
    {
        insertionSortArray[i]=bubbleSortArray[i];
        selectionSortArray[i]=bubbleSortArray[i];

    }
}
/***************************************************************************
*            bubbleSort
*                 
* Purpose       : The purpose is that implement bubble sort and count 
                  comparison operation and move operations.                
*                    
* Pre-condition : All 700  data is assigned to bubbleSortArray.
*
* Post-condition: bubbleSortArray is sorted. comparisonCounter and 
                  moveCounter counter have number of comparisons and move 
                  operations. Then prompt user these counters.
*
***************************************************************************/
void bubbleSort(int bubbleArray[], int SIZE)
{
    int temp,
        wall=0,
        unsorted,
        comparisonCounter=0,
        moveCounter=0;
    bool notDone=true;

    while(notDone && wall<SIZE)
    {
        unsorted = SIZE-1;
        notDone = false;
        while(unsorted >  wall)
        {
            comparisonCounter++;
            if( bubbleArray[unsorted]<bubbleArray[unsorted-1] )
            {
                moveCounter+=3;

                temp=bubbleArray[unsorted];
                bubbleArray[unsorted]=bubbleArray[unsorted-1];
                bubbleArray[unsorted-1]=temp;
                notDone=true;
            }

            unsorted--;
        }
        wall++;
    }
    cout<<"For Bubble Sort, Number of Comparison is "
    <<comparisonCounter<<endl;
    cout<<"For Bubble Sort, Number of Move operation is "
    <<moveCounter<<endl<<endl;
}

/***************************************************************************
*            selectionSort
*                 
* Purpose       : The purpose is that implement selection sort and count 
                  comparison operation and move operations.                
*                    
* Pre-condition : All 700  data is assigned to selectionArray.
*
* Post-condition: selectionArray is sorted. comparisonCounter and moveCounter
                  counter have number of comparisons and move operations.Then
                  prompt user these counters.
*
***************************************************************************/
void selectionSort(int selectionArray[], int SIZE)
{
    int wall,
        smallestIndex,
        smallestValue,
        unsorted,
        comparisonCounter=0,
        moveCounter=0;

    
    for(wall=0; wall<SIZE-1; wall++)
    {
        moveCounter++;
        smallestValue = selectionArray[wall];
        smallestIndex = wall;
        for(unsorted = wall+1; unsorted < SIZE; unsorted++)
        {
            comparisonCounter++;

            if(selectionArray[unsorted] < smallestValue)
            {
                moveCounter++;
                smallestValue = selectionArray[unsorted];
                smallestIndex = unsorted;            
            }
        }    
        moveCounter+=2;
        selectionArray[smallestIndex] = selectionArray[wall];
        selectionArray[wall] = smallestValue;   
    }
    cout<<"For Selection Sort, Number of Comparison is "
    <<comparisonCounter<<endl;
    cout<<"For Selection Sort, Number of Move operation is "
    <<moveCounter<<endl<<endl;
}

/***************************************************************************
*            insertionSort
*                 
* Purpose       : The purpose is that implement insertion sort and count 
                  comparison operation and move operations.                
*                    
* Pre-condition : All 700  data is assigned to insertionArray.
*
* Post-condition: insertionArray is sorted. comparisonCounter and moveCounter
                  counter have number of comparisons and move operations.Then
                  prompt user these counters.
*
***************************************************************************/
void insertionSort(int insertionArray[], int SIZE)
{
    int wall,
        temp,
        location,
        comparisonCounter=0,
        moveCounter=0;

    for(wall=1; wall<SIZE; wall++)
    {
        comparisonCounter++;
        if(insertionArray[wall] < insertionArray[wall-1] )
        {
            moveCounter++;
            temp=insertionArray[wall];
            location=wall;
            do
            {
                moveCounter++;
                insertionArray[location] = insertionArray[location-1];
                location--;
         
                if(location > 0)
                {
                    comparisonCounter++;
                }
            }while(location > 0 && insertionArray[location-1] > temp );
            
            moveCounter++;
            insertionArray[location]=temp;
        }    
    }

    cout<<"For Insertion Sort, Number of Comparison is "
    <<comparisonCounter<<endl;
    cout<<"For Insertion Sort, Number of Move operation is "
    <<moveCounter<<endl;
}
