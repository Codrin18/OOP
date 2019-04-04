#include "Repository.h"

int Repository::add(const Tutorial& tutorial)
{
   return this -> tutorials.add(tutorial);
}

int Repository::del(const Tutorial& tutorial)
{
   return this -> tutorials.del(tutorial);
}

int Repository::update(const Tutorial& tutorial)
{
    return this -> tutorials.update(tutorial);
}
