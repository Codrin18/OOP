#pragma once
#include <iostream>
#include <string>

using namespace std;

class Duration
{
private:
	double minutes;
	double seconds;
public:
	Duration() :minutes(0), seconds(0) {}
	Duration(double min, double sec) :minutes(min), seconds(sec) {}
	double getMinutes() const
	{
		return minutes;
	}
	double getSeconds() const
	{
		return seconds;
	}
	void setMinutes(double min)
	{
		minutes = min;
	}
	void setSeconds(double sec)
	{
		seconds = sec;
	}
};

class Tutorial
{
private:
	string title;
	string presenter;
	int minutes;
	int seconds;
	long long likes;
	string link;

public:
	Tutorial();
	Tutorial(const string& title, const string& presenter, const int& minutes,const int& seconds, const int& likes, const string& link);
	string getTitle() const
	{
		return title;
	}
	string getPresenter() const
	{
		return presenter;
	}
	int getMinutes() const
	{
		return minutes;;
	}
	int getSeconds() const
	{
		return seconds;
	}
	long long getLikes() const
	{
		return likes;
	}
	string getLink() const
	{
		return link;
	}
	void setTitle(const string& _title)
	{
		title = _title;
	}
	void setPresenter(const string& _presenter)
	{
		presenter = _presenter;
	}
	void setMinutes(const int& minutes)
	{
		this->minutes = minutes;
	}
	void setSeconds(const int& seconds)
	{
		this->seconds = seconds;
	}
	void setLikes(const long long& _likes)
	{
		likes = _likes;
	}

	void setLink(const string& _link)
	{
		link = _link;
	}

	void play();
};