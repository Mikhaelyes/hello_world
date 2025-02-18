#include <iostream>
#include <array>

template <typename T, int n>

class VectorND
{
	std::array <T, n> x;
	int i;
public:
	VectorND();
	VectorND(T x[n]);

	T get_x(int i);

	void set_x(T x, int i);

	template <typename T1, int n1>
	friend double mod(VectorND <T1, n1> &A);
	template <typename T1, int n1>
	friend VectorND <T1, n1> operator+ (VectorND <T1, n1> &A, VectorND <T1, n1> &B);
	template <typename T1, int n1>
        friend VectorND <T1, n1> operator- (VectorND <T1, n1> &A, VectorND <T1, n1> &B);
	template <typename T1, int n1>
        friend VectorND <T1, n1> operator* (VectorND <T1, n1> &A, T1 N);
//	template <typename T1, int n1>
//	friend VectorND <T1, n1> operator* (VectorND <T1, n1> &A, VectorND <T1, n1> &B);
	template <typename T1, int n1>
        friend VectorND <T1, n1> operator/ (VectorND <T1, n1> &A, T1 N1);
	template <typename T1, int n1>
        friend T1 skal (VectorND <T1, n1> &A, VectorND <T1, n1> &B);

	template <typename T1, int n1>
	friend std::ostream &operator << (std::ostream &out, VectorND <T1, n1> &A);

};

#include "TVectorND.inl"
