#include "UserInterface.h"
#define DEBUG
#include <cassert>

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
	std::multimap <Date, Bst<MyPair>> v1;
	ReadWindLog f1(v1);
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

	for (auto obj : v1)
		obj.second.DeleteTree(obj.second.GetTree());
	return 0;

}


