#include "Playlist.h"

Playlist::Playlist()
{
	this->current = 0;
}

void Playlist::add(const Tutorial& tutorial)
{
	this->tutorials.add(tutorial);
}

Tutorial Playlist::getCurrentTutorial()
{
	if (this->current == this->tutorials.getSize())
		this->current = 0;
	return this->tutorials[this->current];
}

void Playlist::play()
{
	if (this->tutorials.getSize() == 0)
		return;
	this->current = 0;
	Tutorial currentTutorial = this->getCurrentTutorial();
	currentTutorial.play();
}

void Playlist::next()
{
	if (this->tutorials.getSize() == 0)
		return;
	this->current++;
	Tutorial currentTutorial = this->getCurrentTutorial();
	currentTutorial.play();
}

bool Playlist::isEmpty()
{
	return this->tutorials.getSize() == 0;
}