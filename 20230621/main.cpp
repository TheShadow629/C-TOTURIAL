#include "UserInterface.h"

int main()
{
	UserSpace::MyVector<SLWDT> v1;
	ReadFile f1(v1);

	bool runFlag = true;
	std::cout << "The functions are like below:" << std::endl <<
		"Function 1: The average wind speed and sample standard deviation for this wind speed given a specified month and year. (print on screen only)" << std::endl <<
		"Function 2: Average ambient air temperature and sample standard deviation for each month of a specified year. (print on screen only)" << std::endl <<
		"Function 3: Total solar radiation in kWh/m2 for each month of a specified year. (print on screen only)" << std::endl <<
		"Function 4: Average wind speed (km/h), average ambient ar"
		"temperature and total solar radiation in kWh/m2 for each month of a "
		"specified year.The standard deviation is printed in ( ) next to the "
		"average. (print to a file called\"WindTempSolar.csv\")" << std::endl <<
		"Press 5 to EXIT " << std::endl;
	std::cout << "Please input a number to select function " << std::endl;
	do
	{
		int selection;
		std::cin >> selection;
		switch (selection)
		{
		case 1:
			UserInterface::Function1(f1);
			break;
		case 2:
			UserInterface::Function2(f1);
			break;
		case 3:
			UserInterface::Function3(f1);
			break;
		case 4:
			UserInterface::Function4(f1);
			break;
		case 5:
			UserInterface::Function5_EXIT(runFlag);
			break;
		default:
			std::cout << "Invaild Input" << std::endl;
			return 0;
		}
	} while (runFlag);
	return 0;

}
//
//int fun1()
//{
//	int i = 10;
//	string s1 = "hello";
//	return i;
//	return s1;
//
//}
//int num = fun1();
//
//void fun2(int& oRes,string& oStr)
//{
//	cout << oStr;
//	string s1 = "hello";
//	oStr = s1;
//	int i = 10;
//	oRes = i;
//}
//
//int num;
//string mystring="world";
//fun2(num, mystring);

