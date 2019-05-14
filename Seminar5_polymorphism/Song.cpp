#include "Song.h"
#include "Utils.h"
#include <Windows.h>
#include <shellapi.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

Song::Song() : artist(""), title(""), duration(Duration()), link("") {}

Song::Song(const string& artist, const string& title, const Duration& duration, const string& link)
{
	this->artist = artist;
	this->title = title;
	this->duration = duration;
	this->link = link;
}

Song::Song(const Song & toCopy)
{
	this->artist = toCopy.artist;
	this->title = toCopy.title;
	this->duration = toCopy.duration;
	this->link = toCopy.link;
}

string Song::toString()
{
	stringstream ss;
	ss << this->artist << "-" << this->title << "-" << this->duration.getMinutes() << ":" << this->duration.getSeconds() << "-" << this->link << endl;
	return ss.str();
}

bool Song::operator==(const Song & song)
{
	return (this->artist == song.artist && this->title == song.title);
}

void Song::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
}

istream & operator>>(istream & is, Song & song)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 4)
		return is;

	song.artist = tokens[0];
	song.title = tokens[1];

	vector<string> durationTokens = tokenize(tokens[2], ':');
	if (durationTokens.size() != 2)
		return is;

	song.duration = Duration{ stod(durationTokens[0]), stod(durationTokens[1]) };

	song.link = tokens[3];

	return is;
}

ostream & operator<<(ostream & os, const Song & song)
{
	os << song.artist << "," << song.title << "," << song.duration.getMinutes() << ":" << song.duration.getSeconds() << "," << song.link << "\n";
	return os;
}
