//Programmer: Youngjun Woo
//Date: December 5, 2021
//Purpose: This class will be used to store a simple first-in-first-out queue 
//         data structure.

template < class T >
FIFOQueueClass< T >::FIFOQueueClass()
{
  head = 0;
  tail = 0;
}
// Default Constructor. Will properly initialize a queue to be an empty 
// queue, to which values can be added.

template < class T >
FIFOQueueClass< T >::~FIFOQueueClass()
{
  clear();    
}
// Destructor. Responsible for making sure any dynamic memory associated 
// with an object is freed up when the object is being destroyed.

template < class T >
void FIFOQueueClass< T >::enqueue(const T &newItem)
{
  LinkedNodeClass< T > *newNode;
  
  if (head == 0)
  {
    newNode = new LinkedNodeClass< T >(0, newItem, 0);

    head = newNode;
    tail = newNode;
  }

  else
  {
    newNode = new LinkedNodeClass< T >(0, newItem, head);
    newNode->setBeforeAndAfterPointers();
    head = newNode;    
  }
}
// Inserts the value provided (newItem) into the queue.

template < class T >
bool FIFOQueueClass< T >::dequeue(T &outItem)
{
  bool didDequeue;
  LinkedNodeClass< T > *newTailPtr;

  if (tail == 0)
  {
    didDequeue = false;      
  }

  else
  {
    outItem = tail->getValue();

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
    
    didDequeue = true;
  }

  return didDequeue;
}
// Attempts to take the next item out of the queue. If the queue is empty, 
// the function returns false and the state of the reference parameter 
// (outItem) is undefined. If the queue is not empty, the function returns 
// true and outItem becomes a copy of the next item in the queue, which is
// removed from the data structure.

template < class T >
void FIFOQueueClass< T >::print() const
{
  LinkedNodeClass< T > *currentNode;

  currentNode = head;

  while (currentNode != 0)
  {
    cout << currentNode->getValue() << " ";
    currentNode = currentNode->getNext();    
  }    

  cout << endl;
}
// Prints out the contents of the queue. All printing is done on one line, 
// using a single space to separate values, and a single newline character 
// is printed at the end.

template < class T >
int FIFOQueueClass< T >::getNumElems() const
{
  LinkedNodeClass< T > *currentNode;
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
//Returns the number of nodes contained in the queue.

template < class T >
void FIFOQueueClass< T >::clear()
{
  int numElements;
  T dequeuedValue;

  numElements = getNumElems();
  
  for (int i = 0; i < numElements; i++)
  {
    dequeue(dequeuedValue);    
  }

  head = 0;
  tail = 0;
}
// Clears the queue to an empty state without resulting in any memory leaks.



