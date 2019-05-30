#include "repository.h"
#include "exceptions.h"
#include "utils.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool Repository::add(const string& title, const string& presenter, const int& minutes,const int& seconds, const int& likes, const string& link)
{
	for (auto elem : tutorials)
	{
		if (elem.getLink() == link)
			throw DuplicateException();
	}

	tutorials.push_back(Tutorial{ title,presenter,minutes,seconds,likes,link });

	return true;
}

void Repository::del(const string& link)
{
	int index = -1;
	for (int i = 0; i < this->tutorials.size(); ++i)
	{
		if (this->tutorials[i].getLink() == link)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
		throw DeleteException();

	tutorials.erase(tutorials.begin() + index);
}

bool Repository::update(const Tutorial& tutorial)
{
	int index = -1;
	for (int i = 0; i < this->tutorials.size(); ++i)
	{
		if (this->tutorials[i].getLink() == tutorial.getLink())
		{
			index = i;
			break;
		}
	}

	if (index == -1)
		throw UpdateException();

	this->tutorials[index].setTitle(tutorial.getTitle());
	this->tutorials[index].setPresenter(tutorial.getPresenter());
	this->tutorials[index].setMinutes(tutorial.getMinutes());
	this->tutorials[index].setSeconds(tutorial.getSeconds());
	this->tutorials[index].setLikes(tutorial.getLikes());
	this->tutorials[index].setLink(tutorial.getLink());

	return true;

}

bool Repository::updateLikes(const Tutorial& tutorial)
{
	int index = -1;
	for (int i = 0; i < this->tutorials.size(); ++i)
	{
		if (this->tutorials[i].getLink() == tutorial.getLink())
		{
			index = i;
			break;
		}
	}

	if (index == -1)
		throw "Can not update the number of likes";
	this->tutorials[index].setLikes(this->tutorials[index].getLikes() + 1);

	return true;
}

std::istream& operator >> (std::istream& str, TextHandler& data)
{
	data.readNextRow(str);
	return str;
}

void Repository::readFromFile()
{
	std::ifstream file;
	file.open("tutorial.csv", std::ios_base::in);
	TextHandler row;
	while (file >> row) {
		try
		{
			int minutes = atoi(row[2].c_str());
			int seconds = atoi(row[3].c_str());
			int likes = atoi(row[4].c_str());
			this->add(row[0], row[1],minutes,seconds,likes, row[5]);
		}
		catch (DuplicateException e)
		{
			cout << e.what();
		}
	}
	file.close();	
}

void Repository::writeToFile()
{

	TextHandler row;

	row.writeToFile(tutorials);
}
