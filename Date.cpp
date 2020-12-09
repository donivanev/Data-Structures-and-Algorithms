#include "Date.h"

Date::Date(const int _y, const int _m, const int _d)
{
    this->year = _y;
    this->month = _m;
    this->day = _d;
}

Date& Date::operator=(const Date& other)
{
    if (this != &other)
    {
        this->year = other.year;
        this->month = other.month;
        this->day = other.day;

        return *this;
    }
}

bool Date::operator == (Date otherDate)
{
    if (this->year == otherDate.year && this->month == otherDate.month && this->day == otherDate.day)
    {
        return true;
    }

    return false;
}

bool Date::operator < (Date otherDate)
{
    if (this->year < otherDate.year)
    {
        return true;
    }
    else if (this->year == otherDate.year && this->month < otherDate.month)
    {
        return true;
    }
    else if (this->year == otherDate.year && this->month == otherDate.month && this->day < otherDate.day)
    {
        return true;
    }

    return false;
}

bool Date::operator <= (Date otherDate)
{
    if (this->year < otherDate.year)
    {
        return true;
    }
    else if (this->year == otherDate.year && this->month < otherDate.month)
    {
        return true;
    }
    else if (this->year == otherDate.year && this->month == otherDate.month && this->day <= otherDate.day)
    {
        return true;
    }

    return false;
}

bool Date::operator > (Date otherDate)
{
    if (this->year > otherDate.year)
    {
        return true;
    }
    else if (this->year == otherDate.year && this->month > otherDate.month)
    {
        return true;
    }
    else if (this->year == otherDate.year && this->month == otherDate.month && this->day > otherDate.day)
    {
        return true;
    }

    return false;
}

bool Date::operator >= (Date otherDate)
{
    if (this->year > otherDate.year)
    {
        return true;
    }
    else if (this->year == otherDate.year && this->month > otherDate.month)
    {
        return true;
    }
    else if (this->year == otherDate.year && this->month == otherDate.month && this->day >= otherDate.day)
    {
        return true;
    }

    return false;
}

int Date::getDay()
{
    return this->day;
}

int Date::getMonth()
{
    return this->month;
}

int Date::getYear()
{
    return this->year;
}

std::ostream& operator << (std::ostream& output, const Date& dt)
{
    output << dt.year << " " << dt.month << " " << dt.day;
    return output;
}