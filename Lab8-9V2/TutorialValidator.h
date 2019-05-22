#pragma once

#include "tutorial.h"
#include <string>
#include <vector>


class TutorialExceptions
{
private:
	vector <string> errors;
public:
	TutorialExceptions(vector <string> _errors): errors(_errors) {}
	vector <string> getErrors() const;
};

class TutorialValidator
{
public:
	TutorialValidator() {}
	void validate(const Tutorial& t);
};
