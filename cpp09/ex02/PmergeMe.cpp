#include "PmergeMe.hpp"
#include <sstream>
#include <exception>
#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
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

void PMergeMe::insertionSort(std::vector<int> v) {
	std::vector<int>::iterator head;
	std::vector<int>::iterator cmp;
	int	placeholder = 0;

	head = v.begin() + 1;
	while (head != v.end())
	{
		cmp == head - 1;
		placeholder = *head;
		while (cmp >= v.begin() && *cmp > placeholder) {
			*(cmp + 1) = *cmp;
			--cmp;
		}
		*(cmp + 1) = placeholder;
		++head;
	}
}

void PMergeMe::insertionSort(std::deque<int> v) {
	std::deque<int>::iterator head;
	std::deque<int>::iterator cmp;
	int	placeholder;

	head = v.begin()++;
	while (head != v.end())
	{
		cmp == head - 1;
		placeholder = *head;
		while (cmp >= v.begin() && *cmp > placeholder) {
			*(cmp + 1) = *cmp;
			--cmp;
		}
		*(cmp + 1) = placeholder;
		++head;
	}
}

void PMergeMe::sortVector(void) {
	std::vector<int> a(this->vec.begin(), this->vec.begin() + this->vec.size() / 2);
	std::vector<int> b(this->vec.begin() + this->vec.size() / 2, this->vec.end());

	this->insertionSort(a);
	this->insertionSort(b);

	std::merge(a.begin(), a.end(), b.begin(), b.end(), this->vec.begin());
}

void PMergeMe::sortDeque(void) {
	std::deque<int> a(this->vec.begin(), this->vec.begin() + this->vec.size() / 2);
	std::deque<int> b(this->vec.begin() + this->vec.size() / 2, this->vec.end());

	this->insertionSort(a);
	this->insertionSort(b);

	std::merge(a.begin(), a.end(), b.begin(), b.end(), this->vec.begin());
}

void PMergeMe::display(void) {
	int i = 0;

	std::cout << "Before: ";
	while (this->argv[++i] != NULL)
		std::cout << this->argv[i] << " ";
	std::cout << ";" << std::endl;

	clock_t start = clock();
	this->sortVector();
	clock_t finish = clock();

	std::vector<int>::iterator iter = this->vec.begin();
	std::cout << "After: ";
	while (iter != this->vec.end())
	{
		std::cout << *iter << " ";
		iter++;
	}
	std::cout << ";" << std::endl;

	std::cout << "Time to process a range of " << this->vec.size()
			 << "with std::vector<int>: "<< (finish - start) << std::endl;

	start = clock();
	this->sortDeque();
	finish = clock();

	std::cout << "Time to process a range of " << this->deq.size()
			 << "with std::vector<int>: "<< (finish - start) << std::endl;


}