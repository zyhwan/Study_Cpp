#include <iostream>

using namespace std;

class Base {
public:
	Base() { cout << "기반 클래스" << endl; }
	virtual void what() { cout << "기반 클래스의 what()" << endl; }

};

class Derived : public Base {
public:
	Derived() : Base() { cout << "파생 클래스" << endl; }

	void what() { cout << "파생 클래스의 what()" << endl; }
};

int main() {
	Base p;
	Derived c;

	Base* p_c = &c;
	Base* p_p = &p;

	cout << " == 실제 객체는 Base ==" << endl;
	p_p->what();

	cout << " == 실제 객체는 Derived == " << endl;
	p_c->what();

	return 0;
}