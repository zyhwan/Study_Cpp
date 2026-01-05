#include <iostream>
#include <cstring>

using namespace std;

class Book {
private:
	char* title; //책의 제목
	char* isbn;  //국제표준 도서 번호
	int price;   //책의 정가
public:
	Book(const char* t, const char* i, const int p) : price(p)
	{
		this->title = new char[strlen(t) + 1];
		this->isbn = new char[strlen(i) + 1];
		strcpy(this->title, t);
		strcpy(this->isbn, i);
	}
	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	~Book() {
		delete[] this->title;
		delete[] this->isbn;
	}

};

class EBook : public Book {
private:
	char* DRMKey; //보안 관련 키
public:
	EBook(const char* t, const char* i, const int p, const char* d) : Book(t, i, p)
	{
		this->DRMKey = new char[strlen(d) + 1];
		strcpy(this->DRMKey, d);
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	~EBook() {
		delete[] this->DRMKey;
	}

};


int main() {
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;

	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 20000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();

	return 0;
}


// 생성자 매개변수 타입이 char*인데, 넘기는 값은 문자열 리터럴이라서 타입이 const char[]이기 때문에
// "좋은 C++" 같은 문자열 리터럴은 **수정 불가능한 메모리(읽기 전용)**에 있고, 
// C++에서는 타입이 const char[N] → 전달 시 const char*로 취급된다.
// 그래서 문자열 그대로를 넘겨줄때 const 를 char형 앞에 붙여야한다. char는 예외적으로 그렇다.