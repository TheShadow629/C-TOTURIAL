#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <string.h>
#include<iostream>
#include"Read_temp_save.h"
using namespace std;
class Vector
{
public:
    Vector()
    {
        size_vec=0;
        capture_vec=10;
        vec_info=new int[10];
    }
    ~Vector();
    void insert (Read_temp_save value);
    void print_Vector();
private:
    int size_vec;
    int capture_vec;
    Read_temp_save *vec_info;
};







#endif // VECTOR_H_INCLUDED
