#ifndef Time_h__
#define Time_h__

#include<string>

class Time
{
public:
	Time();
	Time(int h,int m);
	int GetHour();
	void SetHour(int h);
	int GetMin();
	void SetMin(int m);
	void SetTime(int h, int m);
	void SetTime(std::string time);

private:
	int m_hour;
	int m_minute;
};
#endif // Time_h__
