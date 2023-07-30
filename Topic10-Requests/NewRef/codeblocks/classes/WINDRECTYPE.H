#ifndef WINDRECTYPE_H
#define WINDRECTYPE_H

#include "DATE.H"
#include "TIME.H"
#include "VECTOR.H"
#include <sstream>

using namespace std;

    /**
    * @class WindRecType
    * @brief Logs the data of wind speed, solar radiation, ambient temperature
    *        at a specific time and date.
    *
    * Contains data of date, time, wind speed, solar radiation and ambient temperature.
    *
    * @author Noor Hidayat
    */
class WindRecType {
public:
    /**
    *   The WindRecType default constructor initialize the wind speed to a value of 0.
    */
    WindRecType();

    /**
    * WindRecType Constructor
    * @param date The time to initialize with
    * @param time The date to initialize with
    * @param s The wind speed to initialize with
    */
    WindRecType(Date& date, Time& time, float s);

    /**
    * Get the date
    */
    Date& getDate();
    /**
    * Get the time
    */
    Time& getTime();
    /**
    * Get the wind speed
    */
    float getSpeed() const;
    /**
    * Get the Solar Radiation value
    */
    const float getSolarRad() const;
    /**
    * Get the ambient air temperature value
    */
    const float getAmbientAirTemp() const;

    /**
    * Sets the Date
    * @param date Contains the date string in format of dd/mm/yy
    */
    void setDate(string date);
    /**
    * Sets the Time
    * @param time Contains the time in the format of hh:mm
    */
    void setTime(string time);
    /**
    * Sets the speed
    * @param s Contains the wind speed to set to
    */
    void setSpeed(float s);
    /**
    * Sets the Solar radiation value
    * @param s Contains the value of radiation
    */
    void setSolarRad(float s);
    /**
    * Sets the ambient air temperature
    * @param s Contains the value of the ambient air temperature
    */
    void setAmbientAirTemp(float s);

    // debug
    void testOutput(ostream & os, WindRecType & W ) const;

    bool operator < (WindRecType& w) const;

    bool operator > (WindRecType& w) const;

private:
    /** Stores the date object */
    Date d;
    /** Stores the time object */
    Time t;
    /** Stores the wind speed in float */
    float speed;
    /** Stores the solar Radiation value */
    float solarRadiation;
    /** Stores the Ambient Air temperature value */
    float ambientAirTemp;
};

    /**
    * @brief Operator overload for input
    * @param input is the input stream
    * @param W is the object for WindRecType
    */
istream & operator >>( istream & input, WindRecType & W );

    /**
    * @brief Operator overload for output
    * @param os is the output stream
    * @param W is the object for WindRecType
    */
ostream & operator <<( ostream & os, WindRecType & W );

#endif // WINDRECTYPE_H
