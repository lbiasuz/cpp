#include <string>
#include <fstream>
#include <iostream>
#include "Replacer.hpp"

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	Replacer replacer(argv);
	if (!replacer.replace(argv[1]))
	{
		std::cout << "Error while opening file" << std::endl;
		return (1);
	}
}
