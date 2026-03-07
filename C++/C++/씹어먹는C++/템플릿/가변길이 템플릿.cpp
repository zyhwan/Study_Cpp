#include<iostream>

using namespace std;

template<typename T>
void print(T arg)
{
	cout << arg << endl;
}

// typename 뒤에 ... 으로 오는 것을 템플릿 파리미터 팩(parameter pack) 이라고 부른다.
template<typename T, typename... Types>
// 함수에 인자로 ... 로 오는 것을 함수 파라미터 팩 이라고 부른다.
void print(T arg, Types... args)
{
	cout << arg << ", ";
	print(args...);
}

// 템플릿 파라미터 팩과 함수 파라미터 팩의 차이점은 템플릿의 경우 타입 앞에 
// ... 이 오고, 함수의 경우 타입 뒤 에 ... 가 온다는 점이다.


int main()
{
	print(1, 1.31, "abc");
	print(1, 2, 3, 4, 5, 6, 7);

	return 0;
}

// C++ 규칙 상, 파라미터 팩이 없는 함수의 우선순위가 높다.

// 위에 템플릿 순서를 바꿔서 작성하면 오류가 발생한다.
// 왜냐하면 C++컴파일러는 함수를 컴파일 시에, 자신의 앞에 정의되어 있는 함수들
// 밖에 보지 못하기 때문이다.
// 따라서 항상 템플릿 함수를 작성할 때 그 순서에 유의해서 써야 한다.