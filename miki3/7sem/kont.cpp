#include <iostream>
#include <array>
#include <vector>

int main() {
	std::array <int, 5> a;
	a[0] = 5;
	int c = a[1];
	a = {1, 4, 1, 7, 100};
	for(int i = 0; i < 5; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
	int n = 10;
	std::vector <int> b;
	b = {1, 4, 10};
	b.resize(n);
	for(int i = 0; i < n; i++) {
                std::cout << b[i] <<" ";
        }
	std::cout << "\n";

}
