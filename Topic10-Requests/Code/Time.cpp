#include "Time.h"
#include <sstream>
Time::Time()
{
	m_hour = 0;
	m_minute = 0;
}

Time::Time(int h, int m)
{
	m_hour = h;
	m_minute = m;
}

int Time::GetHour()
{
	return m_hour;
}
void Time::SetHour(int h)
{
	m_hour = h;
}
int Time::GetMin()
{
	return m_minute;
}
void Time::SetMin(int m)
{
	m_minute = m;
}
void Time::SetTime(int h, int m)
{
	//minute = m;
	//hour = h;
	SetMin(m);
	SetHour(h);
}

void Time::SetTime(std::string time)
{
	std::string hour, minute;
	std::stringstream singleTime(time);
	getline(singleTime, hour, ':');
	getline(singleTime, minute, ':');
	SetTime(atoi(hour.c_str()), atoi(minute.c_str()));
}

