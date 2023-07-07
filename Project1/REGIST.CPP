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
  for(unsigned i = 0; i < count; i++)
    sum += results[i].getUnit().GetCredits();

  return sum;
}

inline unsigned Registration::GetCount() const
{
    return count;
}

istream & operator >>( istream & input, Registration & R )
{
    //string s;
    //getline(input, s);
  input >> R.studentId >> R.semester >> R.count;

  for(unsigned i = 0; i < R.count; i++)
    input >> R.results[i];  // track down which >> operator is called. Hint: look at what is being input.

  return input;
}

ostream & operator <<( ostream & os, const Registration & R )
{
  os << "Student ID: " << R.studentId << '\n'
     << "Semester:   " << R.semester << '\n';

  for(unsigned i = 0; i < R.count; i++)
    os << R.results[i] << '\n';

  return os;
}
