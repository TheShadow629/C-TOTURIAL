#ifndef Date_h__
#define Date_h__
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

	void SetMonth(int m);
	int GetMonth() const;

	void SetDay(int y);
	int GetDay() const;
	void SetDate(string date);

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
