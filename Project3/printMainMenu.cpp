#include <iostream>
#include "printMainMenu.h"
using namespace std;

//Programmer: Youngjun Woo
//Date: November 4, 2021
//Purpose: It will print basic main menu.

void printMainMenu()
{
  cout << "1. Annotate image with rectangle" << endl;
  cout << "2. Annotate image with pattern from file" << endl;
  cout << "3. Insert another image" << endl;
  cout << "4. Write out current image" << endl;
  cout << "5. Exit the program" << endl;
  cout << "Enter int for main menu choice: " ;
}