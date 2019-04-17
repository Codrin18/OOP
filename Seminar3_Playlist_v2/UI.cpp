#include "UI.h"
#include <string>

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 Manage song repository." << endl;
	cout << "2 Manage playlist." << endl;
	cout << "0 Exit." << endl;
}

void UI::printRepositoryMenu()
{
	cout << endl;
	cout << "1 Add song." << endl;
	cout << "2 Show all songs." << endl;
	cout << "0 Return." << endl;
}

void UI::printPlaylistMenu()
{
	cout << endl;
	cout << "1 Add songs by artist." << endl;
	cout << "2 Start playlist." << endl;
	cout << "3 Next." << endl;
	cout << "0 Return." << endl;
}

void UI::addSongToRepo()
{
	cout << "Enter the artist: ";
	string artist;
	getline(cin, artist);
	cout << "Enter the title: ";
	string title;
	getline(cin, title);
	cout << "Enter the minutes: ";
	double minutes = 0;
	cin >> minutes;
	cout << "Enter the seconds: ";
	double seconds = 0;
	cin >> seconds;
	cin.ignore();
	cout << "Enter the link: ";
	string link;
	getline(cin, link);

	this->ctrl.addSongToRepo(artist, title, minutes, seconds, link);
}

void UI::displayAllSongsRepo()
{
	DynamicVector<Song> v = this->ctrl.getRepo().getSongs();
	Song* songs = v.getElems();

	if (songs == NULL)
		return;

	if (v.getSize() == 0) {
		cout << "There are no songs to display." << endl;
		return;
	}

	for (int i = 0; i < v.getSize(); i++)
	{
		Song s = songs[i];
		Duration d = s.getDuration();
		cout << s.getArtist() << " - " << s.getTitle() << "; " << d.getMinutes() << ":" << d.getSeconds() << endl;
	}
}

void UI::addSongsToPlaylist()
{
	cout << "Enter the artist: ";
	string artist;
	getline(cin, artist);

	this->ctrl.addAllSongsByArtistToPlaylist(artist);
}

void UI::startPlaySongs()
{
	if (this->ctrl.getPlaylist().isEmpty())
		cout << "Nothing to play." << endl;
	this->ctrl.startPlaylist();
}

void UI::nextSong()
{
	this->ctrl.nextSongPlaylist();
}

void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		// repository management
		if (command == 1)
		{
			while (true)
			{
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->addSongToRepo();
					break;
				case 2:
					this->displayAllSongsRepo();
				}
			}
		}
		else if (command == 2)
		{
			while (true)
			{
				UI::printPlaylistMenu();
				int commandPlaylist{ 0 };
				cout << "Input the command: ";
				cin >> commandPlaylist;
				cin.ignore();
				if (commandPlaylist == 0)
					break;
				switch (commandPlaylist)
				{
				case 1:
					addSongsToPlaylist();
					break;
				case 2:
					startPlaySongs();
					break;
				case 3:
					nextSong();
					break;
				default:
					break;
				}
			}
		}

	}
}