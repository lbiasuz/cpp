#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main(void) {
	std::vector<int>	v;

	v.insert(v.begin(), 4);
	v.insert(v.begin(), 43);
	v.insert(v.begin(), 55);

	try {
		std::cout << *easyfind(v, 43) << std::endl;
		std::cout << *easyfind(v, 34) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}