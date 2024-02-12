#include <sstream>
#include <iostream>
#include <string>
#include "RPN.hpp"

int	main(int argc, char **argv) {

	RPN rpn;

	if (argc != 2) 
	{
		std::cout << "Error: Wrong number of arguments";
		return (1);
	}
	try {
		rpn.initialize_data(argv[1]);
		if (!rpn.is_valid_input())
			throw std::runtime_error("Error: Invalid input;");
		std::cout << rpn.calculate() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}