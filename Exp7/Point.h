#pragma once
class Point
{
	double x, y;
public:
	Point(double x, double y);
	double r()const; //计算极坐标的极半径
	double theta()const; //计算极坐标的极角
	double distance(const Point& p)const; //计算与点p的距离
	Point relative(const Point& p)const; //计算相对于p的相对坐标
	bool is_above_left(const Point& p)const; //判断是否在点p的左上方
};
class Rectangle:private Point
{
	double i, j;
	double theta;
public:
	Rectangle(double x, double y, double i, double j, double theta);

	double area() const;
};
class Circle :private Point
{
	double r;
public:
	Circle(double x, double y, double r);

	double area() const;
};