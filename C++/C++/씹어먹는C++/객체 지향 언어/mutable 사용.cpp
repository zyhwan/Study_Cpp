#include <iostream>

using namespace std;

class A {
    mutable int data_;

public:
    A(int data) : data_(data) {}
    void DoSomething(int x) const {
        data_ = x;  // °¡´É!
    }

    void PrintData() const { cout << "data: " << data_ << endl; }
};

int main() {
    A a(10);
    a.DoSomething(3);
    a.PrintData();
}