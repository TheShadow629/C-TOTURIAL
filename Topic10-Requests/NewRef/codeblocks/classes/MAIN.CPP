#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "VECTOR.H"
#include "WINDRECTYPE.H"
#include "WINDLOGDATA.H"


using namespace std;

const string INFILE_NAME = "data/MetData_Mar01-2014-Mar01-2015-ALL.csv";
const string OUTFILE_NAME = "data/WindTempSolar.csv";
const string DATA_SOURCE_FILE = "data/data_source.txt";

int printMenuAndGetChoice();

int readFiles(WindLogData& wind_data);


int main()
{
    WindLogData wind_data;

    readFiles(wind_data);


    while(true)
    {
        int choice = printMenuAndGetChoice();
        if (choice == 1)
        {
            string year;
            string month;

            cout << "Enter year: ";
            cin >> year;
            cout << "Enter Month(1 to 12): ";
            cin >> month;

            wind_data.printSpeedAndStD(year, month);
        }
        else if (choice == 2)
        {
            string year;
            cout << "Enter year: ";
            cin >> year;
            wind_data.printTempAndStd(year);
        }
        else if (choice == 3)
        {
            string month;
            cout << "Enter Month(1 to 12): ";
            cin >> month;
            wind_data.sPCC(month);
        }
        else if (choice == 4)
        {
            string year;
            cout << "Enter year: ";
            cin >> year;
            wind_data.writeToCSV(OUTFILE_NAME, year);
        }
        else if (choice == 5)
        {
            readFiles(wind_data);
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout<< "Invalid choice" << endl;
            break;
        }
    }
    cout << "Program ends" << endl;

    return 0;
}

int printMenuAndGetChoice()
{
    int choice;
    cout << "========== MENU ==========" << endl
         << "1. Print average wind speed and average ambient air temperature for a specified month and year" << endl
         << "2. Print average air temperature for each month of a specified year" << endl
         << "3. Print the Sample Correlation Coefficient for a specified month" << endl
         << "4. Write to CSV, average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m2 for each month of a specified year" << endl
         << "5. Reload program" << endl
         << "6. Exit program" << endl
         << "Please enter a choice:" << endl;
    cin >> choice;
    return choice;
}

int readFiles(WindLogData& wind_data)
{
    wind_data.destroy();

    cout << endl;
    cout << "------======------ Loading Datas ------======------" << endl;
    cout << endl;

    // Read data file names from data_source.txt
    ifstream sourceFile(DATA_SOURCE_FILE);
    if (!sourceFile)
    {
        cerr << "Failed to open data_source.txt" << endl;
        return -1;
    }

    Vector<string> fileNames;
    string fileName;
    while (getline(sourceFile, fileName))
    {
        fileNames.Add(fileName);
    }

    // Process each file
    for (int i = 0; i < fileNames.getSize(); i++)
    {
        const string& fileName = fileNames[i];

        // Open file
        ifstream dataFile("data/" + fileName);
        if (!dataFile)
        {
            cerr << "Failed to open file: " << fileName << endl;
            continue;
        }

        // read data file into vector
        if (!wind_data.readFile("data/" + fileName))
        {
            cerr << "Failed to read file: " << fileName << endl;
        }
    }

    cout << endl;
    cout << "------======------ Loading Completed ------======------" << endl;
    cout << endl;

    return 0;
}


