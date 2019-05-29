#pragma once
#include "tutorial.h"
#include <vector>

using namespace std;

class Playlist
{
private:
	vector<Tutorial> tutorials;
	int current;
public:
	Playlist();

	void add(const Tutorial& tutorial);

	Tutorial getCurrentTutorial();

	void play();

	void next();

	bool isEmpty();
};