#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

int	main(int argc, char ** argv) {
	if (argc < 3)
		return (1);
	try {
		PMergeMe pme = PMergeMe(argv);
		pme.display();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

}