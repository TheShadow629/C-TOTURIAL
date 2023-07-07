#include "ReadFile.h"
#include <string>
#include <fstream>
#include <sstream>
void ReadFile::setDataSourcePath(string path) {
	m_DataSourcePath = path;
}

string ReadFile::getDataSourcePath() const {
	return m_DataSourcePath;
}

void ReadFile::setDataFilePaths(UserSpace::MyVector<string> paths) {
	m_DataFilePaths = paths;
}

UserSpace::MyVector<string> ReadFile::getDataFilePaths() const {
	return m_DataFilePaths;
}

void ReadFile::setRawCsvData(UserSpace::MyVector<UserSpace::MyVector<string>> data) {
	m_RawCsvData = data;
}

UserSpace::MyVector<UserSpace::MyVector<string>> ReadFile::getRawCsvData() const {
	return m_RawCsvData;
}

void ReadFile::setColNames(UserSpace::MyVector<string> colnames) {
	m_ColNames = colnames;
}

UserSpace::MyVector<string> ReadFile::getColNames() const {
	return m_ColNames;
}

void ReadFile::setDataWithoutHead(UserSpace::MyVector<SLWDT> data) {
	m_DataWithoutHead = data;
}

UserSpace::MyVector<SLWDT> ReadFile::getDataWithoutHead() const {
	return m_DataWithoutHead;
}

ReadFile::ReadFile(UserSpace::MyVector<SLWDT>& outData,string source)
{
	m_DataSourcePath = source;//datasource:txt filename
	initialize(outData);
}

void ReadFile::initialize(UserSpace::MyVector<SLWDT>& outData)
{
	ifstream inFile(m_DataSourcePath, ios::in);
	string lineStr;
	while (getline(inFile, lineStr))
	{
		m_DataFilePaths.Add(lineStr);//CSVfilename in txt
	}
	for (int i = 0; i < m_DataFilePaths.GetSize(); i++)//依次处理几个csv file
	{
		//此时处理的csv文件名是m_DataFilePaths[i]
		ifstream singleCSV(m_DataFilePaths[i], ios::in);//get the data from the first csv file, save in the singleCSV.
		string allColName;//save the head data.
		getline(singleCSV, allColName);
		//将表头信息读入m_ColNames
		stringstream ss(allColName);//stringstream can divide by the ',',so we need save the information into ss.
		string colName;
		while (getline(ss, colName, ','))//split the head information by',', and add in add m_colnames one by one.
		{
			m_ColNames.Add(colName);
		}
		//将文件中的信息读入m_RawCsvData
		string line;
		while (getline(singleCSV, line))//read one line.
		{
			stringstream ss(line);//put one line data into a stream variable-ss
			string single;
			UserSpace::MyVector<string> lineArray;
			while (getline(ss, single, ','))//split the line by',', and save the processed data into vector-linearray.
			{
				lineArray.Add(single);
			}
			//m_RawCsvData.push_back(lineArray);

			//此时lineArray就是一行的数据，其形式为：1/03/2015 9:00	12	10.8	111	20	0.1	1011.3	1007.7
			stringstream ss1(lineArray[0]);//read the first element in the first line and save it in ss1.
			string date, time;
			getline(ss1, date, ' ');//split the first element by' ',save in date.
			getline(ss1, time, ' ');//split the first element, save time into time variable.

			SLWDT sld;//declare the variable
			sld.setDate(date);//save the date variable into sld class.
			sld.setTime(time);//same as above.//sld.settime

			for (int k = 1; k < lineArray.GetSize(); k++)
			{
				sld.addData(std::stod((lineArray[k]).c_str()));//read one line from the second data(except the date and time), and save in sld.

			}
			m_DataWithoutHead.Add(sld);//save into member variable,m_datawithouthead,cause sld is local variable, it ends when the loop end, one time variable.  
			outData.Add(sld);//return the useless, the lecture asked outdata.
		}
	}
	//outData = m_DataWithoutHead;
}
//m_DataWithoutHead[j].sensorsData[getColIndex("EV")]

int ReadFile::getColIndex(string colName)
//得到colName在m_DataWithoutHead[j].sensorsData中的下标
{
	int index = 0;
	for (int i = 0; i < m_ColNames.GetSize(); i++)//search the matched head one by one, and give the index to the index variable.
	{
		if (colName == m_ColNames[i])
		{
			index = i;
			break;
		}
	}
	return index - 1;//if find the matched value, casue m_headwithoutdata(type SLWD,also saved in slwdt,so it means save in the sesor data.) saved the value except data and time,so if we want to find the colname, we need to minus 1,minus the data one. if can't find,return -1
}


UserSpace::MyVector<double> ReadFile::getSpecificDataOfDay(int year, int month, int day, string colName)
{
	UserSpace::MyVector<double> result;
	double sum = 0;
	int count=0;
	for (int i = 0; i < m_DataWithoutHead.GetSize(); i++)
	{
		if ((m_DataWithoutHead[i].getDate().getYear() == year) &&
			(m_DataWithoutHead[i].getDate().getMonth() == month) &&
			(m_DataWithoutHead[i].getDate().getDay() == day))
		//judge if date of m_DataWithoutHead[i] matches the para list-(year,month,day)
		{
			sum += m_DataWithoutHead[i].getSensorsData()[getColIndex(colName)];//save everthing without head in the m_datawithouthead, and the type is slwdt, so if wanna use date, involk the getdate method,if wanna use data without date, involk the sensor data.
			//find the matched data by using index.
			count++;//how many times we get the data, using to cal the aver.
		}
	}
	if (count != 0)
	{
		result.Add(sum);
		result.Add(sum / count);
		//result里面第一个数字为当日数据总和，第二个数据为当日数据平均值
	}
	return result;//如果没有符合日期的数据则result为空
	//return to get specific data of day method.
}


UserSpace::MyVector<double> ReadFile::getSpecificDataOfMonth(int year, int month, string colName,bool flag)
{
	//bool flag决定我们需要当日数据的平均值（比如风速）还是总和（比如太阳辐射量）
    //如果flag为false（0）我们就认为是需要总和，如果为true（1），我们就认为是需要平均值
	UserSpace::MyVector<double> result;

	for (int day = 1; day < 32; day++)
	{
		if (getSpecificDataOfDay(year, month, day, colName).GetSize() > 0)
		{
			result.Add(getSpecificDataOfDay(year, month, day, colName)[flag]);
		}
	}
	return result;
}


