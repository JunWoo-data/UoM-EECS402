#include <iostream>
using namespace std;

const int MIN_RGB_AMOUNT = 0;
const int MAX_RGB_AMOUNT = 1000;

int clipRgbAmount(int inRgbAmount);
bool checkIsClipped(int inRgbAmount);

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

///// ColorClass /////
class ColorClass
{
  public:
    ColorClass();
    ColorClass(int inRed, int inGreen, int inBlue);
    
    void setToBlack();
    void setToRed();
    void setToGreen();
    void setToBlue();
    void setToWhite();
    bool setTo(int inRed, int inGreen, int inBlue);
    bool setTo(ColorClass &inColor);
    bool addColor(ColorClass &rhs);
    bool subtractColor(ColorClass &rhs);
    bool adjustBrightness(double adjFactor);
    void printComponentValues() const;
    
  private:
    int redAmount;
    int greenAmount;
    int blueAmount;
};

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
  setTo(0, 0, 0);
}

void ColorClass::setToRed()
{
  setTo(1000, 0, 0);
}

void ColorClass::setToGreen()
{
  setTo(0, 1000, 0);
}

void ColorClass::setToBlue()
{
  setTo(0, 0, 1000);
}

void ColorClass::setToWhite()
{
  setTo(1000, 1000, 1000);
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
