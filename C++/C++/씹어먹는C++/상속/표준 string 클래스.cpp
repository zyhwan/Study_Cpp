#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	// 표준이므로 std 안에string 이 정의되어 있습니다.
	string s = "abc";
	string t = "def";
	string s2 = s;

	cout << s << "의 길이 : " << s.length() << endl;
	cout << s << "뒤에 " << t << "를 붙이면 : " << s + t << endl;

	if (s == s2) {
		cout << s << "와 " << s2 << "는 같다." << endl;
	}
	if (s != t) {
		cout << s << "와 " << t << "는 다르다." << endl;
	}

	return 0;
}