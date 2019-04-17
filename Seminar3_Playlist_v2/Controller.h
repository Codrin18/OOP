#pragma once
#include "Repository.h"
#include "Playlist.h"
#include <iostream>

using namespace std;

class Controller
{
private:
	Repository repo;
	Playlist playlist;

public:
	Controller(const Repository& repo) : repo(repo) {}

	Repository getRepo()const { return this->repo; }
	Playlist getPlaylist() const { return this->playlist; }

	void addSongToRepo(const string& artist, const string& title, const double minutes, const double secunds, const string& link);

	/*
	Adds a given song to the current playlist.
	Input: song - Song, the song must belong to the repository.
	Output: the song is added to the playlist.
	*/
	void addSongToPlaylist(const Song& song);

	// Adds all the songs from the repository, that have the given artist, to the current playlist.
	void addAllSongsByArtistToPlaylist(const string& artist);

	void startPlaylist();
	void nextSongPlaylist();

};