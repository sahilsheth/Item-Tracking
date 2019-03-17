//
//  PackageTracking.cpp
//  Project2
//
//  Created by Han, Wenlin on 2/13/18.
//  Copyright © 2018 Han, Wenlin. All rights reserved.
//

#include "PackageTracking.h"


PackageTracking::PackageTracking()
{
  it= myforward.begin();
  update = 0;
}

PackageTracking::PackageTracking(const string& strnum) {
//to be completed

  snum = strnum;

}

// add a new update
void PackageTracking::m_addUpdate( const string& status, const string& location, const time_t& timeUpdated){
//to be completed
    myforward.push_back (ShippingStatus (status, location, timeUpdated));
    it = myforward.end();
    --it;
}
  
bool PackageTracking::m_moveBackward()//move iterator one step earlier in time
{
//to be completed 
//(note: use it++/it-- to move around list)
//first check if the list is towards the beginning, if it is, dont '--' else 'it--'

    if (it == myforward.begin())
    {
      return false;
    }
    else
    {
      it--;
    }
    return true;
}

bool PackageTracking::m_moveForward()//move iterator one step forward in time
{
  //to be completed 
  //note: use it++/it-- to move around list)
    if(it== myforward.end())
    {
      return false;
    }
    else
    {
      it++;
    }
    return true;
}

string PackageTracking::m_getLocation( )//return the location of the current update
{
//to be completed
  return it->m_getLocation();
}

time_t PackageTracking::m_getTime( )//return the time of the current update
{
//to be completed
  return it->m_getTime();
}

string PackageTracking::m_getStatus( )//return the status of the current update
{
//to be completed
  return it->m_getStatus();
}

int PackageTracking::m_getNumofUpdate() const // get the total numbers of shipping status updates
{
//to be completed
  return update;
}

void PackageTracking::m_printPreviousUpdates() //print all previous updates in the shipping chain when the package was shipped, all the way up to (but not including) the current update you are viewing (may not be the most recent update)
{
//to be completed
  if (myforward.empty())
  {
    cout << "There is no list to be printed" << endl;
  }
  else
  {
    for(it= myforward.begin(); it!= myforward.end(); it--)
    {
      cout << it->m_getStatus() << " " << endl;
      cout << it->m_getLocation() << " "<<endl;
      cout << it->m_getTime()<< " "<<endl;
    }
  }

}

//print all updates from the current update you are viewing to the last update in the tracking chain
void PackageTracking::m_printFollowingUpdates()
{
//to be completed

  if (myforward.empty())
  {
    cout << "List cannot be printed further" << endl;
  }
  else
  {
    for (it = myforward.begin(); it != myforward.end(); it++)
    {
      cout << it->m_getStatus() << " " << endl;
      cout << it->m_getLocation() << " " <<endl;
      cout << it->m_getTime()<< " "<<endl;
    }
  }
}

void PackageTracking::m_printFullTracking()//print all the updates in the tracking chain.
{
//to be completed
  for(it= myforward.begin(); it!= myforward.end(); it++)
  {
   cout << it->m_getStatus() << " " << endl;
   cout << it->m_getLocation() << " " << endl;
   cout << it->m_getTime()<< " "<<endl;
 }

}

bool PackageTracking::m_setCurrent(const time_t& timeUpdated)//view an update.
{
//to be completed
//make loop to move iterator to requested time
//create loop for iterator
for(it= myforward.begin(); it!= myforward.end(); it++)
{
  if (it->m_getTime() == timeUpdated)
  {
      cout << it->m_getStatus() << " " << endl;
      cout << it->m_getLocation() << " " << endl;
      cout << it->m_getTime()<< " "<<endl;
      return true;
  }
}
return false;

}


bool PackageTracking::m_readTrackingFile(string fileName) {
//to be completed
//stringstream , getline using semicolon as a delimiter

//use get line to read into strung, check beginning of string

  ifstream  myfile(fileName.c_str());
  //ifstream  myfile(fileName);


  if(myfile.is_open())
  {
    string sut;
    cout << "Successfully opened up file" <<endl;
    while(getline(myfile,sut))
    {
      if(sut == "new")
      {
        string thenextline;
        getline(myfile, thenextline);
        stringstream mystream(thenextline);
        string status;
        getline(mystream, status, ';');
        string loc;
        getline(mystream, loc, ';');
        time_t watch;
        mystream >> watch;
        m_addUpdate(status, loc, watch);
      }
      else if(sut == "back")
      {
        m_moveBackward();
      }
      else if(sut == "forward")
      {
        m_moveForward();
      }
    }
  }
 return true;
}
