#include <sstream>
#include <iostream>
#include <string>
#include "RPN.hpp"

int	main(int argc, char **argv) {

	RPN rpn;

	if (argc % 2 == 1)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return (1);
	}
	try {
		std::cout << rpn.calculate(&argv[1]) << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}