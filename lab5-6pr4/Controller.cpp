
#include "Controller.h"


int Controller::addTutorialToRepo(const string& title,const string& presenter,const double minutes,const double seconds,const long long& likes,const string& link)
{
    Duration duration{minutes,seconds};
    Tutorial tutorial{title,presenter,duration,likes,link};
    return this -> repo.add(tutorial);
}

int Controller::delTutorialRepo(const string& title,const string& presenter,const double minutes,const double seconds,const long long& likes,const string& link)
{
    Duration duration{minutes,seconds};
    Tutorial tutorial{title,presenter,duration,likes,link};
    return this -> repo.del(tutorial);
}

int Controller::updateTutorialRepo(const string& title,const string& presenter,const double minutes,const double seconds,const long long& likes,const string& link)
{
    Duration duration{minutes,seconds};
    Tutorial tutorial{title,presenter,duration,likes,link};
    return this -> repo.update(tutorial);
}

