#include <string>
#include <iostream>

int	main( void )
{
	std::string str;

	str = "HI THIS IS BRAIN";
	std::string* strPTR = &str;
	std::string& strREF = str;
	std::cout << "str: " << &str << std::endl;
	std::cout << "strPTR: " << strPTR << std::endl;
	std::cout << "strREF: " << &strREF << std::endl;
	std::cout << std::endl;
	std::cout << str << std::endl;
	std::cout << *strPTR << std::endl;
	std::cout << strREF << std::endl;
	return (0);
}