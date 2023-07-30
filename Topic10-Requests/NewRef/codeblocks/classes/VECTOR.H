#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <vector>

using namespace std;

template <class T>

/**
* @class Vector
* @brief The Vector class is a dynamic array
*
* The vector is able to resize itself according to the demand
*
* @author Noor Hidayat
*/
class Vector
{
public:
    /**
    * The default constructor of Vector
    */
    Vector();

    Vector(int size);

    /**
    * The destructor of Vector that deletes the array from the heap
    */
    ~Vector();

    /**
    * Adds an element to the back of the Vector.
    * If the Vector is full, automatically resizes bigger.
    */
    void Add(const T &element);

    /**
    * Deletes the last element of the Vector
    * If Vector is empty, throws an error
    */
    void Remove();

    /**
    * Returns the element at the specified index
    * @param index The integer of the index
    */
    T &At(int index);

    /**
    * Get the number of elements inside the Vector
    */
    const int getSize() const;

    /**
    * Set the number of elements the Vector can hold
    * @param s Is the size value to change the Vector to
    */
    void setSize(const int s);

    /**
    * Empties the vector
    */
    void clearVect();

    /**
    * Checks if the vector is empty.
    * Returns true if empty
    * Returns false if not empty
    */
    bool IsEmpty();

    /**
    * Sorts the array to ascending
    */
    void sortVectAsc();

    /**
    * Operator overload for the equal sign. To create a deep copy
    * @param obj Is the vector obj to copy
    */
    Vector<T> &operator=(const Vector &obj);

    /**
    * Operator overload for the bracket []. To modify or get any index of the element
    */
    T &operator[](const int index);

    /**
    * Operator overload for the == to check whether Vector obj has the same content
    * @param rhs Holds the vector obj
    */
    const bool operator==(const Vector& rhs) const;

    /**
    * Inserts an element at the specified index in the Vector.
    * @param index The index at which to insert the element
    * @param element The element to insert
    */
    void InsertAt(int index, const T& element);

    /**
    * Deletes an element at the specified index in the Vector.
    * @param index The index at which to delete the element
    */
    void DeleteFrom(int index);

    /* debug */
    void print_contents() const;

private:

    /** Stores data into vector */
    vector<T> m_vector;
};

/* Implementation */

template <class T>
Vector<T>::Vector()
{
    m_vector = vector<T>();
}

template <class T>
Vector<T>::Vector(int size)
{
    m_vector = vector<T>(size);
}

template <class T>
Vector<T>::~Vector()
{

}

template <class T>
void Vector<T>::Add(const T &element)
{
    m_vector.push_back(element);
}

template <class T>
void Vector<T>::Remove()
{
    m_vector.pop_back();
}

template <class T>
T &Vector<T>::At(int index)
{
    return m_vector.at(index);
}

template <class T>
const int Vector<T>::getSize() const
{
    return m_vector.size();
}

template <class T>
void Vector<T>::setSize(const int s)
{
    m_vector.resize(s);
}

template <class T>
void Vector<T>::clearVect()
{
    m_vector.clear();
}

template <class T>
bool Vector<T>::IsEmpty()
{
    return m_vector.empty();
}

template <class T>
void Vector<T>::sortVectAsc()
{
    for(size_t i = 0; i < m_vector.size() - 1; ++i)
    {
        for(size_t j = 0; j < m_vector.size() - i - 1; ++j)
            if(m_vector[j] > m_vector[j + 1])
            {
                T temp = m_vector[j];
                m_vector[j] = m_vector[j + 1];
                m_vector[j + 1] = temp;
            }
    }
}

template <class T>
Vector<T> &Vector<T>::operator=(const Vector& obj)
{
    if (this != &obj)
    {
        m_vector = obj.m_vector;
    }
    return *this;
}


template <class T>
T &Vector<T>::operator[](const int index)
{
    return m_vector[index];
}

template <class T>
const bool Vector<T>::operator==(const Vector& rhs) const
{
    return m_vector == rhs.m_vector;
}

template <class T>
void Vector<T>::InsertAt(int index, const T& element)
{

    if (index >= 0 && index <= getSize())
    {
        m_vector.insert(m_vector.begin() + index, element);
    }
    else
    {
        throw "Unable to insert at index. Out of range";
    }



}

template <class T>
void Vector<T>::DeleteFrom(int index)
{
    if (index >= 0 && index < getSize())
    {
        m_vector.erase(m_vector.begin() + index);
    }
    else
    {
        throw "Unable to delete index. Out of range";
    }


}

template <class T>
void Vector<T>::print_contents() const
{
    for (const auto& element : m_vector)
    {
        cout << element << ", ";
    }
    cout << endl;

}

#endif // VECTOR_H
