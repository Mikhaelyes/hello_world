#include <iostream>
#include <cstring>
#include <cmath>
#include "Figure.h"

double distance (Point &A, Point &B)
{
        double d = sqrt((A.get_x() - B.get_x()) * (A.get_x() - B.get_x()) + (A.get_y() - B.get_y()) * (A.get_y() - B.get_y()));
        return d;
}

Figure::Figure() {};

Circle::Circle(Point cen, double rad) : Figure ()
{
	this->cen.x = cen.x;
	this->cen.y = cen.y;
	this->rad = rad;
}
double Circle::set_cen(Point cen)
{
        this->cen.x = cen.x;
	this->cen.y = cen.y;
}
double Circle::set_rad(double rad)
{
        this->rad = rad;
}

//get_cen

double Circle::get_rad()
{
        return rad;
}

double Circle::S()
{
        return (Pi * rad * rad);
}
double Circle::P()
{
        return (2 * Pi * rad);
}


//std::string Human::get_name()
//{
//        return name;
//}
//int Human::get_age()
//{
//        return age;
//}
//void Human::set_name(std::string name)
//{
//        this->name = name;
//}
//void Human::set_age(int age)
//{
//        this->age = age;
//}
//
