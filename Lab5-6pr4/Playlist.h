#pragma once
#include "tutorial.h"
#include "DynamicVector.h"

class Playlist
{
private:
	DynamicVector<Tutorial> tutorials;
	int current;
public:
	Playlist();

	void add(const Tutorial& tutorial);

	Tutorial getCurrentTutorial();

	void play();

	void next();

	bool isEmpty();
};
