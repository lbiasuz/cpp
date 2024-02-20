#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

# define MIN_INT -2147483648

ScalarConverter::ScalarConverter(void) {};
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &old) {
	(void) old;
};
ScalarConverter & ScalarConverter::operator=(ScalarConverter const &old) {
	(void) old;
	return (*this);
};

void	ScalarConverter::convert(std::string str)
{
	std::string	_input;
	char		_char;
	int			_int;
	float		_float;
	double		_double;
	
	_input = str;
	_double = std::strtod(_input.c_str(), NULL);
	if (_input.size() == 1 && _double == 0.0 &&
		_input[0] >= 32 && _input[0] <= 126)
		_double = _input[0];
	_float = static_cast<float>(_double);
	_int = static_cast<int>(_double);
	_char = static_cast<char>(_double);
	if (((_input[0] < 48 || _input[0] > 57) && _input.size() > 2))
		std::cout << "Invalid input \n";
	else
		print(_double, _float, _int, _char);
}

void	ScalarConverter::print(
		double _double,
		float _float,
		int _int,
		char _char)
{
	if (_char >= 32 && _char <= 126)
		std::cout << "char: '" << _char << "'" << std::endl;
	else if (_int < 0 || _int > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (_int == MIN_INT && _double != MIN_INT)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << _int << std::endl;

	if (static_cast<float>(_int) == _float)
		std::cout << "float: " << _float << ".0f" << std::endl;
	else
		std::cout << "float: " << _float << "f" << std::endl;

	if (static_cast<float>(_int) == _float)
		std::cout << "double: " << _double << ".0" << std::endl;
	else
		std::cout << "double: " << _double << std::endl;
}
