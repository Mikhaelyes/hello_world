class Human
{
protected:
	std::string name; int age;
public:
	Human();
	Human(std::string name);
	Human(std::string name, int age);

	std::string get_name();
	int get_age();

	void set_name(std::string name);
	void set_age(int age);
};

class Student: public Human
{
protected:
	int score;
public:
	Student(std::string name, int age, int score);

	int get_age();
	
	void set_score(int score);
};

