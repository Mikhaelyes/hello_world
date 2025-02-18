#include <cmath>
const double Pi = 3.14;

struct Point {
	double x, y;
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	double get_x()
	{
		return x;
	}
	double get_y()
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
};

double distance (Point &A, Point &B);


class Figure
{
public:
        Figure();
	virtual double S() = 0;
	virtual double P() = 0;
};

class Circle: public Figure
{
protected:
        Point cen; double rad;
public:
        Circle(Point cen, double rad);
	double set_cen(Point cen);
        double set_rad(double rad);
//	double get_cen();
	double get_rad();
        double S();
	double P();

};

