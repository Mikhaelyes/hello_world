#include <iostream>

int main()
{
	int n = 1;
	int b = 0;
	try
	{
		if( n == 0) throw 1;
		if( n == 1 && b == 0) throw 1.1;
	}
	catch (int a)
	{
		std::cerr << "Invalid1" <<"\n";
	}
	catch (double d)
	{
		std::cerr << "Invalid2" <<"\n";
	}
	std::cout << "Hello" <<"\n";
	return 0;
}
