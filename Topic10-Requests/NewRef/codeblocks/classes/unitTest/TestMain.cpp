#include <iostream>

// Import test files...
#include "DateTest.hpp"
#include "VectorTest.hpp"
#include "TimeTest.hpp"
#include "NodeTest.hpp"
#include "BstTest.hpp"

using namespace std;

int main(void)
{

    DateTest();
    cout << endl << endl;
    VectorTest();
    cout << endl << endl;
    TimeTest();
    cout << endl << endl;
    NodeTest();
    cout << endl << endl;
    BstTest();
    cout << endl << endl;
}
