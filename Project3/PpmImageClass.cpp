#include <iostream>
#include <fstream>
#include "PpmImageClass.h"
#include "constants.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"
#include "PaternClass.h"
using namespace std;

// -----Resubmission change
// - Put all global functions that was related to image class into 
//   PpmImageClass methods.
//   ex) readImageFile, saveImageFile, annotateRectangle, insertImage,
//       annotatePattern ...
// - save image file by ColorClass.write() method. 

//Programmer: Youngjun Woo
//Date: November 4, 2021
//Purpose: PpmImageClass is 2d array consist of ColorClass.

bool PpmImageClass::readImageFile(string inFileName)
{
  ifstream inFile;
  bool isSuccess;
  
  inFile.open(inFileName.c_str());
  if (inFile.fail())
  {
    cout << "ERROR: Unable to open input image file! " 
         << "Please check your direction."
         << endl;

    inFile.close();
    return false;
  }

  isSuccess = readMagicNumber(inFile);
  if (isSuccess == false)
  {
    inFile.close();  
    return false;    
  }

  else
  {
    isSuccess = readImageSize(inFile);
    if (isSuccess == false)
    {
      inFile.close();  
      return false;    
    }

    else
    {
      isSuccess = readImageMaxValue(inFile);
      if (isSuccess == false)
      {
        inFile.close();  
        return false;    
      }

      else
      {
        isSuccess = readImageMatrix(inFile);
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
  }
}
// This will read Ppm image file and initialize attributes of image.

void PpmImageClass::setMagicNumberTo(string inMagicNumber)
{
  magicNumber = inMagicNumber;    
}
// It will set magic number as input values.

void PpmImageClass::setWidthTo(int inWidth)
{
  width = inWidth;     
}
// It will set image width values as input values.

void PpmImageClass::setHeightTo(int inHeight)
{
  height = inHeight;     
}
// It will set image height values as input values.

void PpmImageClass::setMaxValueTo(int inMaxValue)
{
  maxValue = inMaxValue;     
}
// It will set image max values as input values.

bool PpmImageClass::setColorAtLocation(RowColumnClass &inRowCol, 
                                       ColorClass &inColor)
{
  if (inRowCol.getRow() >= 0 and
      inRowCol.getRow() <= height - 1 and
      inRowCol.getCol() >= 0 and
      inRowCol.getCol() <= width - 1)
  {
    matrixValue[inRowCol.getRow()][inRowCol.getCol()].setTo(inColor);  
    
    return true; 
  }

  else
  {
    return false;
  }
}
// This function attemps to set the pixel at the location specified by the
// inRowCol parameter to the color specified via the inColor parameter. 
// If the location specified is a valid location for the image, the pixel 
// value is changed and the function returns true, otherwise the image is 
// not modified in ANY way, and the function returns false.

string PpmImageClass::getMagicNumber() const
{
  return magicNumber;    
}
// It will get magic number of image.

int PpmImageClass::getWidth() const
{
  return width;    
}
// It will get width of image.

int PpmImageClass::getHeight() const
{
  return height;    
}
// It will get height of image.

int PpmImageClass::getMaxValue() const
{
  return maxValue;    
}
// It will get max value of image.

bool PpmImageClass::getColorAtLocation(RowColumnClass &inRowCol, 
                                       ColorClass &outColor) const
{
  if (inRowCol.getRow() >= 0 and
      inRowCol.getRow() <= height - 1 and
      inRowCol.getCol() >= 0 and
      inRowCol.getCol() <= width - 1)
  {
    outColor = matrixValue[inRowCol.getRow()][inRowCol.getCol()];

    return true;
  }

  else
  {
    return false;
  }
}
// If the row/column provided is a valid row/column for the image, this 
// function returns true and the output parameter "outColor" is assigned 
// to the color of the image pixel at that location. If the row/column is 
// invalid (i.e. outside the image bounds) then the function returns false, 
// and the output parameter "outColor" is not modified in any way.

void PpmImageClass::printHeaderValues() const
{
  cout << "PPM image header information" << endl;
  cout << "  Image magic number: " << getMagicNumber() << endl;
  cout << "  Image width: " << getWidth() << endl;
  cout << "  Image height: " << getHeight() << endl;
  cout << "  Image maxValue: " << getMaxValue() << endl;
}
// It prints image header values: magic number, width, height, max value.

void PpmImageClass::printMatrixValues() const
{
  cout << "PPM image matrix values" << endl;  
  for (int rInd = 0; rInd < height; rInd++)
  {
    matrixValue[rInd][0].printComponentValues();
    
    for (int cInd = 1; cInd < width; cInd++)
    {
      cout << "--" ;
      matrixValue[rInd][cInd].printComponentValues();
    }
    
    cout << endl;  
  }
}
// It will pring image matrix values.

bool PpmImageClass::readMagicNumber(ifstream &inFile)
{
  string headerVal;

  inFile >> headerVal;

  if (headerVal == "")
  {
    cout << "ERROR: EOF before read PPM header values." << endl;

    return false;    
  }

  else if (headerVal != PPM_IMAGE_MAGIC_NUMBER or inFile.fail())
  {
    cout << "ERROR: Invalid ppm image magic number. It must be "
         << PPM_IMAGE_MAGIC_NUMBER << ", but found " << headerVal << endl;

    return false;     
  }
  
  else
  {
    setMagicNumberTo(headerVal);

    return true;
  }
}
// It will read magic number of ppm image file.

bool PpmImageClass::readImageSize(ifstream &inFile)
{
  int headerVal;
  int *imageSizeArray;

  imageSizeArray = new int[PPM_IMAGE_SIZE_VALUE_COUNT];

  for (int i = 0; i < PPM_IMAGE_SIZE_VALUE_COUNT; i++)
  {
    if (inFile.eof())
    {
      cout << "ERROR: EOF before read PPM header values." << endl;
      
      delete [] imageSizeArray; 
      imageSizeArray = 0;
      return false;
    }

    else
    {
      inFile >> headerVal;

      if (inFile.fail() or headerVal <= MIN_PPM_IMAGE_SIZE_VALUE)
      {
        cout << "ERROR: Invalid image size. They must be integer value greater"
             << " than " << MIN_PPM_IMAGE_SIZE_VALUE << endl;         
        
        delete [] imageSizeArray; 
        imageSizeArray = 0;
        return false;
      }  

      else
      {
        imageSizeArray[i] = headerVal;
      }
    }
  }

  setWidthTo(imageSizeArray[0]);
  setHeightTo(imageSizeArray[1]);  
  
  delete [] imageSizeArray; 
  imageSizeArray = 0;
  return true;  
}
// It will read width and height from ppm image file.

bool PpmImageClass::readImageMaxValue(ifstream &inFile)
{
  int headerVal;
  
  if (inFile.eof())
  {
    cout << "ERROR: EOF before read PPM header values." << endl;
    
    return false;
  }

  else
  {
    inFile >> headerVal;
    
    if (inFile.fail())
    {
      cout << "ERROR: Invalid image max value. It must be integer." << endl;       
      
      return false;
    }

    else if (headerVal != MAX_PPM_IMAGE_VALUE)
    {
      cout << "ERROR: Invalid image max value. It must be " 
           << MAX_PPM_IMAGE_VALUE << ", but found " << headerVal << endl;    
      
      return false;
    }

    else
    {
      setMaxValueTo(headerVal);

      return true;    
    }
  }
}
// It will read max value of ppm image file.

bool PpmImageClass::readImageMatrix(ifstream &inFile)
{
  int totalRgbValuesCount;
  int *rgbValuesArray;
  int rgbValue;
  string checkRemainingValues;
  int k;

  totalRgbValuesCount = width * height * 3;
  rgbValuesArray = new int[totalRgbValuesCount];
  
  // Read all matrix values and check errors
  for (int i = 0; i < totalRgbValuesCount; i++)
  {
    if (inFile.eof())
    {
      cout << "ERROR: EOF before read all PPM rgb matrix values." 
           << "Total rgb pixels are supposed to be " 
           << width << " x " << height 
           << ", but there are less rgb pixels in the file." << endl;    
       
      delete [] rgbValuesArray; 
      rgbValuesArray = 0;
      return false;
    }
 
    else 
    {
      inFile >> rgbValue;
 
      if (inFile.fail() or rgbValue < MIN_PPM_IMAGE_VALUE or 
          rgbValue > MAX_PPM_IMAGE_VALUE)
      {
        cout << "ERROR: Invalid rgb values." 
             << "They must be integer value between "
             << MIN_PPM_IMAGE_VALUE << " and " 
             << MAX_PPM_IMAGE_VALUE << "." << endl;  
  
        delete [] rgbValuesArray; 
        rgbValuesArray = 0;
        return false;     
      }
 
      else 
      {
        rgbValuesArray[i] = rgbValue;     
      }
    }
  }    
  
  inFile >> checkRemainingValues;

  if (checkRemainingValues != "")
  {
    cout << "ERROR: There are more rgb values than expected." << endl;  
    
    delete [] rgbValuesArray; 
    rgbValuesArray = 0;
    return false;
  }

  else
  {
    matrixValue = new ColorClass*[height];

    for (int rInd = 0; rInd < height; rInd++)
    {
      matrixValue[rInd] = new ColorClass[width];    
    }    

    k = 0;
    for (int rInd = 0; rInd < height; rInd++)
    {
      for (int cInd = 0; cInd < width; cInd++)
      {
        matrixValue[rInd][cInd] = ColorClass(rgbValuesArray[k], 
                                             rgbValuesArray[k + 1],
                                             rgbValuesArray[k + 2]); 

        k = k + 3;  
      }    
    }

    delete [] rgbValuesArray; 
    rgbValuesArray = 0;
    return true;
  }
}
// It will read matrix values of ppm image file.

void PpmImageClass::saveImageFile() const
{
  ofstream outFile;
  string outFileName;
  bool validInputFound;

  validInputFound = false;
  while (!validInputFound)
  {
    cout << "Enter string for PPM file name to output: ";  
    
    cin >> outFileName;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(200, '\n');

      cout << "ERROR: Error found in file name. Try again! " << endl;
    }

    else
    {
      outFile.open(outFileName.c_str());  
      if (outFile.fail())
      {
        cout << "ERROR: Unable to open output file" << endl;
        outFile.close();
      }    

      else
      {
        outFile << magicNumber << endl;
        outFile << width << " " << height << endl;
        outFile << maxValue << endl;

        for (int rInd = 0; rInd < height; rInd++)
        {
          for (int cInd = 0; cInd < width; cInd++)
          {
            matrixValue[rInd][cInd].writeRgbValue(outFile);   
          }    

          outFile << endl;
        }

        outFile.close();

        validInputFound = true;
      }
    }
  }
}  
// It will save current image.

bool PpmImageClass::checkValidRowCol(RowColumnClass inRowCol) const
{
  if (inRowCol.getRow() > height - 1 or 
      inRowCol.getCol() > width - 1)
  {
    cout << "ERROR: (row, column) goes out of bounds of the original image." 
         << endl;
    cout << "  original image height: " << MIN_PPM_IMAGE_SIZE_VALUE 
         << " ~ " << getHeight() - 1 << endl;
    cout << "  original image width: " << MIN_PPM_IMAGE_SIZE_VALUE 
         << " ~ " << getWidth() - 1 << endl;     
    
    return false;    
  }

  else 
  {
    return true;    
  }
}
// It will check input inRowCol is under bound of current image.

bool PpmImageClass::annotateRectangle(RectangleClass inRectangle)
{
  RowColumnClass imageRowCol;
  ColorClass rectangleColor = inRectangle.getColor();
  int centerRow = inRectangle.getCenter().getRow();
  int centerCol = inRectangle.getCenter().getCol();
  int numOfHalfRow = inRectangle.getNumOfHalfRow();
  int numOfHalfCol = inRectangle.getNumOfHalfCol();
  

  if ((centerRow - numOfHalfRow) >= 0 and 
      (centerCol - numOfHalfCol) >= 0 and
      (centerRow + numOfHalfRow) <= height - 1 and
      (centerCol + numOfHalfCol) <= width - 1)
  {
    if (inRectangle.getIsFilled())
    {
      for (int rInd = centerRow - numOfHalfRow; 
           rInd <= centerRow + numOfHalfRow; 
           rInd++) 
      {
        for (int cInd = centerCol - numOfHalfCol;
             cInd <= centerCol + numOfHalfCol;
             cInd++)
        {
          imageRowCol.setRowCol(rInd, cInd);
          setColorAtLocation(imageRowCol, rectangleColor);  
        }       
      }
    }

    else
    {
      for (int rInd = centerRow - numOfHalfRow;
           rInd <= centerRow + numOfHalfRow;
           rInd++)
      {
        imageRowCol.setRowCol(rInd, centerCol - numOfHalfCol);
        setColorAtLocation(imageRowCol, rectangleColor);
        imageRowCol.setRowCol(rInd, centerCol + numOfHalfCol);
        setColorAtLocation(imageRowCol, rectangleColor);
      }

      for (int cInd = centerCol - numOfHalfCol;
           cInd <= centerCol + numOfHalfCol;
           cInd ++)
      {
        imageRowCol.setRowCol(centerRow - numOfHalfRow, cInd);
        setColorAtLocation(imageRowCol, rectangleColor);
        imageRowCol.setRowCol(centerRow + numOfHalfRow, cInd);  
        setColorAtLocation(imageRowCol, rectangleColor);
      }              
    }

    return true;
  }

  else 
  {
    cout << "ERROR: Your rectangle goes out of bounds of the original image." 
         << endl;   

    return false;       
  }     
}
// It will annotate input rectangle into current image

void PpmImageClass::insertImage(PpmImageClass inImage, RowColumnClass upperLeft,
                                ColorClass transparencyColor)
{
  RowColumnClass imageRowCol;
  ColorClass outColor;

  for (int rInd = 0; rInd < inImage.getHeight(); rInd++)
  {
    for (int cInd = 0; cInd < inImage.getWidth(); cInd++)
    {
      imageRowCol.setRowCol(rInd, cInd);
      inImage.getColorAtLocation(imageRowCol,outColor);

      if (outColor.getRedAmount() != transparencyColor.getRedAmount() or 
          outColor.getGreenAmount() != transparencyColor.getGreenAmount() or 
          outColor.getBlueAmount() != transparencyColor.getBlueAmount())
      {
        imageRowCol.setRowCol(rInd + upperLeft.getRow(), 
                              cInd + upperLeft.getCol());
        setColorAtLocation(imageRowCol, outColor);    
      }  
    }    
  }      
}
// It will insert input image into current image

void PpmImageClass::annotatePattern(PatternClass inPattern, 
                                    RowColumnClass upperLeft)
{
  RowColumnClass rowCol;
  ColorClass inPatternColor;
  int outPattern;

  inPatternColor = inPattern.getColor();

  for (int rInd = 0; rInd < inPattern.getNumRow(); rInd++)
  {
    for (int cInd = 0; cInd < inPattern.getNumCol(); cInd++)
    {
      rowCol.setRowCol(rInd, cInd);
      inPattern.getPatternAtLocation(rowCol, outPattern);

      if (outPattern == 1)
      {
        rowCol.setRowCol(rInd + upperLeft.getRow(), cInd + upperLeft.getCol());
        setColorAtLocation(rowCol, inPatternColor);    
      }    
    }    
  }
}
// It will annotate pattern into current image.