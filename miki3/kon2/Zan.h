#include <iostream>
#include <array>
#include <Data.h>

template <typename T>

class Zan
{
        std::array <typename T> x;
        int i;
public:
        Zan(T x[n], Data y);

        T get_x(int i);

        void set_x(T x, int i);

        template <typename T1>
        friend double mod(Zan <T1> &A);
        template <typename T1>
        friend Zan <T1> operator+ (Zan <T1> &A, Zan <T1> &B);
        template <typename T1>
        friend Zan <T1> operator- (Zan <T1> &A, Zan <T1> &B);
};

#include "Zan.inl"
                          
