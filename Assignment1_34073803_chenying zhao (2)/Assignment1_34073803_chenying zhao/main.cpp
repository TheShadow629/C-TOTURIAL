
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Vector.h"
#include "Read_temp_save.h"
using namespace std;
void ReadLine(string line, Vector& vec)
{
    Read_temp_save object;
    string::iterator First_word_end= find(line.begin(), line.end(),',');
    string first_value= string(line.begin(),First_word_end);
    object.WAST=first_value;
    cout<<first_value<<endl;

    string::iterator second_word_end= find(First_word_end+1, line.end(),',');
    string second_value= string(First_word_end+1,second_word_end);
    object.DP=second_value;
    cout<<second_value<<endl;

    string::iterator third_word_end= find(second_word_end+1, line.end(),',');
    string third_value= string(second_word_end+1,third_word_end);
    object.Dta=third_value;
    cout<<third_value<<endl;

    string::iterator fourth_word_end= find(third_word_end+1, line.end(),',');
    string fourth_value= string(third_word_end+1,fourth_word_end);
    object.Dts=fourth_value;
    cout<<fourth_value<<endl;

    string::iterator fifth_word_end= find(fourth_word_end+1, line.end(),',');
    string fifth_value= string(fourth_word_end+1,fifth_word_end);
    cout<<fifth_value<<endl;

    string::iterator sixth_word_end= find(fifth_word_end+1, line.end(),',');
    string sixth_value= string(fifth_word_end+1,sixth_word_end);
    cout<<sixth_value<<endl;

    string::iterator seventh_word_end= find(sixth_word_end+1, line.end(),',');
    string seventh_value= string(sixth_word_end+1,seventh_word_end);
    cout<<seventh_value<<endl;

    string::iterator eighth_word_end= find(seventh_word_end+1, line.end(),',');
    string eighth_value= string(seventh_word_end+1,eighth_word_end);
    cout<<eighth_value<<endl;

    string::iterator ninth_word_end= find(eighth_word_end+1, line.end(),',');
    string ninth_value= string(eighth_word_end+1,ninth_word_end);
    cout<<ninth_value<<endl;

    string::iterator tenth_word_end= find(ninth_word_end+1, line.end(),',');
    string tenth_value= string(ninth_word_end+1,tenth_word_end);
    cout<<tenth_value<<endl;

    string::iterator eleventh_word_end= find(tenth_word_end+1, line.end(),',');
    string eleventh_value= string(tenth_word_end+1,eleventh_word_end);
    cout<<eleventh_value<<endl;

    string::iterator twelveth_word_end= find(eleventh_word_end+1, line.end(),',');
    string twelveth_value= string(eleventh_word_end+1,twelveth_word_end);
    cout<<twelveth_value<<endl;

    string::iterator thirteenth_word_end= find(twelveth_word_end+1,line.end(),',');
    string thirteenth_value= string(twelveth_word_end+1,thirteenth_word_end);
    cout<<thirteenth_value<<endl;

    string::iterator fourteenth_word_end= find(thirteenth_word_end+1, line.end(),',');
    string fourteenth_value= string(thirteenth_word_end+1,fourteenth_word_end);
    cout<<fourteenth_value<<endl;

    string::iterator fifteenth_word_end= find(fourteenth_word_end+1, line.end(),',');
    string fifteenth_value= string(fourteenth_word_end+1,fifteenth_word_end);
    cout<<fifteenth_value<<endl;

    string::iterator sixteenth_word_end= find(fifteenth_word_end+1, line.end(),',');
    string sixteenth_value= string(fifteenth_word_end+1,sixteenth_word_end);
    cout<<sixteenth_value<<endl;

    string::iterator seventeenth_word_end= find(sixteenth_word_end+1, line.end(),',');
    string seventeenth_value= string(sixteenth_word_end+1,seventeenth_word_end);
    cout<<seventeenth_value<<endl;

    string::iterator eighteenth_word_end= find(seventeenth_word_end+1, line.end(),',');
    string eighteenth_value= string(seventeenth_word_end+1,eighteenth_word_end);
    cout<<eighteenth_value<<endl;

    vec.insert(object);

}


int main()
{
  /*Vector vec;
    vec.insert(1);
    vec.insert(12);//the insert data gonna taken from csv file.
    vec.print_Vector();
*/
    Vector vec;
vec.insert(object);
    fstream file("D://283 remodel//Assignment 1//Assignment 1//data//MetData_Mar01-2014-Mar01-2015-ALL.csv");
    string file_line;
    int    lines=0;
    while(getline(file,file_line))
    {
        if(lines==0)
        {
            lines++;

        }
        else
        {
            cout<<"line_num: "<<lines<<endl;
           ReadLine(file_line,vec);
            lines++;
        }
        if(lines>=10)
        {
            lines++;
            break;
        }


        //cout<<file_line<<endl;
    }


    //string line="1/03/2014 9:00,2.1,56,19,0.1,1012.3,1015.7,1015.9,0,17.3,8,616,29.3,30,29.3,28.1,12,29.56";

    return 0;

 /*ifstream infile("file name");



 ofstream ofile( "file name" );


 switch()
 {
     case 1:
         cout<< "January 1905: 5.5 km/h, 25.5 degrees C"<<endl;
 /* Example output format if there is data:
January 1905: 5.5 km/h, 25.5 degrees C
Example output format if there is no data:
March 1905: No Data
*/
 // break;

  //  case 2:
     /* Average wind speed and average ambient air temperature for each month of a specified
year. (print on screen only)
Example output format is:
1905
January: 5.5 km/h, 25.5 degrees C
February: 4.5 km/h*/

 // break;
   // case 3:
        /* 1905
January: 196.4 kWh/m2
February: 200.3 kWh/m2
March: No Data */
//break;

  //  case 4:
        /* Year
Month,Average Wind Speed, Average Ambient Temperature, Solar Radiation
Example output format is:
1905
January,5.5,25.5,196.4
February,4.5,27.5,200.3
 save in the “WindTempSolar.csv */
 //break;
   // case 5:
     //   exit;
    // but if the user enter the invaild value, it only turn to "no data", it won't exit the value.


 }










