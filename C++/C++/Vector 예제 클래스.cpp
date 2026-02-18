//템플릿의 필요이유를 설명하는 예제 벡터 코드
#include<iostream>

using namespace std;

class Vector {
	string* data; //벡터의 각 원소를 가리킬 포인터
	int capacity; //벡터의 크기, 할당한 메모리의 크기
	int length; //벡터로 생성한 배열의 크기

public:
	Vector(int n = 1) : data(new string[n]), capacity(n), length(0) {}
	
	void push_back(string s) {
		if (capacity <= length) { //메모리 확보해주기.
			string* temp = new string[capacity * 2];
			for (int i = 0; i < length; ++i) {
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
			capacity *= 2;
		}

		data[length] = s; //확장한 백터에 내용값을 할당.
		length++; //문자열 길이 늘리기
	}

	// 임의의 위치의 원소에 접근했을 때([]연산자로 접근) 
	// string 타입의 값을 리턴.
	string operator[](int i) { return data[i]; }

	//x 번째 원소를 삭제.
	void remove(int x) {
		for (int i = x + 1; i < length; ++i) {
			data[i - 1] = data[i];
		}
		length--;
	}

	//현재 벡터의 크기(배열의 크기)
	int size() { return length; }
	~Vector() {
		if (data) {
			delete[] data;
		}
	}

};

int main()
{

}

// 위와 같은 경우엔 string 타입의 데이터 밖에 저장할 수 없다.
// 만약에 사용자가 다양한 다른 타입의 데이터를 저장하고 싶다면
// 위에 data를 담는 string 부분을 계속 바꿔서 코드를 작성해야한다.

// 하지만 사용자가 어떤 데이터를 사용할지 그때 그때마다 다르며
// 그 많은 데이터를 모두 코드를 작성하기에는 효율이 떨어지고 파일이
// 커져 비효율적일 수 밖에 없다. 그래서 우리는 사용자가 원하는
// 데이터 타입을 그때마다 적용할 수 있는 템플릿을 사용해야한다.