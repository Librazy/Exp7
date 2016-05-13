#pragma once
class Point
{
	double x, y;
public:
	Point(double x, double y);
	double r()const; //���㼫����ļ��뾶
	double theta()const; //���㼫����ļ���
	double distance(const Point& p)const; //�������p�ľ���
	Point relative(const Point& p)const; //���������p���������
	bool is_above_left(const Point& p)const; //�ж��Ƿ��ڵ�p�����Ϸ�
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