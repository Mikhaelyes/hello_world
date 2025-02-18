class dro
{
        int x, y;
public:
        dro();
        dro(int x);
        dro(int x, int y);

        int get_x();
        int get_y();

        void set_x(int x);
        void set_y(int y);

	friend double doub(dro &A);
	friend int ch(dro &A);
        friend dro operator+ (dro &A, dro &B);
        friend dro operator- (dro &A, dro &B);
        friend dro operator* (dro&A, dro &B);
        friend dro operator* (dro &A, double n);
        friend dro operator* (double n, dro &A);
        friend dro operator/ (dro &A, dro &B);

        friend dro operator++ (dro &A, int x);
        friend dro operator-- (dro &A, int x);
        friend dro operator++ (dro &A);
        friend dro operator-- (dro &A);
	friend dro operator+ (dro &A);
        friend dro operator- (dro &A);
	friend dro operator+= (dro &A, dro &B);
        friend dro operator-= (dro &A, dro &B);
	friend dro operator*= (dro &A, dro &B);
        friend dro operator/= (dro &A, dro &B);

        friend bool operator== (dro &A, dro &B);
        friend bool operator!= (dro &A, dro &B);
        friend bool operator> (dro &A, dro &B);
        friend bool operator< (dro &A, dro &B);
        friend bool operator>= (dro &A, dro &B);
        friend bool operator<= (dro &A, dro &B);

        friend std::ostream &operator << (std::ostream &out, dro&B);
	friend dro &operator >> (std::istream &out, dro&B);

};
