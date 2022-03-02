#include <iostream>
#include "SortedListClass.h"
#include "LinkedNodeClass.h"
using namespace std;

//Programmer: Youngjun Woo
//Date: November 18, 2021
//Purpose: This class will be used to store a doubly-linked list in an 
// always-sorted way, such that the user does not specify where in the list a 
// value should be inserted, but rather the new value is inserted in the 
// correct place to maintain a sorted order.

SortedListClass::SortedListClass()
{
  head = 0;
  tail = 0;    
}
// Default Constructor. Will properly initialize a list to be an empty list, 
// to which values can be added.

SortedListClass::SortedListClass(const SortedListClass &rhs)
{
  int rhsNumElements;
  int valueAtIndex;

  rhsNumElements = rhs.getNumElems();
  head = 0;
  tail = 0;

  for (int i = 0; i < rhsNumElements; i++)
  {
    rhs.getElemAtIndex(i, valueAtIndex);
    insertValue(valueAtIndex);   
  }
}
// Copy constructor. Will make a complete (deep) copy of the list, such 
// that one can be changed without affecting the other.

SortedListClass::~SortedListClass()
{
  clear();     
}
// Destructor. Responsible for making sure any dynamic memory associated 
// with an object is freed up when the object is being destroyed.

void SortedListClass::clear()
{
  int numElements;
  int removedValue;

  numElements = getNumElems();

  for (int i = 0; i < numElements; i++)
  {
    removeFront(removedValue);    
  }

  head = 0;
  tail = 0;          
}
// Clears the list to an empty state without resulting in any memory leaks.

void SortedListClass::insertValue(const int &valToInsert)
{
  LinkedNodeClass *newNode;
  LinkedNodeClass *currentNode;
  bool isInserted;

  // if current list is empty list, then put new node between head and tail
  if (head == 0)
  {
    newNode = new LinkedNodeClass(0, valToInsert, 0);
    
    head = newNode;
    tail = newNode;
  }

  // if current list is not empty, 
  else
  {
    currentNode = head;
     
    // if valid new node location is between head and current node 
    if (currentNode->getValue() > valToInsert)
    { 
      newNode = new LinkedNodeClass(0, valToInsert, currentNode);
      newNode->setBeforeAndAfterPointers();
      head = newNode;      
    }
    
    // if valid new node location is not between head and current node, find
    // valid new node location by moving current node location
    else if (currentNode->getValue() <= valToInsert)
    {
      isInserted = false;
      while (!isInserted)
      {
        if (currentNode->getValue() <= valToInsert)
        {  
          // if valid new node location is between current node and tail  
          if (currentNode->getNext() == 0)
          {
            newNode = new LinkedNodeClass(currentNode, valToInsert, 0);
            newNode->setBeforeAndAfterPointers();
            tail = newNode;
            
            isInserted = true;
          }   
          
          // move current node location 
          else
          {
            currentNode = currentNode->getNext();    
          }
        }   
        
        // if valid new node location is betweeen current node's previous node
        // and current node
        else
        {
          newNode = new LinkedNodeClass(currentNode->getPrev(), valToInsert,
                                        currentNode);
          newNode->setBeforeAndAfterPointers();

          isInserted = true;    
        } 
      }
    }
  }  
}
// Allows the user to insert a value into the list. Since this is a sorted 
// list, there is no need to specify where in the list to insert the 
// element. It will insert it in the appropriate location based on the 
// value being inserted. If the node value being inserted is found to be 
// "equal to" one or more node values already in the list, the newly 
// inserted node will be placed AFTER the previously inserted nodes.

void SortedListClass::printForward() const
{
  LinkedNodeClass *currentNode;

  cout << "Forward List Contents Follow:" << endl;

  currentNode = head;

  while (currentNode != 0)
  {
    cout << "  " << currentNode->getValue() << endl;
    currentNode = currentNode->getNext();    
  }    
    
  cout << "End Of List Contents" << endl;   
}
// Prints the contents of the list from head to tail to the screen. Begins 
// with a line reading "Forward List Contents Follow:", then prints one 
// list element per line, indented two spaces, then prints the line "End Of 
// List Contents" to indicate the end of the list.

void SortedListClass::printBackward() const
{
  LinkedNodeClass *currentNode;

  cout << "Backward List Contents Follow:" << endl;

  currentNode = tail;

  while (currentNode != 0)
  {
    cout << "  " << currentNode->getValue() << endl;
    currentNode = currentNode->getPrev();    
  }    
    
  cout << "End Of List Contents" << endl;   
}
// Prints the contents of the list from tail to head to the screen. Begins 
// with a line reading "Backward List Contents Follow:", then prints one 
// list element per line, indented two spaces, then prints the line "End Of
// List Contents" to indicate the end of the list.

bool SortedListClass::removeFront(int &theVal)
{
  bool didDeleteItem;
  LinkedNodeClass *newHeadPtr;
  
  if (head == 0)    
  {
    didDeleteItem = false;        
  } 

  else
  {
    theVal = head->getValue();    
    
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
    
    didDeleteItem = true;  
  }
  
  return didDeleteItem;
}
// Removes the front item from the list and returns the value that was 
// contained in it via the reference parameter. If the list was empty, the 
// function returns false to indicate failure, and the contents of the 
// reference parameter upon return is undefined. If the list was not empty 
// and the first item was successfully removed, true is returned, and the 
// reference parameter will be set to the item that was removed.

bool SortedListClass::removeLast(int &theVal)
{
  bool didDeleteItem;
  LinkedNodeClass *newTailPtr;  

  if (tail == 0)    
  {
    didDeleteItem = false;        
  } 
  
  else
  {
    theVal = tail->getValue();    

    if (tail->getPrev() == 0)
    {
      delete tail;
      head = 0;
      tail = 0;
    }  
    
    else
    {
      newTailPtr = tail->getPrev();
      delete tail;
      tail = newTailPtr;
      tail->setNextPointerToNull();
    }  

    didDeleteItem = true;  
  }  

  return didDeleteItem;
}
// Removes the last item from the list and returns the value that was 
// contained in it via the reference parameter. If the list was empty, the 
// function returns false to indicate failure, and the contents of the 
// reference parameter upon return is undefined. If the list was not empty 
// and the last item was successfully removed, true is returned, and the 
// reference parameter will be set to the item that was removed.

int SortedListClass::getNumElems() const
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
// Returns the number of nodes contained in the list.

bool SortedListClass::getElemAtIndex(const int index, int &outVal) const
{
  LinkedNodeClass *currentNode;  
  bool didGetElem;
  int i;

  if (getNumElems() - 1 < index or index < 0)
  {
    didGetElem = false;      
  }

  else
  {
    i = 0;
    currentNode = head;

    while (i < index)
    {
      currentNode = currentNode->getNext();   
      i++; 
    }

    outVal = currentNode->getValue();
    didGetElem = true;
  }

  return didGetElem;
}
// Provides the value stored in the node at index provided in the 0-based 
// "index" parameter. If the index is out of range, then outVal remains 
// unchanged and false is returned. Otherwise, the function returns true, 
// and the reference parameter outVal will contain a copy of the value at 
// that location.



