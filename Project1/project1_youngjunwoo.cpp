#include <iostream>
using namespace std;

//Programmer: Youngjun Woo
//Date: September 17, 2021
//Purpose: To make functions that help users calculate amount of interest 
//         added each month and the balance change, based on balance amount
//         and the number of months that user input

const double MIN_INTEREST_RATE = 0.0015;
const double STD_INTEREST_RATE = 0.00225;
const double MAX_INTEREST_RATE = 0.004;

const double MIN_INTEREST_RATE_BALANCE = 1000.00; 
// Balance amount under this balance (exclusive) will be applied minimum 
// interest rate

const double MAX_INTEREST_RATE_BALANCE = 15000.00;
// Balance amount over this balance (inclusive) will be applied maxium 
// interest rate

bool accrueOneMonthsInterest(double &balanceAmt,
                             const bool doPrintInfo);
// Accrues interest for a single month, based on the specified balance amount.
// If doPrintInfo is flase, the function performs silently, but if true, 
// the amount of interest added for the month, along with the balance after 
// interest is accrued, will be printed.
// Returns true if the function was able to perform as expected, 
// or false otehrwise.

bool accrueInterest(double &balanceAmt, 
                    const int numMonths,
                    const bool doPrintEachMonth);
// Accrues interest over the specified number of months, based on the specified 
// balance amount.
// If doPrintEachMonth is flase, the function performs silently, but if true, 
// the amount of interest added each month, along with the balance after that 
// month, will be printed.
// Returns true if the function was able to perform as expected, 
// or false otehrwise.

#ifdef ANDREW_TEST 
#include "andrewTest.h" 
#else 
int main()
{
  double balanceAmt;
  int numMonths;
  char printOption;
  bool doPrintEachMonth;

  cout << "Enter the initial balance of the account : " ;
  cin >> balanceAmt;

  cout << "Enter the number of months to accrue interest : " ;
  cin >> numMonths;

  cout << "Show month-by-month results - 'y' for yes, any other for no : " ;
  cin >> printOption;

  if (printOption == 'y')
  {
    doPrintEachMonth = true; 
  }
  
  else 
  {
    doPrintEachMonth = false; 
  }

  accrueInterest(balanceAmt, numMonths, doPrintEachMonth);

}
#endif 

bool accrueOneMonthsInterest(double &balanceAmt,
                             const bool doPrintInfo)
{
  double interestRate;

  if (balanceAmt < 0)
  {
    cout << "ERROR in accrueOneMonthsInterest: balanceAmt must be >= 0, " <<
         "but the value " << balanceAmt << " was provided!" << endl;
    cout << "Sorry, an error was detected.  Unable to provide results!" 
         << endl;  

    return false;    
  }

  else
  {
    if (balanceAmt < MIN_INTEREST_RATE_BALANCE)
    {
      interestRate = MIN_INTEREST_RATE;
    }

    else if ( (MIN_INTEREST_RATE_BALANCE <= balanceAmt) 
             & (balanceAmt < MAX_INTEREST_RATE_BALANCE) )
    {
      interestRate = STD_INTEREST_RATE;
    }

    else if (MAX_INTEREST_RATE_BALANCE <= balanceAmt)
    {
      interestRate = MAX_INTEREST_RATE; 
    } 
    
    if (doPrintInfo)
    {
      cout << "Accruing interest for 1 month:" << endl;
      cout << "  " << "Initial balance: " << balanceAmt << endl;
      cout << "  " << "Initial rate: " << interestRate << endl;
      cout << "  " << "Interest accrued: " 
           << balanceAmt * interestRate << endl;
    
      balanceAmt = balanceAmt + balanceAmt * interestRate;
      cout << "  " << "New balance: " << balanceAmt << endl;  
    }

    else
    {
      balanceAmt = balanceAmt + balanceAmt * interestRate;  
    }

    return true;
  }
}

bool accrueInterest(double &balanceAmt, 
                    const int numMonths,
                    const bool doPrintEachMonth)
{
  double initialBalanceAmt;

  initialBalanceAmt = balanceAmt;

  if (balanceAmt < 0)
  {
    return accrueOneMonthsInterest(balanceAmt, doPrintEachMonth);
  }

  else if (numMonths <= 0)
  {
    cout << "ERROR in accrueInterest: numMonths must be > 0, but the value "
         << numMonths << " was provided!" << endl;
    cout << "Sorry, an error was detected.  Unable to provide results!" 
         << endl; 

    return false;
  }

  else
  {
    for (int i = 1; i <= numMonths; i++)
    {  
      accrueOneMonthsInterest(balanceAmt, doPrintEachMonth);
    }

    cout << "Interest accrued for "<< numMonths << " months!" << endl;
    cout << endl;
    cout << "Initial balance: " << initialBalanceAmt << endl;
    cout << "Total interest accrued: " 
         << balanceAmt - initialBalanceAmt << endl;
    cout << "Final balance: " << balanceAmt << endl;

    return true;
  }
}

