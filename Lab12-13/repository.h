#pragma once

#include "tutorial.h"
#include <vector>
#include <fstream>

using namespace std;

class Repository
{
protected:
	vector<Tutorial> tutorials;
public:
	//Default constructor for repository
	Repository() { this->readFromFile(); }
	/*Adds a new element to the repository
	Input:tutorial - a valid variable of type Tutorial
	Output:---*/
	bool add(const string& title, const string& presenter, const int& minutes,const int& seconds, const int& likes, const string& slink);
	/*
	This function deletes an element from the repository
	Input:tutorial - a valid variable of type tutorial
	Output:1 if the tutorial was deleted,0 otherwise
	*/
	void del(const string& link);
	/*
	This function provides an update to the informations about a tutorial
	Input:tutorial - a valid variable of type Tutorial
	Output:1 - if the update was succesfull, 0 - otherwise
	*/
	bool update(const Tutorial& tutorial);
	//This function increases the number of likes 
	bool updateLikes(const Tutorial& tutorial);
	//Returns all the elements from repository
	vector<Tutorial> getTutorials() const
	{
		return this->tutorials;
	}

	void readFromFile();

	void writeToFile();
};