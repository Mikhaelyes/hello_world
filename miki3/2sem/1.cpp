#include <iostream>
#include "Vector2D.h"
int main()
{
        Vector2D a = Vector2D(4, 8);
        Vector2D b = Vector2D(5, 6);
	double n = 5;
	Vector2D c = a + b;
	Vector2D d = a - b;
	Vector2D e1 = a * n;
	Vector2D e2 = n * a;
	double skal = a * b;
	bool B1 = a == b;
	bool B2 = a != b;
	bool B3 = a > b;
	bool B4 = a < b;
	bool B5 = a >= b;
	bool B6 = a <= b;
	double M = mod(a);
	std::cout << "a: " <<a.get_x() << " " << a.get_y() << "\n";
        std::cout << "b: " <<b.get_x() << " " << b.get_y() << "\n";
        std::cout << "operator+: " <<c.get_x() << " " << c.get_y() << "\n";
	std::cout << "operator-: " <<d.get_x() << " " << d.get_y() << "\n";
	std::cout << "operator v*n: " <<e1.get_x() << " " << e1.get_y() << "\n";
	std::cout << "operator n*v: " <<e2.get_x() << " " << e2.get_y() << "\n";
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
        std::cout << "operator -: " <<a.get_x() << " " << a.get_y() << "\n";
	std::cout << "operator skal(v*v): " <<skal << "\n";
	a = b;
	std::cout << "operator out: " <<a <<b <<"\n";
	std::cout << "operator ==: " <<B1 << "\n";
	std::cout << "operator !=: " <<B2 << "\n";
	std::cout << "operator >: " <<B3 << "\n";
	std::cout << "operator <: " <<B4 << "\n";
	std::cout << "operator >=: " <<B5 << "\n";
	std::cout << "operator <=: " <<B6 << "\n";
	std::cout << "operator mod: " <<M << "\n";
}
