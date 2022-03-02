#include <iostream>
#include "checkMenuNumber.h"
using namespace std;

//Programmer: Youngjun Woo
//Date: November 4, 2021
//Purpose: To check input menu number from user is in valid range(menu min ~ 
// menu max)

int checkMenuNumber(int menuMin, int menuMax)
{
  bool validInputFound;
  int menuNumber;

  validInputFound = false;

  while (!validInputFound)
  {
    cin >> menuNumber;

    if (cin.fail() or menuNumber < menuMin or menuNumber > menuMax)
    {
      cin.clear();
      cin.ignore(200, '\n');
      cout << "ERROR: Inavalid menu number. Menu number must be integer " 
           << "between " << menuMin << " and " << menuMax << endl;
      cout << "Enter int for menu choice: " ;
    } 

    else 
    {
      validInputFound = true;  
    }
  }

  return menuNumber;
}