// COURSE.CPP - Course class implementation
#define _CRT_SECURE_NO_WARNINGS
#include "Unit.h"
#include <string>


inline unsigned Unit::GetCredits() const
{
    return unitCredits;
}

inline void Unit::SetCredits(unsigned cred)
{
    unitCredits = cred;
}


void Unit::setunitID(long ID)
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


void Unit::setName(char* nam)
{
    strncpy(name, nam, CourseNameSize);
}

char* Unit::getName() const
{
    char* tmpname=(char*)malloc(20*sizeof(char));
    strncpy(tmpname, name, CourseNameSize);
    return tmpname;
}

Unit::Unit()
{
  name[0] = '\0'; // it is a char * string, not a C++ string object.
}
Unit::Unit( const char * nam, long sect,unsigned cred )
{
  strncpy( name, nam, CourseNameSize );
  unitID = sect;
  unitCredits = cred;
}

istream & operator >>( istream & input, Unit & C )
{
    //string word;
    //getline(input, word, ',');
  input >> C.name >> C.unitID >> C.unitCredits;
  return input;
}

ostream & operator <<( ostream & os, const Unit & C )
{
  os << "  Course:  " << C.name << '\n'
     << "  Section: " << C.unitID << '\n'
     << "  Credits: " << C.unitCredits << '\n';
  return os;
}
