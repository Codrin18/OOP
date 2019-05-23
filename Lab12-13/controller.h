#pragma once

#include "repository.h"
#include "playlist.h"
#include "TutorialValidator.h"

class Controller
{
private:

	Repository repo;
	Playlist playlist;
	vector<Tutorial> watchlist;
	TutorialValidator validator;

public:
	//Constructor for controller
	Controller(const Repository& repo, TutorialValidator& v) : repo(repo),validator(v) {}
	//Returns the elements
	Repository getRepo()const { return this->repo; }
	Playlist getPlaylist() const { return this->playlist; }

	vector<Tutorial> getWatchlist() const { return this->watchlist; }
	//Adds a new tutorial
	bool addTutorialToRepo(const string& title, const string& presenter, const int& minutes, const int& seconds, const int& likes, const string& link);
	//Deletes a tutorial
	void delTutorialRepo(const string& link);
	//Updates a tutorial
	bool updateTutorialRepo(const string& title, const string& presenter, const int& minutes, const int& seconds, const int& likes, const string& link);
	//Adds a tutorial to the watchlist
	void addToWatchlist(const Tutorial& tutorial);
	//Adds a tutorial to the playlist
	void addTutorialToPlaylist(const Tutorial& tutorial);
	//Deletes tutorials from watchlist
	void deleteWatchlist(int index);
	//Gets all tutorials with a given presenter
	void addTutorialByPresenterToPlaylist(const string& presenter);
	//Starts the playlist
	void startPlaylist();
	//It goes to next tutorial
	void nextTutorialPlaylist();
	//Increases the number of likes of a tutorial in repository
	void updateLikesTutorialRepo(const Tutorial& tutorial);
};