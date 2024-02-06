#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <cstdlib>

int	main(int argc, char **argv) {
	std::string spacer;
	std::string date;
	std::string value;

	std::ifstream data("data.csv");
	std::ifstream in(argv[1]);

	if (!in.is_open()) return(0);
	else if (!data.is_open()) return(0);
	else if (argc != 2) return(0);

	BitcoinExchange exc(data);
	for (std::string line; getline(in, line);)
	{
		std::stringstream ss(line);

		ss >> date >> spacer >> value;

		float fv = static_cast<float>(std::strtod(value.c_str(), NULL));

		if (!date.compare("date"))
			continue;
		if (!exc.valid_date(date))
			std::cout << "Error: bad input => " << date << std::endl;
		else if (fv < 0)
			std::cout << "Error: not a positive number"<< std::endl;
		else if (std::strtod(value.c_str(), NULL) > 2147483647.0)
			std::cout << "Error: too large a number"<< std::endl;
		else
			std::cout << date << " => " << value << " = " << exc.search(date) * fv << "\n";
	}
	return (0);
}