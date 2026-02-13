#include <iostream>

using namespace std;

class A {
public:
	int a;

	A() { cout << "A 생성자 호출" <<  endl; }
};

class B {
public:
	int b;

	B() {  cout << "B 생성자 호출" <<  endl; }
};

class C : public A, public B {
public:
	int c;

	C() : A(), B() {  cout << "C 생성자 호출" <<  endl; }
};

int main() { C c; }