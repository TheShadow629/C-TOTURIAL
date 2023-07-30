#ifndef NODETEST_HPP
#define NODETEST_HPP

#include <iostream>
#include <sstream>
#include "TestLib.hpp"       //test library
#include "../NODE.H"

using namespace std;

// Forward declaration
void NodeTest();

void NodeTest()
{
    header("NODE TEST");

    section("Construct Node");
    Node<int> node;

}

#endif // NODETEST_HPP
