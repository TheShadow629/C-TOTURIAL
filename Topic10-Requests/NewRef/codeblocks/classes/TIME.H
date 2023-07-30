#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string.h>  // C string library
#include <sstream>

using namespace std;

class Time {

    /**
    * @class Time
    * @brief It stores the Time
    *
    * The Time includes the hour and the minute
    *
    * @author Noor Hidayat
    */
public:
    /**
    *   The Time default constructor initializes hour and minute to a value of 0.
    */
    Time();

    /**
    * Time Constructor
    * @param hour The hour of the time
    * @param minute The minute of the time
    */
    Time(int hour, int minute);

    /**
    * Get the hour of the time
    */
    const int getHour() const;

    /**
    * Get the minute of the time
    */
    const int getMinute() const;

    /**
    * Set the hour of the time
    * @param hour Contains the hour of the time to set to
    */
    void setHour(const int hour);

    /**
    * Set the minute of the time
    * @param minute Contains the minute of the time to set to
    */
    void setMinute(const int minute);

    bool operator < (const Time& t) const;

    bool operator > (const Time& t) const;

    bool operator==(Time& obj);

    /* debug */
    void print_time() const;

private:
    /** Stores an integer hour of the time */
    int m_hour;
    /** Stores an integer minute of the time */
    int m_minute;
};

    /**
    * @brief Operator overload for input
    * @param input is the input stream
    * @param T is the object for Time
    */
istream & operator >>( istream & input, Time & T);

    /**
    * @brief Operator overload for output
    * @param os is the output stream
    * @param T is the object for Time
    */
ostream & operator <<( ostream & os, const Time & T);

#endif // TIME_H
