
#include "Controller.h"


void Controller::addTutorialToRepo(const string& title,const string& presenter,const double minutes,const double seconds,const long long& likes,const string& link)
{
    Duration duration{minutes,seconds};
    Tutorial tutorial{title,presenter,duration,likes,link};
}
