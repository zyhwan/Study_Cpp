//기존 10진수에서 16진수를 받는 cin으로 초기화 하기 예제

#include <string>
#include <iostream>

int main() {
    int t;
    while (true) {
        // setf 함수의 버전은 2 개가 있는데, 하나는 인자를 1 개만 받는 것이고, 
        // 다른 하나는 위 처럼 인자를 2개 취하는 것입니다.인자 1 개를 받는 
        // setf 는 그냥 인자로 준 형식 플래그를 적용하는 것이지만, 2 개 취하는 것은, 
        // 두 번째 인자(위에서 basefield) 의 내용을 초기화 하고, 첫 번째 인자(hex) 를 적용하는 것입니다.
        std::cin.setf(std::ios_base::hex, std::ios_base::basefield);



        std::cin >> t;
        std::cout << "입력 :: " << t << std::endl;
        if (std::cin.fail()) {
            std::cout << "제대로 입력해주세요" << std::endl;
            std::cin.clear();  
            // 플래그들을 초기화 하고
            // std::cin.ignore(100,'n');//개행문자가 나올 때까지
            // 무시한다
        }
        if (t == 0) break;
    }
}

//실행 결과
//ff
//입력 :: 255
//0xFF
//입력 :: 255
//123
//입력 :: 291
//ABCDE
//입력 :: 703710