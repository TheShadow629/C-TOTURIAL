#pragma once
#include "Unit.h"
#include "Date.h"
class Result
{
public:
	Result();
	void setUnit(Unit u);
	Unit getUnit() const;
	void setmarkPoints(float m);
	float getmarkPoints() const;

	void setDate(int year, int month, int day);//TO DO: impl
	Date getDate() const;//protect data not change.

	//friend ostream& operator <<(ostream& os, const Result& C);
	//friend istream& operator >>(istream& input, Result& C);
	//TO DO: anno  set and get for theDate;
	Unit u1;
private:
	float markPoints;
	Date theDate;
};

ostream& operator <<(ostream& os, const Result& C);
istream& operator >>(istream& input, Result& C);

