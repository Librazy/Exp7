#define _USE_MATH_DEFINES
#include <cmath>
class Point
{
	double x, y;
public:
	Point(double x, double y): x(x),y(y){}
	double r()const; //计算极坐标的极半径
	double theta()const; //计算极坐标的极角
	double distance(const Point& p)const; //计算与点p的距离
	Point relative(const Point& p)const; //计算相对于p的相对坐标
	bool is_above_left(const Point& p)const; //判断是否在点p的左上方
};
double Point::r() const
{
	return x*x + y*y;
}

double Point::theta()const
{
	return (atan(x/y)/M_PI)*180.0;
}

double Point::distance(const Point& p)const
{
	return sqrt((x-p.x)*(x - p.x) + (y - p.y)*(y - p.y));
}

Point Point::relative(const Point& p)const
{
	return Point(x + p. x, y + p.y);
}

bool Point::is_above_left(const Point& p)const
{
	return x > p.x&&y > p.y;
}
