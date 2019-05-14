#pragma once
#include "Song.h"
#include <vector>
#include <string>

using namespace std;

class SongException
{
private:
	vector<string> errors;

public:
	SongException(vector<string> _errors) : errors(_errors) {}
	vector<string> getErrors() const;
};

class SongValidator
{
public:
	SongValidator() {}
	void validate(const Song& s);
};