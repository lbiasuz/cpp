#include "PmergeMe.hpp"
#include <sstream>
#include <exception>
#include <iostream>

PMergeMe::PMergeMe(void) {}

PMergeMe::PMergeMe(char **argv) {
	int i = 1;
	int value;

	this->argv = argv;
	while (argv[i] != NULL)
	{
		std::istringstream iss(argv[i]);
		iss >> value;

		if (iss.fail())
			throw std::runtime_error("Error: Invalid input");

		this->vec.push_back(value);
		this->deq.push_back(value);

		i++;
	}
}

PMergeMe::~PMergeMe(void) {}

PMergeMe::PMergeMe(const PMergeMe & pme) {
	this->vec = pme.vec;
	this->deq = pme.deq;
}

PMergeMe & PMergeMe::operator=(const PMergeMe & pme) {
	this->vec = pme.vec;
	this->deq = pme.deq;
	return (*this);
}

PMergeMe::sort(void) {

}

PMergeMe::display(void) {
	int i = 0;

	std::cout << "Before: ";
	while (this->argv[++i] != NULL)
		std::cout << this->argv[i] << " ";
	std::cout << ";" << std::endl;

	std::vector<int>::iterator iter = this->vec.begin()
	std::cout << "After: ";
	while (iter != this->vec.end())
	{
		std::cout << *iter << " ";
		iter++;
	}
	std::cout << ";" << std::endl;

	// TODO: TEMPO DE EXECUçÃO
}