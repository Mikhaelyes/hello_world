#include <iostream>
#include "vector2D.h"
int main()
{
	std::cout << sum() <<"\n";
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

