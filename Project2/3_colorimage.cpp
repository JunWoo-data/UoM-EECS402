#include <iostream>
#include "1_color.cpp"
#include "2_rowcolumn.cpp"
using namespace std;

const int IMAGE_ROW_SIZE = 2;
const int IMAGE_COL_SIZE = 3;

///// ColorImageClass /////
class ColorImageClass
{ 
  public:
    ColorImageClass();
    void initializeTo(ColorClass &inColor);
    bool addImageTo(ColorImageClass &rhsImg);
    bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd[]);
    bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor);
    bool getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor);
    void printImage();

  private:
    ColorClass colorImage[IMAGE_ROW_SIZE][IMAGE_COL_SIZE];
};

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


// int main() // final
// {
//   ColorClass testColor;
//   RowColumnClass testRowCol;
//   RowColumnClass testRowColOther(111,222);
//   ColorImageClass testImage;
//   ColorImageClass testImages[3];

//   testColor.setToRed();
//   testImage.initializeTo(testColor);
//   cout << "testImage: " << endl;
//   testImage.printImage();
//   cout << endl;

//   testRowCol.setRowCol(555,1);
//   cout << "Color at ";
//   testRowCol.printRowCol();
//   cout << ": ";
//   if (testImage.getColorAtLocation(testRowCol, testColor))
//   {
//     testColor.printComponentValues();
//   }
//   else
//   {
//     cout << "Invalid Index!";
//   }
//   cout << endl;

//   testRowCol.setRow(1);
//   cout << "Color at ";
//   testRowCol.printRowCol();
//   cout << ": ";
//   if (testImage.getColorAtLocation(testRowCol, testColor))
//   {
//     testColor.printComponentValues();
//   }
//   else
//   {
//     cout << "Invalid Index!";
//   }

//   cout << endl;
//   cout << "/////////////////" << endl;

//   ///////////////
//   testColor.setToRed();
//   testColor.adjustBrightness(0.25);
//   testImages[0].initializeTo(testColor);

//   testColor.setToBlue();
//   testColor.adjustBrightness(0.75);
//   testImages[1].initializeTo(testColor);

//   testColor.setToGreen();
//   testImages[2].initializeTo(testColor);

//   cout << "testImages[0] : " << endl;
//   testImages[0].printImage();
//   cout << endl;
//   cout << "testImages[1] : " << endl;
//   testImages[1].printImage();
//   cout << endl;
//   cout << "testImages[2] : " << endl;
//   testImages[2].printImage();
//   cout << endl;

//   testRowCol.setRowCol(1,2);
//   testColor.setToWhite();
//   testImages[1].setColorAtLocation(testRowCol, testColor);
//   cout << "testImages[1] : " << endl;
//   testImages[1].printImage();
//   cout << endl;


// }



// int main()
// {
//   int n = 1;
//   int numImgsToAdd = 2;
//   ColorImageClass imagesToAdd[numImgsToAdd];
//   ColorImageClass resultArray;
//   ColorImageClass testImage;
//   ColorClass testColor;
//   RowColumnClass testRowCol;
//   bool check;

//   cout << "testImage: " << endl;
//   testImage.printImage();
//   cout << endl;
  
//   cout << "resultArray: " << endl;
//   resultArray.printImage();
//   cout << endl;
 
//   cout << "testColor: " << endl;
//   testColor.printComponentValues();
//   cout << endl;


//   for (int i = 0; i < IMAGE_ROW_SIZE; i++)
//   {
//     for (int j = 0; j < IMAGE_COL_SIZE; j++)
//     {
//       testRowCol.setRowCol(i, j);
//       testColor.setTo(n, n, n);
//       imagesToAdd[0].setColorAtLocation(testRowCol, testColor); 
//       testColor.setTo(n + 990, n + 990, n + 990);
//       imagesToAdd[1].setColorAtLocation(testRowCol, testColor); 
//       n ++;
//     }
//   }

//   cout << "iamgesToAdd[0]: " << endl;
//   imagesToAdd[0].printImage();
//   cout << "imagesToAdd[1]: " << endl;
//   imagesToAdd[1].printImage();
//   cout << endl;

//   int sumIsClipped = 0;
//   bool isClipped;
//   for (int k = 0; k < numImgsToAdd; k++)
//   {
//     isClipped = resultArray.addImageTo(imagesToAdd[k]);
//     sumIsClipped += isClipped;
//   }

//   resultArray.printImage();
//   cout << sumIsClipped << endl;
//   cout << endl;

//   cout << " << using addImages function>> " << endl;
//   cout << "testImage: " << endl;
//   testImage.printImage();
//   cout << endl;

//   cout << "iamgesToAdd[0]: " << endl;
//   imagesToAdd[0].printImage();
//   cout << "imagesToAdd[1]: " << endl;
//   imagesToAdd[1].printImage();
//   cout << endl;

//   check = testImage.addImages(2, imagesToAdd);
//   cout << "testImage after using function: " << endl;
//   testImage.printImage();
//   cout << endl;
//   cout << check << endl;
// }

// int main()
// {
//   ColorImageClass testImage;
//   ColorImageClass addedImage;
//   ColorClass testColor;
//   RowColumnClass testRowCol;
//   bool check;
//   int sumIsClipped;


//   for (int i = 0; i < IMAGE_ROW_SIZE; i++)
//   {
//     for (int j = 0; j < IMAGE_COL_SIZE; j++)
//     {
//       testRowCol.setRowCol(i,j);
//       testColor.setTo(i, j, i+j);
//       testImage.setColorAtLocation(testRowCol, testColor);
//     }
//   }
//   cout << "testImage: " << endl;
//   testImage.printImage();
//   cout << endl;

//   testColor.setTo(997, 997, 997);
//   addedImage.initializeTo(testColor);
//   cout << "addedImage: " << endl;
//   addedImage.printImage();
//   cout << endl;

//   check = sumIsClipped = testImage.addImageTo(addedImage);
//   cout << "testImage after add addedImage: " << endl;
//   testImage.printImage();
//   cout << check << endl;
// }




