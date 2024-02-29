#include "RPN.hpp"
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <exception>
#include <sstream>

RPN::RPN(void) {}
RPN::~RPN(void) {}
RPN::RPN(const RPN & rpn) {
	this->stk = rpn.stk;
}
RPN & RPN::operator=(const RPN & rpn) {
	this->stk = rpn.stk;
	return (*this);
}

bool	RPN::is_valid_input(char *argv) {
	if (argv[0] >= 48 && argv[0] <= 57)
		return (true);
	else if (argv[0] == '+' || argv[0] == '-' || argv[0] == '/' || argv[0] == '*')
		return (true);
	return (false);
}

int		RPN::calculate(char **argv) {
	int v1;

	for (int i = 0; argv[i] != NULL; i++)
	{
		if (!this->is_valid_input(argv[i]))
			throw std::invalid_argument(std::string("Argumento inválido"));

		if (argv[i][0] == '+' && this->stk.size() > 1) {
			v1 = this->stk.top();
			this->stk.pop();
			this->stk.top() += v1;
		}
		else if (argv[i][0] == '-' && this->stk.size() > 1) {
			v1 = this->stk.top();
			this->stk.pop();
			this->stk.top() -= v1;
		}
		else if (argv[i][0] == '*' && this->stk.size() > 1) {
			v1 = this->stk.top();
			this->stk.pop();
			this->stk.top() *= v1;
		}
		else if (argv[i][0] == '/' && this->stk.size() > 1)
		{
			if (this->stk.top() == 0)
				throw std::runtime_error(std::string("Error: Division by zero;"));
			v1 = this->stk.top();
			this->stk.pop();
			this->stk.top() /= v1;
		} else {
			if (argv[i][0] < 48 || argv[i][0] > 57)
				throw std::invalid_argument(std::string("Argumento inválido"));
			this->stk.push(std::strtod(argv[i], NULL));
		}
	}
	return (this->stk.top());
}