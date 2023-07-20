#include <math.h>
#include <string>
#include "MathUtils.h"

#include <list>

#include "Vector.h"

//double MathUtils::CalculateAve(const UserSpace::MyVector<double>& inums) 
//{
//    if (inums.GetSize() == 0)
//        return 0;
//
//    double sum = 0.0;
//    for (int i = 0; i < inums.GetSize(); i++) 
//    {
//        sum += inums[i];
//    }
//    return sum / inums.GetSize();
//}
//
//double MathUtils::CalculateStand(const UserSpace::MyVector<double>& inums)
//{
//    if (inums.GetSize() == 0)
//        return -1;
//
//    double ave = MathUtils::CalculateAve(inums);
//    double sum = 0.0;
//    for (int i = 0; i < inums.GetSize(); i++) 
//    {
//        sum += pow(inums[i] - ave, 2);
//    }
//    return sqrt(sum / inums.GetSize());
//}

bool MathUtils::CalculateAve(std::list<double> inums, double& result)
{
	if (inums.empty()) {
		return false;
	}

	double sum = 0.0;
	for (double num : inums) {
		sum += num;
	}

	result = sum / (inums.size());
	return true;
}

bool MathUtils::CalculateStand(std::list<double> inums, double& result)
{
	if (inums.size() < 2) {
		return false;
	}

	double sum = 0.0;
	double sumSquaredDiff = 0.0;
	for (double num : inums) {
		sum += num;
	}

	double average = sum / (inums.size());

	for (double num : inums) {
		double diff = num - average;
		sumSquaredDiff += diff * diff;
	}

	result = sqrt(sumSquaredDiff / (inums.size() ));
	return true;
}

 bool MathUtils::AlmostEqual(double d1, double d2, double tol) 
 {
     return fabs(d1 - d2) < tol;//fabs就是求绝对值
 }

std::string MathUtils::GetMonthFromNum(int m)
{
    std::string months[] = { "Invalid month", "January", "February", "March",
                        "April", "May", "June", "July", "August",
                        "September", "October", "November", "December" };
    return months[m];
}
