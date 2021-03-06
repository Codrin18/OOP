#include "ui.h"
#include "exceptions.h"
#include <Windows.h>
#include <shellapi.h>
using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 Manage tutorial repository." << endl;
	cout << "2 Playlist tutorial" << endl;
	cout << "0 Exit." << endl;
}

void UI::printRepositoryMenu()
{
	cout << endl;
	cout << "1 Add tutorial" << endl;
	cout << "2 List all tutorials" << endl;
	cout << "3 Delete a tutorial" << endl;
	cout << "4 Update a tutorial" << endl;
	cout << "0 Return " << endl;
}

void UI::printPlaylistMenu()
{
	cout << endl;
	cout << "1 Add tutorial to playlist and create my watchlist" << endl;
	cout << "2 Delete a tutorial from my watchlist " << endl;
	cout << "3 See watchlist" << endl;
	cout << "4 Open file" << endl;
	cout << "0 Return" << endl;
}

int UI::validation_link(string my_url)
{
	if (my_url.rfind("http", 0) or my_url.rfind("www", 0))
		return 1;
	return 0;
}

int UI::valid_presenter(string presenter)
{
	if (presenter[0] >= 'A' && presenter[0] <= 'Z')
		return 1;
	return 0;
}

void UI::deleteWatchList()
{
	vector<Tutorial> tutorials = this->ctrl.getWatchlist();
	for (int i = tutorials.size() - 1; i >= 0; i--)
	{
		Tutorial t = tutorials[i];

		cout << t.getTitle() << "-" << t.getPresenter() << "-" << t.getMinutes() << "-" << t.getSeconds() << "-" << t.getLikes() << "-" << t.getLink() << endl;
		cout << "Did you see this tutorial? Please answer with y for yes and n for no..." << endl;
		string answer;
		cin >> answer;
		if (answer == "y")
		{
			this->ctrl.deleteWatchlist(i);
			cout << "Do you want to give it a like ? Please answer with y for yes and n for no..." << endl;
			string answer;
			cin >> answer;
			if (answer == "y") this->ctrl.updateLikesTutorialRepo(tutorials[i]);
		}
	}
}

void UI::addTutorialToRepo()
{

	cout << "Enter the title: ";

	string title;

	getline(cin, title);

	cout << "Enter the presenter: ";

	string presenter;

	getline(cin, presenter);

	

	cout << "Enter the minutes: ";

	int minutes = 0;

	cin >> minutes;

	cout << "Enter the seconds: ";

	int seconds = 0;

	cin >> seconds;

	cout << "Enter the number of likes: ";

	int likes = 0;

	cin >> likes;

	cin.ignore();

	cout << "Enter the link: ";

	string link;

	cin >> link;

	try
	{
		this->ctrl.addTutorialToRepo(title, presenter, minutes, seconds, likes, link);
	}
	catch (TutorialExceptions ex)
	{
		for (auto e : ex.getErrors())
		{
			cout << e << endl;
		}
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
	
	
}

void UI::delTutorialRepo()
{
	
	cout << "Enter the link: ";

	string link;

	getline(cin, link);
	try
	{
		this->ctrl.delTutorialRepo(link);
	}
	catch (RepositoryException &e)
	{
		cout << e.what();
	}
	
}

void UI::updateTutorialRepo()
{
	cout << "Enter the title: ";

	string title;

	getline(cin, title);

	cout << "Enter the presenter: ";

	string presenter;

	getline(cin, presenter);

	cout << "Enter the minutes: ";

	int minutes = 0;

	cin >> minutes;

	cout << "Enter the seconds: ";

	int seconds = 0;

	cin >> seconds;

	cout << "Enter the number of likes: ";

	int likes = 0;

	cin >> likes;

	cin.ignore();

	cout << "Enter the link: ";

	string link;

	getline(cin, link);

	try
	{
		this->ctrl.updateTutorialRepo(title, presenter, minutes, seconds, likes, link);
	}
	catch (TutorialExceptions ex)
	{
		for (auto e : ex.getErrors())
		{
			cout << e << endl;
		}
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::updateLikesTutorialRepo(const Tutorial& tutorial)
{
	this->ctrl.updateLikesTutorialRepo(tutorial);
}

void UI::displayAllTutorialRepo()
{
	vector<Tutorial> v = this->ctrl.getRepo().getTutorials();

	if (v.size() == 0)
	{
		cout << "There are no tutorials to display...";
		return;
	}

	for (int i = 0; i < v.size(); ++i)
	{
		Tutorial t = v[i];

		cout << t.getTitle() << "-" << t.getPresenter() << "-" << t.getMinutes() << "-" << t.getSeconds() << "-" << t.getLikes() << "-" << t.getLink() << endl;
	}

}

void UI::displayWatchlist()
{
	vector<Tutorial> tutorials = this->ctrl.getWatchlist();

	for (int i = 0; i < tutorials.size(); ++i)
	{
		Tutorial t = tutorials[i];

		cout << t.getTitle() << "-" << t.getPresenter() << "-" << t.getMinutes() << "-" << t.getSeconds() << "-" << t.getLikes() << "-" << t.getLink() << endl;
	}
}

void UI::seeWatchlist(int type)
{
	if (type)
	{
		ShellExecute(NULL, "open", "watchlist.html",
			NULL, NULL, SW_SHOWNORMAL);
	}
	else
	{
		system("notepad watchlist.csv");
	}
}

void UI::addTutorialToPlaylist(int fileType)
{
	cout << "Enter the presenter: ";
	string presenter;
	getline(cin, presenter);

	this->ctrl.addTutorialByPresenterToPlaylist(presenter);

	Playlist p = this->ctrl.getPlaylist();
	startPlayTutorials();

	while (true)
	{
		Tutorial  t = p.getCurrentTutorial();
		cout << t.getTitle() << "-" << t.getPresenter() << "-" << t.getMinutes() << "-" << t.getSeconds() << "-" << t.getLikes() << "-" << t.getLink() << endl;
		//startPlayTutorials();
		cout << "Would you like to add this tutorial to your watch list ?Please answer with y for yes and n for no..." << endl;
		string answer;
		cin >> answer;
		if (answer == "y")
		{
			this->ctrl.addToWatchlist(t);
		}
		cout << "Do you want to continue to add tutorials to your watchlist?Please answer with y for yes and n for no..." << endl;
		cin >> answer;

		if (answer == "n") break;
		nextTutorial();
		p.next();
	}

	if (fileType == 0)
	{
		TextHandler* row = new CsvHandler{};
		row->writeToFile(this->ctrl.getWatchlist());
	}
	else
	{
		TextHandler* row = new HtmlHandler{};
		row->writeToFile(this->ctrl.getWatchlist());
	}

}

void UI::startPlayTutorials()
{
	if (this->ctrl.getPlaylist().isEmpty())
		cout << "Nothing to play." << endl;
	this->ctrl.startPlaylist();
}

void UI::nextTutorial()
{
	this->ctrl.nextTutorialPlaylist();
}

void UI::run()
{
	cout << "Where do you want your watchlist to be saved ? Please type 0 for csv file and 1 for html file: ";
	int fileType;
	cin >> fileType;
	while (true)
	{
		UI::printMenu();

		int command{ 0 };

		cout << "Enter the command: ";

		cin >> command;

		cin.ignore();

		if (command == 0)
			break;

		if (command == 1)
		{
			while (true)
			{
				UI::printRepositoryMenu();

				int commandRepo{ 0 };

				cout << "Enter the command: ";

				cin >> commandRepo;
				cin.ignore();

				if (commandRepo == 0)
					break;

				switch (commandRepo)
				{
				case 1:
				{
					this->addTutorialToRepo();
					break;
				}
				case 2:
				{
					this->displayAllTutorialRepo();
					break;
				}
				case 3:
				{
					this->delTutorialRepo();
					break;
				}
				case 4:
				{
					this->updateTutorialRepo();
					break;
				}
				}
			}
		}
		else if (command == 2)
		{
			while (true)
			{
				UI::printPlaylistMenu();
				int commandPlaylist = 0;
				cout << "Enter a command: ";
				cin >> commandPlaylist;
				cin.ignore();

				if (commandPlaylist == 0) break;

				switch (commandPlaylist)
				{
				case 1:
				{
					addTutorialToPlaylist(fileType);
					break;
				}
				case 2:
				{
					deleteWatchList();
					break;
				}
				case 3:
				{
					displayWatchlist();
					break;
				}
				case 4:
				{
					seeWatchlist(fileType);
					break;
				}
				default:
				{
					break;
				}
				}
			}
		}
	}
}