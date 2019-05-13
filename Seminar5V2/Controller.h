#pragma once
#include "FileRepository.h"
#include "Playlist.h"
#include "SongValidator.h"

using namespace std;

class Controller
{
private:
	FileRepository repo;
	Playlist playlist;
	SongValidator validator;

public:
	Controller(const FileRepository& repo, SongValidator validator) : repo{ repo }, validator{ validator } {}

	FileRepository& getRepo() { return this->repo; }
	Playlist getPlaylist() const { return this->playlist; }

	void addSongToRepo(const string& artist, const string& title, const double minutes, const double seconds, const string& source);

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