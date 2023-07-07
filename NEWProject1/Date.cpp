#include "Date.h"
Date::Date()
{
	setYear(0);
}

Date::Date(int y, int m, int d)//reload of function Date()
{
	setYear(y);
	setMonth(m);
	setDay(d);
}

void Date::setYear(int y)
{
	year = y;
}
int Date::getYear() const
{
	return year;
}

void Date::setMonth(int m)
{
	month = m;
}
int Date::getMonth() const
{
	return month;
}


void Date::setDay(int m)
{
	day = m;
}
int Date::getDay() const
{
	return day;
}


ostream& operator <<(ostream& os, const Date& C)
{
	std::string months[] = { "Invalid month", "January", "February", "March",
						"April", "May", "June", "July", "August",
						"September", "October", "November", "December" };
	os << C.getDay() << " " << months[C.getMonth()] << " " << C.getYear() << endl;
	return os;
}
istream& operator >>(istream& input, Date& C)
{
	int  y, m, d;
	input >> y >> m >> d;

	C.setYear(y);
	C.setMonth(m);
	C.setDay(d);
	return input;
}
//Date time1=Date();
//Date time2 = Date(2023,5,21);
// 
//bool compareNum()
//{
//	return 1;
//}
//
//bool compareNum(int a=0, int b=0)
//{
//	return a > b;
//}
//bool res=compareNum();
//
//bool compareNum(float a, float b)
//{
//	return a > b;
//}
//
//bool compareNum(char a, char b)
//{
//	return a > b;
//}
//
//bool compareNum(char a, char b,char c)
//{
//	return a > b;
//}

