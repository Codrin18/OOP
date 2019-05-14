#include "FileRepository.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

FileRepository::FileRepository(const string & filename)
{
	this->filename = filename;
	this->readFromFile();
}

void FileRepository::add(const Song & song)
{
	this->songs.push_back(song);
	this->writeToFile();
}

void FileRepository::update(const string& oldTitle, const string& oldArtist, const Song& newSong)
{
	Song toUpdate = this->findByArtistAndTitle(oldArtist, oldTitle);
	if (toUpdate.getArtist() != "")
	{
		replace(this->songs.begin(), this->songs.end(), toUpdate, newSong);
		this->writeToFile();
	}
}

void FileRepository::readFromFile()
{
	/*filebuf fb;
	if (fb.open(this->filename, ios::in))
	{
		istream is(&fb);
		while (is)
		{
			Song fileSong{};
			is >> fileSong;
			this->songs.push_back(fileSong);
		}
		fb.close();
	}*/
	ifstream file(this->filename, ifstream::in);

	Song fileSong;
	while (file >> fileSong)
	{
		this->add(fileSong);
	}

	file.close();
}

void FileRepository::writeToFile()
{
	ofstream file(this->filename, ofstream::out);
	for (auto song : this->songs)
	{
		file << song;
	}
	file.close();
}
