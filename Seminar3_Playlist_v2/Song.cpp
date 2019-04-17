
#ifdef _WIN32
#include <shellapi.h>
#include "Song.h"
void Song::play()
{
	ShellExecute(NULL, NULL, "mozila.exe", this->getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
}

using namespace std;

Song::Song() : artist(""), title(""), duration(Duration()), link("") {}

Song::Song(const string& artist, const string& title, const Duration& duration, const string& link)
{
	this->artist = artist;
	this->title = title;
	this->duration = duration;
	this->link = link;
}

#endif
