#include "Time.h"
#include <sstream>
Time::Time()
{
	hour = 0;
	minute = 0;
}

Time::Time(int h, int m)
{
	hour = h;
	minute = m;
}

int Time::getHour()
{
	return hour;
}
void Time::setHour(int h)
{
	hour = h;
}
int Time::getMin()
{
	return minute;
}
void Time::setMin(int m)
{
	minute = m;
}
void Time::setTime(int h, int m)
{
	//minute = m;
	//hour = h;
	setMin(m);
	setHour(h);
}

void Time::setTime(std::string time)
{
	std::string hour, minute;
	std::stringstream singleTime(time);
	getline(singleTime, hour, ':');
	getline(singleTime, minute, ':');
	setTime(atoi(hour.c_str()), atoi(minute.c_str()));
}

