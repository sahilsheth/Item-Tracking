//
//  ShippingStatus.cpp
//  Project2
//
//  Created by Han, Wenlin on 2/13/18.
//  Copyright © 2018 Han, Wenlin. All rights reserved.
//

#include "ShippingStatus.h"

ShippingStatus::ShippingStatus() {
  //to be completed
  stat = "";
  loc = "";
  watch = 0;

}

ShippingStatus::ShippingStatus(const string& status, const string& location, const time_t& timeUpdated) {
  //to be completed
  stat = status;
  loc = location;
  watch = timeUpdated;

}

string ShippingStatus::m_getStatus(){
  //to be completed
  return stat;

}

string ShippingStatus::m_getLocation(){
   //to be completed
   return loc;
}

time_t ShippingStatus::m_getTime() {
    //to be completed
    return watch;
}
