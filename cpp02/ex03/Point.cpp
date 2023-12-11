#include "Point.hpp"

Point::Point(void)
{
	this->x = Fixed();
	this->y = Fixed();
}

Point::Point(const Point & p)
{
	this->x = p.x;
	this->y = p.y;
}

Point& Point::operator=(const Point & p)
{
	this->x = p.x;
	this->y = p.y;
	return (*this);
}

Point::~Point(void) {}

Point::Point(const Fixed & fx, const Fixed & fy)
{
	this->x = fx;
	this->y = fy;
}

Fixed Point::getX(void)
{
	return (this->x);
}

Fixed Point::getY(void)
{
	return (this->y);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed as = side(point, a, b);
	Fixed bs = side(point, b, c);
	Fixed cs = side(point, c, a);

	bool has_neg = (as < 0) || (bs < 0) || (cs < 0);
	bool has_pos = (as > 0) || (bs > 0) || (cs > 0);

	return !(has_neg && has_pos);
}

Fixed side (Point a, Point b, Point c)
{
	return (a.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (a.getY() - c.getY());
}