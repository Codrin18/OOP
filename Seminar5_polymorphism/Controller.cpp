#include "Controller.h"
#include "SongValidator.h"
#include <algorithm>

using namespace std;

void Controller::addSongToRepo(const string & artist, const string & title, const double minutes, const double seconds, const string & source)
{
	Song song{ artist, title, Duration{minutes, seconds}, source };
	this->validator.validate(song);

	this->repo.add(song);
}

void Controller::updateSongInRepo(const string & oldArtist, const string & oldTitle, const string & artist, const string & title, const double minutes, const double seconds, const string & source)
{
	Song newSong = Song(artist, title, Duration(minutes, seconds), source);
	this->repo.update(oldTitle, oldArtist, newSong);
}

void Controller::addSongToPlaylist(const Song& song)
{
	this->playlist.add(song);
}

void Controller::addAllSongsByArtistToPlaylist(const string & artist)
{
	//need all songs
	vector<Song> allSongs = this->getRepo().getSongs();
	//find song by artist
	vector<Song> filteredSongs;
	copy_if(allSongs.begin(), allSongs.end(), back_inserter(filteredSongs), [artist](Song s) {return s.getArtist() == artist; });

	for (auto s : filteredSongs)
		this->playlist.add(s);
}

void Controller::startPlaylist()
{
	this->playlist.play();
}

void Controller::nextSongPlaylist()
{
	this->playlist.next();
}
