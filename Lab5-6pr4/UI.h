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

	void addTutorialToRepo();
	void delTutorialRepo();
	void updateTutorialRepo();
	void displayAllTutorialRepo();

	void addTutorialToPlaylist();
	void startPlayTutorials();
	void nextTutorial();
};