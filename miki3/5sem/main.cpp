#include <iostream>
#include "Figure.h"
int main()
{
	Point A(1, 1);
	Circle B (A, 3);
	std::cout << "Perimetr: " <<B.P() <<"\n"; 
	std::cout << "Sqaure: " <<B.S() <<"\n";
	return 0;
}
