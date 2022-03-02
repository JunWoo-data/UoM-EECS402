#include <iostream>
using namespace std;

#include "EventClass.h"
#include "constants.h"

//Programmer: Andrew Morgan
//Date: November 2020
//Purpose: A simple class to represent event objects that can be used in
//         an event-driven simulation.  The overloaded insertion operator
//         for this class ties it to a simulation of traffic flow through
//         an intersection managed by a traffic light, but the rest of
//         the class is intended to be more generic to represent events
//         in most event-driven simulations.

//Programmer: Youngjun Woo
//Date: December 2021
//Purpose: Made overloaded operators(operator>, operator<=) that 
//         SortedListClass needs in order to sort event class objects. 

ostream& operator<<(
     ostream& outStream,
     const EventClass &eventToPrint
     )
{
  outStream << "Event Type: ";
  if (eventToPrint.typeId == EVENT_ARRIVE_EAST)
  {
    outStream << "East-Bound Arrival";
  }
  else if (eventToPrint.typeId == EVENT_ARRIVE_WEST)
  {
    outStream << "West-Bound Arrival";
  }
  else if (eventToPrint.typeId == EVENT_ARRIVE_NORTH)
  {
    outStream << "North-Bound Arrival";
  }
  else if (eventToPrint.typeId == EVENT_ARRIVE_SOUTH)
  {
    outStream << "South-Bound Arrival";
  }
  else if (eventToPrint.typeId == EVENT_CHANGE_GREEN_EW)
  {
    outStream << "Light Change to EW Green";
  }
  else if (eventToPrint.typeId == EVENT_CHANGE_YELLOW_EW)
  {
    outStream << "Light Change to EW Yellow";
  }
  else if (eventToPrint.typeId == EVENT_CHANGE_GREEN_NS)
  {
    outStream << "Light Change to NS Green";
  }
  else if (eventToPrint.typeId == EVENT_CHANGE_YELLOW_NS)
  {
    outStream << "Light Change to NS Yellow";
  }
  else
  {
    outStream << "UNKNOWN";
  }
  outStream << " Time: " << eventToPrint.timeOccurs;
  return outStream;
}

//To implement overloaded operators that SortedListClass needs in order to 
//sort event class objects. An event "A" is "less than" an event "B" if
//"A"'s time is less than "B"'s time.
bool EventClass::operator>(const EventClass rhs)
{
  if (timeOccurs > rhs.getTimeOccurs())
  {
    return true;  
  }

  else
  {
    return false;  
  }
}

bool EventClass::operator<=(const EventClass rhs)
{
  if (timeOccurs <= rhs.getTimeOccurs())
  {
    return true;  
  }

  else
  {
    return false;  
  }  
}

