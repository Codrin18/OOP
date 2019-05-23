#include "exceptions.h"

char const* RepositoryException::what()
{
	return this->message.c_str();
}

char const* DuplicateException::what()
{
	return "Tutorial already exists";
}

char const* DeleteException::what()
{
	return "The tutorial does not exist...";
}

char const* UpdateException::what()
{
	return "The tutorial can not be updated...";
}
