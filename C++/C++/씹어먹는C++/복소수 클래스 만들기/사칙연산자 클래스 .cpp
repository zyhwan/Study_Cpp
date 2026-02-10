#include <iostream>

using namespace std;

class Complex {
private:
	double real, img;

public:
	Complex(double real, double img) : real(real), img(img) {}

	/*Complex plus(const Complex& c);
	Complex minus(const Complex& c);
	Complex times(const Complex& c);
	Complex divide(const Complex& c);
	이와 같이 구성하면 a.plus(b.divide(c)).plus(d); == a + b / c + d;
	이 간단한 연산도 가독성이 떨어지게 된다. 그래서 연산자 오버로딩을 사용해보자*/
	
	Complex operator+(const Complex& c) const;
	Complex operator-(const Complex& c) const;
	Complex operator*(const Complex& c) const;
	Complex operator/(const Complex& c) const;

	void println() { cout << "(" << real << " , " << img << " )" << endl; }
};

Complex Complex::operator+(const Complex& c) const
{
	Complex temp(real + c.real, img + c.img);
	return temp;
}

Complex Complex::operator-(const Complex& c) const
{
	Complex temp(real - c.real, img - c.img);
	return temp;
}

Complex Complex::operator*(const Complex& c) const
{
	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
	return temp;
}

Complex Complex::operator/(const Complex& c) const {
	Complex temp(
		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return temp;
}

int main() {
	Complex a(1.0, 2.0);
	Complex b(3.0, -2.0);

	Complex c = a * b;

	c.println();
}