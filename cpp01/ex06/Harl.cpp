#include "Harl.hpp"
#include <iostream>

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
}

void Harl::complain(std::string str)
{
	int	i = -1;
	if (str == "DEBUG") i = 0;
	if (str == "INFO") i = 1;
	if (str == "WARNING") i = 2;
	if (str == "ERROR") i = 3;
	switch (i)
	{
		case 0:
			this->debug();
			this->info();
			this->warning();
			this->error();
			break;
		case 1:
			this->info();
			this->warning();
			this->error();
			break;
		case 2:
			this->warning();
			this->error();
			break;
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ] " << std::endl;
			break;
	}
}