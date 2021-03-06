

#include "UI.h"
#include <string>
#include <iostream>

using namespace std;

void UI::printMenu()
{
    cout << endl;
    cout << "1 Manage tutorial repository." << endl;
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

void UI::addTutorialToRepo()
{

    cout << "Enter the title: ";

    string title;

    getline(cin,title);

    cout << "Enter the presenter: ";

    string presenter;

    getline(cin,presenter);

    cout << "Enter the minutes: ";

    double minutes = 0;

    cin >> minutes;

    cout << "Enter the seconds: ";

    double seconds = 0;

    cin >> seconds;

    cout << "Enter the number of likes: ";

    long long likes;

    cin >> likes;

    cin.ignore();

    cout << "Enter the link: ";

    string link;

    cin >> link;

    this -> ctrl.addTutorialToRepo(title,presenter,minutes,seconds,likes,link);

}

void UI::delTutorialRepo()
{
    cout << "Enter the title: ";

    string title;

    getline(cin,title);

    cout << "Enter the presenter: ";

    string presenter;

    getline(cin,presenter);

    cout << "Enter the minutes: ";

    double minutes = 0;

    cin >> minutes;

    cout << "Enter the seconds: ";

    double seconds = 0;

    cin >> seconds;

    cout << "Enter the number of likes: ";

    long long likes;

    cin >> likes;

    cin.ignore();

    cout << "Enter the link: ";

    string link;

    getline(cin,link);

    int res = this -> ctrl.delTutorialRepo(title,presenter,minutes,seconds,likes,link);

    if (res == 1)
    {
        cout << "The tutorial was deleted..." << endl;
    }
    else cout << "The tutorial you want to delete does not exists..." <<endl;
}

void UI::updateTutorialRepo()
{
    cout << "Enter the title: ";

    string title;

    getline(cin,title);

    cout << "Enter the presenter: ";

    string presenter;

    getline(cin,presenter);

    cout << "Enter the minutes: ";

    double minutes = 0;

    cin >> minutes;

    cout << "Enter the seconds: ";

    double seconds = 0;

    cin >> seconds;

    cout << "Enter the number of likes: ";

    long long likes;

    cin >> likes;

    cin.ignore();

    cout << "Enter the link: ";

    string link;

    getline(cin,link);

    int res = this -> ctrl.updateTutorialRepo(title,presenter,minutes,seconds,likes,link);

    if (res == 1)
    {
        cout << "The information about the tutorial were updated..." << endl;
    }
    else cout << "The tutorial does not exists..." << endl;
}

void UI::displayAllTutorialRepo()
{
    DynamicVector v = this -> ctrl.getRepo().getTutorials();

    Tutorial* tutorials = v.getAllElems();

    if (tutorials == NULL)
        return;

    if (v.getSize() == 0)
    {
        cout << "There are no tutorials to display...";
        return;
    }

    for (int i = 0; i < v.getSize(); ++i)
    {
        Tutorial t = tutorials[i];
        Duration d = t.getDuration();

        cout << t.getTitle() << "-" << t.getPresenter() << "-" << d.getMinutes() << "-" << d.getSeconds() << "-" << t.getLikes() << "-" << t.getLink() << endl;
    }

}

void UI::run()
{
    while (true)
    {
        UI::printMenu();

        int command{0};

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

                int commandRepo{0};

                cout << "Enter the command: ";

                cin >> commandRepo;
                cin.ignore();

                if (commandRepo == 0)
                    break;

                switch (commandRepo)
                {
                    case 1:
                    {
                        this -> addTutorialToRepo();
                        break;
                    }
                    case 2:
                    {
                        this -> displayAllTutorialRepo();
                        break;
                    }
                    case 3:
                    {
                        this -> delTutorialRepo();
                        break;
                    }
                    case 4:
                    {
                        this -> updateTutorialRepo();
                        break;
                    }
                }
            }
        }
    }
}
