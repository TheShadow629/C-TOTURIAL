#ifndef Time_h__
#define Time_h__

#include<string>

class Time
{
public:
	Time();
	Time(int h,int m);
	int getHour();
	void setHour(int h);
	int getMin();
	void setMin(int m);
	void setTime(int h, int m);
	void setTime(std::string time);

private:
	int hour;
	int minute;
};
#endif // Time_h__
