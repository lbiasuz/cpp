#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>


BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(std::ifstream &in) {
	std::string	date;
	std::string	value;

	for (std::string line; getline(in, line);)
	{
		std::size_t pos = line.find(",");
		if (pos > line.size())
			throw std::runtime_error(std::string("Invalid data input"));
		date = line.substr(0, pos);
		value = line.substr(pos + 1);
		if (!this->valid_date(date) && date.compare("date") != 0)
			throw std::runtime_error(std::string("Error: bad input => " + date));
		if (date.compare("date") != 0)
			entries[date] = static_cast<float>(strtod(value.c_str(), NULL));
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &old) : entries(old.entries) {}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &old) {
	this->entries = old.entries;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {}

float	BitcoinExchange::search(std::string date) {
	std::map<std::string, float>::iterator iter = this->entries.lower_bound(date);

	if (iter->first == date)
		return (iter->second);
	else if (iter == this->entries.end()
			&& iter == this->entries.begin())
		throw std::runtime_error("Error: date price entry not found");
	else
		--iter;
	return (iter->second);
}

bool BitcoinExchange::valid_date(std::string date) {
	struct tm tm;

	if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL)
		return (false);
	if (tm.tm_mday < 1 && tm.tm_year < 2009)
		return (false);
	return (true);
}

bool BitcoinExchange::valid_input(std::string date, std::string value) {
	if (!this->valid_date(date)) {
		std::cout << "Error: bad input => " << date << std::endl;
		return (false);
	} else if (std::strtod(value.c_str(), NULL) < 0) {
		std::cout << "Error: not a positive number"<< std::endl;
		return (false);
	} else if (std::strtod(value.c_str(), NULL) > 2147483647.0) {
		std::cout << "Error: too large a number"<< std::endl;
		return (false);
	}
	return (true);
}