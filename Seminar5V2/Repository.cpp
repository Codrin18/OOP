#include "Repository.h"
#include <algorithm>
#include <vector>

using namespace std;


Song Repository::findByArtistAndTitle(const string& artist, const string& title)
{
	auto it = find_if(this->songs.begin(), this->songs.end(), [artist, title](Song s) {return (s.getArtist() == artist && s.getTitle() == title); });
	if (it != songs.end())
		return *it;
	return Song{};
}
