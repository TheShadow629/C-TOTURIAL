#include "WINDLOGDATA.h"

using namespace std;

WindLogData::WindLogData()
{
    dataToManipulate.clearVect();
}

// read file data into vector ( If column is arranged differently, it can still read the required data)
bool WindLogData::readFile(string fileName)
{
    ifstream inFile(fileName);
    if(!inFile)
    {
        return false;
    }

    // Read header columns and get the indexes.
    // Then set value to the respective index
    string tempStr;
    int dateTimeColumn;
    int speedColumn;
    int solarRadColumn;
    int temperatureColumn;

    WindRecType windLog;
    string timeDate;

    bool headerTaken = false;
    while (getline(inFile, tempStr))
    {
        if (!tempStr.empty())   // Checks for empty rows
        {
            stringstream ss(tempStr);
            string cellValue;
            int index = 0;
            bool invalidData = false;


            while (getline(ss, cellValue, ','))
            {

                // Only the first row of the file sets the header indexes
                if (!headerTaken)
                {
                    if (cellValue == "WAST")
                    {
                        dateTimeColumn = index;
                    }
                    else if (cellValue == "S")
                    {
                        speedColumn = index;
                    }
                    else if (cellValue == "SR")
                    {
                        solarRadColumn = index;
                    }
                    else if (cellValue == "T")
                    {
                        temperatureColumn = index;
                    }

                }
                else
                {
                    // Checks for invalid data
                    if (cellValue == "N/A" || cellValue.empty() || timeDate == cellValue)
                    {
                        invalidData = true;
                        break;
                    }

                    if (index == dateTimeColumn)
                    {
                        Vector<string> result;
                        stringstream ss(cellValue);

                        while (ss.good())
                        {
                            string substr;
                            getline(ss, substr, ' ');
                            result.Add(substr);

                        }
                        windLog.setDate(result.At(0));
                        windLog.setTime(result.At(1));

                    }

                    if (index == speedColumn)
                    {
                        windLog.setSpeed(stof(cellValue));
                    }

                    if (index == solarRadColumn)
                    {
                        windLog.setSolarRad(stof(cellValue));
                    }

                    if (index == temperatureColumn)
                    {
                        windLog.setAmbientAirTemp(stof(cellValue));
                    }

                }
                index++;
            }
            if (!invalidData && headerTaken == true)
            {
                dataToStore[windLog.getDate().GetYear()][windLog.getDate().GetMonthNum()].insert(windLog);
            }
            headerTaken = true;
        }
    }

    inFile.close();
    cout << fileName << " successfully loaded!" << endl;
    return true;
}

// Option 1
void WindLogData::printSpeedAndStD(string year, string month)
{
    dataToManipulate.clearVect();
    dataToStore[stoul(year)][stoul(month)].inOrder(getDataForManipulation, dataToManipulate);
    float averageSpeed = round(getAverageSpeed()*10)/10;
    float standardDeviation = roundf(getStandardDeviationSpeed(averageSpeed)*10.0f)/10.0f;

    if(averageSpeed == 0 && standardDeviation == 0)
    {
        cout << numToMonth(month) << " " << year << ": No Data" << '\n' << endl;
    }
    else
    {
        cout << numToMonth(month) << " " << year << ": " << "\nAverage speed: " << averageSpeed << " km/h "
             << "\nSample stdev: " << standardDeviation << "\n" << endl;
    }
}

// Option 2
void WindLogData::printTempAndStd(string year)
{
    cout << year << endl;
    for(int i = 1; i <= 12; i++)
    {
        dataToManipulate.clearVect();
        dataToStore[stoul(year)][i].inOrder(getDataForManipulation, dataToManipulate);
        float averageTemp = round(getAverageTemp()*10)/10;
        float standardDeviation = roundf(getStandardDeviationTemp(averageTemp)*10.0f)/10.0f;

        if(averageTemp == 0)
        {
            cout << numToMonth(to_string(i)) << ": No Data" << endl;
        }
        else
        {
            cout << numToMonth(to_string(i)) << ": average: " << averageTemp << " degrees C, stdev: "
                 << standardDeviation << endl;
        }

    }
    cout << endl;
}

// Option 3
void WindLogData::sPCC(string month)
{
    dataToManipulate.clearVect();

    // Loop through all keys in the unordered_map.
    for (const auto& [key, value] : dataToStore) {
        dataToStore[key][stoul(month)].inOrder(getDataForManipulation, dataToManipulate);
    }

    float averageSpeed = getAverageSpeed();
    float standardDeviationSpeed = getStandardDeviationSpeed(averageSpeed);
    float averageTemp = getAverageTemp();
    float standardDeviationTemp = getStandardDeviationTemp(averageTemp);
    float averageSolarRad = getAverageSolarRad();
    float standardDeviationSolarRad = getStandardDeviationSolarRad(averageSolarRad);

    float DevSquaredSpeed = 0.0;
    float DevSquaredTemp = 0.0;
    float DevSquaredSolarRad = 0.0;
    float S_T = 0.0;
    float S_R = 0.0;
    float T_R = 0.0;

    for (int i = 0; i < dataToManipulate.getSize(); i++)
    {
        float devSpeed = dataToManipulate[i].getSpeed() - averageSpeed;
        float devTemp = dataToManipulate[i].getAmbientAirTemp() - averageTemp;
        float devSolarRad = dataToManipulate[i].getSolarRad() - averageSolarRad;

        DevSquaredSpeed += devSpeed * devSpeed;
        DevSquaredTemp += devTemp * devTemp;
        DevSquaredSolarRad += devSolarRad * devSolarRad;
        S_T += devSpeed * devTemp;
        S_R += devSpeed * devSolarRad;
        T_R += devTemp * devSolarRad;
    }

    S_T = S_T / sqrt(DevSquaredSpeed * DevSquaredTemp);
    S_T = isnan(S_T) ? 0 : S_T;

    S_R = S_R / sqrt(DevSquaredSpeed * DevSquaredSolarRad);
    S_R = isnan(S_R) ? 0 : S_R;

    T_R = T_R / sqrt(DevSquaredTemp * DevSquaredSolarRad);
    T_R = isnan(T_R) ? 0 : T_R;

    cout << "S_T: " << S_T << endl;
    cout << "S_R: " << S_R << endl;
    cout << "T_R: " << T_R << endl;
    cout << endl;
}

// Option 4
void WindLogData::writeToCSV(string fileName, string year)
{
    ofstream outFile(fileName);

    outFile << year << endl;
    int count = 0;


    for(int i = 1; i <= 12; i++)
    {
        dataToManipulate.clearVect();
        dataToStore[stoul(year)][i].inOrder(getDataForManipulation, dataToManipulate);
        float averageSpeed = round(getAverageSpeed()*10)/10;
        float standardDeviationSpeed = roundf(getStandardDeviationSpeed(averageSpeed)*10.0f)/10.0f;
        float averageTemp = round(getAverageTemp()*10)/10;
        float standardDeviationTemp = roundf(getStandardDeviationTemp(averageTemp)*10.0f)/10.0f;
        float totalSolarRadiation = round(getTotalSolarRadiationMonth()*10)/10;

        if(averageSpeed == 0 && averageTemp == 0 && totalSolarRadiation == 0)
        {
            count++;
            continue;
        }
        else
        {
            outFile << numToMonth(to_string(i)) << ","
                    << averageSpeed
                    << '(' << standardDeviationSpeed << ')' << ","
                    << averageTemp
                    << '(' << standardDeviationTemp << ')' << ","
                    << totalSolarRadiation
                    << endl;
        }
    }
    if(count == 12)
    {
        outFile << "No Data";
    }

    outFile.close();
}

float WindLogData::getStandardDeviationSpeed(float mean)
{
    float totalValue = 0;
    float totalCount = 0;

    for (int i = 0; i < dataToManipulate.getSize(); i++) {
        totalValue += (dataToManipulate[i].getSpeed() - mean) * (dataToManipulate[i].getSpeed() - mean);
        totalCount++;
    }

    return sqrt(totalValue / (totalCount - 1));
}

float WindLogData::getStandardDeviationTemp(float mean)
{
    float totalValue = 0;
    float totalCount = 0;

    for (int i = 0; i < dataToManipulate.getSize(); i++) {
        totalValue += (dataToManipulate[i].getAmbientAirTemp() - mean) * (dataToManipulate[i].getAmbientAirTemp() - mean);
        totalCount++;
    }

    return sqrt(totalValue / (totalCount - 1));
}

float WindLogData::getStandardDeviationSolarRad(float mean)
{
    float totalValue = 0;
    float totalCount = 0;

    for (int i = 0; i < dataToManipulate.getSize(); i++) {
        totalValue += (dataToManipulate[i].getSolarRad() - mean) * (dataToManipulate[i].getSolarRad() - mean);
        totalCount++;
    }

    return sqrt(totalValue / (totalCount - 1));
}

float WindLogData::getAverageSpeed()
{
    float totalValue = 0;
    float totalCount = 0;
    float averageSpeed = 0;
    for (int i = 0; i < dataToManipulate.getSize(); i++) {
        totalValue += dataToManipulate[i].getSpeed();
        totalCount++;
    }

    averageSpeed = totalValue / totalCount;
    if(isnan(averageSpeed))
    {
        return 0;
    }
    else
    {
        return averageSpeed;
    }
}

float WindLogData::getAverageTemp()
{
    float totalValue = 0;
    float totalCount = 0;
    float averageTemp = 0;
    for (int i = 0; i < dataToManipulate.getSize(); i++) {
        totalValue += dataToManipulate[i].getAmbientAirTemp();
        totalCount++;
    }

    averageTemp = totalValue / totalCount;

    if(isnan(averageTemp))
    {
        return 0;
    }
    else
    {
        return averageTemp;
    }
}

float WindLogData::getAverageSolarRad()
{
    float totalValue = 0;
    float totalCount = 0;
    float averageSolar = 0;
    for (int i = 0; i < dataToManipulate.getSize(); i++) {
        totalValue += dataToManipulate[i].getSolarRad();
        totalCount++;
    }

    averageSolar = totalValue / totalCount;

    if(isnan(averageSolar))
    {
        return 0;
    }
    else
    {
        return averageSolar;
    }
}

float WindLogData::getTotalSolarRadiationMonth()
{
    float totalSolarRadiation = 0;
    float totalCount = 0;

    for (int i = 0; i<dataToManipulate.getSize(); i++)
    {
        if (dataToManipulate[i].getSolarRad() >= 100)
        {
            totalSolarRadiation += dataToManipulate[i].getSolarRad();
            totalCount++;
        }
    }

    float solarRadiationInKWH = ((totalSolarRadiation * 1/6)/1000);
    return solarRadiationInKWH;
}

string WindLogData::numToMonth(string month)
{
    string months[] =
    {
        "Invalid input",
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    int monthNum = stoi(month); // Convert month string to integer

    if (monthNum >= 1 && monthNum <= 12)
    {
        return months[monthNum];
    }
    else
    {
        return months[0]; // Return "Invalid input" for out-of-range values
    }
}

void WindLogData::destroy()
{
    dataToStore.clear(); // This would also call the destructor for BST
}

