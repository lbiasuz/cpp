#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::fBits = 8;

Fixed::Fixed(void) {
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &old) {
	std::cout << "Copy constructor called" << std::endl;
	this->value = old.value;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->value = value << Fixed::fBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << Fixed::fBits));
}

Fixed& Fixed::operator=(const Fixed &old) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = old.value;
	return (*this);
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->value / (float)(1 << Fixed::fBits));
}

int		Fixed::toInt(void) const {
	return (this->value >> Fixed::fBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}