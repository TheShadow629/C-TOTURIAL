// Shape.cpp

#include <iostream>   //#include only if needed. Needed here
#include "Shape.h" 
using namespace std;
//-------------------------------------------------------------------

void Shape::Input ()
{
	cout << "Enter " << m_description << " height: ";
	cin >> m_height;
}

//-------------------------------------------------------------------


