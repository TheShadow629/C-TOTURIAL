#include "DATE.H"

Date::Date()
{
    m_day = 0;
    m_month = 1;
    m_year = 0;
}

Date::Date(unsigned day, unsigned month, unsigned year)
{
    SetDay(day);
    SetMonthNum(month);
    m_year = year;
}

unsigned Date::GetDay() const
{
    return m_day;
}

void Date::SetDay( unsigned day )
{
    if (day > 31 || day < 1)
    {
        m_day = 0;
    }
    else
    {
        m_day = day;
    }

}

unsigned Date::GetMonthNum() const
{
    return m_month;
}

void Date::SetMonthNum( unsigned month )
{
    if (month > 12 || month < 1)
    {
        m_month = 1;
    }
    else
    {
        m_month = month;
    }

}

string Date::GetMonthName() const
{
    return ConvertMonth(m_month);
}

unsigned Date::GetYear() const
{
    return m_year;
}

void Date::SetYear( unsigned year )
{
    m_year = year;
}

string Date::ConvertMonth(unsigned month) const
{
    string monthName;
    switch (month)
    {
    case 1:
        monthName = "January";
        break;
    case 2:
        monthName = "February";
        break;
    case 3:
        monthName = "March";
        break;
    case 4:
        monthName = "April";
        break;
    case 5:
        monthName = "May";
        break;
    case 6:
        monthName = "June";
        break;
    case 7:
        monthName = "July";
        break;
    case 8:
        monthName = "August";
        break;
    case 9:
        monthName = "September";
        break;
    case 10:
        monthName = "October";
        break;
    case 11:
        monthName = "November";
        break;
    case 12:
        monthName = "December";
        break;
    default:
        cout << "ERROR: Invalid month.";
        break;

    };
    return monthName;
}

bool Date::operator < (const Date& d) const
{
    if (m_year != d.m_year)
        return m_year < d.m_year;
    if (m_month != d.m_month)
        return m_month < d.m_month;
    return m_day < d.m_day;
}

bool Date::operator > (const Date& d) const
{
    if (m_year != d.m_year)
        return m_year > d.m_year;
    if (m_month != d.m_month)
        return m_month > d.m_month;
    return m_day > d.m_day;
}

/* debug */
void Date::print_date()
{
    cout << "Date: " << GetDay() << " " << GetMonthName() << " " << GetYear() << endl;
}

istream & operator >>( istream & input, Date & D)
{
    string tempStr;

    getline(input, tempStr, '/');
    D.SetDay(stoi(tempStr));

    getline(input, tempStr, '/');
    D.SetMonthNum(stoi(tempStr));

    getline(input, tempStr);
    D.SetYear(stoi(tempStr));

    return input;
}

ostream & operator <<( ostream & os, const Date & D )
{
    os << D.GetDay() << " " << D.GetMonthName() << " " << D.GetYear();

    return os;
}

bool Date::operator==(const Date& other) const
{
    return m_day == other.m_day
           && m_month == other.m_month
           && m_year == other.m_year;
}

bool Date::operator!=(const Date& other) const
{
    return m_day != other.m_day
        || m_month != other.m_month
        || m_year != other.m_year;
}

