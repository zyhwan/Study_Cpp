#include <iostream>

using namespace std;

template<typename T, int num>
T add_num(T t) {
	return t + num;
}

int main() {
	int x = 3;
	cout << "x : " << add_num<int, 5>(x) << endl;
}