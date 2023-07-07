// Light.cpp
//--------------------------------------------------------------------

#include "Light.h"

    // counters for debugging the number of method calls.

static int counter = 0;  // for counting the number of constructions
static int Acounter = 0; // for counting the number of assignments

//--------------------------------------------------------------------

Light::Light ()
{
	cout << "Default Construction count = " << ++counter << endl;
	Clear();
}

//--------------------------------------------------------------------

Light::Light (const Light &other)
{
	cout << "Copy Construction count = " << ++counter << endl;
	Clear ();
	m_colour = other.m_colour;
	m_radius = other.m_radius;
	m_on = other.m_on;
}

//--------------------------------------------------------------------

Light& Light::operator=(const Light & other){

	cout << "Assignment count = " << ++Acounter << endl;
	Clear ();
	m_colour = other.m_colour;
	m_radius = other.m_radius;
	m_on = other.m_on;

}

//--------------------------------------
void Light::Clear ()
{
	//cout << "Running Light Clear" << endl;
	m_colour = "white";
	m_radius = 0;
	m_on = false;
}

//--------------------------------------------------------------------

ostream &operator << (ostream &ostr, const Light &light)
{
	ostr << light.m_radius << " cm, " << light.m_colour << " light is ";
	if (light.m_on)
	{
		ostr << "on";
	}
	else
	{
		ostr << "off";
	}

	return ostr;
}

//--------------------------------------------------------------------

bool Light::Set(float radius)
{
	if (radius > 0)
	{
		m_radius = radius;
		return true;
	}
	else
	{
		return false;
	}
}

//--------------------------------------------------------------------

void Light::Switch ()
{
	if (m_on)
	{
		m_on = false;
	}
	else
	{
		m_on = true;
	}
}

//--------------------------------------------------------------------
