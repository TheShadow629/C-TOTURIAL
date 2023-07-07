// REGIST.CPP - Registration class implementation.

#include "regist.h"
#include<string>


Registration::Registration()
{
    count = 0;
}

//const函数只能访问const成员，
//const修饰类成员函数：该函数对成员变量只能进行只读操作,但是不影响函数内的局部变量
unsigned Registration::GetCredits() const
{
    unsigned sum = 0;
    for (unsigned i = 0; i < count; i++)
        sum += results[i].getUnit().GetCredits();

    return sum;
}

unsigned Registration::GetCount() const
{
    return count;
}


void Registration::setStudentId(long id) {
	studentId = id;
}

void Registration::setSemester(unsigned sem) {
	semester = sem;
}

void Registration::setCount(unsigned c) {
	count = c;
}

long Registration::getStudentId() const{
	return studentId;
}

unsigned Registration::getSemester()const {
	return semester;
}

unsigned Registration::getCount() const {
	return count;
}

Result* Registration::getResults()
{
   // Result* tmp = results;
    return results;
}


istream& operator >>(istream& input, Registration& R)
{
    //string s;
    //getline(input, s);


	long studentId; 
	unsigned semester;
	unsigned count;
	Result results[MaxResults];
    input >> studentId >> semester >> count;
    R.setStudentId(studentId);
    R.setSemester(semester);
    R.setCount(count);

    //input >> R.studentId >> R.semester >> R.count;
    for (unsigned i = 0; i < R.getCount(); i++)
        input >> results[i];  // track down which >> operator is called. Hint: look at what is being input.
    R.setResults(results);
    return input;
}

ostream& operator <<(ostream& os, const Registration& R)
{
    os << "Student ID: " << R.getStudentId() << '\n'
        << "Semester:   " << R.getSemester() << '\n';

    for (unsigned i = 0; i < R.GetCount(); i++)
        os << R.getResults()[i] << '\n';

    return os;
}
