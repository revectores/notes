#include <iostream>

class Employee {
public:
	std::string name;
	int age;
};

class Manager : public Employee {
public:
	short level;
};

int main() {
	Employee e;
	Manager m;
	m.name = "Robert"; m.level = 8;
	std::cout << m.name << " " << m.level;
}
