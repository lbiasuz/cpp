#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <string>

Span::Span(void) {
	this->n = 0;
}

Span::Span(unsigned int i) {
	this->n = i;
	this->vtr = std::vector<int>();
}

Span::Span(const Span & old) {
	this->n = old.n;
	this->vtr = old.vtr;
}

Span::~Span(void) {}

Span & Span::operator=(const Span & old) {
	this->n = old.n;
	this->vtr = old.vtr;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->vtr.size() < this->n)
		this->vtr.push_back(n);
	else
		throw std::runtime_error(std::string("Span full"));
}

void Span::addNumberArr(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->vtr.size() + std::distance(begin, end) <= this->n)
		this->vtr.insert(this->vtr.end(), begin, end);
	else
		throw std::runtime_error(std::string("Span full"));
}

int		Span::shortestSpan(void)
{
	int min;

	if (this->vtr.size() < 2)
		throw std::runtime_error(std::string("Span too short: can't calculate with only one number"));

	std::sort(this->vtr.begin(), this->vtr.end());

	min = this->vtr[1] - this->vtr[0];
	for (size_t i = 2; i < this->vtr.size(); i++)
		if (this->vtr[i] - this->vtr[i - 1] < min)
			min = this->vtr[i] - this->vtr[i - 1];

	return (min);
}

int		Span::longestSpan(void)
{
	if (this->vtr.size() < 2)
		throw std::runtime_error(std::string("Span too short: can't calculate with only one number"));
	std::sort(this->vtr.begin(), this->vtr.end());
	return (this->vtr[this->vtr.size() - 1] - this->vtr[0]);
}