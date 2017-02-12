
/********************************************************************
* File Name:  Lab2a.cpp
*
* Author:  Erman Gurses
*
* Course:  COSC 5312 - Foundations in Programming and Problem 
*          Solving II,  A03539870
* 
* Date:    March 22, 2012
*
* Purpose: This program demonstrates kind of playGame which is named
*          Pig.
*          
*
* Input:  The user will input string which is players names and 
*         char for making decisionRollAgain to end turn or to 
          continue.  
*
* Output: The output will be on the screen. First, before users 
*         start the playGame, the output gives some instructions
*         about the playGame. While they are playing the playGame,
*         the output will let them know current rolled number and 
*         total scores of players. At the end of the playGame the
*         output let players know what total scores they have
*         who wins the playGame.
********************************************************************/

#include <iostream>
#include <time.h>
#include <string>
using namespace std;

//Function Prototypes 
void showInstructions();
int  roll();
void playGame();
void winner(string player1, string player2, int scoreP1, int scoreP2);
int currentPlayer(string playerName, int score);

int main(int argc, char* argv[])
{
  srand(time(0));

  // Call showInstructions function
  showInstructions(); 
  
  // Call playGame function
  playGame(); 
  
  // Tell system program is finished without error.
    return 0;
}

/**********************************************************************
*             showInstructions
* 
* Purpose: The purpose is that give some basic instructions
*           about game. 
* 
* Pre-condition: None.
* 
* Post-condition: The instructions have been showed. 
**********************************************************************/
void showInstructions ()
{
  
  // Display welcome and instructions for the user
  cout<<"\n\n*****************************Welcome The Game of Pig**"<<
  "***************************"<<endl;
  cout<<"\n-The Game of Pig has two players race to reach 100 "<< 
    "points. \n"<<endl;
  cout<<"-Each turn, a player repeatedly rolls a die until either"<<
    " a \n 1 is rolled or the player holds and scores.\n"<<endl;
  cout<<"-At any time during a player's turn, the player is faced"<<
    " with two decisionRollAgains:\n"<<endl;
  cout<<"First one is : roll \n\n-If the player rolls a;\n\n";
  cout<<" 1     : The player scores no additional points for his/her "
  <<"turn\n"<<
    "   and it becomes the opponent's turn. "; 
  cout<<"Any points the player \n         had going into the turn are "
  <<" still valid.\n\n"<<endl; 
  cout<<" 2 - 6 : The number is added to the player's turn total and "
  "the"<< 
    "\n   player's turn continues.\n"<<endl;
  cout<<"Second one is: hold \n\n-The turn total is added to the "
  <<"player's"<< 
    " score and it becomes\n the opponent's turn.\n"<<endl;
}


/**********************************************************************
*             roll
* 
* Purpose: Generate random number between 1-6 inclusive.    
* 
* Pre-condition: Call srand() function with time(0) function to set the
                   seed to be used by random number. 
* 
* Post-condition: Random number generated between 1-6 inclusive and
*                 it retuned.  
**********************************************************************/
int roll()
{

  int rolledDice;

  // generate random number between inclusive 1-3
  rolledDice = (1 + rand() % 6);

  // return generated number
  return rolledDice;

}
/**********************************************************************
*             winner
* 
* Purpose: The purpose is that to determine who winner is. 
           Moreove, it will show scores after the game finishes. 
* 
* Pre-condition: "scoreP1" || "scoreP2" has to be greater than 100.
                 Moreover, string parameters contains players' names.
* 
* Post-condition: If "scoreP1" greater than "scoreP2" prompt the game
*                   is finished and winner is "player1" and show 
*                   "scoreP1" and "scoreP2".
*                 else
*                   prompt the game is finished and winner is 
*                   "player2" and show "scoreP1" and "scoreP2".
**********************************************************************/
void winner(string player1, string player2, int scoreP1, int scoreP2)
{
  // if scoreP1 greater than scoreP2 prompt lines in first brakets
  // otherwise prompt lines in second brackets. 
  if(scoreP1 > scoreP2)
  {  cout<<"The Game is finised"<<endl;
    cout<<"Congratulations!!! " <<player1<<". You are the Winner."
    <<endl;
    cout<<player1<<"'s score is "<<scoreP1<<endl;
    cout<<player2<<"'s score is "<<scoreP2<<endl;
  }
  else
  {
  
    cout<<"The Game is finised"<<endl;
    cout<<"Congratulations!!! " <<player2<<". You are the Winner."
    <<endl;
    cout<<player2<<"'s score is "<<scoreP2<<endl;
    cout<<player1<<"'s score is "<<scoreP1<<endl;
  }// end if
}

/**********************************************************************
*             playGame
* 
* Purpose: This function applies the game according to its 
*          instructions. 
* 
* Pre-condition: The instructions have been showed.  
* 
* Post-condition: The game is quit. 
**********************************************************************/
void playGame()
{
  string player1, 
       player2;
  char   decisionPlayAgain;
   
  int scoreP1 = 0,
    scoreP2  = 0;
  
  // Prompt player1 enter your name and get name 
  cout<<"Player 1 Enter Your Name:";
  cin>>player1;

  // Prompt player2 enter your name and get name 
  cout<<"Player 2 Enter Your Name:";
  cin>>player2;
  
  do
  {
    do
    {
      scoreP1+=currentPlayer(player1, scoreP1);

      cout<<"-----------"<<player1<<"'s turn is over!!!--------\n";
      if(scoreP1<100)
      {
        scoreP2+=currentPlayer(player2,scoreP2);

        cout<<"-----------"<<player2<<"'s turn is over!!!-------"
        <<"-\n";
      }
      

    }while(scoreP1 < 100 && scoreP2 < 100);

    winner(player1,player2,scoreP1,scoreP2);

    cout<<"Do you want to play again? Y/N"<<endl;
      
    cin>>decisionPlayAgain;


    scoreP1 = 0,
    scoreP2 = 0;
    
  }while(decisionPlayAgain=='Y' || decisionPlayAgain=='y');
}

/**********************************************************************
*             currentPlayer
* 
* Purpose: This function gets player's name and its old score
           from playGame function  then it applies this current 
           players "roll"
* 
* Pre-condition: Player's name has entered past turn's score
                 has accumulated
* 
* Post-condition: turnScore has returned
          If rolledScore equal 1
             turnScore=0;
            return turnScore

          if score+turnScore>100
            return turnScore

          if decisionRollAgain not equal 'R' and 
             decisionRollAgain not equal'r'
            return turnScore
**********************************************************************/
int currentPlayer(string playerName, int score)
{
  char decisionRollAgain;

  int turnScore=0,
      rolledScore=0;

    cout<<"\n\n-------------Now "<<playerName<<"'s turn-------------"
    <<"\n\n";
    cout<<playerName<<"'s score is "<<score<<endl;  
    cout<<"Do you want to Roll or Hold? "<<playerName<<endl;
    cout<<"For Roll press R, for Hold press H:";

    cin>>decisionRollAgain;

    cout<<"------------------------------------------"<<endl;

    while(decisionRollAgain == 'R' || decisionRollAgain == 'r')
    {
      rolledScore=roll();
      
      //check player rolled 1
      if(rolledScore == 1)
      {
        cout<<playerName<<" rolled "<<rolledScore<<endl;
        cout<<playerName<<"'s score is "<<score<<endl;
        
        turnScore=0;
        
        return turnScore;
      }
      else
      {
        cout<<"Before this turn, "<<playerName<<
          "'s score was "<<score<<endl;
        cout<<playerName<<" rolled "<<rolledScore<<endl;
        
        turnScore+=rolledScore;
  
        cout<< playerName<<"'s score is "<<score+turnScore<<endl;

        if((score+turnScore)>=100)
        {
          return turnScore;
        }
        
        cout<<"Do you want to Roll or Hold? "<<playerName<<endl;
        cout<<"For Roll press R, for Hold press H:";
        
        cin>>decisionRollAgain;
        
        if(decisionRollAgain != 'R' && decisionRollAgain != 'r')
        {
          return turnScore;
        } 
      }
       cout<<"------------------------------------------"<<endl;
    }
  return turnScore;  
}

