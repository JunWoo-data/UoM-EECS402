#include <iostream>
#include "LIFOStackClass.h"
#include "LinkedNodeClass.h"
using namespace std;

//Programmer: Youngjun Woo
//Date: November 18, 2021
//Purpose: This class will be used to store a simple last-in-first-out stack 
// data structure.

LIFOStackClass::LIFOStackClass()
{
  head = 0;
  tail = 0;    
}
// Default Constructor. Will properly initialize a stack to be an empty 
// stack, to which values can be added.

LIFOStackClass::~LIFOStackClass()
{
  clear();    
}
// Destructor. Responsible for making sure any dynamic memory associated 
// with an object is freed up when the object is being destroyed.

void LIFOStackClass::push(const int &newItem)
{
  LinkedNodeClass *newNode;

  if (head == 0)
  {
    newNode = new LinkedNodeClass(0, newItem, 0);

    head = newNode;
    tail = newNode;    
  }

  else
  {
    newNode = new LinkedNodeClass(0, newItem, head);
    newNode->setBeforeAndAfterPointers();
    head = newNode;    
  }
}
// Inserts the value provided (newItem) into the stack.

bool LIFOStackClass::pop(int &outItem)
{
  bool didPop;
  LinkedNodeClass *newHeadPtr;

  if (head == 0)
  {
    didPop = false;    
  }    

  else
  {
    outItem = head->getValue();

    if (head->getNext() == 0)
    {
      delete head;
      head = 0;
      tail = 0;    
    }    

    else
    {
      newHeadPtr = head->getNext();
      delete head;
      head = newHeadPtr;
      head->setPreviousPointerToNull();    
    }

    didPop = true;
  }

  return didPop;
}
// Attempts to take the next item out of the stack. If the stack is empty, 
// the function returns false and the state of the reference parameter 
// (outItem) is undefined. If the stack is not empty, the function returns 
// true and outItem becomes a copy of the next item in the stack, which is
// removed from the data structure.

void LIFOStackClass::print() const
{
  LinkedNodeClass *currentNode;

  currentNode = head;

  while (currentNode != 0)
  {
    cout << currentNode->getValue() << " ";
    currentNode = currentNode->getNext();    
  }

  cout << endl;
}
// Prints out the contents of the stack. All printing is done on one line, 
// using a single space to separate values, and a single newline character 
// is printed at the end.

int LIFOStackClass::getNumElems() const
{
  LinkedNodeClass *currentNode;
  int numElements;

  currentNode = head;

  if (currentNode == 0)
  {
    numElements = 0;    
  }

  else
  {
    numElements = 1;

    while (currentNode->getNext() != 0)
    {
      numElements++;
      currentNode = currentNode->getNext();    
    }    
  }

  return numElements;
}
// Returns the number of nodes contained in the stack.

void LIFOStackClass::clear()
{
  int numElements;
  int popedValue;

  numElements = getNumElems();
  
  for (int i = 0; i < numElements; i++)
  {
    pop(popedValue);    
  }

  head = 0;
  tail = 0;    
}
// Clears the stack to an empty state without resulting in any memory leaks.
