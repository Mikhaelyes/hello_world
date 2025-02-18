#include <iostream>
#include <cmath>

template <typename T, int n>
VectorND <T, n> ::VectorND()
{
	for(int i = 0; i < n; i++) {
		this->x[i] = 0;
	}
}
template <typename T, int n>
VectorND <T, n> ::VectorND(T x[n])
{
	for(int i = 0; i < n; i++) {
		this->x[i] = x[i];
	}
}

template <typename T, int n>
void VectorND <T, n> ::set_x(T x, int i)
{
	this->x = x[i];
}

template <typename T, int n>
T VectorND <T, n> ::get_x(int i)
{
        return x[i];
}

template <typename T1, int n1>
double mod(VectorND <T1, n1> &A)
{
	double S = 0;
	for(int i = 0; i < n1; i++) {
		S += (A.x[i] * A.x[i]);
	}
	return sqrt(S);
}

template <typename T1, int n1>
VectorND <T1, n1> operator+ (VectorND <T1, n1> &A, VectorND <T1, n1> &B)
{
	VectorND <T1, n1> C;
	for(int i = 0; i < n1; i++) {
		C.x[i] = A.x[i] + B.x[i];
	}
	return C;
}
template <typename T1, int n1>
VectorND <T1, n1> operator- (VectorND <T1, n1> &A, VectorND <T1, n1> &B)
{
	VectorND <T1, n1> C;
        for(int i = 0; i < n1; i++) {
                C.x[i] = A.x[i] - B.x[i];
        }
        return C;
}
template <typename T1, int n1>
VectorND <T1, n1> operator* (VectorND <T1, n1> &A, T1 N)
{
	VectorND <T1, n1> C;
        for(int i = 0; i < n1; i++) {
                C.x[i] = A.x[i] * N;
        }
        return C;
}
//template <typename T1, int n1>
//VectorND <T1, n1> operator* (VectorND <T1, n1> &A, T1 N)
//{
//        VectorND <T1, n1> C;
//        for(int i = 0; i < n1; i++) {
//                C.x[i] = A.x[i] * N;
//        }
//        return C;
//}
//
template <typename T1, int n1>
VectorND <T1, n1> operator/ (VectorND <T1, n1> &A, T1 N1)
{
	VectorND <T1, n1> C;
	try
	{
		if( N1 == 0) {       
			throw 11;
			return C;
		}
		else
		{
        		for(int i = 0; i < n1; i++) {
                		C.x[i] = A.x[i] / N1;
        		}
			return C;
		}
	}
	catch(int a)
	{
		std::cout <<"LOL" <<"\n";
	}
}
template <typename T1, int n1>
T1 skal (VectorND <T1, n1> &A, VectorND <T1, n1> &B)
{
        T1 S = 0;
        for(int i = 0; i < n1; i++) {
                S += A.x[i] * B.x[i];
        }
        return S;
}


//Vector2D operator++ (Vector2D &A, int x)
//{
//        A.x += 1;
//	A.y += 1;
//	return A;
//}
//Vector2D operator-- (Vector2D &A, int x)
//{
//        A.x -= 1;
//	A.y -= 1;
//	return A;
//}
//Vector2D operator++ (Vector2D &A)
//{
//        A.x += 1;
//        A.y += 1;
//        return A;
//}
//Vector2D operator-- (Vector2D &A)
//{
//        A.x -= 1;
//        A.y -= 1;
//        return A;
//}
//Vector2D operator+ (Vector2D &A)
//{
//        return A;
//}
//Vector2D operator- (Vector2D &A)
//{
//        A.x = -A.x;
//        A.y = -A.y;
//        return A;
//}
//
//bool operator== (Vector2D &A, Vector2D &B)
//{
//	return (A.x == B.x && A.y == B.y);
//}
//bool operator!= (Vector2D &A, Vector2D &B)
//{
//        return !(A == B);
//}
//bool operator> (Vector2D &A, Vector2D &B)
//{
//        return (mod(A) > mod(B));
//}
//bool operator< (Vector2D &A, Vector2D &B)
//{
//        return (mod(A) < mod(B));
//}
//bool operator>= (Vector2D &A, Vector2D &B)
//{
//        return (mod(A) >= mod(B));
//}
//bool operator<= (Vector2D &A, Vector2D &B)
//{
//        return (mod(A) <= mod(B));
//}
//
template <typename T1, int n1>
std::ostream &operator<< (std::ostream &out, VectorND <T1, n1> &A)
{
	for(int i = 0; i < n1; i++)
	{
		out <<A.x[i] <<" "; 
	}
	out << "; ";
	return out;
}
//Vector2D &operator>> (std::istream &in, Vector2D &B)
//{
//        in >>B.x >>B.y;
//        return B;
//}
//
