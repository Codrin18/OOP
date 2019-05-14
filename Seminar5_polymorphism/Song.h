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

	double getMinutes() const { return this->minutes; }
	double getSeconds() const { return seconds; }
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
	Song(const Song& toCopy);

	string getArtist() const { return artist; }
	string getTitle() const { return title; }
	Duration getDuration() { return duration; }
	string getLink() const { return link; }

	string toString();

	friend istream& operator>>(istream& is, Song& song);
	friend ostream& operator<<(ostream& os, const Song& song);

	bool operator==(const Song& song);

	void play();
};