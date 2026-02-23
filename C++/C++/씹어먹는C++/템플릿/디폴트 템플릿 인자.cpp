#include <iostream>
#include <string>

template <typename T>
struct Compare {
    bool operator()(const T& a, const T& b) const { return a < b; }
};

// 템플릿 디폴트 인자는 함수 디폴트 인자랑 똑같이 인자 
// 뒤에 = (디폴트 값) 을 넣어주면 됩니다.
template <typename T, typename Comp = Compare<T>>
T Min(T a, T b) {
    Comp comp;
    if (comp(a, b)) {
        return a;
    }
    return b;
}

int main() {
    int a = 3, b = 5;
    std::cout << "Min " << a << " , " << b << " :: " << Min(a, b) << std::endl;

    std::string s1 = "abc", s2 = "def";
    std::cout << "Min " << s1 << " , " << s2 << " :: " << Min(s1, s2)
        << std::endl;
}