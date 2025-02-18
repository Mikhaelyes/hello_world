#include <iostream>
#include <cmath>
#include "Matrix.h"

Matrix::Matrix()
{
        this->x1 = 0;
        this->x2 = 0;
	this->x3 = 0;
	this->x4 = 0;
}
Matrix::Matrix(double x)
{
        this->x1 = x;
        this->x2 = x;
	this->x3 = x;
        this->x4 = x;
}
Matrix::Matrix(double x1, double x2)
{
        this->x1 = x1;
        this->x2 = x1;
	this->x3 = x2;
        this->x4 = x2;
}
Matrix::Matrix(double x1, double x2, double x3)
{
        this->x1 = x1;
        this->x2 = x2;
	this->x3 = x3;
        this->x4 = x3;
}
Matrix::Matrix(double x1, double x2, double x3, double x4)
{
        this->x1 = x1;
        this->x2 = x2;
	this->x3 = x3;
        this->x4 = x4;
}


void Matrix::set_x1(double x1)
{
        this->x1 = x1;
}
void Matrix::set_x2(double x2)
{
        this->x2 = x2;
}
void Matrix::set_x3(double x3)
{
        this->x3 = x3;
}
void Matrix::set_x4(double x4)
{
        this->x4 = x4;
}

double Matrix::get_x1()
{
        return x1;
}
double Matrix::get_x2()
                         {
        return x2;
}
double Matrix::get_x3()
{
        return x3;
}
double Matrix::get_x4()
                         {
        return x4;
}

Matrix *Matrix::plus(Matrix *A)
{
        return new Matrix(x1 + A->get_x1(), x2 + A->get_x2(), x3 + A->get_x3(), x4 + A->get_x4());
}
Matrix *Matrix::minus(Matrix *A)
{
        return new Matrix(x1 - A->get_x1(), x2 - A->get_x2(), x3 - A->get_x3(), x4 - A->get_x4());
}

double det(Matrix&A)
{
        return (A.x1 * A.x4 - A.x2 * A.x3);
}

Matrix operator+ (Matrix &A, Matrix &B)
{
        return Matrix(A.x1 + B.x1, A.x2 + B.x2, A.x3 + B.x3, A.x4 + B.x4);
}
Matrix operator- (Matrix &A, Matrix &B)
{
        return Matrix(A.x1 - B.x1, A.x2 - B.x2, A.x3 - B.x3, A.x4 - B.x4);
}
Matrix operator* (double n, Matrix &B)
{
        return Matrix(n * B.x1, n * B.x2, n * B.x3, n * B.x4);
}
Matrix operator* (Matrix &A, double n)
{
        return Matrix(n * A.x1, n * A.x2, n * A.x3, n * A.x4);
}
Matrix operator* (Matrix &A, Matrix &B)
{
        return Matrix(A.x1 * B.x1 + A.x2 * B.x3, A.x1 * B.x2 + A.x2 * B.x4, A.x3 * B.x1 + A.x4 * B.x3, A.x3 * B.x2 + A.x4 *B.x4);
}
Vector2D operator* (Matrix &A, Vector2D &B)
{
        return Vector2D(A.x1 * B.get_x() + A.x2 * B.get_y(), A.x3 * B.get_x() + A.x4 * B.get_y());
}



Matrix operator++ (Matrix &A, int x)
{
        A.x1 += 1;
        A.x2 += 1;
	A.x3 += 1;
        A.x4 += 1;
        return A;
}
Matrix operator-- (Matrix &A, int x)
{
        A.x1 -= 1;
        A.x2 -= 1;
	A.x3 -= 1;
        A.x4 -= 1;
        return A;
}
Matrix operator++ (Matrix &A)
{
        A.x1 += 1;
        A.x2 += 1;
	A.x3 += 1;
        A.x4 += 1;
        return A;
}
Matrix operator-- (Matrix &A)
{
        A.x1 -= 1;
        A.x2 -= 1;
	A.x3 -= 1;
        A.x4 -= 1;
        return A;
}
Matrix operator+ (Matrix &A)
{
        return A;
}
Matrix operator- (Matrix &A)
{
        A.x1 = -A.x1;
        A.x2 = -A.x2;
	A.x3 = -A.x3;
	A.x4 = -A.x4;
        return A;
}

bool operator== (Matrix&A, Matrix &B)
{
        return (A.x1 == B.x1 && A.x2 == B.x2 && A.x3 == B.x3 && A.x4 == B.x4);
}
bool operator!= (Matrix&A, Matrix &B)
{
        return !(A == B);
}
bool operator> (Matrix&A, Matrix &B)
{
        return (det(A) > det(B));
}
bool operator< (Matrix&A, Matrix &B)
{
        return (det(A) < det(B));
}
bool operator>= (Matrix&A, Matrix &B)
{
        return (det(A) >= det(B));
}
bool operator<= (Matrix&A, Matrix &B)
{
        return (det(A) <= det(B));
}

std::ostream &operator<< (std::ostream &out, Matrix&B)
{
        out <<B.x1 <<" " <<B.x2 <<" " <<B.x3 <<" " <<B.x4 <<"; ";
        return out;
}
Matrix &operator>> (std::istream &in, Matrix &B)
{
        in >>B.x1 >>B.x2 >>B.x3 >>B.x4;
        return B;
}

