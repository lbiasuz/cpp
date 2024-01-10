#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

# define MIN_INT -2147483648

ScalarConverter::ScalarConverter(void)
	: _input(""), _converted(false) {};
ScalarConverter::ScalarConverter(ScalarConverter const &old) 
	:	_input(old._input), _char(old._char), _int(old._int),
		_float(old._float), _double(old._double), _converted(false)
		{};
ScalarConverter& ScalarConverter::operator=(ScalarConverter const &old) {
	this->_input = old._input;
	this->_char = old._char;
	this->_int = old._int;
	this->_float = old._float;
	this->_double = old._double;
	this->_converted = old._converted;
	return (*this);
};
ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string str)
{
	this->_input = str;
	this->_double = std::strtod(this->_input.c_str(), NULL);
	this->_float = static_cast<float>(this->_double);
	this->_int = static_cast<int>(this->_double);
	this->_char = static_cast<char>(this->_double);
	this->_converted = true;
	this->print();
}

void	ScalarConverter::print(void) const
{
	if (this->_converted)
	{
		if (this->_char >= 32 && this->_char <= 126)
			std::cout << "char: '" << this->_char << "'" << std::endl;
		else if (this->_int < 0 || this->_int > 127)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		if (this->_int == MIN_INT && this->_double != MIN_INT)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << this->_int << std::endl;

		if (static_cast<float>(this->_int) == this->_float)
			std::cout << "float: " << this->_float << ".0f" << std::endl;
		else
			std::cout << "float: " << this->_float << "f" << std::endl;

		if (static_cast<float>(this->_int) == this->_float)
			std::cout << "double: " << this->_double << ".0" << std::endl;
		else
			std::cout << "double: " << this->_double << std::endl;
	}
}
