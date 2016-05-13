#define _USE_MATH_DEFINES
#include <cmath>
#include "Point.h"

Point::Point(double x, double y): x(x), y(y)
{}

double Point::r() const
{
	return x*x + y*y;
}

double Point::theta()const
{
	return (atan(x / y) / M_PI)*180.0;
}

double Point::distance(const Point& p)const
{
	return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
}

Point Point::relative(const Point& p)const
{
	return Point(x + p.x, y + p.y);
}

bool Point::is_above_left(const Point& p)const
{
	return x > p.x&&y > p.y;
}

Rectangle::Rectangle(double x, double y, double i, double j, double theta): Point(x,y),i(i),j(j),theta(theta)
{}

double Rectangle::area() const
{
	return i * j;
}

Circle::Circle(double x, double y, double r): Point(x, y), r(r)
{}

double Circle::area() const
{
	return M_PI * r * r;
}
