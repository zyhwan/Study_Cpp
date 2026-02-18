//템플릿 첫 활용
#include<iostream>
#include<string>

using namespace std;

//정의되는 클래스에 대해 템플릿을 정의. 템플릿 인자로 T를 받게되며, T는 반드시
//어떠한 타입의 이름임을 명시하고 있다. 간혹, template<class T>라고 쓰는 경우가
//있는데 <typename T>와 동일한 의미이다.
template<typename T>
class Vector {
    T* data;
    int capacity;
    int length;

public:
    // 생성자
    Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(T s) {
        if (capacity <= length) {
            T* temp = new T[capacity * 2];
            for (int i = 0; i < length; i++) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }

    //임의의 위치'i'의 접근 
    T operator[](int i) { return data[i]; }

    //x 번째 위치한 원소를 제거.
    void remove(int x) {
        for (int i = x + 1; i < length; ++i) {
            data[i - 1] = data[i];
        }
        length--;
    }

    int size() { return length; }
    
    ~Vector() {
        if (data) {
            delete[] data;
        }
    }


};



int main()
{
    // int 를 보관하는 벡터를 만든다. 정의한 템플릿의 인자에 앖을 전달하기 위해서는
    // Vector<int> int_vec;와 같이 <>안에 전달하려는 것을 명시해야한다. 템플릿
    // 인자로 타입을 받게 되는데, T에 int 가 전달된다.

    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(2);

    cout << "-------- int vector ----------" << endl;
    cout << "첫번째 원소 : " << int_vec[0] << endl;
    cout << "두번째 원소 : " << int_vec[1] << endl;

    Vector<string> str_vec;
    str_vec.push_back("hello");
    str_vec.push_back("world");
    cout << "-------- string vector -------" << endl;
    cout << "첫번째 원소 : " << str_vec[0] << endl;
    cout << "두번째 원소 : " << str_vec[1] << endl;
	return 0;
}
