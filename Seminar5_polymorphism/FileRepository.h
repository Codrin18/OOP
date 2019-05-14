#pragma once
#include "Repository.h"

using namespace std;

class FileRepository : public Repository
{
private:
	string filename;

public:
	FileRepository(const string& filename);
	void add(const Song& song);
	void update(const string& oldTitle, const string& oldArtist, const Song& newSong);

private:
	void readFromFile();

public:
	void writeToFile();
};
