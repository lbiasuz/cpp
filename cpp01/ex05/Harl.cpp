#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
	this->keys[0] = "debug";
	this->keys[1] = "info";
	this->keys[2] = "warning";
	this->keys[3] = "error";

	this->values[0] = &Harl::debug;
	this->values[1] = &Harl::info;
	this->values[2] = &Harl::warning;
	this->values[3] = &Harl::error;
}

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

	for (int i = 0; i < 4; i++)
	{

		if (this->keys[i] == str)
		{
			(this->*values[i])();
		}
	}
}