#include <iostream>
#include "RowColumnClass.h"
#include "constants.h"
using namespace std;

//Programmer: Youngjun Woo
//Date: November 4, 2021
//Purpose: RowColumnClass will be used as location information of 2d array.

RowColumnClass::RowColumnClass()
{
  setRowCol(DEFAULT_ROW_COLUMN_VALUE, DEFAULT_ROW_COLUMN_VALUE);
}
// This constructor simply sets both the row and column value of the newly
// created RowColumnClass object to 0.

RowColumnClass::RowColumnClass(int inRow, int inCol)
{
  setRowCol(inRow, inCol); 
}
// This constructor simply set the row and column values to the 
// corresponding values passed into the constructor.

void RowColumnClass::setRowCol(int inRow, int inCol)
{
  setRow(inRow);
  setCol(inCol);
}

void RowColumnClass::setRow(int inRow)
{
  rowIndex = inRow;
}

void RowColumnClass::setCol(int inCol)
{
  colIndex = inCol;
}

void RowColumnClass::setRowColFromUser(string purpose)
{
  bool validInputFound;
  int inRow;
  int inCol;

  validInputFound = false;
  while (!validInputFound)
  {
    cout << "Enter row and column you want for " << purpose << ": ";

    cin >> inRow >> inCol;
    if (cin.fail() or inRow < MIN_ROW_COLUMN_VALUE or 
        inCol < MIN_ROW_COLUMN_VALUE)
    {
      cin.clear();
      cin.ignore(200, '\n');

      cout << "ERROR: Invalid row and column. Row and column must be integer "
           << "greater(include) than " << MIN_ROW_COLUMN_VALUE << endl;
    }  
    
    else
    {
      validInputFound = true;
      setRowCol(inRow, inCol);
    }
  }  
}
// These functions simply set the appropriate attrubute(s) to the value(s)
// provided.

int RowColumnClass::getRow() const
{
  return rowIndex;
}

int RowColumnClass::getCol() const
{
  return colIndex;
}
// These functions just return the appropriate attribute value to the 
// caller.

void RowColumnClass::printRowCol() const
{
  cout << "[" << getRow() << "," << getCol() << "]";
}
// This function prints the object's attribute's in the format 
// "[<row>,<col>]" where <row> and <col> are replaced with the value of the
// corresponding attribute values.