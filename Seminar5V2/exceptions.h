#pragma once
#include <exception>
#include <string>

using namespace std;

class RepositoryException : public exception
{
protected:
	string message;
public:
	RepositoryException() {}
	RepositoryException(const string& msg) :message(msg) {}
	virtual char const* what();

};

class DuplicateSongException : public RepositoryException
{
public:
	DuplicateSongException() {}
	DuplicateSongException(const string& msg) :RepositoryException(message) {}
	virtual char const* what();
};

class FileException : public exception
{
private:
	string message;
public:
	FileException(const string& msg) : message(msg) {}
	char const* what();
};