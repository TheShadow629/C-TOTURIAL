#include "Result.h"

Result::Result()
{

}
void Result::setUnit(Unit u)
{
	u1 = u;
}
Unit Result::getUnit() const
{
	return u1;
}
void Result::setmarkPoints(float m)
{
	markPoints = m;
}
float Result::getmarkPoints() const
{
	return markPoints;
}

void Result::setDate(int year, int month, int day)
{
	theDate.setYear(year);
	theDate.setMonth(month);
	theDate.setDay(day);
}
Date Result::getDate() const
{
	return theDate;
}



istream& operator >>(istream& input, Result& C)
{
	//string word;
	//getline(input, word, ',');
	//char* tmpname = (char*)malloc(10 * sizeof(char));
	string tmpname;
	string tmpID;
	int tmpCredit;
	float tmpMarkPoint;
	Date tmpDate;

	input >> tmpname >> tmpID >> tmpCredit >> tmpMarkPoint;
	input >>tmpDate;
	C.u1.setName(tmpname);
	C.u1.setunitID(tmpID);
	C.u1.setunitCredits(tmpCredit);
	C.u1.setmarkPoints(tmpMarkPoint);
	C.setDate(tmpDate.getYear(), tmpDate.getMonth(), tmpDate.getDay());
	return input;
}

ostream& operator <<(ostream& os, const Result& C)
{
	os << "  Unit Name:  " << C.getUnit().getName() << '\n'
		<< "  Unit ID: " << C.getUnit().getunitID() << '\n'
		<< "  Credits: " << C.getUnit().getunitCredits() << '\n'
		<< "  Marks: " << C.getUnit().getmarkPoints() << '\n'
		<< "  Date: " <<C.getDate();
	return os;
}



