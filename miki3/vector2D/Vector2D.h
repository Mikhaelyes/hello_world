class Vector2D
{
	private:
		double x, y;
	public:
		Vector2D();
		Vector2D(double x);
		Vector2D(double x, double y);
		~Vector2D();
		void set_x(double x);
		void set_y(double y);
		double get_x();
		double get_y();
		Vector2D* operator*(double x);
		double operator*(Vector2D*);
		Vector2D* operator+(Vector2D*);
		Vector2D* operator-(Vector2D*);
		Vector2D* operator/(double a);
};


