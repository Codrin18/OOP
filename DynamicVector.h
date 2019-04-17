#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class DynamicVector
{
private:
    T* elems;
    int size;
    int capacity;
public:
    //default constructor for DynamicVector
    DynamicVector(int capacity = 10);
    //copy constructor for DynamicVector
    DynamicVector(const DynamicVector& v);
    //destructor for DynamicVector
    ~DynamicVector();
    //assignment operator for a dynamic vector
    DynamicVector& operator=(const DynamicVector& v);
    /*
    Overloading the subscript operator
    Input: pos - a valid position within the vector
    Output:a reference to the element on position pos
    */
    T& operator[](int pos);

    void add(const T& e);

    int getSize() const;
    T* getElems() const;
    void setSize(int s) { size = s;}
private:
    void resize(double factor = 2);
};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
    this -> size = 0;
    this -> capacity = capacity;
    this -> elems = new T[capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
{
    this->size = v.size;
    this->capacity = v.capacity;
    this->elems = new T[v.capacity];
    for (int i = 0; i < v.capacity; i++)
    {
        this->elems[i] = v.elems[i];
    }

}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
    delete[] this->elems;
}


template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector& v)
{
    if (this == &v)
        return *this;
    this -> size = v.size;
    this -> capacity = v.capacity;
    delete[] this -> elems;
    this -> elems = new T[v.capacity];
    for (int i = 0; i < v.capacity; i++)
    {
        this->elems[i] = v.elems[i];
    }

    return *this;
}

template <typename T>
T& DynamicVector<T>::operator[](int pos)
{
    return this->elems[pos];
}


template <typename T>
void DynamicVector<T>::add(const T& e)
{
    if (this->size == this->capacity)
        resize();

    this->elems[this->size++] = e;
}

template <typename T>
void DynamicVector<T>::resize(double factor)
{
    this->capacity *= static_cast<int>(factor);

    T* els = new T[this->capacity];
    for (int i = 0; i < this->size; i++)
        els[i] = this->elems[i];

    delete[] this->elems;
    this->elems = els;
}

template <typename T>
int DynamicVector<T>::getSize() const
{
    return this->size;
}

template <typename T>
T* DynamicVector<T>::getElems() const
{
    return this->elems;
}
