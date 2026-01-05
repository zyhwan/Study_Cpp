#include<iostream>

using namespace std;

class Rectangle 
{
private:
	int low;
	int cols;
public:
	Rectangle(int n1, int n2) : low(n1), cols(n2)
	{

	}
	void ShowAreaInfo() {
		cout << "¸éÀû: " << low * cols << endl;
	}
};

class Square : public Rectangle
{
public:
	Square(int n) : Rectangle(n, n)
	{

	}
};


int main() {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();

	return 0;
}