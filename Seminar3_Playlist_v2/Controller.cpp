#include "Controller.h"

void Controller::addSongToRepo(const string& artist, const string& title, const double minutes, const double secunds, const string& link)
{
	Duration duration{ minutes, secunds };
	Song song{ artist, title, duration, link };

	this->repo.add(song);
}

void Controller::addSongToPlaylist(const Song& song)
{
	this->playlist.add(song);
}

void Controller::addAllSongsByArtistToPlaylist(const string& artist)
{
	//need all songs
	DynamicVector<Song> allSongs = this->getRepo().getSongs();
	//find song by artist
	for (int i = 0; i < allSongs.getSize(); i++)
	{
		Song currSong = allSongs[i];
		if (currSong.getArtist() == artist)
		{
			//add songs to playlist
			this->playlist.add(currSong);
		}
	}
}

void Controller::startPlaylist()
{
	this->playlist.play();
}

void Controller::nextSongPlaylist()
{
	this->playlist.next();
}