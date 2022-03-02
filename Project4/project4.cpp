#include <iostream>
#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "LIFOStackClass.h"
using namespace std;

//Programmer: Youngjun Woo
//Date: November 18, 2021
//Purpose: This main function is to test all SortedListClass, FIFOQueueClass,
// and LIFOStackClass related functions.

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else 

int main()
{
  SortedListClass testSortedList;
  bool checkBool;
  int deletedValue;
  int numElements;
  int valueAtIndex;
  int index;

  FIFOQueueClass testFIFOlist;
  int dequeuedValue;

  LIFOStackClass testLILOlist;
  int popedValue;

  // --------- test SortedListClass --------- //
  // InsertValue
  testSortedList.insertValue(3);
  cout << "3 is inserted to testSortedList." << endl;
  testSortedList.insertValue(6);
  cout << "6 is inserted to testSortedList." << endl;
  testSortedList.insertValue(15);
  cout << "15 is inserted to testSortedList." << endl;
  testSortedList.insertValue(4);
  cout << "4 is inserted to testSortedList." << endl;
  cout << endl;

  // PrintForward & PrintBackWard
  cout << "testSortedList: " << endl;
  testSortedList.printForward();
  testSortedList.printBackward();
  cout << endl;

  // copy constructor
  SortedListClass copyConstructedSortedList(testSortedList);
  cout << "copyConstructedSortedList is made by copy constructor with "
       << "testSortedList." << endl;
  cout << "copyConstructedSortedList: " << endl;
  copyConstructedSortedList.printForward();
  cout << endl;

  // clear 
  testSortedList.clear();
  cout << "testSortedList is cleared." << endl;
  cout << "testSortedList: " << endl;
  testSortedList.printForward();
  cout << endl;
  
  // is copy constructor deep copy
  cout << "copyConstructedSortedList have to be same after testSortedList is "
       << "cleared." << endl;
  cout << "copyConstructedSortedList: " << endl;
  copyConstructedSortedList.printForward();
  cout << endl;
  
  // getElemAtIndex
  index = 0;
  checkBool = copyConstructedSortedList.getElemAtIndex(index, valueAtIndex);
  cout << "Index: " << index << endl;
  cout << "Value at index: " << valueAtIndex << endl;
  cout << "Check bool: " << checkBool << endl;
  cout << endl;

  index = 1;
  checkBool = copyConstructedSortedList.getElemAtIndex(index, valueAtIndex);
  cout << "Index: " << index << endl;
  cout << "Value at index: " << valueAtIndex << endl;
  cout << "Check bool: " << checkBool << endl;
  cout << endl;

  index = 2;
  checkBool = copyConstructedSortedList.getElemAtIndex(index, valueAtIndex);
  cout << "Index: " << index << endl;
  cout << "Value at index: " << valueAtIndex << endl;
  cout << "Check bool: " << checkBool << endl;
  cout << endl;

  index = 3;
  checkBool = copyConstructedSortedList.getElemAtIndex(index, valueAtIndex);
  cout << "Index: " << index << endl;
  cout << "Value at index: " << valueAtIndex << endl;
  cout << "Check bool: " << checkBool << endl;
  cout << endl;

  index = 4;
  checkBool = copyConstructedSortedList.getElemAtIndex(index, valueAtIndex);
  cout << "Index: " << index << endl;
  cout << "Value at index: " << valueAtIndex << endl;
  cout << "Check bool: " << checkBool << endl;
  cout << endl;

  index = -1;
  checkBool = copyConstructedSortedList.getElemAtIndex(index, valueAtIndex);
  cout << "Index: " << index << endl;
  cout << "Value at index: " << valueAtIndex << endl;
  cout << "Check bool: " << checkBool << endl;
  cout << endl;

  // getNumElems
  numElements = copyConstructedSortedList.getNumElems();
  cout << "num elements: " << numElements << endl;
  cout << endl;

  // removeLast & removeFront
  checkBool = copyConstructedSortedList.removeLast(deletedValue);
  cout << "Last value removed." << endl;
  cout << "Deleted value: " << deletedValue << endl;
  cout << "Did deleted: " << checkBool << endl;
  copyConstructedSortedList.printForward();
  numElements = copyConstructedSortedList.getNumElems();
  cout << "num elements: " << numElements << endl;
  cout << endl;

  checkBool = copyConstructedSortedList.removeFront(deletedValue);
  cout << "Front value removed." << endl;
  cout << "Deleted value: " << deletedValue << endl;
  cout << "Did deleted: " << checkBool << endl;
  copyConstructedSortedList.printForward();
  numElements = copyConstructedSortedList.getNumElems();
  cout << "num elements: " << numElements << endl;
  cout << endl;

  checkBool = copyConstructedSortedList.removeLast(deletedValue);
  cout << "Last value removed." << endl;
  cout << "Deleted value: " << deletedValue << endl;
  cout << "Did deleted: " << checkBool << endl;
  copyConstructedSortedList.printForward();
  numElements = copyConstructedSortedList.getNumElems();
  cout << "num elements: " << numElements << endl;
  cout << endl;

  checkBool = copyConstructedSortedList.removeLast(deletedValue);
  cout << "Last value removed." << endl;
  cout << "Deleted value: " << deletedValue << endl;
  cout << "Did deleted: " << checkBool << endl;
  copyConstructedSortedList.printForward();
  numElements = copyConstructedSortedList.getNumElems();
  cout << "num elements: " << numElements << endl;
  cout << endl;

  checkBool = copyConstructedSortedList.removeLast(deletedValue);
  cout << "Last value removed." << endl;
  cout << "Deleted value: " << deletedValue << endl;
  cout << "Did deleted: " << checkBool << endl;
  copyConstructedSortedList.printForward();
  copyConstructedSortedList.printBackward();
  numElements = copyConstructedSortedList.getNumElems();
  cout << "num elements: " << numElements << endl;
  cout << endl;

  // --------- test FIFOQueueClass --------- //
  // default constructor
  cout << "testFIFOlist is made by default constructor." << endl;
  cout << "testFIFOlist: " << endl;
  testFIFOlist.print();
  cout << endl;

  // enqueue & getNumElems
  testFIFOlist.enqueue(10);
  cout << "10 is added to testFIFOlist." << endl;
  cout << "testFIFOlist: " << endl;
  testFIFOlist.print();
  cout << "Number of elements: " << testFIFOlist.getNumElems() << endl;
  cout << endl;
 
  testFIFOlist.enqueue(8);
  cout << "8 is added to testFIFOlist." << endl;
  cout << "testFIFOlist: " << endl;
  testFIFOlist.print();
  cout << "Number of elements: " << testFIFOlist.getNumElems() << endl;
  cout << endl;

  testFIFOlist.enqueue(15);
  cout << "15 is added to testFIFOlist." << endl;
  cout << "testFIFOlist: " << endl;
  testFIFOlist.print();
  cout << "Number of elements: " << testFIFOlist.getNumElems() << endl;
  cout << endl;

  // dequeue & getNumElems
  checkBool = testFIFOlist.dequeue(dequeuedValue);
  cout << "testFIFOlist is dequeued." << endl;
  cout << "Dequeued value: " << dequeuedValue << endl;
  cout << "Did dequeued: " << checkBool << endl;
  cout << "Remaining testFIFOlist: " << endl;
  testFIFOlist.print();
  cout << "Number of elements: " << testFIFOlist.getNumElems() << endl;
  cout << endl;

  checkBool = testFIFOlist.dequeue(dequeuedValue);
  cout << "testFIFOlist is dequeued." << endl;
  cout << "Dequeued value: " << dequeuedValue << endl;
  cout << "Did dequeued: " << checkBool << endl;
  cout << "Remaining testFIFOlist: " << endl;
  testFIFOlist.print();
  cout << "Number of elements: " << testFIFOlist.getNumElems() << endl;
  cout << endl;

  checkBool = testFIFOlist.dequeue(dequeuedValue);
  cout << "testFIFOlist is dequeued." << endl;
  cout << "Dequeued value: " << dequeuedValue << endl;
  cout << "Did dequeued: " << checkBool << endl;
  cout << "Remaining testFIFOlist: " << endl;
  testFIFOlist.print();
  cout << "Number of elements: " << testFIFOlist.getNumElems() << endl;
  cout << endl;
  
  checkBool = testFIFOlist.dequeue(dequeuedValue);
  cout << "testFIFOlist is dequeued." << endl;
  cout << "Dequeued value: " << dequeuedValue << endl;
  cout << "Did dequeued: " << checkBool << endl;
  cout << "Remaining testFIFOlist: " << endl;
  testFIFOlist.print();
  cout << "Number of elements: " << testFIFOlist.getNumElems() << endl;
  cout << endl;

  // clear
  testFIFOlist.enqueue(10);
  testFIFOlist.enqueue(123);
  testFIFOlist.enqueue(53);
  testFIFOlist.enqueue(2);
  testFIFOlist.enqueue(205);
  testFIFOlist.enqueue(24);
  cout << "Several values are enqueued" << endl;
  cout << "testFIFOlist: " << endl;
  testFIFOlist.print();
  cout << "Number of elements: " << testFIFOlist.getNumElems() << endl;
  cout << endl;

  testFIFOlist.clear();
  cout << "testFIFOlist is cleared." << endl;
  cout << "Remaining testFIFOlist: " << endl;
  testFIFOlist.print();
  cout << "Number of elements: " << testFIFOlist.getNumElems() << endl;
  cout << endl;

  // --------- test LIFOStackClass --------- //
  // default constructor
  cout << "testLILOlist is made by default constructor." << endl;
  cout << "testLILOlist: " << endl;
  testLILOlist.print();
  cout << endl;

  // push & getNumElems
  testLILOlist.push(10);
  cout << "10 is added to testLILOlist." << endl;
  cout << "testLILOlist: " << endl;
  testLILOlist.print();
  cout << "Number of elements: " << testLILOlist.getNumElems() << endl;
  cout << endl;
 
  testLILOlist.push(8);
  cout << "8 is added to testLILOlist." << endl;
  cout << "testLILOlist: " << endl;
  testLILOlist.print();
  cout << "Number of elements: " << testLILOlist.getNumElems() << endl;
  cout << endl;

  testLILOlist.push(15);
  cout << "15 is added to testLILOlist." << endl;
  cout << "testLILOlist: " << endl;
  testLILOlist.print();
  cout << "Number of elements: " << testLILOlist.getNumElems() << endl;
  cout << endl;

  // pop & getNumElems
  checkBool = testLILOlist.pop(popedValue);
  cout << "testLILOlist is poped." << endl;
  cout << "poped value: " << popedValue << endl;
  cout << "Did poped: " << checkBool << endl;
  cout << "Remaining testLILOlist: " << endl;
  testLILOlist.print();
  cout << "Number of elements: " << testLILOlist.getNumElems() << endl;
  cout << endl;

  checkBool = testLILOlist.pop(popedValue);
  cout << "testLILOlist is poped." << endl;
  cout << "poped value: " << popedValue << endl;
  cout << "Did poped: " << checkBool << endl;
  cout << "Remaining testLILOlist: " << endl;
  testLILOlist.print();
  cout << "Number of elements: " << testLILOlist.getNumElems() << endl;
  cout << endl;

  checkBool = testLILOlist.pop(popedValue);
  cout << "testLILOlist is poped." << endl;
  cout << "poped value: " << popedValue << endl;
  cout << "Did poped: " << checkBool << endl;
  cout << "Remaining testLILOlist: " << endl;
  testLILOlist.print();
  cout << "Number of elements: " << testLILOlist.getNumElems() << endl;
  cout << endl;
  
  checkBool = testLILOlist.pop(popedValue);
  cout << "testLILOlist is poped." << endl;
  cout << "poped value: " << popedValue << endl;
  cout << "Did poped: " << checkBool << endl;
  cout << "Remaining testLILOlist: " << endl;
  testLILOlist.print();
  cout << "Number of elements: " << testLILOlist.getNumElems() << endl;
  cout << endl;

  // clear
  testLILOlist.push(10);
  testLILOlist.push(123);
  testLILOlist.push(53);
  testLILOlist.push(2);
  testLILOlist.push(205);
  testLILOlist.push(24);
  cout << "Several values are pushd" << endl;
  cout << "testLILOlist: " << endl;
  testLILOlist.print();
  cout << "Number of elements: " << testLILOlist.getNumElems() << endl;
  cout << endl;

  testLILOlist.clear();
  cout << "testLILOlist is cleared." << endl;
  cout << "Remaining testLILOlist: " << endl;
  testLILOlist.print();
  cout << "Number of elements: " << testLILOlist.getNumElems() << endl;
  cout << endl;
}

#endif