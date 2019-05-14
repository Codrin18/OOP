#include "controller.h"

bool Controller::addTutorialToRepo(const string& title, const string& presenter, const int& minutes, const int& seconds, const int& likes, const string& link)
{
	bool result = this->repo.add(title, presenter, minutes, seconds, likes, link);

	if (result)
		this->repo.writeToFile();

	return result;
}

void Controller::delTutorialRepo(const string& link)
{
	this->repo.del(link);
}

bool Controller::updateTutorialRepo(const string& title, const string& presenter, const int& minutes, const int& seconds, const int& likes, const string& link)
{
	bool result = this->repo.update(Tutorial{ title,presenter,minutes,seconds,likes,link });

	if (result)
		this->repo.writeToFile();
	return result;
}

void Controller::addToWatchlist(const Tutorial& tutorial)
{
	this->watchlist.push_back(tutorial);
}

void Controller::addTutorialToPlaylist(const Tutorial& tutorial)
{
	this->playlist.add(tutorial);
}

void Controller::deleteWatchlist(int index)
{
	watchlist.erase(watchlist.begin() + index);
}

void Controller::addTutorialByPresenterToPlaylist(const string& presenter)
{
	vector<Tutorial> allTutorials = this->getRepo().getTutorials();

	for (int i = 0; i < allTutorials.size(); ++i)
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

void Controller::updateLikesTutorialRepo(const Tutorial& tutorial)
{
	this->repo.updateLikes(tutorial);
}


