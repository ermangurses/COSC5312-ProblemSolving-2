/********************************************************************
* File Name:  Lab7b.cpp
*
* Author:     Erman Gurses
*
* Course:     COSC 5312 - Foundations in Programming and Problem 
*             Solving II,  A03539870
* 
* Date:       March 22, 2012
*
* Purpose:    The program check that entered password is proper 
              some criteria. These are;
        
        -The password cannot be same user name.
        -The password should contain no fewer than 8 
         characters and no more than 12 characters.
        -The password must contain at least one upper 
         case letter and at least one lower case letter.
        -The password must contain at least one digit.
        -The password must contain at least one 
         non-alphanumeric character.
        -The password may not contain any spaces.
*          
*
* Input: The user will input string which is User name and 
*        and password  
*
* Output: The output will be on the screen. It gives some warning
        if password does not provide some criteria. After 3 wrong 
        enter user have to wait one hour.
********************************************************************/

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int checkWithUsername(char[],char[]);
int checkLength(char[]);
int containUpper(char[], int);
int containLower(char [], int);
int containDigit(char [], int);
int containNonAlphaNumeric(char[], int);
int containSpace(char[], int);
void checkFlags(int flagUserName, int flagLength, int flagContainUpper, 
        int flagContainLower,int flagContainDigit, 
        int flagContainNonAlphaNumeric, int flagContainSpace);

int main(int argc, char* argv[])
{
  const int LENGTH = 12;
  
  char userName[LENGTH],
     passWord[LENGTH];

  int flagCheck=0,
    flagUserName=0,
    flagLength=0,
    flagContainUpper=0,
    flagContainLower=0,
    flagContainDigit=0,
    flagContainNonAlphaNumeric=0,
    flagContainSpace=0,
    counter=0,
    length=0;
    
    // Prompt user enter user name and get user name 
    cout<<"\nEnter Your User Name:";
    cin>>userName;

    cin.ignore();
  
  do
  {
    //Prompt user enter user password and get password
    cout<<"Enter Your Password:";
    cin.getline(passWord,LENGTH);
    
    length=strlen(passWord);

    // function calls
    flagUserName = checkWithUsername(userName,passWord);
    flagLength = checkLength(passWord);
    flagContainUpper = containUpper(passWord,length);
    flagContainLower = containLower(passWord,length);
    flagContainDigit = containDigit(passWord,length);
    flagContainNonAlphaNumeric = containNonAlphaNumeric(passWord,
    length);
    flagContainSpace = containSpace(passWord,length);
  
    checkFlags(flagUserName,flagLength,flagContainUpper,
    flagContainLower, flagContainDigit, flagContainNonAlphaNumeric,
    flagContainSpace);
  
    if(flagUserName && flagLength && flagContainUpper 
    && flagContainLower && flagContainDigit 
    && flagContainNonAlphaNumeric && flagContainSpace)
    {
      flagCheck=1;
    }

    counter++;

  }while(counter < 3 && flagCheck == 0 );

  if(flagCheck == 0)
    cout<<"\nThe user must wait an hour before trying again."<<endl;
  else
    cout<<"\nThank You! Your password is valid."<<endl;

    
  return 0;
}
void checkFlags(int flagUserName, int flagLength, int flagContainUpper, 
int flagContainLower,int flagContainDigit, 
int flagContainNonAlphaNumeric, int flagContainSpace)
{
  
  if(!flagUserName || !flagLength || !flagContainUpper || 
      !flagContainLower || !flagContainDigit
    || !flagContainNonAlphaNumeric || !flagContainSpace)
  {
      cout<<"\nYour password is invalid for the following reasons:"
      <<endl;

      if(!flagUserName)
      {
        cout<<"  A valid password cannot be same your username."
        <<endl;
      }
        
      if(!flagLength)
      {
        cout<<" A valid password should contain no fewer than 8 "
        <<"character and no more than 12 characters."<<endl;
      }
        
      if(!flagContainUpper)
      {
        cout<<"  A valid password must contain at least one "
        "upper case letter"<<endl;
          
      }
      if(!flagContainLower)
      {
        cout<<"  A valid password must contain at least one "
        <<"lower case letter"<<endl;
      }
        
      if(!flagContainDigit) 
      {
        cout<<"  A valid password must contain at least one "
        <<"digit."<<endl;
      }
      
      if(!flagContainNonAlphaNumeric)
      {
        cout<<"  A valid password must contain at least one "
        <<"non-alphanumeric character."<<endl;
      }
      
      if(!flagContainSpace)
      {
        cout<<"  A valid password may not contain any spaces."
        <<endl;
      }
    
    }

}
/**********************************************************************
*             checkWithUsername
* 
* Purpose : The purpose is that checking userName and passWord
             are same or not. 
* 
* Pre-condition : userName and passWord have to been entered by user.
* 
* Post-condition : It returns 1 if they are not same it return 0 if 
                   they are same
**********************************************************************/
int checkWithUsername(char userName[],char passWord[])
{
  int flag = 0;
  
    flag=strcmp(userName,passWord);
    
    if(flag != 0)

      flag=1;

 return flag;
}

/**********************************************************************
*             checkLength
* 
* Purpose    : The purpose is that check length less than 8 or more 
          than 12 
* 
* Pre-condition  : PassWord have to been entered by user.
* 
* Post-condition: It returns 0  if it is length less than 8 or more 
          than 12 
          otherwise returns 1
**********************************************************************/
int checkLength(char passWord[])
{
  int length;

  length = strlen(passWord);
  
  if(length < 8 || length > 12)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

/**********************************************************************
*             containUpper
* 
* Purpose    : The purpose is checking is there any upper case letter.
* 
* Pre-condition  : PassWord have to been entered by user.
* 
* Post-condition: It returns 0 if it is not exist upper case letter  
                  otherwise returns 1
**********************************************************************/
int containUpper(char passWord[], int length)
{

  for(int i=0; i<length; i++)
  {
    if(isupper(passWord[i]))
    {  
      return 1;
    }
  }

  return 0;
}

/**********************************************************************
*             containLower
* 
* Purpose    : The purpose is checking is there  any lower case 
               letter.
* 
* Pre-condition  : PassWord have to been entered by user.
* 
* Post-condition: It returns 0 if it is not exist lower case letter  
                  otherwise returns 1
**********************************************************************/
int containLower(char passWord[], int length)
{

  for(int i = 0; i < length; i++)
  {
    if(islower(passWord[i]))
    {  
      return 1;
    }
  }

  return 0;
}

/**********************************************************************
*             containDigit
* 
* Purpose    : The purpose is checking is there any digit. 
* 
* Pre-condition  :  PassWord have to been entered by user.
* 
* Post-condition: It returns 0 if it is not exist digit  otherwise
                      returns 1
**********************************************************************/
int containDigit(char passWord[], int length)
{
  int i = 0;
  int flag = 0;

  for(int i = 0; i < length; i++)
  {
    if(isdigit(passWord[i]))
    {  
      return 1;
    }

  }

  return 0;
}

/**********************************************************************
*             containNonAlphaNumeric
* 
* Purpose    : The purpose is checking is there any Non-AlphaNumeric
               character. 
* 
* Pre-condition  : PassWord have to been entered by user.
* 
* Post-condition: It returns 0 if it is not exist  Non-AlphaNumeric 
                  character otherwise returns 1
**********************************************************************/
int containNonAlphaNumeric(char passWord[], int length)
{

  for(int i = 0; i<length; i++)
  {
    if(ispunct(passWord[i]))
    {  
      return 1;
    }
  }

  return 0;
}

/**********************************************************************
*             containSpace
* 
* Purpose        : The purpose is checking is there any Space
                   character. 
* 
* Pre-condition  : PassWord have to been entered by user.
* 
* Post-condition : It returns 1 if it is not exist Space character
                   otherwise returns 0
**********************************************************************/
int containSpace(char passWord[], int length)
{


  for(int i=0; i<length; i++)
  {
    if(isspace(passWord[i]))
    {  
      return 0;
    }
  }

  return 1;
}

