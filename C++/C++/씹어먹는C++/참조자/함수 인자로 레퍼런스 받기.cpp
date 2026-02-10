#include<iostream>

using namespace std;

//함수 인자로 레퍼런스 받기
int change_val(int &p) {

	p = 3;
	return 0;
}


int main() {
	int number = 5;

	cout << number << endl;
	change_val(number);
	cout << number << endl;

	return 0;
}