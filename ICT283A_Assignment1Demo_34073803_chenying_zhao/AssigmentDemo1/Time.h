#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED


#include<iostream>
#include<string>
#include <sstream>
#include "Date.h"
using namespace std;

class Time
{
public:
    int hours;
    int min;
    int second;
};

class Date_Time
{
public:
    Date date;
    Time time;
};

Date_Time getDataTime(string data);
string    getMouthEnglish(int month); 
  
#endif
