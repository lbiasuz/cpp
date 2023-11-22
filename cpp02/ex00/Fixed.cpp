#include "Fixed.hpp"
#include <iostream>

const int	Fixed::fBits = 8;

Fixed::Fixed(void) {
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &old) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = old.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &old) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = old.getRawBits();
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