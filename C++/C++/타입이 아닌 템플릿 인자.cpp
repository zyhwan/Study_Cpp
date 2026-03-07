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

// template 의 인자로 T 를 받고, 추가적으로 마치 함수의 인자 
// 처럼 int num 을 또 받고 있습니다.

// 한 가지 중요한 점은 템플릿 인자로 전달할 수 있는 타입은 제한적이다.
// bool, char, int, long, 포인터 타입, enum 타입, 널포인터 등