#pragma once
#include "Song.h"
#include "DynamicVector.h"

class Playlist
{
private:
	DynamicVector<Song> songs;
	int current;
public:
	Playlist();

	void add(const Song& s);

	Song getCurrentSong();

	void play();

	void next();

	bool isEmpty();
};