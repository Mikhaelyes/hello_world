//struct PointK {
//        int day, month;
//        PointK()
//        {
//                day = 0;
//                month = 0;
//        }
//        PointK(int day, int month)
//        {
//                this->day = day;
//                this->month = month;
//        }
//        int get_d()
//        {
//                return day;
//        }
//        int get_m()
//        {
//                return month;
//        }
//        void set_d(int day)
//        {
//                this->day = day;
//       

class Data
{
protected:
        int day; int month;
public:
        Data(int day, int month);
	Data norm();
	friend Data operator+ (Data &A, Data &B);
        friend Data operator- (Data &A, Data &B);
	
        void set_d(int day);
        void set_m(int month);
        int get_d();
        int get_m();

};
//class Year: public Data
//{
//protected:
//        int year;
//public:
//        Year(int year) : Data(int day, int month);
//	Year norm();
//	void set_y(int year);
//	int get_y();
//
//};

