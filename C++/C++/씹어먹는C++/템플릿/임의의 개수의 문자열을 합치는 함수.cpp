#include<iostream>
#include<string>

using namespace std;

template <typename String>
string StrCat(const String& s)
{
	return string(s);
}

template<typename String, typename...Strings>
string StrCat(const String& s, Strings...strs)
{
	return string(s) + StrCat(strs...);
}



int main() 
{
	cout << StrCat(string("this"), " ", "is", " ", string("a"),
		" ", string("sentence")) << endl;

	return 0;
}