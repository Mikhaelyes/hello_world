#include <iostream>
#include "Matrix2.h"

double sum(double x, double y)
{
    return x + y;
};

Vector2D* sum(Vector2D* a, Vector2D* b)
{
    Vector2D* newVector = new Vector2D(a->get_x() + b->get_x(), a->get_y() + b->get_y());
    return newVector;
};

int main()
{
    *Vector2D* null = new Vector2D();
    Vector2D* a = new Vector2D(2);
    Vector2D* b = new Vector2D(0, 2);

    std::cout << "Vector null: " << null->get_x() << " "<< null->get_y() << std::endl;

    std::cout << "Vector a: " << a->get_x() << " "<< a->get_y() << std::endl;

    std::cout << "Vector b: " << b->get_x() << " "<< b->get_y() << std::endl;

    std::cout << "Sum 1.5 + 3.4566: " << sum(1.5, 3.4566) << std::endl;

    Vector2D* Sum = *a + b;
    std::cout << "Sum vector a and vector b: " << Sum->get_x() << " "<< Sum->get_y() << std::endl;

    Vector2D* Sub = *a - b;
    std::cout << "Subtraction vector a and vector b: " << Sub->get_x() << " "<< Sub->get_y() << std::endl;

    Vector2D* Mul = *a * 5.5;
    std::cout << "Multiplication vector a and double 5.5: " << Mul->get_x() << " "<< Mul->get_y() << std::endl;

    Vector2D* Mulv = *a * 5.5;
    std::cout << "Multiplication vector a and vector b: "<< Mulv->get_x() << " "<< Mulv->get_y() << std::endl;

    Vector2D* Div = *a / 5.5;
    std::cout << "Division vector a and double 5.5: " << Div->get_x() << " "<< Div->get_y() << std::endl;*/

