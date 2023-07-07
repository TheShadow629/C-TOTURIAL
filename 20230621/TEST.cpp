#include <cassert>
#include <sstream>
#include "Date.h"
#include "MathUtils.h"
#include "ReadFile.h"
#include "Vector.h"

void testDateConstructor()
{
	// ���� Date �Ĺ��캯���Ƿ���������
	Date d(2022, 2, 27);
	assert(d.getYear() == 2022);
	assert(d.getMonth() == 2);
	assert(d.getDay() == 27);
}

void testDateSettersAndGetters()
{
	// ���� Date �� setter �� getter �����Ƿ���������
	Date d;
	d.setYear(2022);
	assert(d.getYear() == 2022);
	d.setMonth(12);
	assert(d.getMonth() == 12);
	d.setDay(31);
	assert(d.getDay() == 31);
}

void testDateSetDate()
{
	// ���� Date �� setDate �����Ƿ���������
	Date d;
	d.setDate("1/03/2014");
	assert(d.getYear() == 2014);
	assert(d.getMonth() == 3);
	assert(d.getDay() == 1);
}

void testDateIO()
{
	// ���� Date ����������������Ƿ���������
  // Test output operator (operator <<)
	{
		std::ostringstream oss;
		Date date(2022, 1, 1);
		oss << date;
		assert(oss.str() == "1 January 2022\n");
	}

	// Test input operator (operator >>)
	{
		std::istringstream iss("2022 12 31");
		Date date;
		iss >> date;
		assert(date.getDay() == 31);
		assert(date.getMonth() == 12);
		assert(date.getYear() == 2022);
		//assert means if the program satisfied () conditions, continue the next step, if false, stop the prograqm and threw the exception. 
	}
}
int testDate()
{
	testDateConstructor();
	testDateSettersAndGetters();
	testDateSetDate();
	testDateIO();
	return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void testCalculateAve()
{
	UserSpace::MyVector<double> nums;
	nums.Add(1.0);
	nums.Add(2.0);
	nums.Add(3.0);
	assert(MathUtils::almostEqual(MathUtils::CalculateAve(nums), 2.0) == true);
}

void testCalculateStand()
{
	UserSpace::MyVector<double> nums;
	nums.Add(1.0);
	nums.Add(2.0);
	nums.Add(3.0);
	assert(MathUtils::almostEqual(MathUtils::CalculateStand(nums), 2.0) == true);
}

 void testAlmostEqual()
 {
 	assert(MathUtils::almostEqual(1.0, 1.0 + 0.000999999, 0.001) == true);
 	assert(MathUtils::almostEqual(1.0, 1.0 + 0.001, 0.001) == false);
 	assert(MathUtils::almostEqual(1.0, 1.0 + 0.000999, 0.001) == false);
 }

void testGetMonthFromNum()
{
	assert(MathUtils::getMonthFromNum(1) == "January");
	assert(MathUtils::getMonthFromNum(2) == "February");
	assert(MathUtils::getMonthFromNum(3) == "March");
	assert(MathUtils::getMonthFromNum(4) == "April");
	assert(MathUtils::getMonthFromNum(5) == "May");
	assert(MathUtils::getMonthFromNum(6) == "June");
	assert(MathUtils::getMonthFromNum(7) == "July");
	assert(MathUtils::getMonthFromNum(8) == "August");
	assert(MathUtils::getMonthFromNum(9) == "September");
	assert(MathUtils::getMonthFromNum(10) == "October");
	assert(MathUtils::getMonthFromNum(11) == "November");
	assert(MathUtils::getMonthFromNum(12) == "December");
	assert(MathUtils::getMonthFromNum(13) == ""); // invalid month number
}

int testMathUtils()
{
	testCalculateAve();
	testCalculateStand();
	testAlmostEqual();
	testGetMonthFromNum();
	return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void testSetDataSourcePath()
{
	UserSpace::MyVector<SLWDT> outData;
	ReadFile rf(outData);
	rf.setDataSourcePath("test.txt");
	assert(rf.getDataSourcePath() == "test.txt");
}
void testSetDataFilePaths()
{
	UserSpace::MyVector<SLWDT> outData;
	ReadFile rf(outData);

	UserSpace::MyVector<string> paths;
	paths.Add("file1.csv");
	paths.Add("file2.csv");
	paths.Add("file3.csv");
	rf.setDataFilePaths(paths);
	assert(rf.getDataFilePaths() == paths);
}
void testSetRawCsvData()
{
	UserSpace::MyVector<SLWDT> outData;
	ReadFile rf(outData);

	UserSpace::MyVector<UserSpace::MyVector<string>> data;
	UserSpace::MyVector<string> tmp;
	tmp.Add("a");
	tmp.Add("b");
	tmp.Add("c");
	data.Add(tmp);

	rf.setRawCsvData(data);
	assert(rf.getRawCsvData()[0] == data[0]);
}

void testSetColNames()
{
	UserSpace::MyVector<SLWDT> outData;
	ReadFile rf(outData);

	UserSpace::MyVector<string> colnames;
	colnames.Add("name");
	colnames.Add("age");

	rf.setColNames(colnames);
	assert(rf.getColNames() == colnames);
}

void testSetDataWithoutHead()
{
	UserSpace::MyVector<SLWDT> outData;
	ReadFile rf(outData);

	UserSpace::MyVector<SLWDT> data;
	SLWDT tmps;
	string tmpp = "1/03/2014";
	tmps.setDate(tmpp);
	tmpp = "9:00";
	tmps.setTime(tmpp);
	tmps.addData(12.5);
	data.Add(tmps);

	rf.setDataWithoutHead(data);
	assert(!rf.getDataWithoutHead().Empty());
}

void testInitialize()
{
	UserSpace::MyVector<SLWDT> data;
	ReadFile rf(data);
	rf.initialize(data);
	assert(!rf.getDataFilePaths().Empty());
	assert(!rf.getRawCsvData().Empty());
	assert(!rf.getColNames().Empty());
	assert(!rf.getDataWithoutHead().Empty());
}

void testGetColIndex()
{
	UserSpace::MyVector<SLWDT> data;
	ReadFile rf(data);
	UserSpace::MyVector<string> colnames;
	colnames.Add("empty");
	colnames.Add("name");
	colnames.Add("age");
	colnames.Add("gender");

	rf.setColNames(colnames);
	assert(rf.getColIndex("name") == 0);
	assert(rf.getColIndex("age") == 1);
	assert(rf.getColIndex("gender") == 2);
}

void testGetSpecificDataOfMonth()
{
	UserSpace::MyVector<SLWDT> data;
	ReadFile rf(data);
	UserSpace::MyVector<double> monthData = rf.getSpecificDataOfMonth(2014, 3, "T", false);
	assert(!monthData.Empty());
}

void testGetSpecificDataOfDay()
{
	UserSpace::MyVector<SLWDT> data;
	ReadFile rf(data);
	UserSpace::MyVector<double> dayData = rf.getSpecificDataOfDay(2014, 3, 1, "T");
	assert(!dayData.Empty());
}

int testReadFile()
{
	testSetDataSourcePath();
	testSetDataFilePaths();
	testSetRawCsvData();
	testSetColNames();
	testSetDataWithoutHead();
	testInitialize();
	testGetColIndex();
	testGetSpecificDataOfMonth();
	testGetSpecificDataOfDay();
	return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void testSetDateAndGetDate()
{
	SingleLineWithDataAndTime slwdt;
	string dateStr = "1/03/2014";
	slwdt.setDate(dateStr);
	assert(slwdt.getDate().getYear() == 2014);
	assert(slwdt.getDate().getMonth() == 3);
	assert(slwdt.getDate().getDay() == 1);
}

void testSetTimeAndGetTime()
{
	SingleLineWithDataAndTime slwdt;
	string timeStr = "9:00";
	slwdt.setTime(timeStr);
	assert(slwdt.getTime().getHour() == 9);
	assert(slwdt.getTime().getMin() == 0);
}

void testAddDataAndGetSensorsData()
{
	SingleLineWithDataAndTime slwdt;
	slwdt.addData(1.0);
	slwdt.addData(2.0);
	slwdt.addData(3.0);
	UserSpace::MyVector<double> data = slwdt.getSensorsData();
	assert(data.GetSize() == 3);
	assert(data[0] == 1.0);
	assert(data[1] == 2.0);
	assert(data[2] == 3.0);
}

int testSingleLineWithDataAndTime()
{
	testSetDateAndGetDate();
	testSetTimeAndGetTime();
	testAddDataAndGetSensorsData();
	return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void testDefaultConstructor()
{
	Time t;
	assert(t.getHour() == 0);
	assert(t.getMin() == 0);
}

void testCustomConstructor()
{
	Time t(10, 30);
	assert(t.getHour() == 10);
	assert(t.getMin() == 30);
}

void testGetHour()
{
	Time t(9, 40);
	assert(t.getHour() == 9);
}

void testSetHour()
{
	Time t(15, 20);
	t.setHour(16);
	assert(t.getHour() == 16);
}

void testGetMin()
{
	Time t(11, 45);
	assert(t.getMin() == 45);
}

void testSetMin()
{
	Time t(14, 50);
	t.setMin(55);
	assert(t.getMin() == 55);
}

void testSetTime()
{
	Time t;
	t.setTime(12, 30);
	assert(t.getHour() == 12);
	assert(t.getMin() == 30);
}

void testSetTimeFromString()
{
	Time t;
	t.setTime("09:30");
	assert(t.getHour() == 9);
	assert(t.getMin() == 30);
}

void testSetTimeFromStringIncorrectFormat()
{
	Time t;
	try
	{
		t.setTime("9-30");
	}
	catch (const std::exception& e)
	{
		std::string expectedMsg = "Invalid time format, should be HH:MM";
		assert(e.what() == expectedMsg);
	}
}

int testTime()
{
	testDefaultConstructor();
	testCustomConstructor();
	testGetHour();
	testSetHour();
	testGetMin();
	testSetMin();
	testSetTime();
	testSetTimeFromString();
	testSetTimeFromStringIncorrectFormat();

	return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int testUserInterface()
{
	return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
template <class T>
void TestMyVectorConstructor()
{
	UserSpace::MyVector<T> vec;
	assert(vec.GetSize() == 0);
}

template <class T>
void TestMyVectorAdd()
{
	UserSpace::MyVector<T> vec;
	vec.Add(1);
	vec.Add(2);
	assert(vec.GetSize() == 2);
	assert(vec[0] == 1);
	assert(vec[1] == 2);
}

template <class T>
void TestMyVectorInsert()
{
	UserSpace::MyVector<T> vec;
	vec.Add(1);
	vec.Add(3);
	vec.Insert(vec.begin() + 1, 2);
	assert(vec.GetSize() == 3);
	assert(vec[0] == 1);
	assert(vec[1] == 2);
	assert(vec[2] == 3);
}

template <class T>
void TestMyVectorRemoveElements()
{
	UserSpace::MyVector<T> vec;
	vec.Add(1);
	vec.Add(2);
	vec.RemoveElements();
	assert(vec.GetSize() == 0);
}

template <class T>
void TestMyVectorDeletePosition()
{
	UserSpace::MyVector<T> vec;
	vec.Add(1);
	vec.Add(2);
	vec.DeletePosition(vec.begin() + 1);
	assert(vec.GetSize() == 1);
	assert(vec[0] == 1);
}

template <class T>
void TestMyVectorGetSize()
{
	UserSpace::MyVector<T> vec;
	assert(vec.GetSize() == 0);
	vec.Add(1);
	vec.Add(2);
	vec.Add(3);
	assert(vec.GetSize() == 3);
}


template <class T>
void TestMyVectorEmpty()
{
	UserSpace::MyVector<T> vec;
	assert(vec.Empty());
	vec.Add(1);
	assert(!vec.Empty());
}

int testMyVector()
{
	TestMyVectorConstructor<int>();
	TestMyVectorAdd<int>();
	TestMyVectorInsert<int>();
	TestMyVectorRemoveElements<int>();
	TestMyVectorDeletePosition<int>();
	TestMyVectorGetSize<int>();
	TestMyVectorEmpty<int>();
	cout << "All tests passed!" << endl;
	return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++