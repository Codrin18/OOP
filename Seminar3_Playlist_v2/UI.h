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

	void addSongToRepo();
	void displayAllSongsRepo();

	void addSongsToPlaylist();
	void startPlaySongs();
	void nextSong();
};

