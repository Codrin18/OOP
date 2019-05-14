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

class DuplicateException : public RepositoryException
{
public:
	DuplicateException() {}
	DuplicateException(const string& msg) :RepositoryException(msg) {}
	char const* what();
};

class DeleteException : public RepositoryException
{
public:
	DeleteException() {}
	DeleteException(const string& msg) :RepositoryException(msg) {}
	char const* what();
};

class UpdateException : public RepositoryException
{
public:
	UpdateException() {}
	UpdateException(const string& msg) :RepositoryException(msg) {}
	char const* what();
};