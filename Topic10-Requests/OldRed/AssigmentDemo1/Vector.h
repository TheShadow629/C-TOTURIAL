#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include<string>
#include <string.h>
#include<iostream>
#include"Read_temp_save.h"
#include"Weather_data.h"
using namespace std;
template<typename Type>
class Vector
{
public:

    class Vector_Iterator
    {
    public:
        Vector_Iterator()
        {}

        void setPoint(Type *point)
        {
            pointer = point;
        }

        Type* next()
        {
            pointer = pointer + 1;
            return pointer;
        }

    private:
        Type* pointer=nullptr;
    };
    Vector()
    {
        size_vec = 0;
        capture_vec = 0;
        vec_info =nullptr;
    }

    void clear()
    {
        size_vec = 0;
        capture_vec = 0;
        delete[]vec_info;

    }
    ~Vector()
    {
        size_vec = 0;
        capture_vec = 0;
        delete []vec_info;
    }
    void insert (Type value)
    {
        if (capture_vec == 0)
        {
            size_vec = 0;
            capture_vec = 10;
            vec_info = new Type[10];
        }

        if (size_vec < capture_vec-1)
        {
            vec_info[size_vec] = value;
            size_vec++;
        }
        else
        {
            Type *new_vec_info = new Type[capture_vec * 2];
            for (int i = 0; i < size_vec; i++)
            {
                new_vec_info[i] = vec_info[i];
            }
            capture_vec = capture_vec * 2;

            delete []vec_info;
            vec_info = new_vec_info;

            vec_info[size_vec] = value;
            size_vec++;

        }
    }

    Type at(int index)
    {
        return vec_info[index];
    }

    int getSize()
    {
        return size_vec;
    }

    Type* getBegin()
    {
        return vec_info;
    }
private:
    int size_vec;
    int capture_vec;
    Type *vec_info;
};
#endif // VECTOR_H_INCLUDED
