#include "Controller.h"
#include "Repository.h"

int Controller::addTutorialToRepo(const string& title, const string& presenter, const double minutes, const double seconds, const long long& likes, const string& link)
{
	Duration duration{ minutes,seconds };
	Tutorial tutorial{ title,presenter,duration,likes,link };
	return this->repo.add(tutorial);
}

int Controller::delTutorialRepo(const string& title, const string& presenter, const double minutes, const double seconds, const long long& likes, const string& link)
{
	Duration duration{ minutes,seconds };
	Tutorial tutorial{ title,presenter,duration,likes,link };
	return this->repo.del(tutorial);
}

int Controller::updateTutorialRepo(const string& title, const string& presenter, const double minutes, const double seconds, const long long& likes, const string& link)
{
	Duration duration{ minutes,seconds };
	Tutorial tutorial{ title,presenter,duration,likes,link };
	return this->repo.update(tutorial);
}

void Controller::addTutorialToPlaylist(const Tutorial& tutorial)
{
	this->playlist.add(tutorial);
}

void Controller::addTutorialByPresenterToPlaylist(const string& presenter)
{
	DynamicVector<Tutorial> allTutorials = this->getRepo().getTutorials();
	
	for (int i = 0; i < allTutorials.getSize(); ++i)
	{
		Tutorial currTutorial = allTutorials[i];
		if (currTutorial.getPresenter() == presenter)
			this->playlist.add(currTutorial);
	}
}

void Controller::startPlaylist()
{
	this->playlist.play();
}

void Controller::nextTutorialPlaylist()
{
	this->playlist.next();
}
