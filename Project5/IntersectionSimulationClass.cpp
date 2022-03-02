#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "IntersectionSimulationClass.h"
#include "random.h"

//Programmer: Youngjun Woo
//Date: December 2021
//Purpose: Made some function(handleArrivalEvent, handleLightChangeEvent,
//         updateMaxQueueLengthStats, getEventExplanation)

void IntersectionSimulationClass::readParametersFromFile(
     const string &paramFname
     )
{
  bool success = true;;
  ifstream paramF;

  paramF.open(paramFname.c_str());

  //Check that the file was able to be opened...
  if (paramF.fail())
  {
    success = false;
    cout << "ERROR: Unable to open parameter file: " << paramFname << endl;
  }
  else
  {
    //Now read in all the params, according to the specified format of
    //the text-based parameter file.
    if (success)
    {
      paramF >> randomSeedVal;
      if (paramF.fail() ||
          randomSeedVal < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set random generatsor seed" << endl;
      }
    }

    if (success)
    {
      paramF >> timeToStopSim;
      if (paramF.fail() ||
          timeToStopSim <= 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set simulation end time" << endl;
      }
    }

    if (success)
    {
      paramF >> eastWestGreenTime >> eastWestYellowTime;
      if (paramF.fail() ||
          eastWestGreenTime <= 0 ||
          eastWestYellowTime <= 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set east-west times" << endl;
      }
    }

    if (success)
    {
      paramF >> northSouthGreenTime >> northSouthYellowTime;
      if (paramF.fail() ||
          northSouthGreenTime <= 0 ||
          northSouthYellowTime <= 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set north-south times" << endl;
      }
    }

    if (success)
    {
      paramF >> eastArrivalMean >> eastArrivalStdDev;
      if (paramF.fail() ||
          eastArrivalMean <= 0 ||
          eastArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set east arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> westArrivalMean >> westArrivalStdDev;
      if (paramF.fail() ||
          westArrivalMean <= 0 ||
          westArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set west arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> northArrivalMean >> northArrivalStdDev;
      if (paramF.fail() ||
          northArrivalMean <= 0 ||
          northArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set north arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> southArrivalMean >> southArrivalStdDev;
      if (paramF.fail() ||
          southArrivalMean <= 0 ||
          southArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set south arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> percentCarsAdvanceOnYellow;
      if (paramF.fail() || 
          percentCarsAdvanceOnYellow < 0 ||
          percentCarsAdvanceOnYellow > 100)
      {
        success = false;
        cout << "ERROR: Unable to read/set percentage yellow advance" << endl;
      }

      //Use the specified seed to seed the random number generator
      setSeed(randomSeedVal);
    }

    paramF.close();
  }

  //Let the caller know whether things went well or not by printing the
  if (!success)
  {
    cout << "ERROR: Parameter file was NOT read in successfully, so the " <<
            "simulation is NOT setup properly!" << endl;
    isSetupProperly = false;
  }
  else
  {
    cout << "Parameters read in successfully - simulation is ready!" << endl;
    isSetupProperly = true;
  }
}

void IntersectionSimulationClass::printParameters() const
{
  cout << "===== Begin Simulation Parameters =====" << endl;
  if (!isSetupProperly)
  {
    cout << "  Simulation is not yet properly setup!" << endl;
  }
  else
  {
    cout << "  Random generator seed: " << randomSeedVal << endl;
    cout << "  Simulation end time: " << timeToStopSim << endl;

    cout << "  East-West Timing -" <<
            " Green: " << eastWestGreenTime << 
            " Yellow: " << eastWestYellowTime <<
            " Red: " << getEastWestRedTime() << endl;

    cout << "  North-South Timing -" <<
            " Green: " << northSouthGreenTime << 
            " Yellow: " << northSouthYellowTime <<
            " Red: " << getNorthSouthRedTime() << endl;

    cout << "  Arrival Distributions:" << endl;
    cout << "    East - Mean: " << eastArrivalMean << 
            " StdDev: " << eastArrivalStdDev << endl;
    cout << "    West - Mean: " << westArrivalMean << 
            " StdDev: " << westArrivalStdDev << endl;
    cout << "    North - Mean: " << northArrivalMean << 
            " StdDev: " << northArrivalStdDev << endl;
    cout << "    South - Mean: " << southArrivalMean << 
            " StdDev: " << southArrivalStdDev << endl;

    cout << "  Percentage cars advancing through yellow: " <<
            percentCarsAdvanceOnYellow << endl;
  }
  cout << "===== End Simulation Parameters =====" << endl;
}

void IntersectionSimulationClass::scheduleArrival(const string &travelDir)
{
  int arrivalTime;
  double arrivalMean;
  double arrivalStdDev;
  int eventType;
 
  if (travelDir == EAST_DIRECTION)
  {
    arrivalMean = eastArrivalMean;
    arrivalStdDev = eastArrivalStdDev;  
    eventType = EVENT_ARRIVE_EAST;
  }

  else if (travelDir == WEST_DIRECTION)
  {
    arrivalMean = westArrivalMean;
    arrivalStdDev = westArrivalStdDev;  
    eventType = EVENT_ARRIVE_WEST;
  }

  else if (travelDir == NORTH_DIRECTION)
  {
    arrivalMean = northArrivalMean;
    arrivalStdDev = northArrivalStdDev;  
    eventType = EVENT_ARRIVE_NORTH;
  }

  else if (travelDir == SOUTH_DIRECTION)
  {
    arrivalMean = southArrivalMean;
    arrivalStdDev = southArrivalStdDev;  
    eventType = EVENT_ARRIVE_SOUTH;
  }

  else
  {
    arrivalMean = 0;
    arrivalStdDev = 0;
    eventType = EVENT_UNKNOWN;   
  }

  arrivalTime = getPositiveNormal(arrivalMean, arrivalStdDev);
  EventClass eventArrival(currentTime + arrivalTime, eventType);  
  eventList.insertValue(eventArrival);  

  cout << "Time: " << currentTime << " " 
       << "Scheduled Event Type: " << getEventExplanation(eventType) << " "
       << "Time: " << currentTime + arrivalTime << endl;
}

void IntersectionSimulationClass::scheduleLightChange()
{
  int duration;
  int nextEventType;
  
  if (currentLight == LIGHT_GREEN_EW)
  {
    duration = eastWestGreenTime;
    nextEventType = EVENT_CHANGE_YELLOW_EW;
  }

  else if (currentLight == LIGHT_YELLOW_EW)
  {
    duration = eastWestYellowTime;
    nextEventType = EVENT_CHANGE_GREEN_NS;
  }

  else if (currentLight == LIGHT_GREEN_NS)
  {
    duration = northSouthGreenTime;
    nextEventType = EVENT_CHANGE_YELLOW_NS;
  }

  else if (currentLight == LIGHT_YELLOW_NS)
  {
    duration = northSouthYellowTime;
    nextEventType = EVENT_CHANGE_GREEN_EW;
  }

  else
  {
    duration = 0;
    nextEventType = EVENT_UNKNOWN;  
  }

  EventClass eventLightChange(currentTime + duration, nextEventType);
  eventList.insertValue(eventLightChange);

  cout << "Time: " << currentTime << " " 
       << "Scheduled Event Type: " << getEventExplanation(nextEventType) << " "
       << "Time: " << currentTime + duration << endl; 
}

void IntersectionSimulationClass::updateMaxQueueLengthStats()
{
  if (eastQueue.getNumElems() > maxEastQueueLength)
  {
    maxEastQueueLength = eastQueue.getNumElems();  
  }     
  
  if (westQueue.getNumElems() > maxWestQueueLength)
  {
    maxWestQueueLength = westQueue.getNumElems();  
  }

  if (northQueue.getNumElems() > maxNorthQueueLength)
  {
    maxNorthQueueLength = northQueue.getNumElems();  
  }    

  if (southQueue.getNumElems() > maxSouthQueueLength)
  {
    maxSouthQueueLength = southQueue.getNumElems();   
  }
}

string IntersectionSimulationClass::handleArrivalEvent(EventClass currentEvent)                                                     
{
  int queLength;
  int carId;
  string direction;

  if (currentEvent.getType() == EVENT_ARRIVE_EAST)
  {
    direction = EAST_DIRECTION; 
    
    CarClass car(direction, currentTime);
    carId = car.getId();
    eastQueue.enqueue(car);   
    queLength = eastQueue.getNumElems();
  }
  
  else if (currentEvent.getType() == EVENT_ARRIVE_WEST)
  {
    direction = WEST_DIRECTION;    
    
    CarClass car(direction, currentTime);
    carId = car.getId();
    westQueue.enqueue(car);
    queLength = westQueue.getNumElems();
  }
  
  else if (currentEvent.getType() == EVENT_ARRIVE_NORTH)
  {
    direction = NORTH_DIRECTION; 

    CarClass car(direction, currentTime);
    carId = car.getId();
    northQueue.enqueue(car);   
    queLength = northQueue.getNumElems();
  }
  
  else
  {
    direction = SOUTH_DIRECTION;  

    CarClass car(direction, currentTime);
    carId = car.getId();
    southQueue.enqueue(car);  
    queLength = southQueue.getNumElems();
  }

  cout << "Time: " << currentTime << " " 
       << "Car #" << carId << " arrives " << direction << "-bound" 
       << " - queue length: " << queLength << endl;
  
  return direction;
}

void IntersectionSimulationClass::handleLightChangeEvent(EventClass 
                                                         currentEvent)
{
  CarClass advancedCar;
  int numAdvancedEast = 0;
  int numAdvancedWest = 0;
  int numAdvanceNorth = 0;
  int numAdvanceSouth = 0;
  int i;
  bool isEnd;
  int intFromUniform;

  // 1. EVENT_CHANGE_YELLOW_EW   
  if (currentEvent.getType() == EVENT_CHANGE_YELLOW_EW)
  {
    cout << "Advancing cars on east-west green" << endl;

    // advance east bound cars  
    if (eastQueue.getNumElems() != 0)
    {
      i = 0;
      isEnd = false;
      numAdvancedEast = 0;
      while (!isEnd)
      {
        eastQueue.dequeue(advancedCar);
        cout << "  Car #" << advancedCar.getId() << " advances east-bound" 
             << endl;
        numAdvancedEast ++;   

        i ++;

        if (eastQueue.getNumElems() == 0 or i == eastWestGreenTime)
        {
          isEnd = true;  
        }
      }    
    }
    
    // advance west bound cars
    if (westQueue.getNumElems() != 0)
    {
      i = 0;
      isEnd = false;
      numAdvancedWest = 0;
      while (!isEnd)
      {
        westQueue.dequeue(advancedCar);
        cout << "  Car #" << advancedCar.getId() << " advances west-bound" 
             << endl;
        numAdvancedWest ++;    

        i ++;

        if (westQueue.getNumElems() == 0 or i == eastWestGreenTime)
        {
          isEnd = true;  
        }
      }  
    }

    cout << "East-bound cars advanced on green: " << numAdvancedEast << " "
         << "Remaining queue: " << eastQueue.getNumElems() << endl;
    cout << "West-bound cars advanced on green: " << numAdvancedWest << " "
         << "Remaining queue: " << westQueue.getNumElems() << endl;     
    
    // update total advance related statistics
    numTotalAdvancedEast += numAdvancedEast;
    numTotalAdvancedWest += numAdvancedWest;

    // update current light
    currentLight = LIGHT_YELLOW_EW; 
  }

  // 2. EVENT_CHANGE_YELLOW_NS   
  if (currentEvent.getType() == EVENT_CHANGE_YELLOW_NS)
  {
    cout << "Advancing cars on north-south green" << endl;

    // advance north bound cars  
    if (northQueue.getNumElems() != 0)
    {
      i = 0;
      isEnd = false;
      numAdvanceNorth = 0;
      while (!isEnd)
      {
        northQueue.dequeue(advancedCar);
        cout << "  Car #" << advancedCar.getId() << " advances north-bound" 
             << endl;
        numAdvanceNorth ++;   

        i ++;

        if (northQueue.getNumElems() == 0 or i == northSouthGreenTime)
        {
          isEnd = true;  
        }
      }  
    }

    // advance south bound cars
    if (southQueue.getNumElems() != 0)
    {
      i = 0;
      isEnd = false;
      numAdvanceSouth = 0;
      while (!isEnd)
      {
        southQueue.dequeue(advancedCar);
        cout << "  Car #" << advancedCar.getId() << " advances south-bound" 
             << endl;
        numAdvanceSouth ++;    

        i ++;

        if (southQueue.getNumElems() == 0 or i == northSouthGreenTime)
        {
          isEnd = true;  
        }
      }   
    }

    cout << "North-bound cars advanced on green: " << numAdvanceNorth << " "
         << "Remaining queue: " << northQueue.getNumElems() << endl;
    cout << "South-bound cars advanced on green: " << numAdvanceSouth << " "
         << "Remaining queue: " << southQueue.getNumElems() << endl;     
    
    // update total advance related statistics
    numTotalAdvancedNorth += numAdvanceNorth;
    numTotalAdvancedSouth += numAdvanceSouth;

    // update current light
    currentLight = LIGHT_YELLOW_NS; 
  }
  
  // 3. EVENT_CHANGE_GREEN_NS
  else if (currentEvent.getType() == EVENT_CHANGE_GREEN_NS)
  {
    cout << "Advancing cars on east-west yellow" << endl;
    
    // advance east bound cars
    if (eastQueue.getNumElems() == 0)
    {
      cout << "  No east-bound cars waiting to advance on yellow" << endl;  
    }

    else
    {
      i = 0;
      isEnd = false;
      numAdvancedEast = 0;
      while (!isEnd)
      {
        intFromUniform = getUniform(1, 100);

        if (intFromUniform <= percentCarsAdvanceOnYellow)
        {
          cout << "  Next east-bound car will advance on yellow" << endl;
          eastQueue.dequeue(advancedCar);
          cout << "  Car #" << advancedCar.getId() << " advances east-bound" 
               << endl;
          numAdvancedEast ++;  

          i ++;  

          if (eastQueue.getNumElems() == 0) 
          {
            cout << "  No east-bound cars waiting to advance on yellow" 
                 << endl;
            
            isEnd = true;  
          }

          else if (i == eastWestYellowTime)
          {
            isEnd = true;  
          }
        }

        else
        {
          cout << "  Next east-bound car will NOT advance on yellow" << endl;  
          
          isEnd = true;
        }
      }
    }

    // advance west bound cars
    if (westQueue.getNumElems() == 0)
    {
      cout << "  No west-bound cars waiting to advance on yellow" << endl;  
    }

    else
    {
      i = 0;
      isEnd = false;
      numAdvancedWest = 0;
      while (!isEnd)
      {
        intFromUniform = getUniform(1, 100);

        if (intFromUniform <= percentCarsAdvanceOnYellow)
        {
          cout << "  Next west-bound car will advance on yellow" << endl;
          westQueue.dequeue(advancedCar);
          cout << "  Car #" << advancedCar.getId() << " advances west-bound" 
               << endl;
          numAdvancedWest ++;  

          i ++;  

          if (westQueue.getNumElems() == 0) 
          {
            cout << "  No west-bound cars waiting to advance on yellow" 
                 << endl;
            
            isEnd = true;  
          }

          else if (i == eastWestYellowTime)
          {
            isEnd = true;  
          }
        }

        else
        {
          cout << "  Next west-bound car will NOT advance on yellow" << endl;  
          
          isEnd = true;
        }
      }
    }

    cout << "East-bound cars advanced on yellow: " << numAdvancedEast << " "
         << "Remaining queue: " << eastQueue.getNumElems() << endl;
    cout << "West-bound cars advanced on yellow: " << numAdvancedWest << " "
         << "Remaining queue: " << westQueue.getNumElems() << endl;     
    
    // update total advance related statistics
    numTotalAdvancedEast += numAdvancedEast;
    numTotalAdvancedWest += numAdvancedWest;

    // update current light
    currentLight = LIGHT_GREEN_NS;  
  }

  // 4. EVENT_CHANGE_GREEN_EW
  else if (currentEvent.getType() == EVENT_CHANGE_GREEN_EW)
  {
    cout << "Advancing cars on north-south yellow" << endl;
    
    // advance north bound cars
    if (northQueue.getNumElems() == 0)
    {
      cout << "  No north-bound cars waiting to advance on yellow" << endl;  
    }

    else
    {
      i = 0;
      isEnd = false;
      numAdvanceNorth = 0;
      while (!isEnd)
      {
        intFromUniform = getUniform(1, 100);

        if (intFromUniform <= percentCarsAdvanceOnYellow)
        {
          cout << "  Next north-bound car will advance on yellow" << endl;
          northQueue.dequeue(advancedCar);
          cout << "  Car #" << advancedCar.getId() << " advances north-bound" 
               << endl;
          numAdvanceNorth ++;  

          i ++;  

          if (northQueue.getNumElems() == 0)
          {
            cout << "  No north-bound cars waiting to advance on yellow" 
                 << endl;

            isEnd = true;  
          }

          else if (i == northSouthYellowTime)
          {
            isEnd = true;  
          }
        }

        else
        {
          cout << "  Next north-bound car will NOT advance on yellow" << endl;  
          
          isEnd = true;
        }
      }
    }

    // advance south bound cars
    if (southQueue.getNumElems() == 0)
    {
      cout << "  No south-bound cars waiting to advance on yellow" << endl;  
    }

    else
    {
      i = 0;
      isEnd = false;
      numAdvanceSouth = 0;
      while (!isEnd)
      {
        intFromUniform = getUniform(1, 100);

        if (intFromUniform <= percentCarsAdvanceOnYellow)
        {
          cout << "  Next south-bound car will advance on yellow" << endl;
          southQueue.dequeue(advancedCar);
          cout << "  Car #" << advancedCar.getId() << " advances south-bound" 
               << endl;
          numAdvanceSouth ++;  

          i ++;  

          if (southQueue.getNumElems() == 0)
          {
            cout << "  No south-bound cars waiting to advance on yellow" 
                 << endl;

            isEnd = true;  
          }
          
          else if (i == northSouthYellowTime)
          {
            isEnd = true;  
          }
        }

        else
        {
          cout << "  Next south-bound car will NOT advance on yellow" << endl;  
          
          isEnd = true;
        }
      }
    }

    cout << "North-bound cars advanced on yellow: " << numAdvanceNorth << " "
         << "Remaining queue: " << northQueue.getNumElems() << endl;
    cout << "South-bound cars advanced on yellow: " << numAdvanceSouth << " "
         << "Remaining queue: " << southQueue.getNumElems() << endl;     
    
    // update total advance related statistics
    numTotalAdvancedNorth += numAdvanceNorth;
    numTotalAdvancedSouth += numAdvanceSouth;

    // update current light
    currentLight = LIGHT_GREEN_EW;  
  }    
}

bool IntersectionSimulationClass::handleNextEvent()
{
  EventClass currentEvent;
  eventList.removeFront(currentEvent);

  currentTime = currentEvent.getTimeOccurs();
  
  // If the next event's scheduled time occurs after the specified simulation 
  // end time, return false.
  if (currentTime > timeToStopSim)
  {
    cout << endl;
    cout << "Next event occurs AFTER the simulation end time (Event Type: "
         << getEventExplanation(currentEvent.getType()) << " "
         << "Time: " << currentTime << ")!" << endl;
    
    return false;  
  }
  
  // If not, handle current event.
  else
  {
    cout << endl;
    cout << "Handling Event Type: " 
         << getEventExplanation(currentEvent.getType()) << " "
         << "Time: " << currentTime << endl;

    // -- 1. handling arrival event
    string direction;

    if (currentEvent.getType() == EVENT_ARRIVE_EAST or 
        currentEvent.getType() == EVENT_ARRIVE_WEST or 
        currentEvent.getType() == EVENT_ARRIVE_NORTH or 
        currentEvent.getType() == EVENT_ARRIVE_SOUTH)
    {
      direction = handleArrivalEvent(currentEvent);
      scheduleArrival(direction);  
      updateMaxQueueLengthStats(); 
    }

    // -- 2. handling light change event
    if (currentEvent.getType() == EVENT_CHANGE_GREEN_EW or
        currentEvent.getType() == EVENT_CHANGE_YELLOW_EW or
        currentEvent.getType() == EVENT_CHANGE_GREEN_NS or
        currentEvent.getType() == EVENT_CHANGE_YELLOW_NS)
    {
      handleLightChangeEvent(currentEvent); 
      scheduleLightChange();         
    }

    return true;
  }
}

void IntersectionSimulationClass::printStatistics(
     ) const
{
  cout << "===== Begin Simulation Statistics =====" << endl;
  cout << "  Longest east-bound queue: " << maxEastQueueLength << endl;
  cout << "  Longest west-bound queue: " << maxWestQueueLength << endl;
  cout << "  Longest north-bound queue: " << maxNorthQueueLength << endl;
  cout << "  Longest south-bound queue: " << maxSouthQueueLength << endl;
  cout << "  Total cars advanced east-bound: " <<
          numTotalAdvancedEast << endl;
  cout << "  Total cars advanced west-bound: " <<
          numTotalAdvancedWest << endl;
  cout << "  Total cars advanced north-bound: " <<
          numTotalAdvancedNorth << endl;
  cout << "  Total cars advanced south-bound: " <<
          numTotalAdvancedSouth << endl;
  cout << "===== End Simulation Statistics =====" << endl;
}

string IntersectionSimulationClass::getEventExplanation(int eventType)                                                        
{
  string outExplanation;

  if (eventType == EVENT_ARRIVE_EAST)
  {
    outExplanation = "East-Bound Arrival";  
  }  

  else if (eventType == EVENT_ARRIVE_WEST)
  {
    outExplanation = "West-Bound Arrival";  
  }

  else if (eventType == EVENT_ARRIVE_NORTH)
  {
    outExplanation = "North-Bound Arrival";  
  } 

  else if (eventType == EVENT_ARRIVE_SOUTH)
  {
    outExplanation = "South-Bound Arrival";  
  } 

  else if (eventType == EVENT_CHANGE_GREEN_EW)
  {
    outExplanation = "Light change to EW Green";  
  } 

  else if (eventType == EVENT_CHANGE_YELLOW_EW)
  {
    outExplanation = "Light change to EW Yellow";  
  } 

  else if (eventType == EVENT_CHANGE_GREEN_NS)
  {
    outExplanation = "Light change to NS Green";   
  } 

  else if (eventType == EVENT_CHANGE_YELLOW_NS)
  {
    outExplanation = "Light change to NS Yellow";   
  } 

  return outExplanation;
}
