/************************************************************************
* File Name:  Lab8a.cpp
*
* Author:     Erman Gurses
*
* Course:     COSC 5312 - Foundations in Programming and Problem 
*              Solving II,  
* 
* Date:       March 19, 2012
*
* Purpose:    The purpose of program is that calculate differences 
              between budget and expenses. The Budget contains sub 
              categories, which are Housing, Utilities, HouseholdExpense, 
              Transportation, Food, Medical, Insurance, Entertainment,
              Clothing, and Miscellaneous. In order to keep these sub 
              categories there is a struct which is named Budget. The 
              program uses two instances of this struct. The first one is
              referenceBudget, which keeps base budget amount of money 
              for each sub categories. The amount of money has already 
              assigned in the program. 
              The second one is monthOfExpenses, which keeps the user's 
              monthly expenses so the user has to enter the amount of 
              money for each sub categories of monthOfExpenses. 
              After the user enters the program monthly expenses, the 
              program will estimate differences between  referenceBudget
              and monthOfExpenses for each sub categories and prompt them
              to the user. At the end of the estimation of sub categories
              the program prompt the user total differences between 
              referenceBudget and monthOfExpense.  
*
* Input:      The input is that sub categories of Budget which are  
              Housing, Utilities, HouseholdExpense, Transportation, Food,
              Medical, Insurance, Entertainment, Clothing, and 
              Miscellaneous.  
*              
*
* Output:     The output is that differences between each sub categories 
              of referenceBudget and sub categories of monthOfExpenses 
              and total differences between referenceBudget and 
              monthOfExpenses.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


struct Budget
{
        float Housing,
              Utilities,    
              HouseholdExpense,    
              Transportation,    
              Food,    
              Medical,    
              Insurance,    
              Entertainment,    
              Clothing,    
              Miscellaneous;
};

void fillReferenceBudget(Budget * referenceBudget );

void getMonthOfExpenses(Budget * monthOfExpenses );

void calculateDifferences(Budget * referenceBudget,
                          Budget * monthOfExpenses, 
                          float * totalReferenceBudget);

float calculateReferenceBudget(Budget * referenceBudget);

void getMonthOfExpenses(Budget * monthOfExpenses );

float getInput(string  category);

float compareCategory(float referenceBudgetCategory, 
                      float monthOfExpensesCategory, 
                      string category);

void grandTotal(Budget * referenceBudget, 
                Budget * monthOfExpenses);

int main()
{
    Budget * referenceBudget,
           * monthOfExpenses;

    char decision;
    referenceBudget = new Budget;
    monthOfExpenses = new Budget;

    fillReferenceBudget(referenceBudget );

    do
    {
        getMonthOfExpenses(monthOfExpenses);
        

        grandTotal(referenceBudget,monthOfExpenses);

        
        cout<<"\n\n---Do you want to calculate another month?--- (Y/N):";

        cin>>decision;

    }while(decision == 'y' || decision == 'Y');
    
    delete referenceBudget;
    delete monthOfExpenses;

  return 0;
}

/************************************************************************
*            fillReferenceBudget
*                 
* Purpose        : The purpose is that initialize the struct of 
``                  referenceBudget
*                    
* Pre-condition    : referenceBudget has been declared. 
*
* Post-condition: referenceBudget has been initialized 
*
************************************************************************/
void fillReferenceBudget(Budget * referenceBudget)
{

    referenceBudget->Housing              = 500.00;
    referenceBudget->Utilities            = 150.00;
    referenceBudget->HouseholdExpense     = 65.00;
    referenceBudget->Transportation       = 50.00;
    referenceBudget->Food                 = 250.00;
    referenceBudget->Medical              = 30.00;
    referenceBudget->Insurance            = 100.00;
    referenceBudget->Entertainment        = 150.00;
    referenceBudget->Clothing             = 75.00;
    referenceBudget->Miscellaneous        = 50.00;

}

/************************************************************************
*            getMonthOfExpenses
*                 
* Purpose        : The purpose is that initialize the struct of 
``                  monthOfExpenses
*                    
* Pre-condition    : monthOfExpenses has been declared. 
*
* Post-condition: monthOfExpenses has been initialized 
*
************************************************************************/
void getMonthOfExpenses(Budget * monthOfExpenses )
{
    cout<<endl;

    monthOfExpenses->Housing           = getInput("Housing");
    monthOfExpenses->Utilities         = getInput("Utilities");        
    monthOfExpenses->HouseholdExpense  = getInput("Household Expense");
    monthOfExpenses->Transportation    = getInput("Transportation");
    monthOfExpenses->Food              = getInput("Food");                
    monthOfExpenses->Medical           = getInput("Medical");            
    monthOfExpenses->Insurance         = getInput("Insurance");        
    monthOfExpenses->Entertainment     = getInput("Entertainment");    
    monthOfExpenses->Clothing          = getInput("Clothing");            
    monthOfExpenses->Miscellaneous     = getInput("Miscellaneous");        
}

/************************************************************************
*            getInput
*                 
* Purpose       :  The purpose is that to get expenses of sub categories
*                   from the user. It also does a data validation.
* Pre-condition :  None.
*
* Post-condition: Returns entered data the calling function if data is
                    validated.
*
************************************************************************/
float getInput( string  category)
{
    float userInput = 0;
    do
    {
        cout<<"Enter amount of money for "<<category<<":";
        cin>>userInput;

        if(userInput < 0)
        {
            cout<<category<<" cannot be less than 0"<<endl;
        }

    }while(userInput < 0);

    return userInput;

}
/************************************************************************
*            grandTotal
*                 
* Purpose       : The purpose is that calculate total difference between
                    referenceBudget and monthOfExpenses
*                    
* Pre-condition : referenceBudget and monthOfExpenses already initialized
                  compareCategory category function is defined.
*
* Post-condition: Total difference is calculated. 
*
************************************************************************/
void grandTotal(Budget * referenceBudget, Budget * monthOfExpenses)
{
    const float     zero  = 0;
          float total  = 0; 
    

    
    total += compareCategory(referenceBudget->Housing, 
                             monthOfExpenses->Housing, "Housing");
    
    total += compareCategory(referenceBudget->Utilities,
                             monthOfExpenses->Utilities, "Utilities");

    total += compareCategory(referenceBudget->HouseholdExpense, 
                             monthOfExpenses->HouseholdExpense, 
                             "HouseholdExpense");
    
    total += compareCategory(referenceBudget->Transportation, 
                             monthOfExpenses->Transportation,
                             "Transportation");

    total += compareCategory(referenceBudget->Food, 
                             monthOfExpenses->Food,"Food");

    total += compareCategory(referenceBudget->Medical, 
                             monthOfExpenses->Medical,"Medical");
    
    total += compareCategory(referenceBudget->Insurance, 
                             monthOfExpenses->Insurance,"Insurance");
    
    total += compareCategory(referenceBudget->Entertainment, 
                             monthOfExpenses->Entertainment,
                             "Entertainment");
    
    total += compareCategory(referenceBudget->Clothing, 
                             monthOfExpenses->Clothing,"Clothing");

    total += compareCategory(referenceBudget->Miscellaneous, 
                             monthOfExpenses->Miscellaneous,
                             "Miscellaneous");


    total = compareCategory(total,zero,"Total");
    
}

/************************************************************************
*            compareCategory
*                 
* Purpose        : The purpose is that to take 2 same kinds of sub 
                  categories from monthOfExpenses and referenceBudget
                  then estimates differences between them. After 
                  estimation it prompts the user this difference.
*                    
* Pre-condition    : referenceBudgetCategory and monthOfExpensesCategory 
                   has been initialized.
*
* Post-condition: if( referenceBudgetCategory is greater than
                      monthOfExpensesCategory)
                        
                        print Your "category" budget is
                              "referenceBudgetCategory" - 
                              "monthOfExpensesCategory"
                              more than "category" expense.
        
                        return referenceBudgetCategory - 
                               monthOfExpensesCategory
                               
                   if( referenceBudgetCategory is equal 
                      monthOfExpensesCategory)
                    
                        print Your "category" budget is equal 
                        your "category" 
                        
                        return 0
                            
                  if( referenceBudgetCategory is smaller than
                      monthOfExpensesCategory)
                        
                        print Your "category" budget is
                              "referenceBudgetCategory" - 
                              "monthOfExpensesCategory"
                              less than "category" expense.
                        
                        return referenceBudgetCategory - 
                               monthOfExpensesCategory
                        
************************************************************************/    
float compareCategory(float  referenceBudgetCategory, 
                      float monthOfExpensesCategory, 
                      string category)
{
    cout<<endl;

    if( referenceBudgetCategory > monthOfExpensesCategory)
    {
        cout<<"Your "<<category<<" budget is"<<setw(4)<<"$ "
        <<referenceBudgetCategory - monthOfExpensesCategory<<
        " more than "<<category<<" expense"<<endl;

        return referenceBudgetCategory - monthOfExpensesCategory;
    }
    else if(referenceBudgetCategory == monthOfExpensesCategory)
    {
        cout<<"Your "<<category<<" budget is equal your "<<category<< 
        " expense"<<endl;

        return 0;
    }
    else
    {
    
        cout<<"Your "<<category<<" budget is"<<setw(4)<<" $ "
        <<monthOfExpensesCategory - referenceBudgetCategory<<
        " less than "<<category<<" expense"<<endl;
    
        return referenceBudgetCategory - monthOfExpensesCategory;
    }
}

