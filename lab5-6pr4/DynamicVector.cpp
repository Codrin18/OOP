#include "DynamicVector.h"

DynamicVector::DynamicVector(int capacity)
{
    this -> size = 0;
    this -> capacity = capacity;
    this -> elems = new TElem[capacity];
}

DynamicVector::DynamicVector(const DynamicVector& v)
{
    this -> size = v.size;
    this -> capacity = v.capacity;
    this -> elems = new TElem[this -> capacity];

    for (int i = 0; i < this -> size; ++i)
    {
        this -> elems[i] = v.elems[i];
    }
}

DynamicVector::~DynamicVector()
{
    delete[] this -> elems;
}

DynamicVector& DynamicVector::operator=(const DynamicVector& v)
{
    if (this == &v)
        return *this;

    this -> size = v.size;
    this -> capacity = v.capacity;

    delete[] this -> elems;
    this -> elems = new TElem[this->capacity];

    for (int i = 0; i < this -> size; ++i)
        this -> elems[i] = v.elems[i];

    return *this;
}


int DynamicVector::add(const TElem& e)
{
    if (this -> size == this -> capacity)
        this -> resize();

    int index = -1;
    for (int i = 0; i < this -> size; ++i)
    {
        if (this -> elems[i].getLink() == e.getLink())
        {
            index = i;
            break;
        }
    }
    if (index > -1)
    {
        return 0;
    }

    this -> elems[this->size++] = e;

    return 1;
}

int DynamicVector::del(const TElem& e)
{
    int index = -1;
    for (int i = 0; i < this -> size; ++i)
    {
        if (this -> elems[i].getLink() == e.getLink())
        {
            index = i;
            break;
        }
    }

    if (index == -1)
        return 0;


    while(index < this -> size - 1)
    {
        this -> elems[index] = this -> elems[index + 1];
        ++index;
    }

    this -> size--;

    return 1;
}

void DynamicVector::resize(double factor)
{
    this->capacity *= static_cast <int> (factor);

    TElem* els = new TElem[this -> capacity];
    for (int i = 0; i < this -> size; ++i)
        els[i] = this -> elems[i];

    delete[] this -> elems;
    this -> elems = els;
}

int DynamicVector::getSize() const
{
    return this -> size;
}

TElem* DynamicVector::getAllElems() const
{
    return this -> elems;
}
