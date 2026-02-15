//파일에서의 입출력
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

int main() {
	//파일 읽기 준비
	ifstream in("test.txt");
	string s;
	if (in.is_open()) {
		in >> s; 
		// 마지막으로 마치 cin 을 사용 하는 것 처럼 in 객체를 
		// 이용해서 파일로 부터 읽을 수 있습니다. (cin 에서 >> 
		// 로 읽을 때 공백 문자가 나올 까지 읽었던 것처럼 여기도
		// 동일합니다)
		cout << "입력 받은 문자열 :: " << s << endl;
		//visual studio의 콘솔 출력 인코딩과 메모장 파일의 저장
		//방식을 같은 방식으로 맞춰야 출력했을 때 깨지지 않고 잘 나옴.

	}
	else
	{
		cout << "파일을 찾을 수 없습니다." << endl;
	}

	return 0;

}

