#pragma once

#include "tutorial.h"
#include "DynamicVector.h"

class Repository
{
private:
	DynamicVector<Tutorial> tutorials;
public:
	//Default constructor for repository
	Repository() {}
	/*Adds a new element to the repository
	Input:tutorial - a valid variable of type Tutorial
	Output:---*/
	int add(const Tutorial& tutorial);
	/*
	This function deletes an element from the repository
	Input:tutorial - a valid variable of type tutorial
	Output:1 if the tutorial was deleted,0 otherwise
	*/
	int del(const Tutorial& tutorial);
	/*
	This function provides an update to the informations about a tutorial
	Input:tutorial - a valid variable of type Tutorial
	Output:1 - if the update was succesfull, 0 - otherwise
	*/
	int update(const Tutorial& tutorial);
	//Returns all the elements from repository
	DynamicVector<Tutorial> getTutorials() const
	{
		return this->tutorials;
	}
};
