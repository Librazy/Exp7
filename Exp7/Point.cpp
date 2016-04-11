#define _USE_MATH_DEFINES
#include <cmath>
class Point
{
	double x, y;
public:
	Point(double x, double y): x(x),y(y){}
	double r()const; //���㼫����ļ��뾶
	double theta()const; //���㼫����ļ���
	double distance(const Point& p)const; //�������p�ľ���
	Point relative(const Point& p)const; //���������p���������
	bool is_above_left(const Point& p)const; //�ж��Ƿ��ڵ�p�����Ϸ�
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
