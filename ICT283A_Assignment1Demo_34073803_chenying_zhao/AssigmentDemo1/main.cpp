
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include "Vector.h"
#include "FileAnalysis.h"
#include "Read_temp_save.h"
#include "Test.h"
using namespace std;



int main_test()
{
    Test1();
    Test2();
    Test3();

    system("pause");
    return 1;
}

int main()
{
    FileAnalysis file_analysis(
        string("D://283 remodel//ICT283A_Assignment1Demo_34073803_chenying_zhao//AssigmentDemo1//data//MetData_Jan01-2010-Jan01-2011-ALL.csv"),
        string("D://283 remodel//ICT283A_Assignment1Demo_34073803_chenying_zhao//AssigmentDemo1//data//MetData_Jan01-2011-Jan01-2012-ALL.csv"),
        string("D://283 remodel//ICT283A_Assignment1Demo_34073803_chenying_zhao//AssigmentDemo1//data//MetData_Jan01-2012-Jan01-2013-ALL.csv"),
        string("D://283 remodel//ICT283A_Assignment1Demo_34073803_chenying_zhao//AssigmentDemo1//data//MetData_Jan01-2013-Jan01-2014-ALL.csv"),
        string("D://283 remodel//ICT283A_Assignment1Demo_34073803_chenying_zhao//AssigmentDemo1//data//MetData_Mar01-2014-Mar01-2015-ALL.csv"),
        string("D://283 remodel//ICT283A_Assignment1Demo_34073803_chenying_zhao//AssigmentDemo1//data//MetData_Mar01-2015-Mar01-2016-ALL.csv"));
    file_analysis.getFileContent();
    file_analysis.print_Vector();

    while (true)
    {
        cout << "please enter the case(1-6)" << endl;
        int cmd;
        cin >> cmd;
        switch (cmd)
        {
        case 1:
        {
            cout << "please enter year and month" << endl;
            int year, mouth;
            cin >> year;
            cin >> mouth;
            cout << file_analysis.getBstCMD1(year, mouth) << endl;

            /*
               Example output format if there is data:
               January 1905: 5.5 km/h, 25.5 degrees C
               Example output format if there is no data:
               March 1905: No Data
            */

            break;
        }

        case 2:
        {
            cout << "please enter year" << endl;
            int year;
            cin >> year;
            cout << year << endl;
            for (int i = 1; i < 13; i++)
            {
                cout << file_analysis.getBstCMD2(year, i) << endl;
            }
            break;
        }
        case 3:
        {
            cout << "please enter year" << endl;
            int year;
            cin >> year;
            cout << year << endl;
            for (int i = 1; i < 13; i++)
            {
                cout << file_analysis.getBstCMD3(year, i) << endl;
            }
            break;
        }
        case 4:
        {
            fstream file_save("D://283 remodel//ICT283A_Assignment1Demo_34073803_chenying_zhao//AssigmentDemo1//data//WindTempSolar.csv");
            cout << "please enter year" << endl;
            int year;
            cin >> year;
            stringstream ss;
            string all_content;
            ss << year << endl;


            for (int i = 1; i < 13; i++)
            {
                string info = file_analysis.getBstCMD4(year, i);

                if (info.size() != 0)
                {
                    all_content.append(info);
                    all_content.push_back('\n');

                }
            }
            if (all_content.size() == 0)
            {
                ss << "No Data;" << endl;
            }
            file_save << ss.str() << all_content << endl;
            file_save.close();
            break;
        }
        case 5:
        {
            cout << "please enter year,month and day" << endl;
            int year;
            cin >> year;

            int mouth;
            cin >> mouth;

            int day;
            cin >> day;
            cout << "Date: " << mouth << "/" << day << "/" << year << endl;
            cout << "High solar raduation for the day:";

            cout << file_analysis.getBstCMD5(year, mouth,day) << endl;
            cout << "W/m2" << endl;
            break;
        }

        case 6:
            goto end;
        }
    }
    end:
    system("pause");
    return 0;
}
