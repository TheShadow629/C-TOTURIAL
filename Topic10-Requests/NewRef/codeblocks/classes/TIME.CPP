#include "TIME.H"
#include<iostream>
#include<iomanip>

Time::Time()
{
    m_hour = 0;
    m_minute = 0;
}

Time::Time(int hour, int minute)
{
    m_hour = hour;
    m_minute = minute;
}

const int Time::getHour() const
{
    return m_hour;
}

const int Time::getMinute() const
{
    return m_minute;
}

void Time::setHour(const int hour)
{
    m_hour = hour;
}

void Time::setMinute(const int minute)
{
    m_minute = minute;
}

bool Time::operator < (const Time& t) const
{
    if (m_hour != t.m_hour)
        return m_hour < t.m_hour;
    return m_minute < t.m_minute;
}

bool Time::operator > (const Time& t) const
{
    if (m_hour != t.m_hour)
        return m_hour > t.m_hour;
    return m_minute > t.m_minute;
}


bool Time::operator==(Time& obj)
{
    if ((this->getHour() == obj.getHour()) && this->getMinute() == obj.getMinute()) {
        return true;
    } else {
        return false;
    }
}

/* debug */
void Time::print_time() const
{
    ostringstream ss;
    ss << setw(2) << setfill('0')  << getHour() << ":" << setw(2) << setfill('0')  << getMinute();
    string s = ss.str();

    cout << s << endl;
}

istream & operator >>( istream & input, Time & T)
{
    string tempStr;

    getline(input, tempStr, ':');
    T.setHour(stoi(tempStr));

    getline(input, tempStr);
    T.setMinute(stoi(tempStr));

    return input;
}

ostream & operator <<( ostream & os, const Time & T )
{
    os << setw(2) << setfill('0')  << T.getHour() << ":" << setw(2) << setfill('0')  << T.getMinute();

  return os;
}
