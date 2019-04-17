#include "Playlist.h"

Playlist::Playlist()
{
	this->current = 0;
}

void Playlist::add(const Song& song)
{
	this->songs.add(song);
}

Song Playlist::getCurrentSong()
{
	if (this->current == this->songs.getSize())
		this->current = 0;
	return this->songs[this->current];
}

void Playlist::play()
{
	if (this->songs.getSize() == 0)
		return;
	this->current = 0;
	Song currentSong = this->getCurrentSong();
	currentSong.play();
}

void Playlist::next()
{
	if (this->songs.getSize() == 0)
		return;
	this->current++;
	Song currentSong = this->getCurrentSong();
	currentSong.play();
}

bool Playlist::isEmpty()
{
	return this->songs.getSize() == 0;
}
