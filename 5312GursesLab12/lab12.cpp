
/***********************************************************************
* File Name:  Lab12.cpp
*
* Author:     Erman Gurses
*
* Course:     COSC 5312 - Foundations in Programming and Problem 
*              Solving II,  
* 
* Date:       April 21, 2012
*
* Purpose:  The program reads  employee records from file and then 
            puts those records into a Queue. 
            The program prompt the user a menu in order to operate 
            some operations:
                
*           Press 1: Display Records for Bood Bank Department 
            Press 2: Display Records for Chemistry Department 
            Press 3: Display Records for Hematology Department 
            Press 4: Display Records for Microbiology Department 
            Press Q: Quit Program
            
            After the user choose 1, 2, 3 or 4, the program calculates 
            and displays the average hourly pay (to 2 decimal places) 
            for employees in that department.
*
* Input:    The program reads records from file.  
*
* Output:    The menu is displayed on the screen in order to choose type 
            of operation. 
            After the user choose type of operation, the program 
            displays;
                Display Records for Bood Bank Department or 
                Display Records for Chemistry Department or
                Display Records for Hematology Department or
                Display Records for Microbiology Department.
            After one department's records have displayed, the program 
            calculates and displays the average hourly pay 
            (to 2 decimal places) for employees in that department.
                
                    
***********************************************************************/
#include "Queue.h"
#include "Queue.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct Data
{
     string departmentCode,
            jobCode,
            lastName,
            firstName,
            phoneNumber,
            dateHired;

     char supervisoryCode,
          shiftCode,
          payCode;

     float hourlyPayRate;
          
};

bool openInputFile(ifstream & inFile); 

void readFile(Queue<Data> & queueForBLB, Queue<Data> & queueForCHE, 
              Queue<Data> & queueForHEM, Queue<Data> & queueForMIC, 
              ifstream  & inFile);

char menu(Queue<Data> & queueForBLB, Queue<Data> & queueForCHE, 
          Queue<Data> & queueForHEM, Queue<Data> & queueForMIC);

void showRecords(Queue<Data> queue);


int main()
{
    Queue<Data> queueForBLB,
                queueForCHE,
                queueForHEM,
                queueForMIC;
                
    ifstream    inFile;
    ofstream    outFile; 
    char        decision;


    if(!openInputFile(inFile))
    {    
       return 0;   
    }

    
    readFile(queueForBLB, queueForCHE, 
             queueForHEM, queueForMIC, inFile);  
    do
    {
        decision = menu(queueForBLB, queueForCHE, 
                        queueForHEM, queueForMIC);
   
    }while(decision!='Q' &&  decision!='q');

    outFile.close();
    
    return 0;
}


/***********************************************************************
*            openInputFile
*                 
* Purpose        : Try to open an input file for use by the program.
*                    
* Pre-condition    : None.
*
* Post-condition: If output file has not been opened print error message 
                    and return false
*                  If output file has been opened  
*                    return true.
*
***********************************************************************/

bool openInputFile(ifstream & inFile) 
{
   inFile.open("LabEmpData.txt");
   
   if (!inFile)
   {
      cout << "The input File cannot be opened!!!\n";

      return false;
   }
   return true;
}

/**********************************************************************
*             readFile
*
* Purpose: This function reads records from an input file then puts
           these records into 4 different types of queues. Each queue 
           stores different records based on their department code.
*
* Pre-condition:   The input file stream has been successfully opened.
*
* Post-condition: if (data.departmentCode equals "BLB")
       
                        put "data" into queueForBLB
            
                  else if (data.departmentCode equals "CHE")
                    
                        put "data" into queueForCHE
                 
                     else if (data.departmentCode equals "HEM")
                        
                        put "data" into queueForHEM
                    
                  else if (data.departmentCode equals "MIC")
                        
                        put "data" into queueForMIC
     
                    After all, records has been loaded into 4 different 
                    types of queues based on their departmentCode.
**********************************************************************/
void readFile( Queue<Data> & queueForBLB, Queue<Data> & queueForCHE,
               Queue<Data> & queueForHEM, Queue<Data> & queueForMIC,
               ifstream    & inFile)
{
 
   Data      data;
   string oneRecord;

   while (getline(inFile, oneRecord))
   {
       data.departmentCode   =  oneRecord.substr(0,3);
       data.supervisoryCode  =  oneRecord[3];
       data.jobCode          =  oneRecord.substr(4,3);
       data.lastName         =  oneRecord.substr(8,12);
       data.firstName        =  oneRecord.substr(20,9);
       data.phoneNumber      =  oneRecord.substr(30,8);
       data.shiftCode        =  oneRecord[39];       
       data.payCode          =  oneRecord[40];
       data.dateHired        =  oneRecord.substr(41,8);
       data.hourlyPayRate    =  atof(oneRecord.substr(50,5).data());
            
       if (data.departmentCode == "BLB")
       {
            queueForBLB.enqueue(data);
       }
       else if (data.departmentCode == "CHE")
       {
            queueForCHE.enqueue(data);
       }
       else if (data.departmentCode == "HEM")
       {
            queueForHEM.enqueue(data);
       }
       else if (data.departmentCode == "MIC")
       {
            queueForMIC.enqueue(data);      
       }
   } 
}


/**********************************************************************
*             menu
* Purpose: The purpose is that prompt the user menu. After the user
           choose option, this function calls another function in order
           to implement menu's option.
*
* Pre-condition: The Queue has been initialized.
*
* Post-condition: Proper function has called in menu function 
                  and decision returned to the main function. 
**********************************************************************/
char menu ( Queue<Data> & queueForBLB, Queue<Data> & queueForCHE, 
            Queue<Data> & queueForHEM, Queue<Data> & queueForMIC )
{
    Data data;
    char decision;


    do
    {
       cout<<"\nPress 1: Records for Bood Bank Department "<<endl;
       cout<<"Press 2: Records for Chemistry Department "<<endl;
       cout<<"Press 3: Records for Hematology Department "<<endl;
       cout<<"Press 4: Records for Microbiology Department "<<endl;
       cout<<"Press Q: Quit Program"<<endl;
       cin>>decision;
        
        switch(decision)
        {
            case '1': 
                showRecords(queueForBLB);
                return decision;
            case '2':
                showRecords(queueForCHE);
                return decision;
            case '3': 
                showRecords(queueForHEM);
                return decision;
            case '4':
                showRecords(queueForMIC);     
                return decision;            
            case 'Q':
            case 'q':
                return decision;
            default:
                cout<<"You must enter 1, 2, 3, 4 or Q-q"<<endl;
        }

    }while(decision!='1' && decision!='2' && 
           decision!='3' && decision!='4');


}

/**********************************************************************
*             showRecords
*
* Purpose: The purpose is that show all employees records based on their
            department Code.
*
* Pre-condition: The menu has been prompted the user and  the user has
                 made his/her choice.  
*
* Post-condition: The records have been displayed on the screen based on
                    their department code.
**********************************************************************/
void showRecords(Queue<Data> queue)
{
    Data   data;
    float  averageHourlyPay = 0;
    int    counter = 0;

    cout<<"-Last Name-\t-First Name-\t-Supervisory Code-     "
        <<"-Job Code-"<<endl;

    while(queue.dequeue(data))
    {
        cout<<"  "<<data.lastName<<"\t  "
            <<data.firstName<<"\t\t"
            <<data.supervisoryCode<<"\t\t  "
            <<data.jobCode<<endl;

        averageHourlyPay += data.hourlyPayRate;
        counter++;

    }

    averageHourlyPay = averageHourlyPay / counter;

    cout<<"\nAverage of Hourly Pay is "<<"$"<<fixed
        <<setprecision(2)<<averageHourlyPay<<endl;

}
