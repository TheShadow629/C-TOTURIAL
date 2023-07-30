
#include "Date.h"
Date::Date()
{
	SetYear(0);
}

Date::Date(int y, int m, int d)//reload of function Date()
{
	SetYear(y);
	SetMonth(m);
	SetDay(d);
}

void Date::SetYear(int y)
{
	m_year = y;
}
int Date::GetYear() const
{
	return m_year;
}

void Date::SetMonth(int m)
{
	m_month = m;
}
int Date::GetMonth() const
{
	return m_month;
}


void Date::SetDay(int m)
{
	m_day = m;
}
int Date::GetDay() const
{
	return m_day;
}

void Date::SetDate(string date)
{
	string day, month, year;
	stringstream singleDate(date);
	getline(singleDate, day, '/');
	getline(singleDate, month, '/');
	getline(singleDate, year, '/');

	SetDay(atoi(day.c_str()));
	SetMonth(atoi(month.c_str()));
	SetYear(atoi(year.c_str()));
}


ostream& operator <<(ostream& os, const Date& C)
{
	std::string months[] = { "Invalid month", "January", "February", "March",
						"April", "May", "June", "July", "August",
						"September", "October", "November", "December" };
	os << C.GetDay() << " " << months[C.GetMonth()] << " " << C.GetYear() << endl;
	return os;
}
istream& operator >>(istream& input, Date& C)
{
	int  y, m, d;
	input >> y >> m >> d;
	C.SetYear(y);
	C.SetMonth(m);
	C.SetDay(d);
	return input;
}

bool operator>(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() > rhs.GetYear())
	{
		return true;
	}
	else if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() > rhs.GetMonth())
		{
			return true;
		}
		else if (lhs.GetMonth() == rhs.GetMonth())
		{
			if (lhs.GetDay() > rhs.GetDay())
			{
				return true;
			}
		}
	}
	return false;
}

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() < rhs.GetYear())
	{
		return true;
	}
	else if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() < rhs.GetMonth())
		{
			return true;
		}
		else if (lhs.GetMonth() == rhs.GetMonth())
		{
			if (lhs.GetDay() < rhs.GetDay())
			{
				return true;
			}
		}
	}
	return false;
}


