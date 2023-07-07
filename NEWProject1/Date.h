#pragma once

#include <iostream>
using namespace std;
class Date
{
public:
	Date();
	Date(int y, int m, int d);
	void setYear(int y);
	int getYear() const;

	void setMonth(int m);//TO DO: impl
	int getMonth() const;//TO DO: impl

	void setDay(int y);//TO DO: impl
	int getDay() const;//TO DO: impl



	//friend ostream& operator <<(ostream& os, const Date& C);//os相当于cout，是系统自带的，C是另外一个操作数（类型为Date）
	//friend istream& operator >>(istream& input, Date& C);//istream&时返回类型，返回的是一个输入流,具体是操作系统自己定义的一个basic类。
	////友元函数 可以直接访问私有变量C.Year
private:
	int year;
	int month;
	int day;
};

ostream& operator <<(ostream& os, const Date& C);
istream& operator >>(istream& input, Date& C);



