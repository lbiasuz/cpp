#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::fBits = 8;

Fixed::Fixed(void) {
	this->value = 0;
}

Fixed::~Fixed(void) {}

Fixed::Fixed(const Fixed &old) {
	this->value = old.value;
}

Fixed::Fixed(const int value) {
	this->value = value << Fixed::fBits;
}

Fixed::Fixed(const float value) {
	this->value = roundf(value * (1 << Fixed::fBits));
}

Fixed& Fixed::operator=(const Fixed &old) {
	this->value = old.value;
	return (*this);
}

int		Fixed::getRawBits(void) const {
	return (this->value);
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->value / (float)(1 << Fixed::fBits));
}

int		Fixed::toInt(void) const {
	return (this->value >> Fixed::fBits);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b) {
	return ((a < b) ? a : b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b) {
	return ((a < b) ? a : b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b) {
	return ((a > b) ? a : b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b) {
	return ((a > b) ? a : b);
}

bool	Fixed::operator>(const Fixed &old) const {
	return (this->value > old.value);
}

bool	Fixed::operator<(const Fixed &old) const {
	return (this->value < old.value);
}

bool	Fixed::operator>=(const Fixed &old) const {
	return (this->value >= old.value);
}

bool	Fixed::operator<=(const Fixed &old) const {
	return (this->value <= old.value);
}

bool	Fixed::operator==(const Fixed &old) const {
	return (this->value == old.value);
}

bool	Fixed::operator!=(const Fixed &old) const {
	return (this->value != old.value);
}

Fixed	Fixed::operator+(const Fixed &old) const {
	Fixed	newF;
	newF.setRawBits(this->value + old.value);
	return (newF);
}

Fixed	Fixed::operator-(const Fixed &old) const {
	Fixed	newF;
	newF.setRawBits(this->value - old.value);
	return (newF);
}

Fixed	Fixed::operator*(const Fixed &old) const {
	return (Fixed(this->toFloat() * old.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &old) const {
	return (Fixed(this->toFloat() / old.toFloat()));
}

Fixed&	Fixed::operator++(void) {
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	old(*this);
	this->value++;
	return (old);
}

Fixed&	Fixed::operator--(void) {
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	old(*this);
	this->value--;
	return (old);
}

std::ostream& operator<<(std::ostream& out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}