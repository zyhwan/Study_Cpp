#include <iostream>
#include <string>

using namespace std;

class Base {
	string s;

public:
	Base() : s("기반") { cout << "기반 클래스" << endl; }

	virtual void incorrect() { cout << "기반 클래스 " << endl; }
};
class Derived : public Base {
	string s;

public:
	Derived() : Base(), s("파생") {}

	void incorrect() override { cout << "파생 클래스 " << endl; }
};
int main() {
	Base p;
	Derived c;

	Base* p_c = &c;
	Base* p_p = &p;

	cout << " == 실제 객체는 Base == " << endl;
	p_p->incorrect();

	cout << " == 실제 객체는 Derived == " << endl;
	p_c->incorrect();
	return 0;
}