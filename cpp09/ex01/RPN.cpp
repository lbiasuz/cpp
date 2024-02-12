#include "RPN.hpp"
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <exception>

RPN::RPN(void) {}
RPN::~RPN(void) {}
RPN::RPN(const RPN & rpn) {
	this->lst = rpn.lst;
}
RPN & RPN::operator=(const RPN & rpn) {
	this->lst = rpn.lst;
	return (*this);
}

bool	RPN::is_valid_input(void) {
	if (this->lst.size() % 2 == 1 || this->lst.size() < 3)
		return (false);
	return (true); 
}

int		RPN::calculate(char *argv) {
	size_t		pos = 0;
	std::string	separator = " ";
	std::string	input(argv);
	std::string	value;

	pos = input.find(separator);
	while (pos != std::string::npos)
	{
		value = input.substr(0, pos);
		this->lst.push_back(value);
		input.erase(0, pos + separator.length());
		pos = input.find(separator);
	}
	this->lst.push_back(input);
	this->lst.push_back("");

	if (!this->is_valid_input())
		throw std::runtime_error("Error: Wrong number of arguments;");

	int	acum = static_cast<int>(std::strtod(this->lst.front().c_str(), NULL));
	this->lst.pop_front();
	while (this->lst.front() != this->lst.back())
	{
		int v1 = static_cast<int>(std::strtod(this->lst.front().c_str(), NULL));
		this->lst.pop_front();
		if (!this->lst.front().compare("+"))
			acum += v1;
		else if (!this->lst.front().compare("-"))
			acum -= v1;
		else if (!this->lst.front().compare("/"))
		{
			if (v1 == 0)
				throw std::runtime_error(std::string("Error: Division by zero;"));
			acum /= v1;
		}
		else if (!this->lst.front().compare("*"))
			acum *= v1;
		else
			throw std::runtime_error("Error: Invalid token");
	}
	return (acum);
}