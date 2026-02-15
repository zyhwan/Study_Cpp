//이진수로 읽기 예제
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

int main() {
	ifstream in("test.txt", ios::binary);
	// 위와 같이 ifstream 객체를 생성할 때 생성자에 
	// 옵션으로 binary 형태로 받겠다고 명시할 수 있다.
	// 이 말은 문자열 데이터를 받는게 아니라 그냥
	// 이진 그대로의 값을 받아내겠다는 의미이다.

	string s;

	int x;

	if (in.is_open()) {
		in.read((char*)(&x), 4);
		// read 함수는 말 그대로, 4 바이트의 내용을 
		// 읽으라는 의미로, 첫 번째 인자에 해당하는 
		// 버퍼를 전달해주어야 합니다. 우리의 경우 
		// int 변수를 마치 4 바이트 짜리 char 배열이라
		// 생각하게 해서이를 전달하였습니다. 
		// 두 번째 인자로 반드시 몇 바이트를 읽을 지
		// 전달해야 합니다.

		cout << hex << x << endl;
	}
	else
	{
		cout << "파일을 찾을 수 없습니다." << endl;
	}

	return 0;
}