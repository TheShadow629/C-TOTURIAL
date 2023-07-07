// COURSE.H - Course class definition
// author KRI
// modified smr

#ifndef Unit_H
#define Unit_H

#include <iostream>
#include <string.h>  // C string library

using namespace std;

const unsigned CourseNameSize = 10;

class Unit {
public:
  Unit();
  Unit( const char * nam, long sect, unsigned cred );
  // Construct a course from a name, section letter,
  // and number of credits.
  //unsingned int
  unsigned GetCredits() const;
  // Get the number of credits.

  void SetCredits( unsigned cred );
  // Set the number of credits.

  void setunitID(long ID);

  long getunitID();

  void setunitCredits(int cre);
  
  int getunitCredits();

  void setName(char* nam);

  char* getName() const;


  // 
  // These operators have been made friends. They have
  // privileged access to class internals.
  // Very useful for debugging the class, but not very good for class design.
  // We will keep using it for now but you will have a chance in a later lab
  // to redesign this class.
  friend ostream & operator <<( ostream & os, const Unit & C );
  friend istream & operator >>( istream & input, Unit & C );

private:
  char name[CourseNameSize];  // course name, C style string. not a C++ string object
  long unitID;   // section (letter) can be enrolment mode
  int  unitCredits;   // number of credits
};

//域访问标识符
//内联


#endif
