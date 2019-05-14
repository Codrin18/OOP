#include "SongValidator.h"

vector<string> SongException::getErrors() const
{
	return this->errors;
}

void SongValidator::validate(const Song & s)
{
	vector<string> errors;
	if (s.getTitle().size() < 3)
		errors.push_back("Title must have at least 3 chars.\n");
	if (!isupper(s.getArtist()[0]))
		errors.push_back("The artist must start with a capital letter.\n");

	if (errors.size() > 0)
		throw SongException(errors);
}
