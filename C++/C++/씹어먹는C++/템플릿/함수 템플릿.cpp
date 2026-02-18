//함수 템플릿

#include<iostream>
#include<string>

using namespace std;

template<typename T>
T max(T& a, T& b) {
	return a > b ? a : b;
}

int main() {
	int a = 1, b = 2;
	//템플릿 함수가 인스턴스화 되는 부분은 Max(a, b)가 호출되는 부분이다.
	//클래스를 인스턴스화 했을 때와 다르게 <>로 타입을 지정하는 부분이 없다.
	//컴파일러가 자동으로 알아서 Max<int>(a, b)로 타입을 추정해 인스턴스화 한다.
	cout << "Max (" << a << "," << b << ") ? : " << max(a, b) << endl;


	//string은 사전식 비교 규칙을 따르기 때문에 world가 출력됨.
	string s = "hello", t = "world";
	cout << "Max (" << s << "," << t << ") ? : " << max(s, t) << endl;
	


	return 0;
}
