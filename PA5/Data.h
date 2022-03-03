#pragma once

#include <iostream>

using std::endl;
using std::ostream;

class Data {
public:
    Data(int customerNumber, int serviceTime, int totalTime);

    int getCustomerNumber(void) const;
    void setCustomerNumber(int number);

    int getServiceTime(void) const;
    void setServiceTime(int time);
    void decrementServiceTime(void);

    int getTotalTime(void) const;
    void setTotalTime(int time);
private:
    int mCustomerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
    int mServiceTime;   // Random time; varies between express and normal lanes; units in minutes
    int mTotalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
};

ostream& operator<< (ostream& lhs, const Data& rhs);