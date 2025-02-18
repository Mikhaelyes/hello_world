#include <iostream>
#include "Data.h"
int main()
{
	Data B (1, 1);
	B.set_m(12);
	B.set_d(35);
	int D1 = B.get_d();
	int D2 = B.get_m();

	Data B1 (25, 1);
	Data C = B1 + B;
	int D3 = C.get_d();
        int D4 = C.get_m();
	std::cout <<D2 <<" " <<D1 <<"\n";
	std::cout <<D4 <<" " <<D3 <<"\n";
        return 0;
}

