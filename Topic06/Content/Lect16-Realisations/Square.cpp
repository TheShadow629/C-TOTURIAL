// Square.cpp
// what else is needed here?  IO is done here.

#include "Square.h" 

//-------------------------------------------------------------------

void Square::Draw () const // what does const do?
{
	for (int row = 0; row < m_height; row++)
	{
		for (int col = 0; col < m_height * ASPECT_RATIO; col++)
		{
			cout << '*';
		}
		cout << endl;
	}
	cout << endl;
}

//-------------------------------------------------------------------

