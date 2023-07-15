#ifndef MathUtils_h__
#define MathUtils_h__

#include "Vector.h"
#include <string>

class MathUtils
{
public:
	static double CalculateAve(const UserSpace::MyVector<double>& inums) ;
	static double CalculateStand(const UserSpace::MyVector<double>& inums);
	static bool AlmostEqual(double d1, double d2, double tol=0.01);
	static std::string GetMonthFromNum(int m);
};


#endif // MathUtils_h__
