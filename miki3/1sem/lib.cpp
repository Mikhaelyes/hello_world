#include <iostream>
#include "lib.h"

Complex::Complex(double _x, double _y)
{
        x = _x;
        y = _y;
}

Complex::~Complex()
{
        std::cout << "complex class is deleted\n";
}
void Complex::set_x(double _x)
{
        x = _x;
}
void Complex::set_y(double _y)
{
       y = _y;
}
double Complex::get_x()
{
        return x;
}
double Complex::get_y()
{
        return y;
}
Complex *Complex::plus(Complex *A)
{
        return new Complex(x + A->get_x(), y + A->get_y());
}
Complex *Complex::minus(Complex *A)
{
        return new Complex(x - A->get_x(), y - A->get_y());
}
Complex *Complex::sop()
{
        return new Complex( x, -y);
}
Complex *Complex::mul(double _z)
{
        return new Complex(x * _z, y * _z);
}
Complex *Complex::mul1(Complex *A)
{
        return new Complex(x* A->get_x() - y * A->get_y(), y * A->get_x() + x*A->get_y());
}
double Complex::mod()
{
        return x * x + y * y;
}
 

