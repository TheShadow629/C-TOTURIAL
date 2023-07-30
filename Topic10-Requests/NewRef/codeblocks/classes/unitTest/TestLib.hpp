#ifndef TESTLIB_H
#define TESTLIB_H

#include <string>
#include <iomanip>

using namespace std;

/* Displays text as header */
void header(string title);

/* Displays text as new section */
void section(string section);

/* Displays a pass message */
void pass(string testName);

/* Displays a failure message */
void fail(string testName);

/* Evaluates actual result against expected result */
template <class T>
void require(T actual, T expected, string testName);

void header(string header)
{
    cout << endl
         << "=== " << header << " ===" << endl;
}

void section(string section)
{
    cout << endl
         << "--- " << section << " ---" << endl;
}

void pass(string testName)
{
    cout << left << setw(60) << testName << setw(20);
    cout << "- PASSED" << endl;
}

void fail(string testName)
{
    cout << left << setw(60) << testName << setw(20);
    cout << "- FAILED" << endl;
}

template <class T>
void require(T actual, T expected, string testName)
{
    cout << left << setw(60) << setfill(' ') << testName << setw(20) << setfill(' ');
    if (actual == expected)
        cout << "- PASSED" << endl;
    else
        cout << "- FAILED" << endl;
}
#endif
