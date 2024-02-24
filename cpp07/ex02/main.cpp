#include "Array.hpp"
#include <iostream>

int	main(void) {

	// Contructor tests
	Array<int> arr;
	Array<int> arr2(5);

	// Index out of range test
	try {
		std::cout << arr[0] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// Assign and access test
	arr2[3] = 33333;
	std::cout << arr2[3] << std::endl;
	std::cout << arr2.getSize() << std::endl;

	// Copy and copy assign test
	arr2 = arr;
	Array<int> arr3(2);
	arr = arr3;
	arr3 = arr2;

	const Array<int> arr4(3);
	std::cout << arr4[2] << std::endl;
}