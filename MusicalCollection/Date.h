#pragma once

#include <iostream>
#include <cstring>

class Date
{
    int year, month, day;

public:
    Date(const int _y = 1, const int _m = 1, const int _d = 1);

    bool operator == (Date otherDateTime);
    bool operator < (Date otherDateTime);
    bool operator > (Date otherDateTime);
    bool operator <= (Date otherDateTime);
    bool operator >= (Date otherDateTime);

    int getDay();
    int getMonth();
    int getYear();

    friend std::ostream& operator << (std::ostream& output, const Date& dt);
};