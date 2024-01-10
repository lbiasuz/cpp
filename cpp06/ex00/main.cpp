#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	std::string str;

	str = argv[1];
	if (argc != 2) {
		std::cout << "Usage: ./convert [value]" << std::endl;
		return 1;
	}
	ScalarConverter converter;
	converter.convert(str);
	return (0);
}