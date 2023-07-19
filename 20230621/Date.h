#ifndef Date_h__
#define Date_h__

#include <iostream>
#include <sstream>
#include<string>

using namespace std;
class Date
{
public:
	Date();
	Date(int y, int m, int d);
	void SetYear(int y);
	int GetYear() const;

	void SetMonth(int m);//TO DO: impl
	int GetMonth() const;//TO DO: impl

	void SetDay(int y);//TO DO: impl
	int GetDay() const;//TO DO: impl
	void SetDate(string date);

	//friend ostream& operator <<(ostream& os, const Date& C);//os相当于cout，是系统自带的，C是另外一个操作数（类型为Date）
	//friend istream& operator >>(istream& input, Date& C);//istream&时返回类型，返回的是一个输入流,具体是操作系统自己定义的一个basic类。
	////友元函数 可以直接访问私有变量C.Year
private:
	int m_year;
	int m_month;
	int m_day;
};

ostream& operator <<(ostream& os, const Date& C);
istream& operator >>(istream& input, Date& C);

bool operator>(const Date& lhs, const Date& rhs);
bool operator<(const Date& lhs, const Date& rhs);


#endif // Date_h__
