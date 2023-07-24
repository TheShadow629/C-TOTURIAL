#include "ReadFile.h"
#include <string>
#include <fstream>
#include <sstream>

#include "BinerySearchTree.h"

void ReadFile::SetDataSourcePath(string path) {
	m_DataSourcePath = path;
}

string ReadFile::GetDataSourcePath() const {
	return m_DataSourcePath;
}

//void ReadFile::SetDataFilePaths(UserSpace::MyVector<string> paths) {
//	m_DataFilePaths = paths;
//}
//
//UserSpace::MyVector<string> ReadFile::GetDataFilePaths() const {
//	return m_DataFilePaths;
//}

//void ReadFile::SetRawCsvData(UserSpace::MyVector<UserSpace::MyVector<string>> data) {
//	m_RawCsvData = data;
//}

//UserSpace::MyVector<UserSpace::MyVector<string>> ReadFile::GetRawCsvData() const {
//	return m_RawCsvData;
//}

//void ReadFile::SetColNames(UserSpace::MyVector<string> colnames) {
//	m_ColNames = colnames;
//}
//
//UserSpace::MyVector<string> ReadFile::GetColNames() const {
//	return m_ColNames;
//}

//void ReadFile::SetDataWithoutHead(UserSpace::MyVector<SLWDT> data) {
//	m_DataWithoutHead = data;
//}
//
//UserSpace::MyVector<SLWDT> ReadFile::GetDataWithoutHead() const {
//	return m_DataWithoutHead;
//}

ReadFile::ReadFile(std::multimap <Date, std::map<std::string, double>>& outData, string source)
{
	m_DataSourcePath = source;//datasource:txt filename
	Initialize(outData);
}

void ReadFile::Initialize(std::multimap <Date, std::map<std::string, double>>& outData)
{
	ifstream inFile(m_DataSourcePath, ios::in);
	string lineStr;
	while (getline(inFile, lineStr))
	{
		m_DataFilePaths.push_back(lineStr);//CSVfilename in txt
	}
	//for (int i = 0; i < m_DataFilePaths.GetSize(); i++)//依次处理几个csv file
	for (auto CsvFileName = m_DataFilePaths.begin(); CsvFileName != m_DataFilePaths.end(); ++CsvFileName)
	{
		//此时处理的csv文件名是m_DataFilePaths[i]
		//ifstream singleCSV(m_DataFilePaths[i], ios::in);//get the data from the first csv file, save in the singleCSV.
		ifstream singleCSV(*CsvFileName, ios::in);//get the data from the first csv file, save in the singleCSV.
		string allColName;//save the head data.
		getline(singleCSV, allColName);
		//将表头信息读入m_ColNames
		stringstream ss(allColName);//stringstream can divide by the ',',so we need save the information into ss.
		string colName;

		//UserSpace::MyVector<string> preColNames;
		//if (m_ColNames.GetSize() > 0)//说明前面已经读取过至少一个文件
		//	preColNames = m_ColNames;

		//UserSpace::MyVector<string> New_m_ColNames;
		//while (getline(ss, colName, ','))//split the head information by',', and add in add m_colnames one by one.
		//{
		//	New_m_ColNames.Add(colName);
		//}
		//m_ColNames = New_m_ColNames;

		m_ColNames.clear();
		while (getline(ss, colName, ','))//split the head information by',', and add in add m_colnames one by one.
		{
			m_ColNames.push_back(colName);
		}

		string line;
		while (getline(singleCSV, line))//read one line.
		{
			stringstream ss(line);//put one line data into a stream variable-ss
			string single;
			//UserSpace::MyVector<string> lineArray;
			std::list<string> lineArray;
			while (getline(ss, single, ','))//split the line by',', and save the processed data into vector-linearray.
			{
				lineArray.push_back(single);
			}
			//m_RawCsvData.push_back(lineArray);

			//此时lineArray就是一行的数据，其形式为：1/03/2015 9:00	12	10.8	111	20	0.1	1011.3	1007.7
			stringstream ss1(*lineArray.begin());//read the first element in the first line and save it in ss1.
			string date/*, time*/;
			getline(ss1, date, ' ');//split the first element by' ',save in date.
			//getline(ss1, time, ' ');//split the first element, save time into time variable.

			//SLWDT sld;//declare the variable
			//sld.SetDate(date);//save the date variable into sld class.
			//sld.SetTime(time);//same as above.//sld.settime

			Date lineDate;
			lineDate.SetDate(date);
			std::map<std::string, double> lineSensor;
			if (lineDate.GetYear() != 0)//为了过滤空行
			{
				//m_ColNames.pop_front();
				//lineArray.pop_front();
				//for (int k = 1; k < lineArray.GetSize(); k++)
				auto ColName = m_ColNames.begin();
				ColName++;
				auto value = lineArray.begin();
				value++;

				for ( ; 
					(ColName != m_ColNames.end())&&(value!= lineArray.end());
					ColName++, value++)
				{
					try//为了过滤NA数据,使用tryCatch过滤错误数据
					{
						//sld.AddData(pair<string, double>(m_ColNames[k], std::stod(lineArray[k])));
						lineSensor.insert(pair<string, double>(*ColName, std::stod(*value)));
					}
					catch (...)
					{
						continue;//cout << "Something else" << endl;
					}
				}
				//m_DataWithoutHead.Add(sld);//save into member variable,m_datawithouthead,cause sld is local variable, it ends when the loop end, one time variable.  
				//outData.Add(sld);//return the useless, the lecture asked outdata.
				//m_MapDataWithoutHead[sld.GetDate()]= sld;
				//m_MapDataWithoutHead.insert(std::pair<Date, SLWDT>(sld.GetDate(), sld));

				m_MapDataWithoutHead1.insert(std::pair<Date, std::map<std::string, double>>(lineDate, lineSensor));
				outData.insert(std::pair<Date, std::map<std::string, double>>(lineDate, lineSensor));

				//outData.insert(std::pair<Date, SLWDT>(sld.GetDate(), sld));
			}
			//if (preColNames.GetSize() > 0)//说明前面已经读取过至少一个文件
			//{
			//	for (int k = 1; k < preColNames.GetSize(); k++)
			//	{
			//		int colIndex = GetColIndex(preColNames[k]) + 1;
			//		try {
			//			//为了过滤"N/A"和空行的情况)
			//			if (colIndex < lineArray.GetSize())
			//				sld.AddData(std::stod((lineArray[colIndex]).c_str()));
			//			else
			//				continue;
			//		}
			//		catch (std::invalid_argument&) {
			//			//cout << "Invalid_argument" << endl;
			//		}
			//		catch (std::out_of_range&) {
			//			//cout << "Out of range" << endl;
			//		}
			//		catch (...) {
			//			//cout << "Something else" << endl;
			//		}
			//	}
			//}
			//else
			//{
			//	//首次读文件，即读入第一个文件
			//	for (int k = 1; k < lineArray.GetSize(); k++)
			//	{
			//		sld.AddData(std::stod((lineArray[k]).c_str()));//read one line from the second data(except the date and time), and save in sld.
			//	}
			//}
			////为了过滤空行的情况
			//if (sld.GetSensorsData().GetSize() < m_ColNames.GetSize() - 1)
			//	continue;
		}
		//if (preColNames.GetSize() > 0)
		//	m_ColNames = preColNames;//恢复m_ColNames的内容，如此可以保证所有文件的数据顺序都按照第一个文件的表头顺序存储
	}
	//outData = m_DataWithoutHead;
}

//int ReadFile::GetColIndex(string colName)
////得到colName在m_DataWithoutHead[j].sensorsData中的下标
//{
//	int index = 0;
//	for (int i = 0; i < m_ColNames.GetSize(); i++)//search the matched head one by one, and give the index to the index variable.
//	{
//		if (colName == m_ColNames[i])
//		{
//			index = i;
//			break;
//		}
//	}
//	return index - 1;//if find the matched value, casue m_headwithoutdata(type SLWD,also saved in slwdt,so it means save in the sesor data.) saved the value except data and time,so if we want to find the colname, we need to minus 1,minus the data one. if can't find,return -1
//}

double ReadFile::GetDayData(int year, int month, int day, string colName, bool flag)
{
	//如果flag为false（0）我们就认为是需要总和，如果为true（1），我们就认为是需要平均值
	//double sum = 0;
	//int count = 0;
	//Date d(year, month, day);
	//auto iter1 = m_MapDataWithoutHead.lower_bound(d);
	//auto iter2 = m_MapDataWithoutHead.upper_bound(d);
	//int c = m_MapDataWithoutHead.count(d);
	//if (iter1 != std::end(m_MapDataWithoutHead)&&(c!=0))
	//{
	//	for (auto iter = iter1; iter != iter2; ++iter)
	//	{
	//		sum += iter->second.GetMapSensorsData()[colName];
	//		count++;
	//	}
	//	if (flag)
	//		return sum / count;
	//	else
	//		return sum;
	//}
	//else
	//{
	//	return 0;
	//}

	double sum = 0;
	int Count = 0;

	Date d(year, month, day);
	auto iter1 = m_MapDataWithoutHead1.lower_bound(d);
	auto iter2 = m_MapDataWithoutHead1.upper_bound(d);
	int c = m_MapDataWithoutHead1.count(d);

	if (iter1 != std::end(m_MapDataWithoutHead1) && (c != 0))
	{
		for (auto iter = iter1; iter != iter2; ++iter)
		{
			sum += iter->second[colName];
			Count++;
		}
		if (flag)
			return sum / Count;
		else
			return sum;
	}
	else
	{
		return 0;
	}

	//for (int i = 0; i < m_DataWithoutHead.GetSize(); i++)
	//{
	//	if ((m_DataWithoutHead[i].GetDate().GetYear() == year) &&
	//		(m_DataWithoutHead[i].GetDate().GetMonth() == month) &&
	//		(m_DataWithoutHead[i].GetDate().GetDay() == day))
	//		//judge if date of m_DataWithoutHead[i] matches the para list-(year,month,day)
	//	{
	//		//sum += m_DataWithoutHead[i].GetSensorsData()[GetColIndex(colName)];//save everthing without head in the m_datawithouthead, and the type is slwdt, so if wanna use date, involk the getdate method,if wanna use data without date, involk the sensor data.
	//		//find the matched data by using index.
	//		sum += m_DataWithoutHead[i].GetMapSensorsData()[colName];
	//		//save everthing without head in the m_datawithouthead, and the type is slwdt, so if wanna use date, involk the getdate method,if wanna use data without date, involk the sensor data.
	//		count++;//how many times we get the data, using to cal the aver.
	//	}
	//}

	//if (count != 0)
	//{
	//	result.Add(sum);
	//	result.Add(sum / count);
	//	//result里面第一个数字为当日数据总和，第二个数据为当日数据平均值
	//}
	//return result;//如果没有符合日期的数据则result为空
	//return to get specific data of day method.
}

Bst<double>& ReadFile::GetMonthData(int year, int month, string colName, bool flag)
{
	//bool flag决定我们需要当日数据的平均值（比如风速）还是总和（比如太阳辐射量）
	//如果flag为false（0）我们就认为是需要总和，如果为true（1），我们就认为是需要平均值
	//UserSpace::MyVector<double> result;
	Bst<double> res(0);
	for (int day = 1; day < DayNums; day++)
	{
		double dayValue = GetDayData(year, month, day, colName, flag);
		if (dayValue)
		{
			//result.Add(GetDayData(year, month, day, colName, flag));
			res.Insert(res.GetTree(), dayValue);
		}
	}
	return res;
	//return result;
}


