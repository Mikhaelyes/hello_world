#include <iostream>
#include <cmath>
#include "dro.h"
#include <algorithm>

dro::dro()
{
        this->x = 1;
        this->y = 1;
}
dro::dro(int x)
{
        this->x = 1;
        this->y = 1;
}
dro::dro(int x, int y)
{
	if (y == 0) {
		 std::cout << "Error: invalid second number " <<"\n";
		 y = 1;
	}
	int n = std::__gcd(x, y);
        this->x = x / n;
        this->y = y / n;
}


void dro::set_x(int x)
{
      this->x = x;
}
void dro::set_y(int y)
{
      this->y = y;
}

int dro::get_x()
{
        return x;
}
int dro::get_y()
{
        return y;
}

double doub(dro &A)
{
	return (double) A.x / (double) A.y;
}
int ch(dro &A)
{
        return A.x / A.y;
}


dro operator+ (dro &A, dro &B)
{
        return dro(A.x * B.y + B.x * A.y, A.y * B.y);
}
dro operator- (dro &A, dro &B)
{
        return dro(A.x * B.y - B.x * A.y, A.y * B.y);
}
dro operator* (double n, dro &B)
{
	n = n * 1000;
	n = (int) n;
        return dro(n * B.x, 1000 * B.y);
}
dro operator* (dro &A, double n)
{
	n = n*1000;
	n = (int) n;
        return dro(A.x * n, A.y * 1000);
}
dro operator* (dro &A, dro &B)
{
        return dro(A.x * B.x, A.y * B.y);
}
dro operator/ (dro &A, dro &B)
{
        return dro(A.x * B.y, A.y * B.x);
}

dro operator++ (dro &A, int x)
{
        A.x += A.y;
        return A;
}
dro operator-- (dro &A, int x)
{
        A.x -= A.y;
        return A;
}
dro operator++ (dro &A)
{
        A.x += A.y;
        return A;
}
dro operator-- (dro &A)
{
        A.x -= A.y;
        return A;
}
dro operator+ (dro &A)
{
        return A;
}
dro operator- (dro &A)
{
        A.x = -A.x;
        return A;
}
dro operator+= (dro &A, dro &B)
{
        A = A + B;
	return A;
}
dro operator-= (dro &A, dro &B)
{
        A = A - B;
	return A;
}
dro operator*= (dro &A, dro &B)
{
        A = A * B;
        return A;
}
dro operator/= (dro &A, dro &B)
{
        A = A / B;
        return A;
}

bool operator== (dro &A, dro &B)
{
        return (A.x == B.x && A.y == B.y);
}
bool operator!= (dro &A, dro &B)
{
        return !(A == B);
}
bool operator> (dro &A, dro &B)
{
        return (A.x * B.y > B.x * A.y);
}
bool operator< (dro &A, dro &B)
{
        return (A.x * B.y < B.x * A.y);
}
bool operator>= (dro &A, dro &B)
{
        return (A.x * B.y >= B.x * A.y);
}
bool operator<= (dro &A, dro &B)
{
        return (A.x * B.y <= B.x * A.y);
}


std::ostream &operator<< (std::ostream &out, dro &B)
{
        out <<B.x <<" " <<B.y <<"; ";
        return out;
}
dro &operator>> (std::istream &in, dro &B)
{
	in >>B.x >>B.y;
        return B;
}

