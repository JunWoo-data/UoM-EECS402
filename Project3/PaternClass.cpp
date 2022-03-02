#include <iostream>
#include <fstream>
#include "PaternClass.h"
#include "constants.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
using namespace std;

bool PatternClass::readPatternFile(string inFileName)
{
  ifstream inFile;
  bool isSuccess;

  inFile.open(inFileName.c_str());
  if (inFile.fail())
  {
    cout << "ERROR: Unable to open input pattern file! " 
         << "Please check your direction."
         << endl;

    inFile.close();
    return false;  
  }
  
  isSuccess = readPatternSize(inFile);
  if (isSuccess == false)
  {
    inFile.close();
    return false;    
  }

  else
  {
    isSuccess = readPatternMatrix(inFile);
    if (isSuccess == false)
    {
      inFile.close();
      return false;    
    }    

    else
    {
      inFile.close();
      return true;    
    }
  }
}
// This will read pattern file and initialize attributes of pattern.

void PatternClass::setNumColTo(int inNumCol)
{
  numCol = inNumCol;    
}
// It will set number of column values as input values.

void PatternClass::setNumRowTo(int inNumRow)
{
  numRow = inNumRow;    
}
// It will set number of row values as input values.

void PatternClass::setColorsToRed()
{
  patternColor.setToRed();
}
// It will set pattern color as red.

void PatternClass::setColorsToGreen()
{
  patternColor.setToGreen();
}
// It will set pattern color as green.

void PatternClass::setColorsToBlue()
{
  patternColor.setToBlue();  
}
// It will set pattern color as blue.

void PatternClass::setColorsToWhite()
{
  patternColor.setToWhite();
}
// It will set pattern color as white.

void PatternClass::setColorsToBlack()
{
  patternColor.setToBlack();
}
// It will set pattern color as black.

int PatternClass::getNumCol() const
{
  return numCol;    
}
// It will get number of column values of pattern.

int PatternClass::getNumRow() const
{
  return numRow;        
}
// It will get number of row values of pattern.

ColorClass PatternClass::getColor() const
{
  return patternColor;    
}
// It will get color of pattern.

int PatternClass::getPatternAtLocation(RowColumnClass &inRowCol, 
                                       int &outPattern) const
{
  if (inRowCol.getRow() >= 0 and
      inRowCol.getRow() <= numRow - 1 and
      inRowCol.getCol() >= 0 and
      inRowCol.getCol() <= numCol - 1)
  {
    outPattern = matrixValue[inRowCol.getRow()][inRowCol.getCol()];

    return true;
  }

  else
  {
    return false;
  }    
}
// It will get value of pattern matrix at input inRowCol location.

void PatternClass::printSize() const
{
  cout << "Pattern size information" << endl;
  cout << "  pattern number of rows: " << getNumRow() << endl;
  cout << "  pattern number of cols: " << getNumCol() << endl;   
}
// It will print pattern size related values: number of rows and columns. 

void PatternClass::printMatrix() const
{
  cout << "Pattern matrix values" << endl;  
  for (int rInd = 0; rInd < getNumRow(); rInd++)
  {
    for (int cInd = 0; cInd < getNumCol(); cInd++)
    {
      cout << matrixValue[rInd][cInd] << " ";    
    }

    cout << endl;    
  }
}
// It will print pattern matrix values.

bool PatternClass::readPatternSize(ifstream &inFile)
{
  int sizeVal;
  int *patternSizeArray;
  
  patternSizeArray = new int[PATTERN_SIZE_VALUE_COUNT];
  
  for (int i = 0; i < PATTERN_SIZE_VALUE_COUNT; i++)
  {
    if (inFile.eof())
    {
      cout << "ERROR: EOF before read pattern size values." << endl;
      
      delete [] patternSizeArray; 
      patternSizeArray = 0;
      return false;
    }

    else
    {
      inFile >> sizeVal;

      if (inFile.fail() or sizeVal <= MIN_PATTERN_SIZE_VALUE)
      {
        cout << "ERROR: Invalid pattern size. They must be integer value "
             << "greater than " << MIN_PATTERN_SIZE_VALUE << endl;         
        
        delete [] patternSizeArray; 
        patternSizeArray = 0;
        return false;
      }  

      else
      {
        patternSizeArray[i] = sizeVal;
      }
    }
  }

  setNumColTo(patternSizeArray[0]);
  setNumRowTo(patternSizeArray[1]);  
  
  delete [] patternSizeArray; 
  patternSizeArray = 0;
  return true;  
}
// It will read number of column and row values that appear in top of the 
// pattern file.

bool PatternClass::readPatternMatrix(ifstream &inFile)
{
  int totalPatternValuesCount;
  int *patternValueArray;
  int patternValue;
  string checkRemainingValues;
  int k;

  totalPatternValuesCount = numRow * numCol;
  patternValueArray = new int[totalPatternValuesCount];
  
  for (int i = 0; i < totalPatternValuesCount; i++)
  {
    if (inFile.eof())
    {
      cout << "ERROR: EOF before read all pattern matrix values." 
           << "Total pattern values are supposed to be " 
           << numRow << " x " << numCol 
           << ", but there are less pattern values in the file." << endl;    
       
      delete [] patternValueArray; 
      patternValueArray = 0;
      return false;
    }
 
    else 
    {
      inFile >> patternValue;
 
      if (inFile.fail() or patternValue < MIN_PATTERN_VALUE or 
          patternValue > MAX_PATTERN_VALUE)
      {
        cout << "ERROR: Invalid pattern values. They must be integer value "
             << "between " << MIN_PATTERN_VALUE << " and " 
             << MAX_PATTERN_VALUE << "." << endl;  
  
        delete [] patternValueArray; 
        patternValueArray = 0;
        return false;     
      }
 
      else 
      {
        patternValueArray[i] = patternValue;     
      }
    }
  }

  inFile >> checkRemainingValues;

  if (checkRemainingValues != "")
  {
    cout << "ERROR: There are more pattern values than expected." << endl;  
    
    delete [] patternValueArray; 
    patternValueArray = 0;
    return false;
  }

  else
  {
    matrixValue = new int*[numRow];

    for (int rInd = 0; rInd < numRow; rInd++)
    {
      matrixValue[rInd] = new int[numCol];    
    }    
    
    k = 0;
    for (int rInd = 0; rInd < numRow; rInd++)
    {
      for (int cInd = 0; cInd < numCol; cInd++)
      {
        matrixValue[rInd][cInd] = patternValueArray[k];
        k = k + 1;  
      }    
    }

    delete [] patternValueArray; 
    patternValueArray = 0;
    return true;
  }
}
// It will read pattern matrix values that appear after pattern size values.

 
