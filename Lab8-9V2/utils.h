#pragma once
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "tutorial.h"
class CSVHandler
{
public:
	std::string const& operator[](std::size_t index) const;
	std::size_t size() const;
	void readNextRow(std::istream& str);
	void writeToFile(std::vector<Tutorial> watchList);
	void writeToHTML(std::vector<Tutorial> watchList);
private:
	std::vector<std::string>    m_data;
};
