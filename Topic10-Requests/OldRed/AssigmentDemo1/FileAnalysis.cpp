#include "FileAnalysis.h"
#include "Time.h"



bool operator==(const Time_key &obj1,const Time_key &obj2)
{
    return obj1.year == obj2.year&&obj1.month == obj2.month;
}

bool operator<(const Time_key &obj1,const Time_key &obj2)
{
    if (obj1 == obj2)
    {
        return false;
    }

    if (obj1.year < obj2.year)
    {
        return true;
    }
    else if (obj1.year == obj2.year)
    {
        return obj1.month < obj2.month;
    }

    return false;
}


bool operator>(const Time_key &obj1,const Time_key &obj2)
{
    if (obj1 == obj2)
    {
        return false;
    }
    return !(obj1 < obj2);
}


bool operator<(const Bst_Node &obj1,const Bst_Node &obj2)
{
    return obj1.key < obj2.key;
}

bool operator>(const Bst_Node &obj1, const Bst_Node &obj2)
{
    return obj1.key > obj2.key;
}

bool operator == (const Bst_Node &obj1, const Bst_Node &obj2)
{
    return obj1.key == obj2.key;
}

bool operator<=(const Bst_Node &obj1, const Bst_Node &obj2)
{
    if (obj1.key == obj2.key)
    {
        return true;
    }
    return obj1.key < obj2.key;
}

bool operator>=(Bst_Node &obj1, Bst_Node &obj2)
{
    if (obj1.key == obj2.key)
    {
        return true;
    }
    return obj1.key > obj2.key;
}

FileAnalysis::FileAnalysis(string filepath1, string filepath2, string filepath3, string filepath4, string filepath5,string filepath6)
    : file1(filepath1), file2(filepath2), file3(filepath3), file4(filepath4), file5(filepath5), file6(filepath6)
{
}


void FileAnalysis::getFileContent()
{
    string line;
    int    lines = 0;
    while (getline(file1, line))
    {
        if (lines == 0)//don't read the first line.
        {
            lines++;

        }
        else
        {
            lines++;
            Weather_Data object = paraseLine(line);
            Date_Time time = getDataTime(object.getWAST());
           // my_vec.insert(object);

            Bst_Node node;
            node.key.year = time.date.year;
            node.key.month = time.date.month;

            auto val = find_val(root, node);
            if (val == nullptr)
            {
                node.data.push_back(object);
                InsertBintree(root, node);
               
            }
            else
            {
                val->data.push_back(object);
            }

            set<Bst_Node>::iterator it = my_st.find(node);
            if (it == my_st.end())
            {
                node.data.push_back(object);
                my_st.insert(node);
                //InsertBintree(root, node);
            }
            else
            {
                vector<Weather_Data,std::allocator<Weather_Data>> *tmp= (vector<Weather_Data, std::allocator<Weather_Data>> *)&it->data;
                tmp->push_back(object);
                //(*val_).data.push_back(object);
            }
        }
    }

 
 
    lines = 0;
    while (getline(file2, line))
    {
        if (lines == 0)//don't read the first line.
        {
            lines++;

        }
        else
        {
            lines++;
            Weather_Data object = paraseLine(line);
            Date_Time time = getDataTime(object.getWAST());
            // my_vec.insert(object);

            Bst_Node node;
            node.key.year = time.date.year;
            node.key.month = time.date.month;

            auto val = find_val(root, node);
            if (val == nullptr)
            {
                node.data.push_back(object);
                InsertBintree(root, node);

            }
            else
            {
                val->data.push_back(object);
            }

            set<Bst_Node>::iterator it = my_st.find(node);
            if (it == my_st.end())
            {
                node.data.push_back(object);
                my_st.insert(node);
                //InsertBintree(root, node);
            }
            else
            {
                vector<Weather_Data, std::allocator<Weather_Data>> *tmp = (vector<Weather_Data, std::allocator<Weather_Data>> *)&it->data;
                tmp->push_back(object);
                //(*val_).data.push_back(object);
            }
        }
    }

    lines = 0;
    while (getline(file3, line))
    {
        if (lines == 0)//don't read the first line.
        {
            lines++;

        }
        else
        {
            lines++;
            Weather_Data object = paraseLine(line);
            Date_Time time = getDataTime(object.getWAST());
            // my_vec.insert(object);

            Bst_Node node;
            node.key.year = time.date.year;
            node.key.month = time.date.month;

            auto val = find_val(root, node);
            if (val == nullptr)
            {
                node.data.push_back(object);
                InsertBintree(root, node);

            }
            else
            {
                val->data.push_back(object);
            }

            set<Bst_Node>::iterator it = my_st.find(node);
            if (it == my_st.end())
            {
                node.data.push_back(object);
                my_st.insert(node);
                //InsertBintree(root, node);
            }
            else
            {
                vector<Weather_Data, std::allocator<Weather_Data>> *tmp = (vector<Weather_Data, std::allocator<Weather_Data>> *)&it->data;
                tmp->push_back(object);
                //(*val_).data.push_back(object);
            }
        }
    }


    lines = 0;
    while (getline(file4, line))
    {
        if (lines == 0)//don't read the first line.
        {
            lines++;

        }
        else
        {
            lines++;
            Weather_Data object = paraseLine(line);
            Date_Time time = getDataTime(object.getWAST());
            // my_vec.insert(object);

            Bst_Node node;
            node.key.year = time.date.year;
            node.key.month = time.date.month;

            auto val = find_val(root, node);
            if (val == nullptr)
            {
                node.data.push_back(object);
                InsertBintree(root, node);

            }
            else
            {
                val->data.push_back(object);
            }

            set<Bst_Node>::iterator it = my_st.find(node);
            if (it == my_st.end())
            {
                node.data.push_back(object);
                my_st.insert(node);
                //InsertBintree(root, node);
            }
            else
            {
                vector<Weather_Data, std::allocator<Weather_Data>> *tmp = (vector<Weather_Data, std::allocator<Weather_Data>> *)&it->data;
                tmp->push_back(object);
                //(*val_).data.push_back(object);
            }
        }
    }


    lines = 0;
    while (getline(file5, line))
    {
        if (lines == 0)//don't read the first line.
        {
            lines++;

        }
        else
        {
            lines++;
            Weather_Data object = paraseLine(line);
            Date_Time time = getDataTime(object.getWAST());
            // my_vec.insert(object);

            Bst_Node node;
            node.key.year = time.date.year;
            node.key.month = time.date.month;

            auto val = find_val(root, node);
            if (val == nullptr)
            {
                node.data.push_back(object);
                InsertBintree(root, node);

            }
            else
            {
                val->data.push_back(object);
            }

            set<Bst_Node>::iterator it = my_st.find(node);
            if (it == my_st.end())
            {
                node.data.push_back(object);
                my_st.insert(node);
                //InsertBintree(root, node);
            }
            else
            {
                vector<Weather_Data, std::allocator<Weather_Data>> *tmp = (vector<Weather_Data, std::allocator<Weather_Data>> *)&it->data;
                tmp->push_back(object);
                //(*val_).data.push_back(object);
            }
        }
    }



    lines = 0;
    while (getline(file6, line))
    {
        if (lines == 0)//don't read the first line.
        {
            lines++;

        }
        else
        {
            lines++;
            Weather_Data object = paraseLine(line);
            Date_Time time = getDataTime(object.getWAST());
            // my_vec.insert(object);

            Bst_Node node;
            node.key.year = time.date.year;
            node.key.month = time.date.month;

            auto val = find_val(root, node);
            if (val == nullptr)
            {
                node.data.push_back(object);
                InsertBintree(root, node);

            }
            else
            {
                val->data.push_back(object);
            }

            set<Bst_Node>::iterator it = my_st.find(node);
            if (it == my_st.end())
            {
                node.data.push_back(object);
                my_st.insert(node);
                //InsertBintree(root, node);
            }
            else
            {
                vector<Weather_Data, std::allocator<Weather_Data>>* tmp = (vector<Weather_Data, std::allocator<Weather_Data>> *) & it->data;
                tmp->push_back(object);
                //(*val_).data.push_back(object);
            }
        }
    }
 }


FileAnalysis::~FileAnalysis()
{
    file1.close();
    file2.close();
    my_vec.clear();
}


string FileAnalysis::getCMD1(int year, int month)
{
    //cout << "January 1905: 5.5 km/h, 25.5 degrees C" << endl;
    string ret;
    stringstream ss;
    ss << getMouthEnglish(month) <<" ";
    ss << year << ": ";
    //string s1 = ss.str();
    //cout << s1 << endl; // 30

    bool have_data = false;
    double all_wind_speed=0, wind_times=0;
    double all_t = 0, t_times = 0;
    for (int i = 0; i < my_vec.getSize(); i++)
    {
       /* cout << my_vec.at(i).WAST << endl;*/
        Date_Time data= getDataTime(my_vec.at(i).getWAST());
        if (data.date.month == month && data.date.year==year)
        {
            have_data = true;
            all_wind_speed += stod(my_vec.at(i).S); 
            wind_times++;

            all_t+= stod(my_vec.at(i).T);
            t_times++;
        }
        
    }
    //March 1905: No Data
    if (have_data == false)
    {
        ss << year << "No Data";
        return ss.str();
    }
    ss << all_wind_speed/ wind_times << "km/h, ";
    ss << all_t / t_times << " degrees C";
    return ss.str();
}

string FileAnalysis::getCMD2(int year, int month)
{
    string ret;
    stringstream ss;
    ss << getMouthEnglish(month) << ": ";

    bool have_data = false;
    double all_wind_speed = 0, wind_times = 0;
    double all_t = 0, t_times = 0;
    for (int i = 0; i < my_vec.getSize(); i++)
    {
        Date_Time data = getDataTime(my_vec.at(i).getWAST());
        if (data.date.month == month && data.date.year == year)
        {
            have_data = true;
            all_wind_speed += stod(my_vec.at(i).S);
            wind_times++;

            all_t += stod(my_vec.at(i).T);
            t_times++;
        }

    }

    if (have_data == false)
    {
        ss << year << "No Data";
        return ss.str();
    }
    ss << all_wind_speed / wind_times << "km/h, ";
    ss << all_t / t_times << " degrees C";
    return ss.str();
}

string FileAnalysis::getCMD3(int year, int month)
{
    //January: 196.4 kWh / m2
    string ret;
    stringstream ss;
    ss << getMouthEnglish(month) << ": ";

    bool have_data = false;
    double all_sr = 0, sr_times = 0;
    for (int i = 0; i < my_vec.getSize(); i++)
    {
        Date_Time data = getDataTime(my_vec.at(i).getWAST());
        if (data.date.month == month && data.date.year == year)
        {
            have_data = true;
            all_sr += stod(my_vec.at(i).SR);
            sr_times++;
        }

    }

    if (have_data == false)
    {
        ss << year << "No Data";
        return ss.str();
    }
    ss << all_sr / sr_times << " kWh / m2 ";
 
    return ss.str();
}

string FileAnalysis::getCMD4(int year, int month)
{
    //January, 5.5, 25.5, 196.4
    //February, 4.5, 27.5, 200.3

    string ret;
    stringstream ss;
    ss << getMouthEnglish(month) << ": ";

    double all_wind_speed = 0, wind_times = 0;
    double all_t = 0, t_times = 0;

    bool have_data = false;
    double all_sr = 0, sr_times = 0;
    for (int i = 0; i < my_vec.getSize(); i++)
    {
        Date_Time data = getDataTime(my_vec.at(i).getWAST());
        if (data.date.month == month && data.date.year == year)
        {
            have_data = true;
            all_sr += stod(my_vec.at(i).SR);
            sr_times++;
            all_wind_speed += stod(my_vec.at(i).S);
            wind_times++;

            all_t += stod(my_vec.at(i).T);
            t_times++;
        }

    }

    if (have_data == false)
    {
        return "";
    }
    ss << all_wind_speed / wind_times << "," << all_t/ t_times<<","<< all_sr/ sr_times;

    return ss.str();

}


string FileAnalysis::getBstCMD1(int year, int month)
{
    string ret;
    stringstream ss;
    ss << getMouthEnglish(month) << ": ";

    bool have_data = false;
    double all_wind_speed = 0, wind_times = 0;
    double all_t = 0, t_times = 0;

    Bst_Node node;
    node.key.year = year;
    node.key.month = month;

    auto vec_weather = find_val(root, node);

    if (vec_weather == nullptr)
    {
        ss << year << "No Data";
        return ss.str();
    }

    for (int i = 0; i < vec_weather->data.size(); i++)
    {
        Date_Time data = getDataTime(vec_weather->data.at(i).getWAST());
        if (data.date.month == month && data.date.year == year)
        {
            have_data = true;
            all_wind_speed += stod(vec_weather->data.at(i).S);
            wind_times++;

            all_t += stod(vec_weather->data.at(i).T);
            t_times++;
        }

    }

    
    ss << all_wind_speed / wind_times << "km/h, ";
    ss << all_t / t_times << " degrees C";
    return ss.str();
}

string FileAnalysis::getBstCMD2(int year, int month)
{
    string ret;
    stringstream ss;
    ss << getMouthEnglish(month) << ": ";

    bool have_data = false;
    double all_wind_speed = 0, wind_times = 0;
    double all_t = 0, t_times = 0;


    Bst_Node node;
    node.key.year = year;
    node.key.month = month;

    auto vec_weather = find_val(root, node);

    if (vec_weather == nullptr)
    {
        ss << year << "No Data";
        return ss.str();
    }

    for (int i = 0; i < vec_weather->data.size(); i++)
    {
        Date_Time data = getDataTime(vec_weather->data.at(i).getWAST());
        if (data.date.month == month && data.date.year == year)
        {
            have_data = true;
            if (vec_weather->data.at(i).S != "N/A")
            {
                all_wind_speed += stod(vec_weather->data.at(i).S);
                wind_times++;
            }
       
            if (vec_weather->data.at(i).T != "N/A")
            {
                all_t += stod(vec_weather->data.at(i).T);
                t_times++;
            }
        }
    }

    if (have_data == false)
    {
        ss << year << "No Data";
        return ss.str();
    }
    ss << all_wind_speed / wind_times << "km/h, ";
    ss << all_t / t_times << " degrees C";
    return ss.str();
}

string FileAnalysis::getBstCMD3(int year, int month)
{
    //January: 196.4 kWh / m2
    string ret;
    stringstream ss;
    ss << getMouthEnglish(month) << ": ";

    bool have_data = false;
    double all_sr = 0, sr_times = 0;
    Bst_Node node;
    node.key.year = year;
    node.key.month = month;

    auto vec_weather = find_val(root, node);

    if (vec_weather == nullptr)
    {
        ss << year << "No Data";
        return ss.str();
    }

    for (int i = 0; i < vec_weather->data.size(); i++)
    {
        Date_Time data = getDataTime(vec_weather->data.at(i).getWAST());
        if (data.date.month == month && data.date.year == year)
        {
            have_data = true;

            if (vec_weather->data.at(i).SR != "N/A")
            {
                all_sr += stod(vec_weather->data.at(i).SR);
                sr_times++;
            }
        }
    }

    if (have_data == false)
    {
        ss << year << "No Data";
        return ss.str();
    }
    ss << all_sr / sr_times << " kWh / m2 ";

    return ss.str();
}

string FileAnalysis::getBstCMD4(int year, int month)
{
    //January, 5.5, 25.5, 196.4
 //February, 4.5, 27.5, 200.3

    string ret;
    stringstream ss;
    ss << getMouthEnglish(month) << ": ";

    double all_wind_speed = 0, wind_times = 0;
    double all_t = 0, t_times = 0;


    Bst_Node node;
    node.key.year = year;
    node.key.month = month;

    auto vec_weather = find_val(root, node);

    if (vec_weather == nullptr)
    {
        ss << year << "No Data";
        return ss.str();
    }



    bool have_data = false;
    double all_sr = 0, sr_times = 0;
    for (int i = 0; i < vec_weather->data.size(); i++)
    {
        Date_Time data = getDataTime(vec_weather->data.at(i).getWAST());
        if (data.date.month == month && data.date.year == year)
        {
            have_data = true;

            if (vec_weather->data.at(i).SR != "N/A")
            {
                all_sr += stod(vec_weather->data.at(i).SR);
                sr_times++;
            }
  
            if (vec_weather->data.at(i).S != "N/A")
            {
                all_wind_speed += stod(vec_weather->data.at(i).S);
                wind_times++;
            }
     
            if (vec_weather->data.at(i).T != "N/A")
            {
                all_t += stod(vec_weather->data.at(i).T);
                t_times++;
            }
         
        }

    }

    if (have_data == false)
    {
        return "";
    }
    ss << all_wind_speed / wind_times << "," << all_t / t_times << "," << all_sr / sr_times;

    return ss.str();
}

double FileAnalysis::getBstCMD5(int year, int month, int days)
{
    string ret;
    stringstream ss;
    ss << getMouthEnglish(month) << ": ";

    bool have_data = false;
    double all_wind_speed = 0, wind_times = 0;
    double all_t = 0, t_times = 0;

    Bst_Node node;
    node.key.year = year;
    node.key.month = month;

    auto vec_weather = my_st.find(node);

    if (vec_weather == my_st.end())
    {
        return 0;
    }
    vector<Weather_Data, std::allocator<Weather_Data>> *tmp = (vector<Weather_Data, std::allocator<Weather_Data>> *)&vec_weather->data;
    for (int i = 0; i < vec_weather->data.size(); i++)
    {
        Date_Time data = getDataTime((*tmp)[i].getWAST());
        if (data.date.month == month && data.date.year == year&& data.date.days==days)
        {
            all_t += stod(vec_weather->data.at(i).SR);
            t_times++;
        }

    }

    return all_t/ t_times;
}

void FileAnalysis::print_Vector()
{
    //for (int i = 0; i < my_vec.getSize(); i++)
    //{
    //    cout << my_vec.at(i).DP << endl;
    //}
   /* cout << "读取的行数:" << my_vec.getSize() << endl;*/
}

Weather_Data FileAnalysis::paraseLine(string line)
{
    Weather_Data object;
    string::iterator First_word_end = find(line.begin(), line.end(), ',');
    string first_value = string(line.begin(), First_word_end);
    object.WAST = first_value;

    string::iterator second_word_end = find(First_word_end + 1, line.end(), ',');
    string second_value = string(First_word_end + 1, second_word_end);
    object.DP = second_value;

    string::iterator third_word_end = find(second_word_end + 1, line.end(), ',');
    string third_value = string(second_word_end + 1, third_word_end);
    object.Dta = third_value;

    string::iterator fourth_word_end = find(third_word_end + 1, line.end(), ',');
    string fourth_value = string(third_word_end + 1, fourth_word_end);
    object.Dts = fourth_value;

    string::iterator fifth_word_end = find(fourth_word_end + 1, line.end(), ',');
    string fifth_value = string(fourth_word_end + 1, fifth_word_end);
    object.EV = fifth_value;

    string::iterator sixth_word_end = find(fifth_word_end + 1, line.end(), ',');
    string sixth_value = string(fifth_word_end + 1, sixth_word_end);
    object.QFE = sixth_value;

    string::iterator seventh_word_end = find(sixth_word_end + 1, line.end(), ',');
    string seventh_value = string(sixth_word_end + 1, seventh_word_end);
    object.QFF = seventh_value;

    string::iterator eighth_word_end = find(seventh_word_end + 1, line.end(), ',');
    string eighth_value = string(seventh_word_end + 1, eighth_word_end);
    object.QNH = eighth_value;

    string::iterator ninth_word_end = find(eighth_word_end + 1, line.end(), ',');
    string ninth_value = string(eighth_word_end + 1, ninth_word_end);
    object.RF = ninth_value;

    string::iterator tenth_word_end = find(ninth_word_end + 1, line.end(), ',');
    string tenth_value = string(ninth_word_end + 1, tenth_word_end);
    object.RH = tenth_value;


    string::iterator eleventh_word_end = find(tenth_word_end + 1, line.end(), ',');
    string eleventh_value = string(tenth_word_end + 1, eleventh_word_end);
    object.S = eleventh_value;

    string::iterator twelveth_word_end = find(eleventh_word_end + 1, line.end(), ',');
    string twelveth_value = string(eleventh_word_end + 1, twelveth_word_end);
    object.SR = twelveth_value;


    string::iterator thirteenth_word_end = find(twelveth_word_end + 1, line.end(), ',');
    string thirteenth_value = string(twelveth_word_end + 1, thirteenth_word_end);
    object.ST1 = thirteenth_value;


    string::iterator fourteenth_word_end = find(thirteenth_word_end + 1, line.end(), ',');
    string fourteenth_value = string(thirteenth_word_end + 1, fourteenth_word_end);
    object.ST2 = fourteenth_value;

    string::iterator fifteenth_word_end = find(fourteenth_word_end + 1, line.end(), ',');
    string fifteenth_value = string(fourteenth_word_end + 1, fifteenth_word_end);
    object.ST3 = fifteenth_value;

    string::iterator sixteenth_word_end = find(fifteenth_word_end + 1, line.end(), ',');
    string sixteenth_value = string(fifteenth_word_end + 1, sixteenth_word_end);
    object.ST4 = sixteenth_value;

    string::iterator seventeenth_word_end = find(sixteenth_word_end + 1, line.end(), ',');
    string seventeenth_value = string(sixteenth_word_end + 1, seventeenth_word_end);
    object.Sx = seventeenth_value;

    string::iterator eighteenth_word_end = find(seventeenth_word_end + 1, line.end(), ',');
    string eighteenth_value = string(seventeenth_word_end + 1, eighteenth_word_end);
    object.T = eighteenth_value;

    return object;
}