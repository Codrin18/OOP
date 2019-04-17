#pragma once

#include "Repository.h"
#include "Playlist.h"

class Controller
{
private:

	Repository repo;
	Playlist playlist;

public:
	//Constructor for controller
	Controller(const Repository& repo) : repo(repo) {}
	//Returns the elements
	Repository getRepo()const { return this->repo; }
	Playlist getPlaylist() const { return this->playlist; }
	//Adds a new tutorial
	int addTutorialToRepo(const string& title, const string& presenter, const double minutes, const double seconds, const long long& likes, const string& link);
	//Deletes a tutorial
	int delTutorialRepo(const string& title, const string& presenter, const double minutes, const double seconds, const long long& likes, const string& link);
	//Updates a tutorial
	int updateTutorialRepo(const string& title, const string& presenter, const double minutes, const double seconds, const long long& likes, const string& link);

	void addTutorialToPlaylist(const Tutorial& tutorial);

	void addTutorialByPresenterToPlaylist(const string& presenter);

	void startPlaylist();

	void nextTutorialPlaylist();
};