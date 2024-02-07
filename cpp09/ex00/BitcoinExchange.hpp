#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>

class BitcoinExchange {
	private:
		std::map<std::string, float> entries;
		BitcoinExchange(void);

	public:
		bool valid_date(std::string date);
		bool valid_input(std::string date, std::string value);
		float search(std::string date);
		BitcoinExchange(std::ifstream &in);
		BitcoinExchange(const BitcoinExchange &old);
		BitcoinExchange& operator=(const BitcoinExchange &old);
		~BitcoinExchange(void);
};

# endif