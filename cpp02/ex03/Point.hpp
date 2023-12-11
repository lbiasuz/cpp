#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point {
	private:
		Fixed	x;
		Fixed	y;

	public:
		Point(void);
		Point(const Point & p);
		Point& operator=(const Point & p);
		Point(const Fixed & fx, const Fixed & fy);
		~Point(void);

		Fixed getX(void);
		Fixed getY(void);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
Fixed side (Point a, Point b, Point c);

#endif