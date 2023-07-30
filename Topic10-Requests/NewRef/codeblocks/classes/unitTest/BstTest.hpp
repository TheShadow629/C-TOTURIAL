#ifndef BSTTEST_HPP
#define BSTTEST_HPP

#include <iostream>
#include <sstream>
#include "TestLib.hpp"       //test library
#include "../BST.H"
#include "../DATE.H"
#include <fstream>

using namespace std;

// Forward declaration
void BstTest();

Date get_date_from_line(const string& line) {

    stringstream ss(line);
    string datetime;
    getline(ss, datetime, ','); // Get datetime from line

    stringstream ss_datetime(datetime);
    string date;
    getline(ss_datetime, date, ' '); // Get date from datetime

    stringstream ss_date(date);
    string month, day, year;

    getline(ss_date, month, '/');
    getline(ss_date, day, '/');
    getline(ss_date, year, ' ');

    return Date(stoi(day), stoi(month), stoi(year));
}

void printInteger(int& i) {
    cout << i << ' ';
}

bool getGreaterThanFive(const int& i)
{
    return i > 5;
}

// Implementation
void BstTest()
{
    header("BST TEST");

    section("INSERT and SEARCH test. Inserted 5,21,3,8,90,1,4 and search for 5");
    Bst<int> b1;
    b1.insert(5);
    b1.insert(21);
    b1.insert(3);
    b1.insert(8);
    b1.insert(90);
    b1.insert(1);
    b1.insert(4);

    b1.inOrder();
    cout << endl;
    require<bool>(b1.search(5), true, "Integer 5 exists in BST");


    section("INSERT date in data folder into the tree");

    Bst<Date> dateTree;

    ifstream dataFile("data/MetData_Mar01-2015-Mar01-2016-ALL.csv");
    if (!dataFile) {
        cerr << "Error opening file. Please check the file path and permissions." << endl;
        return;
    }
    string line;
    // Skip the header line
    getline(dataFile, line);

    while(getline(dataFile, line)) {
        // Get date from line
        Date date = get_date_from_line(line);
        // Insert date into BST
        dateTree.insert(date);
    }

    cout << "Printing tree in order traversal:" << endl;
    dateTree.inOrder();

    cout << endl;

    section("in order traversal with function pointers that prints out the integers");
    b1.inOrder(printInteger);

    cout << endl;

    section("Test delete node. Inserted 1,2,3,4,5,6. Deleted node 3");
    Bst<int> b2;
    b2.insert(1);
    b2.insert(2);
    b2.insert(3);
    b2.insert(4);
    b2.insert(5);
    b2.insert(6);
    b2.deleteNode(3);
    b2.inOrder();
    cout << endl;
    require<bool>(b2.search(3), false, "Integer 3 No longer exists.");

    section("Test delete node that does not exist. Inserted 1,2,3,9,8,7. Deleted node 4");
    Bst<int> b3;
    b3.insert(1);
    b3.insert(2);
    b3.insert(3);
    b3.insert(9);
    b3.insert(8);
    b3.insert(7);
    b3.deleteNode(4);
    b3.inOrder();
    cout << "\nExpected output: BST is not affected." << endl;
    require<bool>(b3.search(1), true, "Integer 1 still exists");
    require<bool>(b3.search(2), true, "Integer 2 still exists");
    require<bool>(b3.search(3), true, "Integer 3 still exists");
    require<bool>(b3.search(9), true, "Integer 9 still exists");
    require<bool>(b3.search(8), true, "Integer 8 still exists");
    require<bool>(b3.search(7), true, "Integer 7 still exists");


}

#endif // BSTTEST_HPP
