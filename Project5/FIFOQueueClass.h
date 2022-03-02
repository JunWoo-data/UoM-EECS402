#ifndef _FIFOQUEUECLASS_H_
#define _FIFOQUEUECLASS_H_

#include <iostream>
#include "LinkedNodeClass.h"
using namespace std;

//Programmer: Youngjun Woo
//Date: December 5, 2021
//Purpose: This class will be used to store a simple first-in-first-out queue 
//         data structure.

template < class T >
class FIFOQueueClass
{
  private:
    LinkedNodeClass< T > *head;
    //Points to the first node in a queue, or NULL if queue is empty.

    LinkedNodeClass< T > *tail;
    //Points to the last node in a queue, or NULL if queue is empty.

  public:    
    FIFOQueueClass();
    // Default Constructor. Will properly initialize a queue to be an empty 
    // queue, to which values can be added.

    ~FIFOQueueClass();
    // Destructor. Responsible for making sure any dynamic memory associated 
    // with an object is freed up when the object is being destroyed.

    void enqueue(const T &newItem);
    // Inserts the value provided (newItem) into the queue.

    bool dequeue(T &outItem);
    // Attempts to take the next item out of the queue. If the queue is empty, 
    // the function returns false and the state of the reference parameter 
    // (outItem) is undefined. If the queue is not empty, the function returns 
    // true and outItem becomes a copy of the next item in the queue, which is
    // removed from the data structure.

    void print() const;
    // Prints out the contents of the queue. All printing is done on one line, 
    // using a single space to separate values, and a single newline character 
    // is printed at the end.

    int getNumElems() const;
    //Returns the number of nodes contained in the queue.

    void clear();
    // Clears the queue to an empty state without resulting in any memory leaks.
};

#include "FIFOQueueClass.inl"
#endif