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

	//friend ostream& operator <<(ostream& os, const Date& C);//os�൱��cout����ϵͳ�Դ��ģ�C������һ��������������ΪDate��
	//friend istream& operator >>(istream& input, Date& C);//istream&ʱ�������ͣ����ص���һ��������,�����ǲ���ϵͳ�Լ������һ��basic�ࡣ
	////��Ԫ���� ����ֱ�ӷ���˽�б���C.Year
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
