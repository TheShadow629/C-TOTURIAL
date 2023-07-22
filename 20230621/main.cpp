#include "UserInterface.h"
#define DEBUG
#include "BinerySearchTree.h"

#ifdef DEBUG
template<typename T>
void printData(T d)
{
	std::cout << d<<std::endl;
}
#endif

int main()
{
#ifdef DEBUG
	////测试Bst的内容
	//Bst<int> mybst(9);
	//mybst.Insert(mybst.GetTree(), 3);
	//mybst.Insert(mybst.GetTree(), 6);
	//mybst.Insert(mybst.GetTree(), 2);
	//mybst.Insert(mybst.GetTree(), 8);
	//mybst.Insert(mybst.GetTree(), 1);
	//mybst.Insert(mybst.GetTree(), 7);
	//mybst.Insert(mybst.GetTree(), 300);
	//mybst.Insert(mybst.GetTree(), 0);
	//mybst.InOrderTraversal(printData);
	//mybst.DeleteTree(mybst.GetTree());
#endif
	std::multimap <Date, SLWDT> v1;
	ReadFile f1(v1);

#ifdef DEBUG
	//测试map拿取数据正确性的内容
	//for (int i=0;i<v1.GetSize();i++)
	//{
	//	map<string,double>::iterator iter;
	//	for (iter = v1[i].GetMapSensorsData().begin(); iter != v1[i].GetMapSensorsData().end(); iter++)
	//	{
	//		cout << iter->first << ' ' << iter->second << endl;
	//	}
	//}

#endif

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
			UserInterface::Function5(f1);
			break;
		case 6:
			UserInterface::Function6_EXIT(runFlag);
			break;
		default:
			std::cout << "Invaild Input" << std::endl;
			return 0;
		}
	} while (runFlag);
	return 0;

}


