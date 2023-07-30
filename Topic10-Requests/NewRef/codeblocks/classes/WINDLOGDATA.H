#ifndef WINDLOGDATA_H
#define WINDLOGDATA_H

#include "VECTOR.H"
#include "WINDRECTYPE.H"
#include <string>
#include <fstream>
#include <cmath>
#include <unordered_map>
#include "DATE.H"
#include "BST.H"

using namespace std;

/**
 * @class WindLogData
 * @brief Manages all wind logs data in a vector.
 *        Wind logs data can be read from file and inputted into the vector.
 *        Available methods such as printing the wind logs for specific year and month.
 *
 * Contains data of inputted wind logs and methods to print and write data to CSV file.
 *
 * @author Noor Hidayat
 *
 */
class WindLogData
{
public:

    /**
     * @brief Default constructor for WindLogData class.
     *
     * This constructor initializes a new instance of the WindLogData class, setting up the necessary
     * resources for managing wind log data.
     */
    WindLogData();

    /**
     * @brief  This function reads CSV file containing wind logs.
     *
     * @param fileName - name of file to be read
     * @return bool - returns true if file found and false if file not found
     */
    bool readFile(string fileName);

    /**
     * @brief  Prints the wind speed and temperature for a specific year and month
     *
     * @param year - year (eg. 2016)
     *        month - month in numeric (1 to 12)
     */
    void printSpeedAndStD(string year, string month);

    /**
     * @brief  Prints the wind speed and temperature for a specific year
     *
     * @param year - year (eg. 2016)
     */
    void printTempAndStd(string year);

    /**
     * @brief  Writes wind speed, temperature, solar radiation, date and time
     *         to CSV file for a specific year
     *
     * @param year - year to be specified, in string
     */
    void writeToCSV(string fileName, string year);

    /**
     * @brief  Calculates and prints the Solar panel correlation coefficient for a specified month.
     *
     * @param month - month to be specified.
     */
    void sPCC(string month);

    static void getDataForManipulation(WindRecType& i, Vector<WindRecType>& dataVect) {
//        cout << i << ' ';
        dataVect.Add(i);
    }

    /**
     * @brief  Destroy all variables to their default states.
     */
    void destroy();

private:

//    /**
//     * @brief  Get the average wind speed for the specific month and year
//     *
//     * @param year - year to be specified
//     *        month - month to be specified in numeric(1 to 12)
//     * @return float - returns average wind speed in km/h, 0 if no data is found
//     */
    float getAverageSpeed();


//    /**
//     * @brief  Get the average temperature for the specific month and year
//     *
//     * @param year - year to be specified
//     *        month - month to be specified in numeric(1 to 12)
//     * @return float - returns average temperature in degrees C, 0 if no data is found
//     */
    float getAverageTemp();

//    /**
//     * @brief  Get the average solar radiation for the specific month and year
//     *
//     * @param year - year to be specified
//     *        month - month to be specified in numeric(1 to 12)
//     * @return float - returns average solar radiation, 0 if no data is found
//     */
    float getAverageSolarRad();

//    /**
//     * @brief  Get the total solar radiation for the specific month and year
//     *
//     * @param year - year to be specified
//     *        month - month to be specified in numeric(1 to 12)
//     * @return float - returns total solar radiation in kWh/m2, 0 if no data is found
//     */
    float getTotalSolarRadiationMonth();


    /**
    * @brief  Get the standard deviation for speed of the year and month
    *
    * @return float - returns the standard deviation value
    */
    float getStandardDeviationSpeed(float mean);

    /**
    * @brief  Get the standard deviation for temperature of the year and month
    *
    * @return float - returns the standard deviation value
    */
    float getStandardDeviationTemp(float mean);

    /**
    * @brief  Get the standard deviation for solar radiation of the year and month
    *
    * @return float - returns the standard deviation value
    */
    float getStandardDeviationSolarRad(float mean);


    /**
     * @brief  Converts month of year in numeric to alphabets (eg. 1 to January)
     *
     * @param num - numeric representation for month (eg. 1 = January)
     *
     * @return string - returns the month in alphabets (eg. input 1, returns "January")
     */
    string numToMonth(string num);

    /**
    * @brief  Sets the target year and month for which data is to be processed.
    *
    * @param year - target year to be specified.
    *        month - target month to be specified.
    */
    void setTargetYearMonth(int year, int month);


    unordered_map<unsigned, unordered_map<unsigned, Bst<WindRecType>>> dataToStore;
    Vector<WindRecType> dataToManipulate;

};

#endif // WINDLOGDATA_H
