#include "playlist.h"

Playlist::Playlist()
{
	this->current = 0;
}

void Playlist::add(const Tutorial& tutorial)
{
	this->tutorials.push_back(tutorial);
}

Tutorial Playlist::getCurrentTutorial()
{
	if (this->current == this->tutorials.size())
		this->current = 0;
	return this->tutorials[this->current];
}

void Playlist::play()
{
	if (this->tutorials.size() == 0)
		return;
	this->current = 0;
	Tutorial currentTutorial = this->getCurrentTutorial();
	currentTutorial.play();
}

void Playlist::next()
{
	if (this->tutorials.size() == 0)
		return;
	this->current++;
	Tutorial currentTutorial = this->getCurrentTutorial();
	currentTutorial.play();
}

bool Playlist::isEmpty()
{
	return this->tutorials.size() == 0;
}