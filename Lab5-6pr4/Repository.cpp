#include "Repository.h"

int Repository::add(const Tutorial& tutorial)
{
	for (int i = 0; i < this->tutorials.getSize(); ++i)
	{
		if (this->tutorials[i].getLink() == tutorial.getLink())
			return 0;
	}

	this->tutorials.add(tutorial);
	return 1;
}

int Repository::del(const Tutorial& tutorial)
{
	int index = -1;
	for (int i = 0; i < this->tutorials.getSize(); ++i)
	{
		if (this->tutorials[i].getLink() == tutorial.getLink())
		{
			index = i;
			break;
		}
	}
	
	if (index == -1)
		return 0;
	while (index < this->tutorials.getSize() - 1)
	{
		this->tutorials[index] = this->tutorials[index + 1];
		++index;
	}
	this->tutorials.setSize(this->tutorials.getSize() - 1);
	return 1;
}

int Repository::update(const Tutorial& tutorial)
{
	int index = -1;
	for (int i = 0; i < this->tutorials.getSize(); ++i)
	{
		if (this->tutorials[i].getLink() == tutorial.getLink())
		{
			index = i;
			break;
		}
	}
	
	if (index == -1)
		return 0;

	this->tutorials[index].setTitle(tutorial.getTitle());
	this->tutorials[index].setPresenter(tutorial.getPresenter());
	this->tutorials[index].setDuration(tutorial.getDuration());
	this->tutorials[index].setLikes(tutorial.getLikes());
	this->tutorials[index].setLink(tutorial.getLink());

	return 1;
}
