#include <iostream>
#include "Matrix.h"
int main()
{    
        Matrix a = Matrix(4, 8, 5, 16);
        Matrix b = Matrix(5, 6, 4, 3);
	Vector2D V1 = Vector2D(4, 7); 
        double n = 5;
        Matrix c = a + b;
        Matrix d = a - b;
        Matrix e1 = a * n;
        Matrix e2 = n * a;
        Matrix e3 = a * b;
        bool B1 = a == b;
        bool B2 = a != b;
        bool B3 = a > b;
        bool B4 = a < b;
        bool B5 = a >= b;
        bool B6 = a <= b;
        double M = det(a);
	Vector2D V = a * V1;
        std::cout << "a: " <<a.get_x1() << " " << a.get_x2() << " " << a.get_x3() << " " << a.get_x4() << "\n";
	std::cout << "b: " <<b.get_x1() << " " << b.get_x2() << " " << b.get_x3() << " " << b.get_x4() << "\n";
	std::cout << "c: " <<c.get_x1() << " " << c.get_x2() << " " << c.get_x3() << " " << c.get_x4() << "\n";
	std::cout << "d: " <<d.get_x1() << " " << d.get_x2() << " " << d.get_x3() << " " << d.get_x4() << "\n";
	std::cout << "a * n: " <<e1.get_x1() << " " << e1.get_x2() << " " << e1.get_x3() << " " << e1.get_x4() << "\n";
	std::cout << "n * a: " <<e2.get_x1() << " " << e2.get_x2() << " " << e2.get_x3() << " " << e2.get_x4() << "\n";
	std::cout << "a * b: " <<e3.get_x1() << " " << e3.get_x2() << " " << e3.get_x3() << " " << e3.get_x4() << "\n";
	a++;
	std::cout << "a++: " <<a.get_x1() << " " << a.get_x2() << " " << a.get_x3() << " " << a.get_x4() << "\n";
	a--;
	std::cout << "a--: " <<a.get_x1() << " " << a.get_x2() << " " << a.get_x3() << " " << a.get_x4() << "\n";
	++a;
	std::cout << "++a: " <<a.get_x1() << " " << a.get_x2() << " " << a.get_x3() << " " << a.get_x4() << "\n";
	--a;
	std::cout << "--a: " <<a.get_x1() << " " << a.get_x2() << " " << a.get_x3() << " " << a.get_x4() << "\n";

        std::cout << "operator out: " <<"a: " <<a <<"b: " <<b <<"\n";

	std::cout << "V1: " <<V1 << "\n";
	std::cout << "m * v: " <<V << "\n";
        std::cout << "operator ==: " <<B1 << "\n";
        std::cout << "operator !=: " <<B2 << "\n";
        std::cout << "operator >: " <<B3 << "\n";
        std::cout << "operator <: " <<B4 << "\n";
        std::cout << "operator >=: " <<B5 << "\n";
        std::cout << "operator <=: " <<B6 << "\n";
        std::cout << "operator det: " <<M << "\n";
}

