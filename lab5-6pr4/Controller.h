#pragma once

#include "Repository.h"

class Controller
{
    private:

        Repository repo;

    public:

        Controller(const Repository& repo) : repo(repo) {}

        Repository getRepo()const { return this->repo; }

        void addTutorialToRepo(const string& title,const string& presenter,const double minutes,const double seconds,const long long& likes,const string& link);
};
