#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

using namespace std;

    /**
    * @class Date
    * @brief It stores a date. Specifically in the format of dd/mm/yyyy
    * @author Noor Hidayat
    */
class Date {

public:
    /**
    *   The Date default constructor initializes day to 0, month to 1, and date to 0.
    */
    Date();

    /**
    * Date Constructor
    * @param day The day of the date
    * @param month The month of the date in string
    * @param year The year of the date
    */
    Date(unsigned day, unsigned month, unsigned year);

    /**
    * Get the day of the month
    */
    unsigned GetDay() const;

    /**
    * Set the day of the month
    * @param day Contains the day of the month to set to
    */
    void SetDay( unsigned day );

    /**
    * Get the month's numerical value
    */
    unsigned GetMonthNum() const;

    /**
    * Set the month in numerical value
    * @param month Contains the month to set to.
    * If month is not within  1 - 12 , defaults to 0
    */
    void SetMonthNum( unsigned month );

    /**
    * Get the month's named value
    */
    string GetMonthName() const;

    /**
    * Get the year
    */
    unsigned GetYear() const;

    /**
    * Set the year
    * @param year Contains the year to set to
    */
    void SetYear( unsigned year );

    /**
    * Operator overload for the < to check whether Date is earlier
    * @param d Holds the Date obj
    */
    bool operator < (const Date& d) const;

    /**
    * Operator overload for the < to check whether Date is later
    * @param d Holds the Date obj
    */
    bool operator > (const Date& d) const;

    /**
    * Operator overload for the == to check whether Dates are equal
    * @param d Holds the Date obj
    */
    bool operator == (const Date& d) const;

    bool operator != (const Date& other) const;

        /* debug */
    void print_date();

private:
    /**
    * Converts numerical month to string month's name
    * @param month Contains the numerical month
    */
    string ConvertMonth(unsigned month) const;

    /** Stores the day of the month in integer */
    unsigned int m_day;
    /** Stores a numerical value of the month */
    unsigned int m_month;
    /** Stores the year in integer */
    unsigned int m_year;
};

    /**
    * @brief Operator overload for input
    * @param input is the input stream
    * @param D is the object for Date
    */
istream & operator >>( istream & input, Date & D);

    /**
    * @brief Operator overload for output
    * @param os is the output stream
    * @param D is the object for Date
    */
ostream & operator <<( ostream & os, const Date & D);

    /**
    * @brief A function object (aka functor) to use unordered map
    */
namespace std {
    template<>
    struct hash<Date> {
        size_t operator()(const Date& k) const {
            size_t h1 = hash<int>()(k.GetDay());
            size_t h2 = hash<int>()(k.GetMonthNum());
            size_t h3 = hash<int>()(k.GetYear());
            return h1 ^ (h2 << 1) ^ (h3 << 2);
        }
    };
}

#endif // DATE_H
