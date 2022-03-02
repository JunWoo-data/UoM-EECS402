#include <iostream>
#include "constants.h"
#include "RowColumnClass.h"
#include "ColorClass.h"
#include "RectangleClass.h"
#include "PpmImageClass.h"
#include "PaternClass.h"
#include "printMainMenu.h"
#include "checkMenuNumber.h"
#include "calculateCenterAndHalfValues.h"
using namespace std;

int main()
{ 
  PpmImageClass baseImage;
  PpmImageClass insertImage;
  RowColumnClass upperLeft;
  RowColumnClass lowerRight;
  RowColumnClass center;
  RectangleClass rectangleForAnnotate;
  ColorClass color;
  PatternClass insertPattern;
  string ppmImageFileName;
  string patternFileName;
  bool isSuccess;
  int menuNumber;
  bool validInputFound;
  bool validLowerRightFound;
  int *centerAndSizeValues; 
  string unit;

  cout << "Enter string for PPM image file name to load: ";
  cin >> ppmImageFileName;

  isSuccess = baseImage.readImageFile(ppmImageFileName);
  if (isSuccess == true)
  {  
    menuNumber = DEFAULT_MAIN_MENU_NUMBER;
    while (menuNumber != CHOICE_EXIT_MAIN_MENU)
    {
      cin.clear();
      cin.ignore(200, '\n');
      
      printMainMenu();
      menuNumber = checkMenuNumber(MIN_MAIN_MENU_NUMBER, MAX_MAIN_MENU_NUMBER); 
      
      // ========== annotate rectangle ==========
      if (menuNumber == CHOICE_ANNOTATE_RECTANGLE_MAIN_MENU)
      {
        cout << "1. Specify upper left and lower right corners of rectangle" 
             << endl;
        cout << "2. Specify upper left corner and dimensions of rectangle" 
             << endl;
        cout << "3. Specify extent from center of rectangle" << endl;  
        cout << "Enter int for rectangle specification method: ";   
        menuNumber = checkMenuNumber(MIN_RECTANGLE_SPECIFICATION_MENU_NUMBER,
                                     MAX_RECTANGLE_SPECIFICATION_MENU_NUMBER);
        
        // -- annotate rectangle method one
        if (menuNumber == CHOICE_SPECIFY_UPPER_LEFT_LOWER_RIGHT_METHOD)
        {
          validInputFound = false;
          while (!validInputFound)
          {
            upperLeft.setRowColFromUser("upper left");
            isSuccess = baseImage.checkValidRowCol(upperLeft);

            if (isSuccess == true)
            { 
              validLowerRightFound = false; 
              while (!validLowerRightFound)
              {
                lowerRight.setRowColFromUser("lower right"); 
                isSuccess = baseImage.checkValidRowCol(lowerRight);

                if (isSuccess == true)
                {
                  if (lowerRight.getRow() < upperLeft.getRow() or 
                      lowerRight.getCol() < upperLeft.getCol())
                  {
                    cin.clear();
                    cin.ignore(200, '\n');
    
                    cout << "ERROR: Your rectangle's lower right corner has " 
                         << "wrong position with rectangle's upper left corner." 
                         << endl;
                    cout << "Lower right row(column) must be greater(include) "
                         << "than upper left row(column)." << endl;
                    cout << "  current upper left (row, col): " << "(" 
                         << upperLeft.getRow() << ", " << upperLeft.getCol() 
                         << ")" << endl;
                    cout << "  current lower right (row, col): " << "(" 
                         << lowerRight.getRow() << ", " << lowerRight.getCol() 
                         << ")" << endl;     
                  }

                  else
                  {
                    validLowerRightFound = true;    
                  }    
                }
              } 
              
              centerAndSizeValues = calculateCenterAndHalfValues(upperLeft, 
                                                                 lowerRight);
              center.setRowCol(centerAndSizeValues[0], centerAndSizeValues[1]);
              rectangleForAnnotate.setCenterTo(center);
              rectangleForAnnotate.setSizeTo(centerAndSizeValues[2], 
                                             centerAndSizeValues[3]);
              
              color.setColorFromUser("rectangle");
              rectangleForAnnotate.setColorsTo(color.getRedAmount(),
                                               color.getGreenAmount(),
                                               color.getBlueAmount());
    
              rectangleForAnnotate.setIsFilledFromUser();
              
              isSuccess = baseImage.annotateRectangle(rectangleForAnnotate);   
              if (isSuccess == true)
              { 
                validInputFound = true;  
              }
            }
          }          
        }
        
        // -- annotate rectangle method two
        else if (menuNumber == CHOICE_SPECIFY_UPPER_LEFT_DIMENSION_METHOD)
        {
          validInputFound = false;
          while (!validInputFound)
          {
            upperLeft.setRowColFromUser("upper left");
            isSuccess = baseImage.checkValidRowCol(upperLeft);
            
            if (isSuccess == true)
            {
              rectangleForAnnotate.setSizeFromUser("full");
              centerAndSizeValues = 
              calculateCenterAndHalfValues(upperLeft, 
                                    rectangleForAnnotate.getNumOfHalfRow() * 2, 
                                    rectangleForAnnotate.getNumOfHalfCol() * 2);
              center.setRowCol(centerAndSizeValues[0], centerAndSizeValues[1]);
              rectangleForAnnotate.setCenterTo(center);
              
              color.setColorFromUser("rectangle");
              rectangleForAnnotate.setColorsTo(color.getRedAmount(),
                                               color.getGreenAmount(),
                                               color.getBlueAmount());
              
              rectangleForAnnotate.setIsFilledFromUser();
    
              isSuccess = baseImage.annotateRectangle(rectangleForAnnotate);
              if (isSuccess == true)
              {
                validInputFound = true;  
              }
            }
          }
        }
        
        // -- annotate rectangle method three
        else
        {
          validInputFound = false;
          while(!validInputFound)
          {
            center.setRowColFromUser("center");
            isSuccess = baseImage.checkValidRowCol(center);  

            if (isSuccess == true)
            {
              rectangleForAnnotate.setCenterTo(center);

              rectangleForAnnotate.setSizeFromUser("half");

              color.setColorFromUser("rectangle");
              rectangleForAnnotate.setColorsTo(color.getRedAmount(),
                                               color.getGreenAmount(),
                                               color.getBlueAmount());
              
              rectangleForAnnotate.setIsFilledFromUser();
    
              isSuccess = baseImage.annotateRectangle(rectangleForAnnotate);
              if (isSuccess == true)
              {
                validInputFound = true;  
              }       
            }
          }          
        }

        delete [] centerAndSizeValues;
        centerAndSizeValues = 0;
      }
      
      // ========== annotate pattern ==========
      else if (menuNumber == CHOICE_ANNOTATE_PATTERN_MAIN_MENU)
      { 
        validInputFound = false;
        while (!validInputFound)
        {
          cout << "Enter string for file name containing pattern: " ;
          cin >> patternFileName;
          
          isSuccess = insertPattern.readPatternFile(patternFileName); 
          if (isSuccess == true)
          {
            if (insertPattern.getNumCol() > baseImage.getWidth() or 
                insertPattern.getNumRow() > baseImage.getHeight())
            {
              cout << "ERROR: Pattern is bigger than original image." 
                   << endl;
              cout << "  original image height: " << MIN_PPM_IMAGE_SIZE_VALUE 
                   << " ~ " << baseImage.getHeight() - 1 << endl;
              cout << "  original image width: " << MIN_PPM_IMAGE_SIZE_VALUE 
                   << " ~ " << baseImage.getWidth() - 1 << endl;
              cout << "Try smaller pattern than original image." << endl;
            }  

            else
            {
              validInputFound = true;  
            }
          }
        }

        validInputFound = false;
        while (!validInputFound)
        {
          upperLeft.setRowColFromUser("upper left"); 
          isSuccess = baseImage.checkValidRowCol(upperLeft);

          if (isSuccess == true)
          {
            if ((upperLeft.getRow() + insertPattern.getNumRow() - 1) > 
                (baseImage.getHeight() - 1)) 
            { 
              cout << "ERROR: Your pattern rows goes out of bounds of the" 
                   << " original image." << endl;
              cout << "  original image height: " << MIN_PPM_IMAGE_SIZE_VALUE 
                   << " ~ " << baseImage.getHeight() - 1 << endl; 
              cout << "  pattern rows + left corner row: "
                   << insertPattern.getNumRow() + upperLeft.getRow() - 1 
                   << endl;
            }
        
            else if ((upperLeft.getCol() + insertPattern.getNumCol() - 1) > 
                     (baseImage.getWidth() - 1))
            {
              cout << "ERROR: Your pattern columns goes out of bounds of" 
                   << " the original image." << endl;
              cout << "  original image width: " << MIN_PPM_IMAGE_SIZE_VALUE 
                   << " ~ " << baseImage.getWidth() - 1 << endl; 
              cout << "  pattern columns + left corner col: "
                   << insertPattern.getNumCol() + upperLeft.getCol() - 1 
                   << endl;
            }

            else
            {
              color.setColorFromUser("pattern"); 
              baseImage.annotatePattern(insertPattern, upperLeft);
              validInputFound = true;    
            }    
          }   
        }  
      }

      // ========== insert another image ==========
      else if (menuNumber == CHOICE_INSERT_IMAGE_MAIN_MENU)
      {
        validInputFound = false;
        while (!validInputFound)
        {
          cout << "Enter string for file name of PPM image to insert: ";
          cin >> ppmImageFileName;  

          isSuccess = insertImage.readImageFile(ppmImageFileName); 
          if (isSuccess == true)
          {
            if (insertImage.getWidth() > baseImage.getWidth() or 
                insertImage.getHeight() > baseImage.getHeight())
            {
              cout << "ERROR: Insert image is bigger than original image." 
                   << endl;
              cout << "  original image height: " << MIN_PPM_IMAGE_SIZE_VALUE 
                   << " ~ " << baseImage.getHeight() - 1 << endl;
              cout << "  original image width: " << MIN_PPM_IMAGE_SIZE_VALUE 
                   << " ~ " << baseImage.getWidth() - 1 << endl;
              cout << "Try smaller image than original image." << endl;
            }

            else
            {
              validInputFound = true;  
            }    
          }        
        }
        
        validInputFound = false;
        while (!validInputFound)
        {
          upperLeft.setRowColFromUser("upper left");
          isSuccess = baseImage.checkValidRowCol(upperLeft);

          if (isSuccess == true)
          {
            if ((upperLeft.getRow() + insertImage.getHeight() - 1) > 
                (baseImage.getHeight() - 1)) 
            { 
              cout << "ERROR: Your insert image rows goes out of bounds of the" 
                   << " original image." << endl;
              cout << "  original image height: " << MIN_PPM_IMAGE_SIZE_VALUE 
                   << " ~ " << baseImage.getHeight() - 1 << endl; 
              cout << "  insert image height + left corner row: "
                   << insertImage.getHeight() + upperLeft.getRow() - 1 << endl;
            }
        
            else if ((upperLeft.getCol() + insertImage.getWidth() - 1) > 
                     (baseImage.getWidth() - 1))
            {
              cout << "ERROR: Your insert image columns goes out of bounds of" 
                   << " the original image." << endl;
              cout << "  original image width: " << MIN_PPM_IMAGE_SIZE_VALUE 
                   << " ~ " << baseImage.getWidth() - 1 << endl; 
              cout << "  insert image width + left corner col: "
                   << insertImage.getWidth() + upperLeft.getCol() - 1 << endl;
            }

            else
            {
              color.setColorFromUser("transperency");    
              baseImage.insertImage(insertImage, upperLeft, color);
              validInputFound = true;
            }  
          }
        }
      }

      // ========== write out current image ==========
      else if (menuNumber == CHOICE_WRITE_OUT_MAIN_MENU)
      {
        baseImage.saveImageFile();  
      }   

      // ========== exite the program ==========
      else if (menuNumber == CHOICE_EXIT_MAIN_MENU)
      {
        cout << "Thank you for using this program." << endl;
        return 0;  
      }
    }  
  }

  else 
  {
    return 0;    
  }
}