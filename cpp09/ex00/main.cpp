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
		std::cout << date << " => " << value << " = ";
		std::cout << exc.search(date) * static_cast<float>(std::strtod(value.c_str(), NULL)) << "\n";
	}
	return (0);
}