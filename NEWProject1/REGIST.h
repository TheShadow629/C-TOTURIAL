// REGIST.H - Registration class definition
// author KRI
// modified smr

#ifndef REGIST_H
#define REGIST_H

#include <iostream>
#include "Unit.h"
#include "Result.h"

using namespace std;

const unsigned MaxResults = 10;

class Registration {
public:
	Registration();

	unsigned GetCredits() const;
	unsigned GetCount() const;

	// 声明set方法
	void setStudentId(long id);
	void setSemester(unsigned sem);
	void setCount(unsigned c);

	// 声明get方法
	long getStudentId() const;
	unsigned getSemester()const;
	unsigned getCount()const;
	Result* getResults();

	// These operators have been made friends. They have
	// privileged access to class internals.
	// Very useful for debugging the class, but not very good for class design.
	// We will keep using it for now but you will have a chance in a later lab
	// to redesign this class.
	//friend ostream& operator <<(ostream& os, const Registration& R);
	//friend istream& operator >>(istream& input, Registration& R);

private:
	long studentId;             // student ID number
	unsigned semester;          // semester year, number
	unsigned count;             // number of courses
	//Unit courses[MaxCourses]; // array of courses
	Result results[MaxResults];

};
ostream& operator <<(ostream& os, const Registration& R);
istream& operator >>(istream& input, Registration& R);


#endif

