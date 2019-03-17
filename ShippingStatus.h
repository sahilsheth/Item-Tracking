//
//  ShippingStatus.h
//  Project2
//
//  Created by Han, Wenlin on 2/13/18.
//  Copyright © 2018 Han, Wenlin. All rights reserved.
//

#ifndef ShippingStatus_h
#define ShippingStatus_h

#pragma once

#include <string>
using namespace std;

class ShippingStatus {
public:
    ShippingStatus();
    ShippingStatus(const string& status, const string& location, const time_t& timeUpdated );

    string m_getStatus();
    string m_getLocation();
    time_t m_getTime();

private:
    string stat;
    string loc;
    time_t watch;

};


#endif /* ShippingStatus_h */
