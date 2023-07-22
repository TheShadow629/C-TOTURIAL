#pragma once
#include<iostream>
#include<fstream>
#include<set>
#include<vector>
#include<algorithm>
#include "Weather_data.h"
#include"Vector.h"
#include"Bst_Tree.h"
using namespace std;

struct Time_key
{
    int year;
    int month;
};

bool operator==(const Time_key &obj1, const Time_key &obj2);
bool operator<(const Time_key &obj1, const Time_key &obj2);
bool operator>(const Time_key &obj1, const Time_key &obj2);

struct Bst_Node
{
    Time_key key;
    vector<Weather_Data> data;
};

bool operator<   (const Bst_Node &obj1,const  Bst_Node &obj2);
bool operator>   (const Bst_Node &obj1,const  Bst_Node &obj2);
bool operator == (const Bst_Node &obj1,const  Bst_Node &obj2);
bool operator<=  (const Bst_Node &obj1,const  Bst_Node &obj2);
bool operator>=  (const Bst_Node &obj1,const  Bst_Node &obj2);

class FileAnalysis
{
public:
    FileAnalysis(string filepath1,string filepath2, string filepath3, string filepath4, string filepath5, string filepath6);
    ~FileAnalysis();
    void getFileContent();
    void print_Vector();
    Weather_Data paraseLine(string line);
public:
    string getCMD1(int year, int month);
    string getCMD2(int year, int month);
    string getCMD3(int year, int month);
    string getCMD4(int year, int month);
public:
    string getBstCMD1(int year, int month);
    string getBstCMD2(int year, int month);
    string getBstCMD3(int year, int month);
    string getBstCMD4(int year, int month);
    double getBstCMD5(int year, int month,int days);
private:
    string  file_path;
    fstream file1;
    fstream file2;
    fstream file3;
    fstream file4;
    fstream file5;
    fstream file6;
    BinTreeNode<Bst_Node>* root = nullptr;
    set<Bst_Node> my_st;
    Vector<Weather_Data> my_vec;
};

