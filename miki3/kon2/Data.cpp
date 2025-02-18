#include <iostream>
#include <cstring>
#include "Data.h"

Data::Data(int day, int month)
{
        this->day = day;
        this->month = month;
	norm();
}
Data Data::norm()
{
        this->month = month + (day - (day % 30)) / 30;
        this->day = day % 30;
}

void Data::set_d(int day)
{
        this->day = day;
	norm();
}
void Data::set_m(int month)
{
        this->month = month;
	norm();
}

int Data::get_d()
{
        return day;
}
int Data::get_m()
{
        return month;
}
Data operator+ (Data &A, Data &B)
{
        Data C = Data(A.day + B.day, A.month + B.month);
	C.norm();
	return C;
}
Data operator- (Data &A, Data &B)
{
        Data C = Data(A.day - B.day, A.month - B.month);
	C.norm();
	return C;
}


//Year::Year(int year) : Data(int day, int month)
//{
//        this->day = day;
//        this->month = month;
//	this->year = year;
//	norm();
//}
//
//void Year::set_y(int year)
//{
//        this->year = year;
//        norm();
//}
//
//int Year::get_y()
//{
//        return year;
//}
//Year Year::norm()
//{
//	this->month = month + (day - (day % 30)) / 30;
//	this->year = year + (month - (month % 12)) / 12;
//        this->day = day % 30;
//}
