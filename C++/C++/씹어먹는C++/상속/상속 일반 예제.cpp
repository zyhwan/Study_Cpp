#include <iostream>
#include <string>

using namespace std;

class Base {
	string s;
public:
	Base() : s("기반") { cout << "기반 클래스" << endl; }

	void what() { cout << s << endl; }
};

class Derived : public Base {
	string s;
public:
	Derived() : Base(), s("파생") {
		cout << "파생 클래스" << endl;

		what();
	}
	void what() { cout << s << endl; }
};

int main() {
	cout << " === 기반 클래스 생성 ===" << endl;
	Base p;

	cout << " === 파생 클래스 생성 ===" << endl;
	Derived c;

	return 0;
}