#include <math.h>
#include <string>
#include "MathUtils.h"
#include "Vector.h"

double MathUtils::CalculateAve(const UserSpace::MyVector<double>& inums) 
{
    if (inums.GetSize() == 0)
        return 0;

    double sum = 0.0;
    for (int i = 0; i < inums.GetSize(); i++) 
    {
        sum += inums[i];
    }
    return sum / inums.GetSize();
}

double MathUtils::CalculateStand(const UserSpace::MyVector<double>& inums)
{
    if (inums.GetSize() == 0)
        return -1;

    double ave = MathUtils::CalculateAve(inums);
    double sum = 0.0;
    for (int i = 0; i < inums.GetSize(); i++) 
    {
        sum += pow(inums[i] - ave, 2);
       // pow(a, b);a^b
    }
    return sqrt(sum / inums.GetSize());
    //sqrt(a) ;a^0.5
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
