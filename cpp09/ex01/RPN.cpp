#include "RPN.hpp"
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <exception>
#include <sstream>

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
	std::list<std::string>::iterator iter;
	int value;

	if (this->lst.size() % 2 == 1 || this->lst.size() < 3)
		return (false);
	
	iter = this->lst.begin();
	while (iter != this->lst.end()) {
		std::istringstream iss(*iter);
		iss >> value;

		if (iss.fail()
			&& iter->compare("*")
			&& iter->compare("/")
			&& iter->compare("-")
			&& iter->compare("+")
			&& iter->compare(""))
			return (false);
		++iter;
	}
	return (true); 
}

void	RPN::initialize_data(char *argv) {
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
}

int		RPN::calculate(void) {
	int	acum;
	int v1;

	acum = static_cast<int>(std::strtod(this->lst.front().c_str(), NULL));
	this->lst.pop_front();
	while (this->lst.front() != this->lst.back() && this->lst.front().compare(""))
	{
		std::istringstream iss(this->lst.front());
		iss >> v1;

		this->lst.pop_front();
		if (!this->lst.front().compare("+"))
			acum += v1;
		else if (!this->lst.front().compare("-"))
			acum -= v1;
		else if (!this->lst.front().compare("*"))
			acum *= v1;
		else if (!this->lst.front().compare("/"))
		{
			if (v1 == 0)
				throw std::runtime_error(std::string("Error: Division by zero;"));
			acum /= v1;
		}
	}
	return (acum);
}