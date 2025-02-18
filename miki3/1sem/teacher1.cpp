#include <iostream>

class Complex
{
	double x, y;  	//private
public:
	Complex(double _x, double _y);
	~Complex();
	void set_x(double _x);
	void set_y(double _y);
	double get_x();
	double get_y();
	Complex *plus(Complex *A);
	Complex *minus(Complex *A);
	Complex *sop();
	Complex *mul(double _z);
	Complex *mul1(Complex *A);
	double mod();
};

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


int main()
{
	Complex *a = new Complex(0, 0);
	a->set_x(4);
	a->set_y(8);
	Complex *b = new Complex(0, 0);
	b->set_x(5);
	b->set_y(6);
	Complex *c = a->plus(b);
	Complex *d = a->minus(b);
	Complex *e = a->sop();
	Complex *f = a->mul(4);
	Complex *g = a->mul1(b);
	double z = a->mod();
	std::cout << "a: " <<a->get_x() << " " << a->get_y() << "\n";
	std::cout << "b: " <<b->get_x() << " " << b->get_y() << "\n";
	std::cout << "plus: " <<c->get_x() << " " << c->get_y() << "\n";
	std::cout << "minus: " <<d->get_x() << " " << d->get_y() << "\n";
	std::cout << "sop: " <<e->get_x() << " " << e->get_y() << "\n";
	std::cout << "multiply on num 4: " <<f->get_x() << " " << f->get_y() << "\n";
	std::cout << "multiply a and b: "<< g->get_x() << " " << g->get_y() << "\n";
	std::cout << "module: " << z << "\n";
	delete a, b, c, d, e, f, g;
	
		
}






