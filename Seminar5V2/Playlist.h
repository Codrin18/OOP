#pragma once
#include "Song.h"
#include <vector>

using namespace std;

class Playlist
{
private:
	vector<Song> songs;
	int current;
public:
	Playlist();

	void add(const Song& s);

	Song getCurrentSong();

	void play();

	void next();

	bool isEmpty();
};