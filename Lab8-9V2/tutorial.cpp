
#include <Windows.h>
#include <iostream>
#include <string>
#include "tutorial.h"
#include <shellapi.h>

Tutorial::Tutorial() :title(""), presenter(""), minutes(0),seconds(0), likes(0), link("") {}

Tutorial::Tutorial(const string& title, const string& presenter,const int& minutes,const int& seconds, const int& likes, const string& link)
{
	this->title = title;
	this->presenter = presenter;
	this->minutes = minutes;
	this->seconds = seconds;
	this->likes = likes;
	this->link = link;
}

void Tutorial::play()
{
	ShellExecute(NULL, NULL, "firefox.exe", this->getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
}