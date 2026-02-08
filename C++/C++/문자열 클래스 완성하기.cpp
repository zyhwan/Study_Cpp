#include <iostream>
#include <string>

using namespace std;

class String {
	char* str;
	int len;
public:
	String(char c, int n); // 문자 c 가 n 개 있는 문자열로 정의
	String(const char* s);
	String(const String& s);
	~String();

	void Showstr();
	void add_string(const String& s);
	void copy_string(const String& s);
	int strlen();
};

String::String(char c, int n)
{
	cout << "생성자 호출!" << endl;
	len = n;
	str = new char[len + 1];
	for (int i = 0; i < len; ++i) {
		str[i] = c;
	}
	str[len] = '\0';

}

String::String(const char* s)
{
	cout << "생성자 호출!" << endl;
	len = 0;
	const char* temp = s;

	while (*temp != '\0') {
		len++;
		s++;
	}

	str = new char[len + 1];
	for (int i = 0; i < len; ++i) {
		str[i] = s[i];
	}
	str[len] = '\0';
}

String::String(const String& s)
{
	cout << "복사 생성자 호출!" << endl;
	str = nullptr;
	copy_string(s);
}

String::~String()
{
	cout << "소멸자 호출!" << endl;
	if (str) delete[] str;
}

void String::Showstr()
{
	cout << str << endl;
}

void String::add_string(const String& s)
{
	char* temp = new char[s.len + len + 1];
	for (int i = 0; i < len; i++)
	{
		temp[i] = str[i];
	}
	for (int i = 0; i < s.len; i++)
	{
		temp[i + len] = s.str[i];
	}
	temp[len + s.len] = '\0';

	delete[] str;
	str = temp;
	len += s.len;
}

void String::copy_string(const String& s)
{
	if (str) delete[]str;
	len = s.len;
	str = new char[len + 1];
	for (int i = 0; i < len; ++i) {
		str[i] = s.str[i];
	}
	str[len] = '\0';
}

int String::strlen()
{
	return len;
}

int main() {
	String str('s', 10);
	str.Showstr();
	String str1(str);
	str1.Showstr();
	str1.add_string(str);
	str1.Showstr();
}