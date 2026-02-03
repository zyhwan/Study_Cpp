#include<iostream>

using namespace std;


int main() {
	int x;
	int& y = x;
	int& z = y;

	x = 1;
	cout << x << y << z << endl;
	y = 2;
	cout << x << y << z << endl;
	z = 3;
	cout << x << y << z << endl;

	return 0;
}

//여러가지 참조자 예시