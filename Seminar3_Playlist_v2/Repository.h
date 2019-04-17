#pragma once
#include "Song.h"
#include "DynamicVector.h"

class Repository
{
private:
	DynamicVector<Song>  songs;

public:
	Repository() {}

	void add(const Song& song);

	DynamicVector<Song> getSongs() const { return this->songs; }
};
