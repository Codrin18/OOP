#include "utils.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include "tutorial.h"

std::string const& CSVHandler::operator[](std::size_t index) const
{
	return m_data[index];
}

std::size_t CSVHandler::size() const
{
	return m_data.size();
}

void CSVHandler::readNextRow(std::istream& str)
{
	std::string         line;
	std::getline(str, line);

	std::stringstream   lineStream(line);
	std::string         cell;

	m_data.clear();
	while (std::getline(lineStream, cell, ','))
	{
		m_data.push_back(cell);
	}
	// This checks for a trailing comma with no data after it.
	if (!lineStream && cell.empty())
	{
		// If there was a trailing comma then add an empty element.
		m_data.push_back("");
	}
}
void CSVHandler::writeToFile(std::vector<Tutorial> watchList)
{
	std::ofstream myfile;

	myfile.open("tutorial.csv", std::ios_base::out);

	for (auto t : watchList) {
		myfile << t.getTitle() << "," << t.getPresenter() << "," << t.getMinutes() << "," << t.getSeconds() << "," <<  t.getLikes() << "," << t.getLink();
	}

	myfile.close();
}

void CSVHandler::writeToHTML(std::vector<Tutorial> watchList)
{
	string htmlStart = "<!DOCTYPE html><html><head><style>table {font-family: arial, sans-serif;border-collapse: collapse;width: 100%;}td, th {border: 1px solid #dddddd;text-align: left;padding: 8px;}tr:nth-child(even) {background-color: #dddddd;}</style></head><body><h2>Pets available</h2><table><tr><th>Bree</th><th>Name</th><th>Age</th><th>Photo</th></tr>";
	string htmlEnd = "</table></body></html>";
	ofstream myfile;

	myfile.open("plop.html", std::ios_base::out);

	myfile << htmlStart;

	for (auto t : watchList) {
		myfile << "<tr>";
		myfile << "<td>" << t.getTitle() << "</td>";
		myfile << "<td>" << t.getPresenter() << "</td>";
		myfile << "<td>" << t.getMinutes() << "</td>";
		myfile << "<td>" << t.getSeconds() << "</td>";
		myfile << "<td>" << t.getLikes() << "</td>";
		myfile << "<td>" << t.getLink() << "</td>";
		myfile << "</tr>";
	}

	myfile << htmlEnd;

	myfile.close();
}
