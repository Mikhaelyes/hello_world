#include <iostream>
#include <cstring>
#include "Human.h"

Human::Human()
{
	this->name = "Empty";
	this->age = 0;
}
Human::Human(std::string name)
{
	this->name = name;
	this->age = 0;
}
Human::Human(std::string name, int age)
{
        this->name = name;
        this->age = age;
}
std::string Human::get_name()
{
	return name;
}
int Human::get_age()
{
	return age;
}
void Human::set_name(std::string name)
{
	this->name = name;
}
void Human::set_age(int age)
{
	this->age = age;
}


