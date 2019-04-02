#pragma once

#include "tutorial.h"

typedef Tutorial TElem;

class DynamicVector
{
    private:
        TElem* elems;
        int size;
        int capacity;

    public:

        DynamicVector(int capacity = 10);

        DynamicVector(const DynamicVector& v);
        ~DynamicVector();

        DynamicVector& operator=(const DynamicVector& v);

        void add(const TElem& e);

        int getSize() const;
        TElem* getAllElems() const;

    private:

        void resize(double factor = 2);
};
