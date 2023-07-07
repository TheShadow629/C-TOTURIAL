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

void Result::setDate(int year,int month,int day)
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
	char* tmpname = (char*)malloc(10 * sizeof(char));
	long tmpID;
	int tmpCredit;
	Date tmpDate;
	input >> tmpname >> tmpID >> tmpCredit;
	C.getUnit().setName(tmpname);
	C.getUnit().setunitID(tmpID);
	C.getUnit().setunitCredits(tmpCredit);
	C.setDate(tmpDate.getYear(), tmpDate.getMonth(), tmpDate.getDay());
	return input;
}

ostream& operator <<(ostream& os, const Result& C)
{
	os << "  Course:  " << C.getUnit().getName() << '\n'
		<< "  Section: " << C.getUnit().getunitID() << '\n'
		<< "  Credits: " << C.getUnit().getunitCredits() << '\n'
		<< "  Mark: " << C.getmarkPoints() << '\n' << C.getDate() << '\n';
	return os;
}



