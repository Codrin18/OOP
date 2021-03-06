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

DynamicVector operator+(const DynamicVector& v,const TElem& e)
{
    DynamicVector res = v;

    res.add(e);

    return res;
}

DynamicVector operator+(const TElem& e,const DynamicVector& v)
{
    return v + e;
}

void DynamicVector::add(const TElem& e)
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
        return;
    }

    this -> elems[this->size++] = e;
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

int DynamicVector::update(const TElem& e)
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

    this -> elems[index].setTitle(e.getTitle());
    this -> elems[index].setPresenter(e.getPresenter());
    this -> elems[index].setDuration(e.getDuration());
    this -> elems[index].setLikes(e.getLikes());

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
