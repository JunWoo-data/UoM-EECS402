#include <iostream>
#include "calculateCenterAndHalfValues.h"
#include "constants.h"
#include "RowColumnClass.h"
using namespace std;

//Programmer: Youngjun Woo
//Date: November 4, 2021
//Purpose: Calculate rectangle center and number of half row and columns from 
// other rectangle location information. 

int * calculateCenterAndHalfValues(RowColumnClass upperLeft, 
                                   RowColumnClass lowerRight)
{
  int *resultArray;
  int centerRow;
  int centerCol;
  int numOfHalfRow;
  int numOfHalfCol;
  
  resultArray = new int[RECTANGLE_LOCATION_AND_SIZE_VALUES_COUNT];
   
  centerRow = (upperLeft.getRow() + lowerRight.getRow()) / 2;
  centerCol = (upperLeft.getCol() + lowerRight.getCol()) / 2;
  numOfHalfRow = centerRow - upperLeft.getRow();
  numOfHalfCol = lowerRight.getCol() - centerCol;
  
  resultArray[0] = centerRow;
  resultArray[1] = centerCol;
  resultArray[2] = numOfHalfRow;
  resultArray[3] = numOfHalfCol;

  return resultArray;
}

int * calculateCenterAndHalfValues(RowColumnClass upperLeft, int numOfRows, 
                                   int numOfCols)
{
  int *resultArray;
  int centerRow;
  int centerCol;
  int numOfHalfRow;
  int numOfHalfCol;

  resultArray = new int[RECTANGLE_LOCATION_AND_SIZE_VALUES_COUNT];

  centerRow = upperLeft.getRow() + (numOfRows / 2);
  centerCol = upperLeft.getCol() + (numOfCols / 2);
  numOfHalfRow = numOfRows / 2;
  numOfHalfCol = numOfCols / 2;

  resultArray[0] = centerRow;
  resultArray[1] = centerCol;
  resultArray[2] = numOfHalfRow;
  resultArray[3] = numOfHalfCol;

  return resultArray;
}