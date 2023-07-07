// COURSE.CPP - Course class implementation
#define _CRT_SECURE_NO_WARNINGS
#include "Unit.h"
#include <string>
#include <sstream>


inline unsigned Unit::GetCredits() const
{
    return unitCredits;
}

inline void Unit::SetCredits(unsigned cred)
{
    unitCredits = cred;
}


void Unit::setunitID(string ID)
{
    unitID = ID;
}

long Unit::getunitID()
{
    return unitID;
}

void Unit::setunitCredits(int cre)
{
    unitCredits = cre;
}

int Unit::getunitCredits()
{
    return unitCredits;
}


void Unit::setName(string nam)
{
    name = nam;
    //strncpy(name, nam, CourseNameSize);
}

string Unit::getName() const
{
    //char* tmpname=(char*)malloc(20*sizeof(char));
    //strncpy(tmpname, name, CourseNameSize);
    //return tmpname;
    return name;
}

Unit::Unit()
{
  name[0] = '\0'; // it is a char * string, not a C++ string object.
}
Unit::Unit( const string nam, long sect,unsigned cred )
{
    name = nam;
  //strncpy( name, nam, CourseNameSize );
  unitID = sect;
  unitCredits = cred;
}

//双目运算符，操作数有两个，一个是istream类型的input，另一个是Unit类型的C
istream & operator >>( istream & input, Unit & C )
{

  //input >> C.name >> C.unitID >> C.unitCredits;
  //return input;
  
  string line;//用来存放单行数据  
  while (getline(input, line))
  {
      istringstream sin(line);//将line转换为sstream
      string word;//存放以分隔符分隔开的元素
      string Words[5];
       int i = 0;
       for (int i = 0; getline(sin, word, ','); i++)
       {
           Words[i] = word;
       }

       //CHM_1020,1234566,3
       //Words: CHM_1020 1234566 3



       C.setName(Words[0]);
       C.setunitID(atoi(Words[1].c_str()));
       C.setunitCredits(atoi(Words[2].c_str()));

      //while (getline(sin, word, ','))
      //{
      //    C.setName(word);
      //    words.push_back(word); //将每一格中的数据逐个push
      //}
  }
  return input;
}

ostream & operator <<( ostream & os, const Unit & C )
{
  os << "  Course:  " << C.name << '\n'
     << "  Section: " << C.unitID << '\n'
     << "  Credits: " << C.unitCredits << '\n';
  return os;
}
