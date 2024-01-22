#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main(void) {

	std::srand(static_cast<unsigned int>(std::time(0)));

	Span sp = Span(5);
	sp.addNumber(6);
	try {
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	Span sp2 = Span(10000);
	std::vector<int> vtr;
	for (int i = 0; i < 10000; i++)
		vtr.push_back(std::rand() % 10000);
	
	sp2.addNumberArr(vtr.begin(), vtr.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	
	try {
		sp2.addNumber(84);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
