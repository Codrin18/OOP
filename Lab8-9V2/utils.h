#pragma once
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "tutorial.h"
class TextHandler
{
public:
	std::string const& operator[](std::size_t index) const;
	std::size_t size() const;
	void readNextRow(std::istream& str);
	virtual void writeToFile(std::vector<Tutorial> watchList);
private:
	std::vector<std::string>    m_data;
};

class CsvHandler : public TextHandler
{
public:
	void
		writeToFile(std::vector<Tutorial> tutorials);
};

class HtmlHandler : public TextHandler
{
public:
	void
		writeToFile(std::vector<Tutorial> tutorials);
};