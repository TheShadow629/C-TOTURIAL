#ifndef TIMETEST_HPP
#define TIMETEST_HPP

#include <iostream>
#include "TestLib.hpp"//test library
#include "../TIME.H"

using namespace std;

// Forward declaration
void TimeTest();

// Implementation
void TimeTest()
{
    header("TIME TEST");

    section("Test Default Constructor");
    Time v1;
    v1.print_time(); //debug
    require<int>(v1.getHour(), 0, "An empty TIME obj should have a hour value of 0");
    require<int>(v1.getMinute(), 0, "An empty TIME obj should have a minute value of 0");

    section("Test Default Constructor with Parameter Time(10, 35)");
    Time v2(10,35);
    v2.print_time(); //debug
    require<int>(v2.getHour(), 10, "The hour is initialized a value of 10");
    require<int>(v2.getMinute(), 35, "The minute is initialized a value of 35");

    section("Test get and set hour and minute");
    Time v3;
    v3.setHour(5);
    v3.setMinute(30);
    int hour = v3.getHour();
    int minute = v3.getMinute();
    v3.print_time(); //debug
    require<int>(v3.getHour(), hour, "The hour is set to 5. Get is working.");
    require<int>(v3.getMinute(), minute, "The minute is set to 30. Get is working");

    section("Test double equal operator. 2 Time obj have the same hour and minute");
    Time v4(2,55);
    v4.print_time(); //debug
    Time v5(2, 55);
    v5.print_time(); //debug
    require<int>(v4 == v5, true, "Both hour and minute are the same. Should return true");
}


#endif // TIMETEST_HPP
