#include <iostream>

using namespace std;

class Animal {
public:
	Animal() {}
	virtual ~Animal() {}
	virtual void speak() = 0;
};

class Dog : public Animal {
public:
	Dog() : Animal() {}
	
	void speak() override { cout << "啃啃" << endl; }
};

class Cat : public Animal {
public:
	Cat() : Animal() {}
	void speak() override { cout << "具克具克" << endl; }
};

int main() {
	Animal* dog = new Dog();
	Animal* cat = new Cat();

	dog->speak();
	cat->speak();

	return 0;

}