//c++에서 close()를 사용하는 경우

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    // 파일 읽기 준비
    ifstream in("test.txt");
    string s;

    if (in.is_open()) {
        in >> s;
        cout << "입력 받은 문자열 :: " << s << endl;
    }
    else {
        cout << "파일을 찾을 수 없습니다!" << endl;
    }

    in.close();
    in.open("other.txt");
    // 위 처럼 새로운 파일에서 같은 객체가 입력을 받기 
    // 위해서는 기존 파일 스트림과의 연결을 종료하고, 
    // 새로운 파일과 연결을 시켜주면 됩니다. 기존 파일과의 
    // 스트림 종료는 close 함수가, 새로운 파일과의 연결은 
    // open 함수가 수행하고 있습니다. open 함수가 있기에 
    // 굳이 ifstream 객체 생성자에서 파일 경로를 바로 지정해줄 
    // 필요는 없고, 나중에 open 으로 원하는 파일을 열어도 상관없습니다.


    if (in.is_open()) {
        in >> s;
        cout << "입력 받은 문자열 :: " << s << endl;
    }
    else {
        cout << "파일을 찾을 수 없습니다!" << endl;
    }

    return 0;
}

