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
	
	void addToWatchlist(const Tutorial& tutorial);

	void addTutorialToPlaylist(const Tutorial& tutorial);

	void deleteWatchlist(int index);

	void addTutorialByPresenterToPlaylist(const string& presenter);

	void startPlaylist();

	void nextTutorialPlaylist();

	void updateLikesTutorialRepo(const Tutorial& tutorial);
};