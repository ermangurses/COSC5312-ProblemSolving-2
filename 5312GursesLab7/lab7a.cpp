/********************************************************************    
* File Name:  Lab7a.cpp
*
* Author:     Erman Gurses
*
* Course:     COSC 5312 - Foundations in Programming and Problem 
*              Solving II,  
* 
* Date:       February 29, 2012
*
* Purpose:    The program implements the rock-paper-scissors game.
                In the game;
                a) Rock smashes scissors.
                b) Paper wraps rock.
                c) Scissors cuts paper and,
                1 represents Rock
                2 represents Scissors
                3 represents paper
*                First, computer generates numbers 1-3 inclusive.
                then the program asks the user to choice 1-3 inclusive.
                After both sides give decisions, the program compares
                decisions then decides which side win for the current 
                turn regarding the game rules. After that, the program 
                ask the use whether play again or not. If the user's 
                decision no the program prompts how many turns played,
                how many turns the user won, how many turns the 
                computer won and how many turns are ties. If the user's 
                decision yes, the play keeps going. 
                Moreover, in this program all variable operations are 
                call by reference.
*
* Input:      The program takes two inputs. First one is from the user
                by using keyboard numbers (1-3 inclusive) to decide 
                rock, scissor and paper. Second one is from random 
                number generator(1-3 inclusive) that represents the 
                computer's decision. 
                In addition, the user decides the game whether is 
                finished or not.

*              
*
* Output:      The program compares the user's and computer's decision 
                 for each turn and decides which has won for current turn. 
                 Then prompts the user who won. At the end of the game,
                 the program prompts how many turns played, how many 
                 turn the user won, how many turn the computer won and
                 how many turn are tie.

********************************************************************/

#include <fstream>
#include <iostream>
#include <time.h>



using namespace std; 

int  * getComputersChoice(); 
int  * getHumansChoice();
char * determineWinner(int * humanChoice, int *computerChoice);
void   showCurrentRound(char *lastResult);
void   updateTotals(char *lastResult, int * totalGames,    
       int * humanWins, int * computerWins, int * numberTies);
void   displayResults(int * totalGames, int  * humanWins, 
       int * computerWins, int * numberTies);

int main()
{

    int  *humanChoice, 
         *computerChoice,
         *totalGames,
         *humanWins,
         *computerWins,
         *numberTies;
    char *lastResult,
         *playAgain;

    totalGames     =  new int;
    humanWins      =  new int;
    computerWins   =  new int;
    numberTies     =  new int;
    playAgain      =  new char;

    *totalGames=0;
    *humanWins=0;
    *computerWins=0;
    *numberTies=0;

    srand(time(0));

    do
    {
        computerChoice = getComputersChoice();
        humanChoice = getHumansChoice();
        lastResult = determineWinner(humanChoice,computerChoice);
        showCurrentRound(lastResult);
        updateTotals(lastResult, totalGames,humanWins,computerWins,
        numberTies);

        cout<<"\nDo you want to do again?(Y/N):";
        
        cin>>*playAgain;
        
        delete lastResult;
        delete humanChoice;
        delete computerChoice;
    
    }while(*playAgain=='y' || *playAgain=='Y');

    displayResults(totalGames,humanWins,computerWins,numberTies);
      
    delete totalGames;
    delete humanWins;
    delete computerWins;
    delete numberTies;    
    delete playAgain; 

  return 0;
}

/**********************************************************************
*             getComputersChoice
* 
* Purpose       : The purpose is that generate numbers 1-3 inclusive.
* 
* Pre-condition : srand(time(0)) called to seed random number generator
* 
* Post-condition: Returns randomNumber pointer which points gererated
                    random number's address.
**********************************************************************/
int * getComputersChoice() 
{
    int * randomNumber = new int; 

    *randomNumber = (1+rand()%3);
    
    return randomNumber;

}

/**********************************************************************
*             getHumansChoice
* 
* Purpose       : The purpose is that get decision from user to choose
                  rock, scissor and paper respectively 1, 2, 3.
* 
* Pre-condition : None.
* 
* Post-condition: Returns choice pointer which points the user's 
                  decision address.
**********************************************************************/
int * getHumansChoice()
{
    int *choice= new int;
    
    do
    {
        cout<<"Choose from one of the following options:"<<endl;
        cout<<"1. Rock"<<endl;
        cout<<"2. Scissors"<<endl;
        cout<<"3. Paper"<<endl;
        cin>>*choice;

    }while( *choice < 1 || *choice > 3);

 return choice;
}

/**********************************************************************
*             determineWinner
* 
* Purpose        : The purpose is that determine who is the winner for 
                    current turn. Computer or Human or In case of tie.
* 
* Pre-condition    : computerChoice is generated and humanChoice is 
                    entered by user
* 
* Post-condition: It could return  a char pointer which point
                    address of char variable;

                    t= tie condition,
                    h= human won,
                    c= computer won.

                    if tie condition
                        *result='t';
                        return result;

                    if human winner
                        *result='h';
                        return result;

                    if computer winner
                        *result='c';
                        return result;

**********************************************************************/
char * determineWinner(int * humanChoice, int *computerChoice)
{
    char *result;

    result = new char;
    
    if(*humanChoice==*computerChoice)
    {

        *result='t';
        return result;    

    }
    else
    {
        switch(*humanChoice)
        {       
            case 1:               
                if(*computerChoice == 2)
                {
                    cout<<"Rock smashed scissors"<<endl;
                    
                    *result='h';
                     return result;
                }
                else if(*computerChoice == 3) 
                {
                    cout<<"Paper wraps rock"<<endl;
                    
                    *result='c';
                    return result;
                }

            case 2:
                if(*computerChoice == 1)
                {
                    cout<<"Rock smashed scissors"<<endl;
                    
                    *result='c';
                    return result;

                }else if (*computerChoice == 3)
                {
                    cout<<"Scissors cut paper"<<endl;
                    
                    *result='h';
                    return result;        
                }    
            
            case 3:              
                if(*computerChoice == 1)
                {
                    cout<<"Paper wraps rock"<<endl;
                    
                    *result='h';
                    return result;

                }else if (*computerChoice == 2)
                {
                    cout<<"Scissors cut paper"<<endl;
                  
                    *result='c';
                    return result;              
                }    

        }// switch

    }// if
}
/**********************************************************************
*             showCurrentRound
* 
* Purpose        : The purpose is that show the turn's winner
* 
* Pre-condition    : the lastresult estimated. 
* 
* Post-condition: if (lastResult equals t)
*                    print "It was a tie"
*
*                  if (lastResult equals h)
*                    print "You beat the computer!"
*
*                  if (lastResult equals c)
*                    print "The computer beat you."
**********************************************************************/
void showCurrentRound(char * lastResult)
{
    
    cout<<"For this round"<<endl;

    switch(*lastResult)
    {
        case 't': cout<<"It was a tie"<<endl;
        
            break;

        case 'h': cout<<"You beat the computer!"<<endl;
        
            break;

        case 'c': cout<<"The computer beat you."<<endl;
        
            break;
    }   
}


/**********************************************************************
*             updateTotals
* 
* Purpose        : The purpose is that checking each functions' flags.
* 
* Pre-condition    : Flags have to have 0 or 1
* 
* Post-condition: Prompt user which condition is not valid
**********************************************************************/
void updateTotals(char *lastResult, int * totalGames,    int * humanWins, 
                  int * computerWins, int * numberTies)
{
    *totalGames=*totalGames+1;

    switch(*lastResult)
    {
        case 't': *numberTies=*numberTies+1;
        
            break;

        case 'h': *humanWins=*humanWins+1; 
        
            break;

        case 'c': *computerWins=*computerWins+1;
        
            break;
    
    }
}

/**********************************************************************
*             displayResults
* 
* Purpose        : The purpose is that show statistics at the end of the 
                 game
* 
* Pre-condition    : The user entered no for "Do you want to do again?
                    (Y/N)" question
* 
* Post-condition: Prompt the user how many turns played, how many turn
                    the computer won, how many turn the user won,  
                    and how many turn are tie.

                    if(humanWins greated than computerWins)
                        print "Congratulations!  You beat the computer",
                        humanWins-computerWins, "times"
**********************************************************************/  
void displayResults(int * totalGames, int  * humanWins, 
                    int * computerWins, int * numberTies)
{
    
    cout<<"\n\nThere were a total of "<<*totalGames<<" played."<<endl;
    cout<<"The computer won "<<*computerWins<< " games."<<endl;
    cout<< "You won "<< *humanWins<<" games."<<endl;
    cout<< "There were "<< *numberTies <<" tied games."<<endl;
    if(*humanWins > *computerWins)
    {
        cout<<"Congratulations!  You beat the computer "<<
            *humanWins - *computerWins <<" times! "<<endl;
    
    }
}




