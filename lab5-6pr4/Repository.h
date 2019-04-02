#pragma once

#include "tutorial.h"
#include "DynamicVector.h"

class Repository
{
    private:

        DynamicVector tutorials;

    public:

        Repository(){}

        void add(const Tutorial& tutorial);

        DynamicVector getTutorials() const
        {
            return this -> tutorials;
        }
};
