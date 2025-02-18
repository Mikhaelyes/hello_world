#include "vector2D.h"
class Matrix
{
        double x1, x2, x3, x4;
public:
        Matrix();
        Matrix(double x1);
        Matrix(double x1, double x2);
        Matrix(double x1, double x2, double x3);
        Matrix(double x1, double x2, double x3, double x4);


        double get_x1();
        double get_x2();
	double get_x3();
        double get_x4();

        void set_x1(double x1);
        void set_x2(double x2);
	void set_x3(double x3);
	void set_x4(double x4);

        Matrix *plus(Matrix *A);
        Matrix *minus(Matrix *A);

        friend double det(Matrix &A);
        friend Matrix operator+ (Matrix &A, Matrix &B);
        friend Matrix operator- (Matrix &A, Matrix &B);
        friend Matrix operator* (Matrix &A, Matrix &B);
        friend Matrix operator* (Matrix &A, double n);
        friend Matrix operator* (double n, Matrix &A);
	friend Vector2D operator* (Matrix &A, Vector2D &B);

        friend Matrix operator++ (Matrix &A, int x);
        friend Matrix operator-- (Matrix &A, int x);
        friend Matrix operator++ (Matrix &A);
        friend Matrix operator-- (Matrix &A);
        friend Matrix operator+ (Matrix &A);
        friend Matrix operator- (Matrix &A);

        friend bool operator== (Matrix &A, Matrix &B);
        friend bool operator!= (Matrix &A, Matrix &B);
        friend bool operator> (Matrix &A, Matrix &B);
        friend bool operator< (Matrix &A, Matrix &B);
        friend bool operator>= (Matrix &A, Matrix &B);
        friend bool operator<= (Matrix &A, Matrix &B);

	friend std::ostream &operator << (std::ostream &out, Matrix &B);
	friend Matrix &operator >> (std::istream &out, Matrix &B);
};
	
