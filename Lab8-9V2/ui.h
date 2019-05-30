#pragma once
#include "controller.h"
#include "utils.h"
class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	static void printMenu();
	static void printRepositoryMenu();
	static void printPlaylistMenu();
	static int validation_link(string my_url);
	static int valid_presenter(string presenter);
	void deleteWatchList();

	void addTutorialToRepo();
	void delTutorialRepo();
	void updateTutorialRepo();
	void updateLikesTutorialRepo(const Tutorial& tutorial);
	void displayAllTutorialRepo();
	void displayWatchlist();
	void seeWatchlist(int type);

	void addTutorialToPlaylist(int type);
	void startPlayTutorials();
	void nextTutorial();
};