#include<iostream>

using namespace std;

template<typename T>
void print(T arg)
{
	cout << arg << endl;
}

// typename 뒤에 ... 으로 오는 것을 템플릿 파리미터 팩(parameter pack) 이라고 부릅니다.
template<typename T, typename... Types>
void print(T arg, Types... args)
{
	cout << arg << ", ";
	print(args...);
}


int main()
{
	print(1, 1.31, "abc");
	print(1, 2, 3, 4, 5, 6, 7);

	return 0;
}