#ifndef DATETEST_HPP
#define DATETEST_HPP

#include <iostream>
#include "TestLib.hpp"//test library
#include "../DATE.H"

using namespace std;

// Forward declaration
void DateTest();

// Implementation
void DateTest()
{
    header("DATE TEST");

    section("Test Default Constructor");
    Date v1;
    v1.print_date(); //debug
    require<int>(v1.GetDay(), 0, "An empty DATE obj should have a day value of 0");

    section("Test Default Constructor with parameter with invalid day and month input. Date v3(50, 50, 0)");
    Date v3(50, 50, 0);
    v3.print_date(); //debug
    require<int>(v3.GetDay(), 0, "Day defaults to 0");
    require<int>(v3.GetMonthNum(), 1, "Month defaults to 1");

    section("Test get month's name");
    require<string>(v3.GetMonthName(), "January", "Month 1 should return January");

    section("Test set Day and Month and Year. Date v2; v2.SetDay(16); v2.SetMonthNum(7); v2.SetYear(2022);");
    Date v2;
    v2.SetDay(16);
    v2.SetMonthNum(7);
    v2.SetYear(2022);
    v2.print_date(); //debug
    require<int>(v2.GetDay(), 16, "Day should be 16");
    require<int>(v2.GetMonthNum(), 7, "Month should be numerical of July which is 7");
    require<int>(v2.GetYear(), 2022, "Year should be 2022");


}


#endif // DATETEST_HPP
