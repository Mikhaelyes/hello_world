#include <iostream>
#include "TVectorND.h"
int main()
{
	double x[3] = {4, 1, 2};
	double y[3] = {5, 1, 2};
	double z[2] = {1, 4};
        VectorND <double, 3> a(x);
        VectorND <double, 3> b(y);

	double test1 = a.get_x(0);

	double n = 5;
	double n1 = 0;
	VectorND <double, 3> c = a + b;
	VectorND <double, 3> d = a - b;
	VectorND <double, 3> f = a * n;
	VectorND <double, 3> g = a / n1;
	double S = skal(a, b);
//	bool B1 = a == b;
//	bool B2 = a != b;
//	bool B3 = a > b;
//	bool B4 = a < b;
//	bool B5 = a >= b;
//	bool B6 = a <= b;
	double M = mod(a);

	std::cout <<"a: " << a <<"\n";
	std::cout <<"b: " << b <<"\n";
	std::cout <<"+: " << c <<"\n";
	std::cout <<"-: " << d <<"\n";
	std::cout <<"* 5: " << f <<"\n";
	std::cout <<"/ n1: " << g <<"\n";
	std::cout <<"skal: " << S <<"\n";

//	std::cout << "operator skal(v*v): " <<skal << "\n";
//	a = b;
//	std::cout << "operator out: " <<a <<b <<"\n";
//	std::cout << "operator ==: " <<B1 << "\n";
//	std::cout << "operator !=: " <<B2 << "\n";
//	std::cout << "operator >: " <<B3 << "\n";
//	std::cout << "operator <: " <<B4 << "\n";
//	std::cout << "operator >=: " <<B5 << "\n";
//	std::cout << "operator <=: " <<B6 << "\n";
	std::cout << "operator mod a: " <<M << "\n";
}
