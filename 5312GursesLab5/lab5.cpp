/********************************************************************
* File Name:  Lab5.cpp
*
* Author:     Erman Gurses
*
* Course:     COSC 5312 - Foundations in Programming and Problem 
*             Solving II,  A03539870
* 
* Date:       March 22, 2012
*
* Purpose:    The purpose is that implementation of two different search 
              algorithm which are Linear Search and Binary Search. 
              Program reads ascending order numbers from file and puts 
              them into array then prompts user which algorithm do you 
              want to use. After User select search algorithm, program 
              asks user array size.(1000, 2500, 5000, 10000) then asks 
              user target value which is searched in array. After search 
              implements, program displays and writes how many comparison 
              operations made. It keeps going until user decide to exit 
              program. 
*          
*
* Input:      The Inputs ascending order 10000 numbers 
*              
*
* Output:     These are 2 different output stream one is screen output
              the other one is file output.
********************************************************************/

#include <fstream>
#include <iostream>


using namespace std; 


void readInputFile( ifstream & inFile, int inputArray[], int SIZE);
bool openInputFile(ifstream & inFile); 
bool openOutputFile(ofstream & outFile);
void implementSearch(int inputArray[], ofstream & outFile);
void writeOutputFile(ofstream & outFile, int counter, int decision, 
                     int size);

const int SIZE = 10000;

int main()
{
    
    ifstream inFile;
    ofstream outFile;
    int inputArray[SIZE]={0};

    if(!openInputFile(inFile))
    {
        return 0;
    }

    if(!openOutputFile(outFile))
    {
        return 0;
    
    }
    
    readInputFile(inFile,inputArray,SIZE);
    
    inFile.close();
    
    
    
    implementSearch(inputArray,outFile);


    outFile.close();
    

  return 0;
}

/************************************************************************
*            openInputFile
*                 
* Purpose        : Try to open an input file for use by the program.
*                    
* Pre-condition    : None.
*
* Post-condition: If input file has not been opened print error message
                    and return false
*                  If input file has been opened  
*                    return true.
*
************************************************************************/
bool openInputFile(ifstream & inFile) 
{
   inFile.open("lab5input.txt");
   
   if (!inFile)
   {
      cout << "The input File cannot been opened!!!\n";

      return false;
   }
   return true;
}


/************************************************************************
*            readInputFile
*                 
* Purpose        : Try to assign data from inFile to inputArray
*                    
* Pre-condition    : InputFile had to been opened.
*
* Post-condition: All 10000 data in inputArray.
*
************************************************************************/
void readInputFile( ifstream & inFile, int inputArray[], int SIZE)
{
    
    for(int i=0; i<10000; i++)
    {
        inFile>>inputArray[i];    
    }

}

/************************************************************************
*            linearSearch
*                 
* Purpose    : The purpose is that implementation of linear search and 
              count howmany comparisons are made. The function searches 
              target element as a sequentially. While loop checks two 
              condition. First one is index which has to be lower than 
              SIZE.

              SIZE is determined by user.(1000, 2500, 5000, 10000) Second 
              one is "found" variable. If this condition is correct 
              "inputArray[index] == target" which means program finds 
              target value "found" can be true so while loop check this 
              variable too. One of these condition is false while loop is
              terminated.

              This is basic linear search, actually numbers are ordered 
              so we could improve efficienty if we compare value of 
              numbers. If this condition is true 
              "inputArray[index] < target" program could be terminated. 
              However I implemented basic linear search
              and I put counter between while and if statements.
*                    
* Pre-condition    : inputArray is loaded with numbers. SIZE and target are 
                  entered by user.
*
* Post-condition: It returns counter which is number of comparison.
*
************************************************************************/

int linearSearch (int inputArray[], int SIZE, int target)
{
    bool found    = false;
    int  position = -1,
         index    =  0,
         counter  =  0;

    while( index < SIZE && found == false)
    {     
        counter++;

        if( inputArray[index] == target)
        {
            found=true;
            position=index;
        }
        index++;
    }
    return counter;
}


/************************************************************************
*            binarySearch
*                 
* Purpose        : It implements binary search measure number of 
                  comparison 
                  In each iteration It finds a value in the middle of 
                  array and checks it whether or not equal to target 
                  value. If equals it returns directly counter number 
                  which is my purpose estimate an efficiency, normally it
                  returns index number which is mid.

                  If this "inputArray[mid]>target" condition is correct,
                  you can eliminate half of your array which is bigger 
                  side.

                  So your new last element's index is mid-1.
                  
                  Else you can eliminate half of your array which is 
                  smaller side. So your new first element's index is mid+1.
                  This search basicly divides the array into 2 pieces each 
                  iteration. When first is bigger than last the iteration 
                  is erminated.
*                    
* Pre-condition    : inputArray is loaded with numbers. SIZE and target are 
                  entered by user.
*
* Post-condition: It returns counter which is number of comparison.
*
*
************************************************************************/
int binarySearch (int inputArray[], int SIZE, int target)
{
    int   first=0,
          last=SIZE-1,
          mid,
          x=0,
          counter=0;
    while(first<=last)
    {
        mid=(first+last)/2;
        counter++;
        if(inputArray[mid]==target)
        {
            return counter;
        }

        else if(inputArray[mid]>target)
        {
            last=mid-1;
        }
        else
        {
            first=mid+1;  
        }
    }

    return counter;

}

/************************************************************************
*            openOutputFile
*                 
* Purpose        : Try to open an output file for use by the program.
*                    
* Pre-condition    : None.
*
* Post-condition: If output file has not been opened print error message 
                    and returns false
*                  If output file has been opened  
*                    returns true.
*
************************************************************************/
bool openOutputFile(ofstream & outFile) 
{
    char fileName[30];

    cout<<"Enter file name:";
    cin>>fileName;

    outFile.open(fileName);

   if (!outFile)
   {
      cout << "The Output File cannot been opened!!!";

      return false;
   }
   
    return true;
}



/************************************************************************
*            implementSearch
*                 
* Purpose        : This function works like a menu. 
*                    
* Pre-condition  : inputArray is loaded with numbers. outFile is opened.
*
* Post-condition: If decision is 1
                     prompt and get user SIZE and target,
                     implement linear search,
                     get comparison number which is counter,
                     send these data (outFile,counter,decisionAlgorithm,
                     size) to writeOutputFile function.
                      
                 If decision is 2
                     prompt and get user SIZE and target,
                     implement binary search,
                     get comparison number which is counter,
                     send these data (outFile,counter,decisionAlgorithm,
                     size) to writeOutputFile function.
                     
                 Keep going until user teminate the program.
*
************************************************************************/
void implementSearch(int inputArray[], ofstream & outFile)
{
    int flagFileMode = 0;

    char decisionLoop;
    int  decisionAlgorithm,
         size,
         target,
         counter = 0;
         
     do
     {
         cout<<"\nFor Linear, Search Press 1"<<endl;
         cout<<"For Binary, Search Press 2"<<endl;
         cout<<"Which algorithm do you want to choose?:";

         cin>>decisionAlgorithm;

         switch(decisionAlgorithm)
         {
            case 1:

                cout<<"You can choose four different sizes of array:"
                <<" 1000, 2500, 5000 and 10000."<<endl;
                cout<<"Enter size of array:";
                cin>>size;

                cout<<"Enter your target:";
                cin>>target;

                counter=linearSearch (inputArray,size,target);
            

                writeOutputFile(outFile,counter,decisionAlgorithm,size);
                break;
          
            case 2:
                
                cout<<"You can choose four different sizes of array:"
                <<" 1000 2500, 5000 and 10000."<<endl;
                cout<<"Enter size of array:";
                cin>>size;

                cout<<"Enter your target:";
                cin>>target;

                counter=binarySearch(inputArray,size,target);

                writeOutputFile(outFile,counter,decisionAlgorithm,size);
                break;
         }

         cout<<"Do you want to do again? Y/N:";
         cin>>decisionLoop;
     
     }while(decisionLoop =='Y'|| decisionLoop =='y');

}

/************************************************************************
*            writeOutputFile
*                 
* Purpose        : The purpose is that write information about search 
                    types onto screen and into file
*                    
* Pre-condition    : outFile has to been opened. Counter has number of 
                    comparison, decision  and size had to been entered 
                    by user, 
*
* Post-condition: If decision is 1
                     prompt user information about linear search.
                     
                      
                 If decision is 2
                     prompt user information about binary search.
*
************************************************************************/

void writeOutputFile(ofstream & outFile, int counter, int decision,
                     int size)
{
    switch(decision)
    {
        case 1:
    
          outFile<<"\nYou implemented Linear Search in "<<size<<
          " elements"<<endl;
          outFile<<"Number of comparisons is "<<counter<<endl<<endl;
          cout<<"\nYou implemented Linear Search in "<<size<<
          " elements"<<endl;
          cout<<"Number of comparisons is "<<counter<<endl<<endl;
          break;
            
        case 2:
        
          outFile<<"\nYou implemented Binary Search in "<<size<<
          " elements"<<endl;
          outFile<<"Number of comparisons is "<<counter<<endl<<endl;
          cout<<"\nYou implemented Binary Search in "<<size<<
          " elements"<<endl;
          cout<<"Number of comparisons is "<<counter<<endl<<endl;
          break;
    
    }
}

