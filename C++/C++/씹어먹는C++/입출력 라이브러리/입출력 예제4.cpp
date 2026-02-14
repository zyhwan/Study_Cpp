// 조작자의 사용
#include <iostream>
#include <string>

int main() {
    int t;
    while (true) {
        std::cin >> std::hex >> t;
        // 바로 위에서 hex 가 cin 에서 수를 받는 방식을 바꿔버렸기 때문입니다. 
        // 이 때문에 hex 와 같이, 스트림을 조작하여 입력 혹은 출력 방식을 
        // 바꿔주는 함수를 조작자라고 부릅니다 (그렇습니다! hex 는 함수 입니다).
        // 참고로, 예제3에서 사용하였던 형식 플래그 hex 와 이 hex 는 이름만 같지 
        // 아예 다른 것입니다. (그렇기에, 위에서는 ios_base::hex 로 사용하였죠)
        std::cout << "입력 :: " << t << std::endl;
        if (std::cin.fail()) {
            std::cout << "제대로 입력해주세요" << std::endl;
            std::cin.clear();           // 플래그들을 초기화 하고
            std::cin.ignore(100, 'n');  //개행문자가 나올 때까지 무시한다
        }
        if (t == 0) break;
    }
}