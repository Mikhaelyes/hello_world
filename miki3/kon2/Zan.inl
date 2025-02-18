#include <iostream>
#include <cmath>

template <typename T>
Zan <T> ::Zan(T x[n], Data y)
{
        
}

template <typename T, int n>
void Zan <T, n> ::set_x(T x, int i)
{
        this->x = x[i];
}

template <typename T, int n>
T Zan <T, n> ::get_x(int i)
{
        return x[i];
}
template <typename T1, int n1>
Zan <T1, n1> operator+ (Zan <T1, n1> &A, Zan <T1, n1> &B)
{
        Zan <T1, n1> C;
        for(int i = 0; i < n1; i++) {
                C.x[i] = A.x[i] + B.x[i];
        }
        return C;
}
template <typename T1, int n1>
Zan <T1, n1> operator- (Zan <T1, n1> &A, Zan <T1, n1> &B)
{
        Zan <T1, n1> C;
        for(int i = 0; i < n1; i++) {
                C.x[i] = A.x[i] - B.x[i];
        }
        return C;
}


