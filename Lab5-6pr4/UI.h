#pragma once

#include "Controller.h"

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
	void deleteWatchList();

	void addTutorialToRepo();
	void delTutorialRepo();
	void updateTutorialRepo();
	void updateLikesTutorialRepo(const Tutorial& tutorial);
	void displayAllTutorialRepo();
	void displayWatchlist();

	void addTutorialToPlaylist();
	void startPlayTutorials();
	void nextTutorial();
};