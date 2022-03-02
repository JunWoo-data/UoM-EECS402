#include <iostream>
#include "RectangleClass.h"
#include "constants.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "checkMenuNumber.h"
using namespace std;

//Programmer: Youngjun Woo
//Date: November 4, 2021
//Purpose: Rectangle class will be used when annotate image with rectangle.
// Rectangle can have 5 colors(red, green, blue, white, black), also can be 
// filled with that color or not. Also rectangle's size will be decided by 
// two numbers: number of half rows and columns.

RectangleClass::RectangleClass()
{
  RowColumnClass inCenter(MIN_ROW_COLUMN_VALUE, MIN_ROW_COLUMN_VALUE);
  setCenterTo(inCenter);
  setSizeTo(DEFAULT_RECTANGLE_SIZE_VALUE, DEFAULT_RECTANGLE_SIZE_VALUE);
  setColorsToWhite();
  setIsFilled(false);
}
// It will generate basic rectangle which have center as (0,0), number of 
// half row and column values as 0, white color, and not filled.

void RectangleClass::setCenterTo(RowColumnClass inCenter)
{
  center.setRowCol(inCenter.getRow(), inCenter.getCol()); 
}
// It will center of rectangle as input center.

void RectangleClass::setSizeTo(int inNumOfHalfRow, int inNumOfHalfCol)
{
  numOfHalfRow = inNumOfHalfRow;
  numOfHalfCol = inNumOfHalfCol;
}
// It will set center and number of half row and column values as input 
// values.

void RectangleClass::setSizeFromUser(string unit)
{
  bool validInputFound;
  int inRow;
  int inCol;
  
  if (unit != "half" and unit != "full")
  {
    cout << "ERROR: input string must be 'half' or 'full'.";  
  }

  else
  {
    validInputFound = false;
    while (!validInputFound)
    {
      cout << "Enter int for " << unit << " number of rows: ";
  
      cin >> inRow;
      if (cin.fail() or inRow < MIN_RECTANGLE_SIZE_VALUE)
      {
        cin.clear();
        cin.ignore(200, '\n');
  
        cout << "ERROR: Invalid " << unit << " number of rows" << endl;
        cout << "It must be integer greater(include) than "
             << MIN_RECTANGLE_SIZE_VALUE << endl;
      }
  
      else
      {
        validInputFound = true;  
      } 
    }
  
    validInputFound = false;
    while (!validInputFound)
    {
      cout << "Enter int for " << unit << " number of cols: ";
  
      cin >> inCol;
      if (cin.fail() or inCol < MIN_RECTANGLE_SIZE_VALUE)
      {
        cin.clear();
        cin.ignore(200, '\n');
  
        cout << "ERROR: Invalid " << unit << " number of cols" << endl;
        cout << "It must be integer greater(include) than "
             << MIN_RECTANGLE_SIZE_VALUE << endl;
      }
  
      else
      {
        validInputFound = true;  
      } 
    }

    if (unit == "half")
    {
      setSizeTo(inRow, inCol);  
    }
  
    else if (unit == "full")
    {
      setSizeTo(inRow/2, inCol/2);  
    }
  }
}
// It will set number of half row and column as input values from user.
// If unit = full, this means that input values are number of row and 
// number of columns, if unit = half, this means that input values are
// number of half row and number of half columns.

void RectangleClass::setColorsTo(int inRValue, int inGValue, int inBValue)
{
  rectangleColor.setTo(inRValue, inGValue, inBValue);       
}
// It will set rectangle color to input r, g, b values.

void RectangleClass::setColorsToRed()
{
  rectangleColor.setToRed();
}
// It will set rectangle color to red.

void RectangleClass::setColorsToGreen()
{
  rectangleColor.setToGreen();
}
// It will set rectangle color to green.

void RectangleClass::setColorsToBlue()
{
  rectangleColor.setToBlue();  
}
// It will set rectangle color to blue.

void RectangleClass::setColorsToWhite()
{
  rectangleColor.setToWhite();
}
// It will set rectangle color to white.

void RectangleClass::setColorsToBlack()
{
  rectangleColor.setToBlack();
}
// It will set rectangle color to black.

void RectangleClass::setIsFilled(bool inIsFilled)
{
  isFilled = inIsFilled;
}
// It will set rectangle filling option.

void RectangleClass::setIsFilledFromUser()
{
  int menuNumber;

  cout << "1. No" << endl;
  cout << "2. Yes" << endl;
  cout << "Enter int for rectangle fill option: "; 

  menuNumber = checkMenuNumber(MIN_RECTANGLE_FILL_MENU_NUMBER, 
                               MAX_RECTANGLE_FILL_MENU_NUMBER);  
  
  if (menuNumber == CHOICE_NO)
  {
    setIsFilled(false);  
  }  

  else if (menuNumber == CHOICE_YES)
  {
    setIsFilled(true);  
  }   
}
// It will set rectangle filling option as input value from user.

RowColumnClass RectangleClass::getCenter() const
{
  return center;  
} 
// It will get rectangle center.

int RectangleClass::getNumOfHalfRow() const
{
  return numOfHalfRow;    
}
// it will get number of half row value of rectangle.

int RectangleClass::getNumOfHalfCol() const
{
  return numOfHalfCol;    
}
// it will get number of half row value of rectangle.

ColorClass RectangleClass::getColor() const
{
  return rectangleColor;
}
// it will get color of rectangle.

bool RectangleClass::getIsFilled() const
{
  return isFilled;  
}
// it will get filling option of rectangle.

void RectangleClass::printRectangleValues() const
{
  cout << "Center: " << "(" << getCenter().getRow() << ", " 
       << getCenter().getCol() << ")" << endl;
  cout << "Number of half rows: " << getNumOfHalfRow() << endl;
  cout << "Number of half cols: " << getNumOfHalfCol() << endl;
  cout << "Color: " << endl;
  getColor().printComponentValues();
  cout << endl;
  cout << "isFilled: " << getIsFilled() << endl;
}
// it will print rectangle's all information.