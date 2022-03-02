#ifndef _SORTEDLISTCLASS_H_
#define _SORTEDLISTCLASS_H_

#include <iostream>
#include "LinkedNodeClass.h"
using namespace std;

//Programmer: Youngjun Woo
//Date: December 5, 2021
//Purpose: This class will be used to store a doubly-linked list in an 
//         always-sorted way, such that the user does not specify where in the 
//         list a value should be inserted, but rather the new value is 
//         inserted in the correct place to maintain a sorted order.

template < class T >
class SortedListClass
{
  private:
    LinkedNodeClass< T > *head;
    // Points to the first node in a list, or NULL if list is empty.

    LinkedNodeClass< T > *tail;
    // Points to the last node in a list, or NULL if list is empty.

  public:
    SortedListClass();
    // Default Constructor. Will properly initialize a list to be an empty list, 
    // to which values can be added.

    SortedListClass(const SortedListClass< T > &rhs);
    // Copy constructor. Will make a complete (deep) copy of the list, such 
    // that one can be changed without affecting the other.

    ~SortedListClass();
    // Destructor. Responsible for making sure any dynamic memory associated 
    // with an object is freed up when the object is being destroyed.

    void clear();
    // Clears the list to an empty state without resulting in any memory leaks.

    void insertValue(const T &valToInsert);
    // Allows the user to insert a value into the list. Since this is a sorted 
    // list, there is no need to specify where in the list to insert the 
    // element. It will insert it in the appropriate location based on the 
    // value being inserted. If the node value being inserted is found to be 
    // "equal to" one or more node values already in the list, the newly 
    // inserted node will be placed AFTER the previously inserted nodes.

    void printForward() const;
    // Prints the contents of the list from head to tail to the screen. Begins 
    // with a line reading "Forward List Contents Follow:", then prints one 
    // list element per line, indented two spaces, then prints the line "End Of 
    // List Contents" to indicate the end of the list.

    void printBackward() const;
    // Prints the contents of the list from tail to head to the screen. Begins 
    // with a line reading "Backward List Contents Follow:", then prints one 
    // list element per line, indented two spaces, then prints the line "End Of
    // List Contents" to indicate the end of the list.

    bool removeFront(T &theVal);
    // Removes the front item from the list and returns the value that was 
    // contained in it via the reference parameter. If the list was empty, the 
    // function returns false to indicate failure, and the contents of the 
    // reference parameter upon return is undefined. If the list was not empty 
    // and the first item was successfully removed, true is returned, and the 
    // reference parameter will be set to the item that was removed.

    bool removeLast(T &theVal);
    // Removes the last item from the list and returns the value that was 
    // contained in it via the reference parameter. If the list was empty, the 
    // function returns false to indicate failure, and the contents of the 
    // reference parameter upon return is undefined. If the list was not empty 
    // and the last item was successfully removed, true is returned, and the 
    // reference parameter will be set to the item that was removed.

    int getNumElems() const;
    // Returns the number of nodes contained in the list.

    bool getElemAtIndex(const int index, T &outVal) const;
    // Provides the value stored in the node at index provided in the 0-based 
    // "index" parameter. If the index is out of range, then outVal remains 
    // unchanged and false is returned. Otherwise, the function returns true, 
    // and the reference parameter outVal will contain a copy of the value at 
    // that location.
};

#include "SortedListClass.inl"
#endif