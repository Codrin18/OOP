#pragma once
#include <iostream>

using namespace std;

class Duration
{
private:
	double minutes;
	double seconds;
public:
	Duration() :minutes(0), seconds(0) {}
	Duration(double min, double sec) : minutes(min), seconds(sec) {}

	double getMinutes() { return this->minutes; }
	double getSeconds() { return seconds; }
	void setMinutes(double min) { this->minutes = min; }
	void setSeconds(double sec) { seconds = sec; }
};

class Song
{
private:
	string artist;
	string title;
	Duration duration;
	string link;
public:
	Song();
	Song(const string& artist, const string& title, const Duration& duration, const string& link);

	string getArtist() { return artist; }
	string getTitle() const { return title; }
	Duration getDuration() const { return duration; }
	string getLink() const { return link; }

	void play();
};