#include "TutorialValidator.h"

vector<string> TutorialExceptions::getErrors() const
{
	return this->errors;
}

void TutorialValidator::validate(const Tutorial& t)
{
	vector <string> errors;

	if (t.getPresenter()[0] >= 'a' && t.getPresenter()[0] <= 'z')
		errors.push_back("The name of the presenter has to start with an uppercase letter...");
	if (t.getLink().rfind("http", 0) == false && t.getLink().rfind("www", 0) == false)
		errors.push_back("The link is not valid....");

	if (errors.size() > 0)
		throw TutorialExceptions(errors);
}
