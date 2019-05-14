#pragma once
#include "Song.h"
#include <vector>

using namespace std;

class Repository
{
protected:
	vector<Song>  songs;

public:
	Repository() {}

	Song findByArtistAndTitle(const std::string& artist, const std::string& title);

	vector<Song> getSongs() const { return this->songs; }
};
