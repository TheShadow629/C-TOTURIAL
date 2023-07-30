
#include "Time.h"

Date_Time getDataTime(string data)
{
    Date_Time ret;
    /*string data = "1/03/2014 9:00";*/
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == '/' || data[i] == ':')
        {
            data[i] = ' ';
        }
    }
     
    stringstream ss;
    ss << data;

    Date data_;
    ss >> data_.month;
    ss >> data_.days;
    ss >> data_.year;
    Time time;
    ss >> time.hours;
    ss >> time.min;

    ret.date = data_;
    ret.time = time;
    //cout << "year:=" << data_.year << endl;
    //cout << "month:=" << data_.month << endl;
    //cout << "day:=" << data_.days << endl;
    //cout << "hour:=" << time.hours << endl;
    //cout << "min:=" << time.min << endl;
    //system("pause");
    return ret;
}
string    getMouthEnglish(int month)
{
    if (month == 1)
    {
        return "January";
    }
    else if (month == 2)
    {
        return "February";
    }
    else if (month == 3)
    {
        return "March";
    }
    else if (month == 4)
    {
        return "April";
    }
    else if (month == 5)
    {
        return "May";
    }
    else if (month == 6)
    {
        return "June";
    }
    else if (month == 7)
    {
        return "July";
    }
    else if (month == 8)
    {
        return "August";
    }
    else if (month == 9)
    {
        return "September";
    }
    else if (month == 10)
    {
        return "October";
    }
    else if (month == 11)
    {
        return "November";
    }
    else if (month == 12)
    {
        return "December";
    }
    return "";
}