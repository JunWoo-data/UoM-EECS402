#include <iostream>
#include <fstream>
#include "ColorClass.h"
#include "constants.h"
#include "checkMenuNumber.h"
using namespace std;

// -----Resubmission change
// - Make new write method from ColorClass.
// - Make new setColorFromUser method from ColorClass.

//Programmer: Youngjun Woo
//Date: November 4, 2021
//Purpose: ColorClass is information about image pixel. ClorClass consists of 
// red, green, blue integer value. PPM image's red, green, blue value have 255
// as maximum value.

ColorClass::ColorClass()
{
  setToWhite();
}
// This constructor set the color's initial RGB values to the color full
// white (r = maximum value, g = maximum value, b = maximum value).

ColorClass::ColorClass(int inRed, int inGreen, int inBlue)
{
  setTo(inRed, inGreen, inBlue);
}
// This constructor set the color's initial RGB values to the value
// provided.

void ColorClass::setToBlack()
{
  setTo(MIN_PPM_IMAGE_VALUE, MIN_PPM_IMAGE_VALUE, MIN_PPM_IMAGE_VALUE);
}
// Set the color's RGB values to the black color.
// (r = minimum value , g = minimum value, b = minimum value)

void ColorClass::setToRed()
{
  setTo(MAX_PPM_IMAGE_VALUE, MIN_PPM_IMAGE_VALUE, MIN_PPM_IMAGE_VALUE);
}
// Set the color's RGB values to the red color.
// (r = maximum value , g = minimum value, b = minimum value)

void ColorClass::setToGreen()
{
  setTo(MIN_PPM_IMAGE_VALUE, MAX_PPM_IMAGE_VALUE, MIN_PPM_IMAGE_VALUE);
}
// Set the color's RGB values to the green color.
// (r = minimum value , g = maximum value, b = minimum value)

void ColorClass::setToBlue()
{
  setTo(MIN_PPM_IMAGE_VALUE, MIN_PPM_IMAGE_VALUE, MAX_PPM_IMAGE_VALUE);
}
// Set the color's RGB values to the blue color.
// (r = minimum value , g = minimum value, b = maximum value)

void ColorClass::setToWhite()
{
  setTo(MAX_PPM_IMAGE_VALUE, MAX_PPM_IMAGE_VALUE, MAX_PPM_IMAGE_VALUE);
}
// Set the color's RGB values to the white color.
// (r = maximum value , g = maximum value, b = maximum value)

void ColorClass::setTo(int inRed, int inGreen, int inBlue)
{ 
  redAmount = inRed;
  greenAmount = inGreen;
  blueAmount = inBlue;
}
// Set the color's RGB values to the provided values. 

void ColorClass::setTo(ColorClass &inColor)
{
  setTo(inColor.redAmount, inColor.greenAmount, inColor.blueAmount);
}
// Set the color's RGB values to the same as those in the "inColor" input
// parameter. 

void ColorClass::setColorFromUser(string purpose)
{
  int menuNumber;

  cout << "1. Red" << endl;
  cout << "2. Green" << endl;
  cout << "3. Blue" << endl;
  cout << "4. Black" << endl;
  cout << "5. White" << endl;
  cout << "Enter int for " << purpose << " color: ";    

  menuNumber = checkMenuNumber(MIN_COLOR_MENU_NUMBER, MAX_COLOR_MENU_NUMBER); 
  
  if (menuNumber == CHOICE_RED)
  {
    setToRed(); 
  }  

  else if (menuNumber == CHOICE_GREEN)
  {
    setToGreen();
  }  

  else if (menuNumber == CHOICE_BLUE)
  {
    setToBlue(); 
  }
  
  else if (menuNumber == CHOICE_BLACK)
  {
    setToBlack();
  } 

  else if (menuNumber == CHOICE_WHITE)
  {
    setToWhite();
  }        
}
// Set the color's RGB values to the input from user.

int ColorClass::getRedAmount() const
{
  return redAmount;
}
// get ColorClass's red value.

int ColorClass::getGreenAmount() const
{
  return greenAmount;
}
// get ColorClass's green value.

int ColorClass::getBlueAmount() const
{
  return blueAmount;
}
// get ColorClass's blue value.

void ColorClass::printComponentValues() const
{
  cout << "R:" << getRedAmount() << " G:" << getGreenAmount() 
       << " B:" << getBlueAmount();
}
// Prints the component color values to the console using the following 
// format: "R: <red> G: <green> B: <blue>" where <red>, <green>, and <blue> 
// are all replaced with their corresponding component color values.

void ColorClass::writeRgbValue(ofstream &outFile) const
{
  outFile << getRedAmount() << " " << getGreenAmount() << " " 
          << getBlueAmount() << " ";  
}
// Write rgb values on outFile using the following format: 
// redAmount greenAmount blueAmount  