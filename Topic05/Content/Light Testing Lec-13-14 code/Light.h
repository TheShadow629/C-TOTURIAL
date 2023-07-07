// Light.h
// Class representing a light
//
// Version
// original - Nicola Ritter
// modified - smr
//
//--------------------------------------------------------------------

#ifndef LIGHT_H
#define LIGHT_H

//--------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

//--------------------------------------------------------------------

// not part of the Light class. Used only for demonstration
void resetcount();

class Light
{
public:
	Light ();
	Light (const Light &other);  // what kind of constructor is this? Is it essential to have it? Why?
	virtual ~Light () {};        // Why would this be virtual

	virtual void Clear ();

	void Set (const string &colour) {m_colour = colour;}  // implementation in the interface for demo purposes only
	bool Set (float radius);
	void Switch ();

	void Get (string &colour) const {colour = m_colour;} // implementation in the interface for demo purposes only

	friend ostream& operator << (ostream &ostr, const Light &light);  // for debugging only. shouldn't normally be friend

protected:
	// Any string giving a colour is acceptable
	string m_colour;
	// In centimeters
	float  m_radius;
	bool   m_on;
};

//--------------------------------------------------------------------

#endif
