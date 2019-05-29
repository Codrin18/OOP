#include "TutorialValidator.h"

vector<string> TutorialExceptions::getErrors() const
{
	return this->errors;
}

string TutorialExceptions::getErrorsAsString() const
{

	string err;
	for (auto e : this->errors)
		err += e;
	return err;
}

void TutorialValidator::validate(const Tutorial& t)
{
	vector <string> errors;

	if (t.getPresenter()[0] >= 'a' && t.getPresenter()[0] <= 'z')
		errors.push_back("The name of the presenter has to start with an uppercase letter...");

	int posWww = t.getLink().find("www");
	int posHttp = t.getLink().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The youtube source must start with one of the following strings: \"www\" or \"http\"");

	if (errors.size() > 0)
		throw TutorialExceptions(errors);
}
