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



	//friend ostream& operator <<(ostream& os, const Date& C);//os�൱��cout����ϵͳ�Դ��ģ�C������һ��������������ΪDate��
	//friend istream& operator >>(istream& input, Date& C);//istream&ʱ�������ͣ����ص���һ��������,�����ǲ���ϵͳ�Լ������һ��basic�ࡣ
	////��Ԫ���� ����ֱ�ӷ���˽�б���C.Year
private:
	int year;
	int month;
	int day;
};

ostream& operator <<(ostream& os, const Date& C);
istream& operator >>(istream& input, Date& C);



