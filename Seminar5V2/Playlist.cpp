#include "Playlist.h"

Playlist::Playlist()
{
	this->current = 0;
}

void Playlist::add(const Song& s)
{
	this->songs.push_back(s);
}

Song Playlist::getCurrentSong()
{
	if (this->current == this->songs.size())
		this->current = 0;
	return this->songs[this->current];
}

void Playlist::play()
{
	if (this->songs.size() == 0)
		return;
	this->current = 0;
	Song currentSong = this->getCurrentSong();
	currentSong.play();
}

void Playlist::next()
{
	if (this->songs.size() == 0)
		return;
	this->current++;
	Song currentSong = this->getCurrentSong();
	currentSong.play();
}

bool Playlist::isEmpty()
{
	return this->songs.size() == 0;
}
