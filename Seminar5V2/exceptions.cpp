#include "exceptions.h"

char const* RepositoryException::what()
{
	return this->message.c_str();
}

char const* DuplicateSongException::what()
{
	return "Song already exists";
}

char const* FileException::what()
{
	return this->message.c_str();
}
