#pragma once

#include "Repository.h"
#include "Playlist.h"

class Controller
{
private:

	Repository repo;
	Playlist playlist;
	DynamicVector<Tutorial> watchlist;

public:
	//Constructor for controller
	Controller(const Repository& repo) : repo(repo) {}
	//Returns the elements
	Repository getRepo()const { return this->repo; }
	Playlist getPlaylist() const { return this->playlist; }

	DynamicVector<Tutorial> getWatchlist() const { return this->watchlist; }
	//Adds a new tutorial
	int addTutorialToRepo(const string& title, const string& presenter, const double minutes, const double seconds, const long long& likes, const string& link);
	//Deletes a tutorial
	int delTutorialRepo(const string& title, const string& presenter, const double minutes, const double seconds, const long long& likes, const string& link);
	//Updates a tutorial
	int updateTutorialRepo(const string& title, const string& presenter, const double minutes, const double seconds, const long long& likes, const string& link);
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