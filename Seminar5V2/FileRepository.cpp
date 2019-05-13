#include "FileRepository.h"
#include <iostream>
#include <fstream>

using namespace std;

FileRepository::FileRepository(const string & filename)
{
	this->filename = filename;
	this->readFromFile();
}

void FileRepository::add(const Song & song)
{
	if (this->findByArtistAndTitle(song.getArtist(), song.getTitle()).getArtist() != "")
		throw DuplicateSongException();
	this->songs.push_back(song);
	this->writeToFile();
}

void FileRepository::readFromFile()
{
	ifstream file(this->filename, ifstream::in);

	if (!file.is_open())
		throw FileException("File could not be opened!");

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

	if (!file.is_open())
		throw FileException("File could not be opened!");

	for (auto song : this->songs)
	{
		file << song;
	}
	file.close();
}
