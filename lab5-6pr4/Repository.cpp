#include "Repository.h"

void Repository::add(const Tutorial& tutorial)
{
   //this -> tutorials = tutorials + tutorial;
   //this -> tutorials.add(tutorial);
   this -> tutorials = tutorial + tutorials;
}

int Repository::del(const Tutorial& tutorial)
{
   return this -> tutorials.del(tutorial);
}

int Repository::update(const Tutorial& tutorial)
{
    return this -> tutorials.update(tutorial);
}
