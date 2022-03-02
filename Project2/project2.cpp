#include <iostream>
using namespace std;

//Programmer: Youngjun Woo
//Date: October 11, 2021
//Purpose: To develope some classes to represent and utilize colors and images
      
//// << Declarations & Initializations >> ////
const int MIN_RGB_AMOUNT = 0;
const int MAX_RGB_AMOUNT = 1000;
// RGB values have values between 0 and 1000.

const int IMAGE_ROW_SIZE = 10;
const int IMAGE_COL_SIZE = 18;
// We consider that our images are the form of 2D array with 10 rows and 
// 18 columns. 

const int DEFAULT_ROW_COLUMN_VALUE = -99999;
// RowColumnClass set the row and column values to -99999 by default.

//// << Global Function Prototypes >> ////
int clipRgbAmount(int inRgbAmount);
// If input RGB value is outside the valid range, it is clipped to be within
// the valid range by this clipRgbAmount function. Clipping is done such that
// a requested color value less than the allowed minimum is clipped to the 
// minimum, while color values higher than the allowed maximum are clipped
// to the maximum.

bool checkIsClipped(int inRgbAmount);
// This function check whether the input RGB value is outside the valid range
// or not. If the input RGB value is outside the valid range, then return true,
// otherwise return false. 

//// <<< Class Definitions >>> ////
class ColorClass
{
  public:
    ColorClass();
    // This constructor set the color's initial RGB values to the color full
    // white (r = 1000, g = 1000, b = 1000).

    ColorClass(int inRed, int inGreen, int inBlue);
    // This constructor set the color's initial RGB values to the value
    // provided. If a specified color value is outside the valid range, it will
    // be clipped to ensure all ColorClass attributes are always set to be 
    // within the valid range.
    
    void setToBlack();
    // Set the color's RGB values to the black color.
    // (r = 0 , g = 0, b = 0)

    void setToRed();
    // Set the color's RGB values to the red color.
    // (r = 1000 , g = 0, b = 0)

    void setToGreen();
    // Set the color's RGB values to the green color.
    // (r = 0 , g = 1000, b = 0)

    void setToBlue();
    // Set the color's RGB values to the blue color.
    // (r = 0 , g = 0, b = 1000)

    void setToWhite();
    // Set the color's RGB values to the white color.
    // (r = 1000 , g = 1000, b = 1000)

    bool setTo(int inRed, int inGreen, int inBlue);
    // Set the color's RGB values to the provided values. If any clipping was
    // necessary, the function returns true, otherwise the function returns 
    // false.

    bool setTo(ColorClass &inColor);
    // Set the color's RGB values to the same as those in the "inColor" input
    // parameter. If any clipping was necessary, the function returns true, 
    // otherwise the function returns false.

    bool addColor(ColorClass &rhs);
    // This function causes each RGB value to have the corresponding value from
    // the input parameter color added to it. If any resulting color value 
    // would end up outside the valid color value range, the value is "clipped" 
    // in order to keep the RGB color values within the valid range. If any 
    // clipping was necessary, the function returns true, otherwise the 
    // function returns false.

    bool subtractColor(ColorClass &rhs);
    // This function causes each RGB value to have the corresponding value from
    // the input parameter subtracted from it. If any resulting color value 
    // would end up outside the valid color value range, the value is "clipped" 
    // in order to keep the RGB color values within the valid range. If any 
    // clipping was necessary, the function returns true, otherwise the 
    // function returns false.

    bool adjustBrightness(double adjFactor);
    // This function performs a simplified brightness adjustment which 
    // multiplies each RGB value by the adjustment factor provided. 
    // If adjFactor is greater than 1, the color gets brighter, if adjFactor is 
    // less than 1, the color gets dimmer. If any resulting color value 
    // would end up outside the valid color value range, the value is "clipped" 
    // in order to keep the RGB color values within the valid range. If any 
    // clipping was necessary, the function returns true, otherwise the 
    // function returns false.

    void printComponentValues() const;
    // Prints the component color values to the console using the following 
    // format: "R: <red> G: <green> B: <blue>" where <red>, <green>, and <blue> 
    // are all replaced with their corresponding component color values. 
    
  private:
    int redAmount;
    int greenAmount;
    int blueAmount;
};

class RowColumnClass
{
  public:
    RowColumnClass();
    // This constructor simply sets both the row and column value of the newly
    // created RowColumnClass object to -99999.

    RowColumnClass(int inRow, int inCol);
    // This constructor simply set the row and column values to the 
    // corresponding values passed into the constructor.

    void setRowCol(int inRow, int inCol);
    void setRow(int inRow);
    void setCol(int inCol);
    // These functions simply set the appropriate attrubute(s) to the value(s)
    // provided.

    int getRow();
    int getCol();
    // These functions just return the appropriate attribute value to the 
    // caller.

    void addRowColTo(RowColumnClass &inRowCol);
    // This function adds the row and column index values in the input 
    // parameter to the row and column index of the object the function is 
    // called on.

    void printRowCol();
    // This function prints the object's attribute's in the format 
    // "[<row>,<col>]" where <row> and <col> are replaced with the value of the
    // corresponding attribute values.

  private:
    int rowIndex;
    int colIndex;
};

class ColorImageClass
{ 
  public:
    ColorImageClass();
    // This constructor simply sets all pixels in the image to full black.

    void initializeTo(ColorClass &inColor);
    // This function initializes all image pixels to the color provided via 
    // input.

    bool addImageTo(ColorImageClass &rhsImg);
    // This function performs a pixel-wise addition, such that each pixel in 
    // the image has the pixel in the corresponding location in the right 
    // hand side input image added to it. If the result of one or more of the
    // pixel additions required color value clipping, this function returns
    // true, otherwise it returns false.

    bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd[]);
    // This function causes the image's pixel values to be set to the sum of
    // the corresponding pixels in each image in the imagesToAdd input 
    // parameter. If the result of one or more of the pixel additions required 
    // color value clipping, this function returns true, otherwise it returns 
    // false.

    bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor);
    // This function attemps to set the pixel at the location specified by the
    // inRowCol parameter to the color specified via the inColor parameter. 
    // If the location specified is a valid location for the image, the pixel 
    // value is changed and the function returns true, otherwise the image is 
    // not modified in ANY way, and the function returns false.

    bool getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor);
    // If the row/column provided is a valid row/column for the image, this 
    // function returns true and the output parameter "outColor" is assigned 
    // to the color of the image pixel at that location. If the row/column is 
    // invalid (i.e. outside the image bounds) then the function returns false, 
    // and the output parameter "outColor" is not modified in any way.

    void printImage();
    // This function prints the contents of the image to the screen. Each pixel 
    // is printed using the format described for the ColorClass above. 
    // The image is printed one row of pixels per line. Between each pixel in 
    // a row, "--" are printed.

  private:
    ColorClass colorImage[IMAGE_ROW_SIZE][IMAGE_COL_SIZE];
};


#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main()
{
  ColorClass testColor;
  RowColumnClass testRowCol;
  RowColumnClass testRowColOther(111, 222);
  ColorImageClass testImage;
  ColorImageClass testImages[3];
  
  //Test some basic ColorClass operations...
  cout << "Initial: ";
  testColor.printComponentValues();
  cout << endl;

  testColor.setToBlack();
  cout << "Black: ";
  testColor.printComponentValues();
  cout << endl;

  testColor.setToGreen();
  cout << "Green: ";
  testColor.printComponentValues();
  cout << endl;

  testColor.adjustBrightness(0.5);
  cout << "Dimmer Green: ";
  testColor.printComponentValues();
  cout << endl;

  //Test some basic RowColumnClass operations...
  cout << "Want defaults: ";
  testRowCol.printRowCol();
  cout << endl;

  testRowCol.setRowCol(2, 8);
  cout << "Want 2,8: ";
  testRowCol.printRowCol();
  cout << endl;

  cout << "Want 111, 222: ";
  testRowColOther.printRowCol();
  cout << endl;

  testRowColOther.setRowCol(4, 2);
  testRowCol.addRowColTo(testRowColOther);
  cout << "Want 6,10: ";
  testRowCol.printRowCol();
  cout << endl;

  //Test some basic ColorImageClass operations...
  testColor.setToRed();
  testImage.initializeTo(testColor);
  testRowCol.setRowCol(555, 5);
  cout << "Want: Color at [555,5]: Invalid Index!" << endl;
  cout << "Color at ";
  testRowCol.printRowCol();
  cout << ": ";
  if (testImage.getColorAtLocation(testRowCol, testColor))
  {
    testColor.printComponentValues();
  }
  else
  {
    cout << "Invalid Index!";
  }
  cout << endl;

  testRowCol.setRow(4);
  cout << "Want: Color at [4,5]: R: 1000 G: 0 B: 0" << endl;
  cout << "Color at ";
  testRowCol.printRowCol();
  cout << ": ";
  if (testImage.getColorAtLocation(testRowCol, testColor))
  {
    testColor.printComponentValues();
  }
  else
  {
    cout << "Invalid Index!";
  }
  cout << endl;

  //Set up an array of images of different colors
  testColor.setToRed();
  testColor.adjustBrightness(0.25);
  testImages[0].initializeTo(testColor);
  testColor.setToBlue();
  testColor.adjustBrightness(0.75);
  testImages[1].initializeTo(testColor);
  testColor.setToGreen();
  testImages[2].initializeTo(testColor);

  //Modify a few individual pixel colors
  testRowCol.setRowCol(4, 2);
  testColor.setToWhite();
  testImages[1].setColorAtLocation(testRowCol, testColor);
  testRowCol.setRowCol(2, 4);
  testColor.setToBlack();
  testImages[2].setColorAtLocation(testRowCol, testColor);

  //Add up all images in testImages array and assign result
  //to the testImage image
  testImage.addImages(3, testImages);

  //Check some certain values
  cout << "Added values:" << endl;
  for (int colInd = 0; colInd < 8; colInd += 2)
  {
    testRowCol.setRowCol(4, colInd);
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
      testColor.printComponentValues();
    }
    else
    {
      cout << "Invalid Index!";
    }
    cout << endl;
  }

  for (int rowInd = 0; rowInd < 8; rowInd += 2)
  {
    testRowCol.setRowCol(rowInd, 4);
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
      testColor.printComponentValues();
    }
    else
    {
      cout << "Invalid Index!";
    }
    cout << endl;
  }

  cout << "Printing entire test image:" << endl;
  testImage.printImage();
  
  return 0;
}
#endif

//// << Global Function Definitions >> ////
int clipRgbAmount(int inRgbAmount)
{
  if (inRgbAmount < MIN_RGB_AMOUNT)
  {
    return MIN_RGB_AMOUNT;
  }

  else if (inRgbAmount > MAX_RGB_AMOUNT)
  {
    return MAX_RGB_AMOUNT;
  }

  else
  {
    return inRgbAmount;
  }
}

bool checkIsClipped(int inRgbAmount)
{
  if (inRgbAmount < MIN_RGB_AMOUNT)
  {
    return true;
  }

  else if (inRgbAmount > MAX_RGB_AMOUNT)
  {
    return true;
  }

  else
  {
    return false;
  }
}

//// << Class Method Definitions >> ////

// ColorClass //
ColorClass::ColorClass()
{
  setToWhite();
}

ColorClass::ColorClass(int inRed, int inGreen, int inBlue)
{
  setTo(clipRgbAmount(inRed), clipRgbAmount(inGreen), clipRgbAmount(inBlue));
}

void ColorClass::setToBlack()
{
  setTo(MIN_RGB_AMOUNT, MIN_RGB_AMOUNT, MIN_RGB_AMOUNT);
}

void ColorClass::setToRed()
{
  setTo(MAX_RGB_AMOUNT, MIN_RGB_AMOUNT, MIN_RGB_AMOUNT);
}

void ColorClass::setToGreen()
{
  setTo(MIN_RGB_AMOUNT, MAX_RGB_AMOUNT, MIN_RGB_AMOUNT);
}

void ColorClass::setToBlue()
{
  setTo(MIN_RGB_AMOUNT, MIN_RGB_AMOUNT, MAX_RGB_AMOUNT);
}

void ColorClass::setToWhite()
{
  setTo(MAX_RGB_AMOUNT, MAX_RGB_AMOUNT, MAX_RGB_AMOUNT);
}

bool ColorClass::setTo(int inRed, int inGreen, int inBlue)
{ 
  bool isClipped;

  isClipped = checkIsClipped(inRed) or checkIsClipped(inGreen) 
              or checkIsClipped(inBlue);

  redAmount = clipRgbAmount(inRed);
  greenAmount = clipRgbAmount(inGreen);
  blueAmount = clipRgbAmount(inBlue);
  
  return isClipped;
}

bool ColorClass::setTo(ColorClass &inColor)
{
  bool isClipped;

  isClipped = checkIsClipped(inColor.redAmount) 
              or checkIsClipped(inColor.greenAmount) 
              or checkIsClipped(inColor.blueAmount);
  
  setTo(clipRgbAmount(inColor.redAmount), clipRgbAmount(inColor.greenAmount), 
        clipRgbAmount(inColor.blueAmount));
  
  return isClipped;
}

bool ColorClass::addColor(ColorClass &rhs)
{
  bool isClipped;

  isClipped = checkIsClipped(redAmount + rhs.redAmount) 
              or checkIsClipped(greenAmount + rhs.greenAmount) 
              or checkIsClipped(blueAmount + rhs.blueAmount);  
  
  setTo(clipRgbAmount(redAmount + rhs.redAmount), 
        clipRgbAmount(greenAmount + rhs.greenAmount),
        clipRgbAmount(blueAmount + rhs.blueAmount));

  return isClipped;
}

bool ColorClass::subtractColor(ColorClass &rhs)
{
  bool isClipped;

  isClipped = checkIsClipped(redAmount - rhs.redAmount) 
              or checkIsClipped(greenAmount - rhs.greenAmount) 
              or checkIsClipped(blueAmount - rhs.blueAmount);
  
  setTo(clipRgbAmount(redAmount - rhs.redAmount), 
        clipRgbAmount(greenAmount - rhs.greenAmount),
        clipRgbAmount(blueAmount - rhs.blueAmount));
  
  return isClipped;
}

bool ColorClass::adjustBrightness(double adjFactor)
{
  bool isClipped;

  isClipped = checkIsClipped(redAmount * adjFactor) 
              or checkIsClipped(greenAmount * adjFactor) 
              or checkIsClipped(blueAmount * adjFactor);  
  
  setTo(clipRgbAmount(redAmount * adjFactor), 
        clipRgbAmount(greenAmount * adjFactor),
        clipRgbAmount(blueAmount * adjFactor));

  return isClipped;
}

void ColorClass::printComponentValues() const
{
  cout << "R:" << redAmount << " G:" << greenAmount << " B:" << blueAmount;
}

// RowColumnClass //
RowColumnClass::RowColumnClass()
{
  setRowCol(DEFAULT_ROW_COLUMN_VALUE, DEFAULT_ROW_COLUMN_VALUE);
}

RowColumnClass::RowColumnClass(int inRow, int inCol)
{
  setRowCol(inRow, inCol); 
}

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

int RowColumnClass::getRow()
{
  return rowIndex;
}

int RowColumnClass::getCol()
{
  return colIndex;
}

void RowColumnClass::printRowCol()
{
  cout << "[" << getRow() << "," << getCol() << "]";
}

void RowColumnClass::addRowColTo(RowColumnClass &inRowCol)
{
  setRowCol(rowIndex + inRowCol.getRow(), colIndex + inRowCol.getCol());
}

// ColorImageClass // 
ColorImageClass::ColorImageClass()
{
  ColorClass blackColor;

  blackColor.setToBlack();
  initializeTo(blackColor);
}

void ColorImageClass::initializeTo(ColorClass &inColor)
{
  
  for (int i = 0; i < IMAGE_ROW_SIZE; i++)
  {
    for (int j = 0; j < IMAGE_COL_SIZE; j++)
    {
      colorImage[i][j].setTo(inColor);
    }
  }   
}

bool ColorImageClass::addImageTo(ColorImageClass &rhsImg)
{
  bool isClipped;

  for (int i = 0; i < IMAGE_ROW_SIZE; i++)
  {
    for (int j = 0; j < IMAGE_COL_SIZE; j++)
    {
      isClipped += colorImage[i][j].addColor(rhsImg.colorImage[i][j]);
    }    
  }  

  return isClipped;
}

bool ColorImageClass::addImages(int numImgsToAdd, ColorImageClass imagesToAdd[])
{
  ColorImageClass resultArray;
  bool isClipped;  
  
  for (int k = 0; k < numImgsToAdd; k++)
  {
    isClipped += resultArray.addImageTo(imagesToAdd[k]);
  }

  for (int i = 0; i < IMAGE_ROW_SIZE; i++)
  {
    for (int j = 0; j < IMAGE_COL_SIZE; j++)
    {
      colorImage[i][j].setTo(resultArray.colorImage[i][j]);
    }
  }

  return isClipped;
}

bool ColorImageClass::setColorAtLocation(RowColumnClass &inRowCol, 
                                         ColorClass &inColor)
{
  if (inRowCol.getRow() >= 0 and
      inRowCol.getRow() <= IMAGE_ROW_SIZE -1 and
      inRowCol.getCol() >= 0 and
      inRowCol.getCol() <= IMAGE_COL_SIZE -1)
  {
    colorImage[inRowCol.getRow()][inRowCol.getCol()].setTo(inColor);  
    
    return true; 
  }

  else
  {
    return false;
  }
}

bool ColorImageClass::getColorAtLocation(RowColumnClass &inRowCol, 
                                         ColorClass &outColor)
{
  if (inRowCol.getRow() >= 0 and
      inRowCol.getRow() <= IMAGE_ROW_SIZE - 1 and
      inRowCol.getCol() >= 0 and
      inRowCol.getCol() <= IMAGE_COL_SIZE - 1)
  {
    outColor = colorImage[inRowCol.getRow()][inRowCol.getCol()];

    return true;
  }

  else
  {
    return false;
  }
}

void ColorImageClass::printImage()
{
  for (int i = 0; i < IMAGE_ROW_SIZE; i++)
  {
    colorImage[i][0].printComponentValues();
    for (int j = 1; j < IMAGE_COL_SIZE; j++)
    {
      cout << "--" ;
      colorImage[i][j].printComponentValues();
    }
    cout << endl;  
  }
}