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

// template 의 인자로 T 를 받고, 
// 추가적으로 마치 함수의 인자 처럼 int num 을 또 받고 있다.

// 정수 타입들 (bool, char, int, long 등등). 당연히 float 과 double 은 제외
// 포인터 타입
// enum 타입
// std::nullptr_t(널 포인터)