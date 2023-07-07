#include"Vector.h"
Vector::Vector()


    Vector::~Vector()
    {
        size_vec=0;
        capture_vec=10;
        delete[] vec_info;
    }

    void Vector::insert(Read_temp_save value)
    {
        if(size_vec<capture_vec)
        {
            vec_info[size_vec]=value;
            size_vec++;
        }
        else
        {
            Read_temp_save *new_vec_info= new Read_temp_save[capture_vec*2];
            memcpy(new_vec_info,vec_info,size_vec*sizeof(Read_temp_save));
            capture_vec=capture_vec*2;

            delete[] vec_info;
            vec_info=new_vec_info;

        }
    }
    void Vector::print_Vector()
    {
        for(int i=0; i<size_vec;i++)
        {
            cout<<vec_info[i]<<endl;
        }
    }
