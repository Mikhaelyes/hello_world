class Complex
{
        double x, y;    //private
public:
        Complex(double _x, double _y);
        ~Complex();
        void set_x(double _x);
        void set_y(double _y);
        double get_x();
        double get_y();
        Complex *plus(Complex *A);
        Complex *minus(Complex *A);
        Complex *sop();
        Complex *mul(double _z);
        Complex *mul1(Complex *A);
        double mod();
};
double sum();

