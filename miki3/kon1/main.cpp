#include <iostream>
#include "dro.h"
int main()
{
        dro a = dro(4, 5);
        dro b = dro(7, 6);
	dro c1 = dro(4, 8);
        double n = 5;
        dro c = a + b;
        dro d = a - b;
        dro e1 = a * n;
        dro e2 = n * a;
        dro skal = a * b;
	dro e3 = a / b;
        bool B1 = a == b;
        bool B2 = a != b;
        bool B3 = a > b;
        bool B4 = a < b;
        bool B5 = a >= b;
        bool B6 = a <= b;
        double M = doub(b);
	int M1 = ch(b);
        std::cout << "a: " <<a.get_x() << " " << a.get_y() << "\n";
        std::cout << "b: " <<b.get_x() << " " << b.get_y() << "\n";
        std::cout << "operator+: " <<c.get_x() << " " << c.get_y() << "\n";
        std::cout << "operator-: " <<d.get_x() << " " << d.get_y() << "\n";
        std::cout << "operator v*n: " <<e1.get_x() << " " << e1.get_y() << "\n";
        std::cout << "operator n*v: " <<e2.get_x() << " " << e2.get_y() << "\n";
	std::cout << "operator /: " <<e3.get_x() << " " << e3.get_y() << "\n";
        a++;
        std::cout << "operator ++pref: " <<a.get_x() << " " << a.get_y() << "\n";
        a--;
        std::cout << "operator --pref: " <<a.get_x() << " " << a.get_y() << "\n";
	++a;
	std::cout << "operator ++post: " <<a.get_x() << " " << a.get_y() << "\n";
        --a;
        std::cout << "operator --post: " <<a.get_x() << " " << a.get_y() << "\n";
        -a;
        std::cout << "operator -: " <<a.get_x() << " " << a.get_y() << "\n";
        -a;
        +a;
        std::cout << "operator +: " <<a.get_x() << " " << a.get_y() << "\n";
	a += b;
        std::cout << "operator +=: " <<a.get_x() << " " << a.get_y() << "\n";
	a -= b;
	c1 -= b;
        std::cout << "operator -=: " <<c1.get_x() << " " << c1.get_y() << "\n";
	a *= b;
	std::cout << "operator *=: " <<a.get_x() << " " << a.get_y() << "\n";
	a /= b;
	std::cout << "operator /=: " <<a.get_x() << " " << a.get_y() << "\n";

	//        std::cout << "operator skal(v*v): " <<skal << "\n";
        std::cout << "operator out: " <<a <<b <<"\n";
        std::cout << "operator ==: " <<B1 << "\n";
        std::cout << "operator !=: " <<B2 << "\n";
        std::cout << "operator >: " <<B3 << "\n";
        std::cout << "operator <: " <<B4 << "\n";
        std::cout << "operator >=: " <<B5 << "\n";
        std::cout << "operator <=: " <<B6 << "\n";
        std::cout << "operator doub: " <<M << "\n";
	std::cout << "operator ch: " <<M1 << "\n";
}
  
