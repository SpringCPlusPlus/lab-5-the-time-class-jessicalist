#include <iostream>
#include "../include/Time.h"
using namespace std;

// Overload the + operator
Time Time::operator+(const Time &other) const
{
    int h = hours + other.hours;
    int m = (minutes + other.minutes);
    int newM = m % 60;
    h = h + ((m - newM) / 60) % 24;
    
    return Time(h, newM);
}

// Overload the += operator
Time& Time::operator+=(const Time &other)
{   
//i hatw this shit
    *this = *this + other;
    return *this;
}

// Overload the < operator
bool Time::operator<(const Time &other) const
{
    if(hours > other.hours){
        return false;
    }
    else if (hours < other.hours){
        return true;
    }
    else{
        return minutes < other.minutes;
    } 
}

// Overload the > operator
bool Time::operator>(const Time &other) const
{
    return other < *this;
}

// Overload the == operator
bool Time::operator==(const Time &other) const
{
    return hours == other.hours && minutes == other.minutes;
}

// Overload the friend function operator<<
ostream &operator<<(ostream &os, const Time &tm)
{
    os << tm.hours << ":" << tm.minutes;
    return os;
}
