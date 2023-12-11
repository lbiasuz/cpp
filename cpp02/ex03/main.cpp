#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	a = a + Fixed( 2 );
	std::cout << a << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	Point p1(Fixed(1.0f), Fixed(2.0f));
	Point p2(Fixed(3.0f), Fixed(1.0f));
	Point p3(Fixed(2.0f), Fixed(3.0f));

	std::cout << bsp(p1, p2, p3, Point(Fixed(2.0f), Fixed(2.0f))) << std::endl;
	std::cout << bsp(p1, p2, p3, Point(Fixed(1.0f), Fixed(5.0f))) << std::endl;
	std::cout << bsp(p1, p2, p3, Point(Fixed(1.0f), Fixed(3.0f))) << std::endl;
	return 0;




}