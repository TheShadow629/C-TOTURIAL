#include "WINDRECTYPE.H"

WindRecType::WindRecType()
{
    //ctor
}

WindRecType::WindRecType(Date& date, Time& time, float s)
{
    d = date;
    t = time;
    speed = s;
}

void WindRecType::setDate(string date)
{

    Vector<string> result;
    stringstream ss(date);

    while (ss.good())
    {
        string substr;
        getline(ss, substr, '/');
        result.Add(substr);
    }
    d.SetDay(stoi(result.At(0)));
    d.SetMonthNum(stoi(result.At(1)));
    d.SetYear(stoi(result.At(2)));
}

void WindRecType::setTime(string time)
{
    Vector<string> result;
    stringstream ss(time);

    while (ss.good())
    {
        string substr;
        getline(ss, substr, ':');
        result.Add(substr);
    }
    t.setHour(stoi(result.At(0)));
    t.setMinute(stoi(result.At(1)));
}

void WindRecType::setSpeed(float s)
{
    speed = s;
}

void WindRecType::setSolarRad(float s)
{
    solarRadiation = s;
}

void WindRecType::setAmbientAirTemp(float s)
{
    ambientAirTemp = s;
}

const float WindRecType::getSolarRad() const
{
    return solarRadiation;
}

const float WindRecType::getAmbientAirTemp() const
{
    return ambientAirTemp;
}

Date& WindRecType::getDate()
{
    return d;
}

Time& WindRecType::getTime()
{
    return t;
}

float WindRecType::getSpeed() const
{
    return speed;
}

bool WindRecType::operator < (WindRecType& w) const
{
    if (d == w.getDate())
        return t < w.getTime();
    else
        return d < w.getDate();
}

bool WindRecType::operator > (WindRecType& w) const
{
    if (d == w.getDate())
        return t > w.getTime();
    else
        return d > w.getDate();
}



void WindRecType::testOutput(ostream & os, WindRecType & W ) const
{
    os << W.getDate().GetDay() << "/" << W.getDate().GetMonthNum() << "/" << W.getDate().GetYear() << "," << W.getTime() << "," << W.getSpeed() << "\n";
}

istream & operator >>( istream & input, WindRecType & W )
{
    return input;
}

ostream & operator <<( ostream & os, WindRecType & W )
{
    os << W.getDate() << "  Time: " << W.getTime() << "  Speed: " << W.getSpeed() << "\n";

    return os;
}
