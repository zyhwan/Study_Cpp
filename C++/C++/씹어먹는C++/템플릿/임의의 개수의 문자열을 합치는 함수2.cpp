#include<iostream>
#include<string>

using namespace std;

size_t GetStringSize(const char* s) { return strlen(s); }

size_t GetStringSize(const string& s) { return s.size(); }

template<typename String, typename... Strings>