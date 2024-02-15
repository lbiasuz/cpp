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

void PMergeMe::insertionSort(std::vector<int> &v) {
	std::vector<int>::iterator head;
	std::vector<int>::iterator cmp;

	head = v.begin() + 1;
	while (head != v.end())
	{
		int	placeholder = *head;
		cmp = head - 1;
		while (cmp > v.begin() && *cmp > placeholder) {
			*(cmp + 1) = *cmp;
			--cmp;
		}
		*(cmp + 1) = placeholder;
		++head;
	}
}

void PMergeMe::insertionSort(std::deque<int> &v) {
	std::deque<int>::iterator head;
	std::deque<int>::iterator cmp;

	head = v.begin();
	while (head != v.end())
	{
		int	placeholder = *head;
		cmp = head;
		while (cmp >= v.begin() && *cmp > placeholder) {
			*cmp = *(cmp - 1);
			cmp--;
		}
		*cmp = placeholder;
		++head;
	}
}

void PMergeMe::merge(std::vector<int> &a, std::vector<int> &b, std::vector<int> &v) {
	std::vector<int>::iterator ita = a.begin();
	std::vector<int>::iterator itb = b.begin();

	while (ita != a.end() && itb != b.end()) {
		if (*ita < *itb) {
			v.push_back(*ita);
			ita++;
		} else {
			v.push_back(*itb);
			itb++;
		}
	}
	while (ita != a.end()) {
		v.push_back(*ita);
		ita++;
	}
	while (itb != b.end()) {
		v.push_back(*itb);
		itb++;
	}
}

void PMergeMe::merge(std::deque<int> &a, std::deque<int> &b, std::deque<int> &v) {
	std::deque<int>::iterator ita = a.begin();
	std::deque<int>::iterator itb = b.begin();

	while (ita != a.end() && itb != b.end()) {
		if (*ita < *itb) {
			v.push_back(*ita);
			ita++;
		} else {
			v.push_back(*itb);
			itb++;
		}
	}
	while (ita != a.end()) {
		v.push_back(*ita);
		ita++;
	}
	while (itb != b.end()) {
		v.push_back(*itb);
		itb++;
	}
}

void PMergeMe::sortVector(std::vector<int> & v) {
	if (v.size() <= 1)
		insertionSort(v);

	else {
		std::vector<int> a(v.begin(), v.begin() + (v.size() / 2));
		std::vector<int> b(v.begin() + (v.size() / 2), v.end());

		this->sortVector(a);
		this->sortVector(b);

		v.clear();

		merge(a, b, v);
	}
}

void PMergeMe::sortDeque(std::deque<int> & v) {
	if (v.size() <= 1)
		insertionSort(v);

	else {
		std::deque<int> a(v.begin(), v.begin() + (v.size() / 2));
		std::deque<int> b(v.begin() + (v.size() / 2), v.end());

		this->sortDeque(a);
		this->sortDeque(b);

		v.clear();

		merge(a, b, v);
	}
}

void PMergeMe::display(void) {
	int i = 0;

	std::cout << "Before:";
	while (this->argv[++i] != NULL)
		std::cout << " " << this->argv[i];
	std::cout << ";" << std::endl;

	clock_t start = clock();
	this->sortVector(this->vec);
	clock_t finish = clock();

	std::vector<int>::iterator iter = this->vec.begin();
	std::cout << "After:";
	while (iter != this->vec.end())
	{
		std::cout << " " << *iter ;
		iter++;
	}
	std::cout << ";" << std::endl;

	std::cout << "Time to process a range of " << this->vec.size()
			 << " with std::vector<int> : "<< (finish - start) << std::endl;

	start = clock();
	this->sortDeque(this->deq);
	finish = clock();

	std::cout << "Time to process a range of " << this->deq.size()
			 << "with std::deque<int>: "<< (finish - start) << std::endl;
}