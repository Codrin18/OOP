#include <iostream>
#include <string>
#include "tutorial.h"

Tutorial::Tutorial():title(""),presenter(""),duration(Duration()),likes(0),link(""){}

Tutorial::Tutorial(const string& title,const string& presenter,const Duration& duration,const long long& likes,const string& link)
{
    this -> title = title;
    this -> presenter = presenter;
    this -> duration = duration;
    this -> likes = likes;
    this -> link = link;
}

