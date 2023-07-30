#ifndef VECTORTEST_HPP
#define VECTORTEST_HPP

#include <iostream>
#include <sstream>
#include "TestLib.hpp"       //test library
#include "../VECTOR.H"
#include "../DATE.H"

using namespace std;

// Forward declaration
void VectorTest();

// Implementation
void VectorTest()
{
    header("VECTOR TEST");

    section("Test Add");
    Vector<int> v2;
    for (int i = 0; i < 15; i++)
        v2.Add(i);
    v2.print_contents(); // debug
    require<int>(v2.getSize(), 15, "Add should add 15 elements to the vector");

    section("Test Vector containing Date class type");
    Date dateobj(20, 03, 2022);
    Vector<Date> v10;
    v10.Add(dateobj);
    v10.print_contents(); // debug
    require<int>(v10[0].GetDay(), 20, "The Date should have a day value of 20");

    section("Test Remove");
    Vector<int> v4;
    for (int i = 0; i < 15; i++)
        v4.Add(i);
    v4.Remove();
    v4.print_contents(); // debug
    require<int>(v4.getSize(), 14, "Remove should reduce to 14 elements of the vector");

    section("Test At");
    Vector<int> v3;
    for (int i = 0; i <10 ; i++)
        v3.Add(i+1);
    v3.print_contents(); // debug
    require<int>(v3.At(4), 5, "At(4) should return the 5th element of the vector");

    section("Test [] operator by changing 3rd element to 5");
    Vector<int> v7;
    for (int i = 0; i <10 ; i++)
        v7.Add(i+1);
    v7[3] = 5;
    v7.print_contents(); // debug
    require<int>(v7[3], 5, "should return 5 in the 3rd index");

    section("Test double equal operator overload");
    Vector<int> v8;
    for (int i = 0; i <15 ; i++)
        v8.Add(i+1);
    Vector<int> v9;
    v9 = v8;
    v8.print_contents(); // debug
    v9.print_contents(); // debug
    require<bool>(v8 == v9, true, "Both vector are equal. Should return true");

    section("Test single equal operator overload");
    Vector<int> v5;
    for (int i = 0; i <15 ; i++)
        v5.Add(i+1);
    Vector<int> v6;
    v6 = v5;
    v6.Remove();
    v5.print_contents(); // debug
    v6.print_contents(); // debug
    require<int>(v6 == v5, false, "Both vectors are deep copied. Should return false");

    section("Test to check if vector is empty");
    Vector<int> v12;
    require<int>(v12.IsEmpty(), true, "Vector is empty. Should return true");

    section("Test to clear vector's content");
    Vector<int> v11;
    for (int i = 0; i <5 ; i++)
        v11.Add(i+1);
    v11.print_contents(); // debug
    v11.clearVect();
    v11.print_contents(); // debug
    require<int>(v11.IsEmpty(), true, "The Vector should be empty");

    section("Test vector sort to ascending");
    Vector<int> v13;
    v13.Add(7);
    v13.Add(3);
    v13.Add(9);
    v13.print_contents(); // debug
    v13.sortVectAsc();
    v13.print_contents(); // debug
    require<int>(v13.At(2), 9, "Vector should be ascending therefore last element is 9");

    //special tests for exceptions
    cout << "\n";
    string testName = "At() should throw an exception if input < 0";
    try
    {
        v3.At(-1);
        fail(testName);
    }
    catch(...)
    {
        pass(testName);
    }

    // special tests for exceptions
    testName = "At() should throw an exception if input > current length";
    try
    {
        v3.At(10);
        fail(testName);
    }
    catch (...)
    {
        pass(testName);
    }

    section("Test to insert 6 at index of 1");
    Vector<int> v14;
    v14.Add(1);
    v14.Add(2);
    v14.Add(3);
    v14.Add(4);
    v14.Add(5);
    v14.InsertAt(1, 6);
    v14.print_contents(); // debug
    require<int>(v14.At(1), 6, "Index 1 should be a value of 6");

    section("Test to delete 6 from vector with value 1, 6, 2, 3, 4, 5");
    v14.DeleteFrom(1);
    v14.print_contents(); // debug
    require<int>(v14.At(1), 2, "Index 1 should be a value of 2");

}

#endif // VECTORTEST_HPP
