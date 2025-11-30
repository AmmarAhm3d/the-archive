#include<iostream>
using namespace std;

template<class T>
bool compareTemp(T x, T y) {
	if (x != y)
		return false;
	return true;
}

template<class T>
bool compareTemp(T* x, T* y) {
	if (x == y)
		return true;
	return false;
}

template<>
bool compareTemp< const char* >(const char* x, const char* y) {
	if (strcmp(x, y) != 0)
		return false;
	return true;
}

int main(int argc, char const* argv[])
{
	int x = 'a', y = 97;
	char a = 'a', b = 'a';
	char* aptr = &a, * bptr = &b;
	string str1 = "String", str2 = "String";
	(compareTemp(x, y)) ? cout << "Integers are equal" : cout << "Integers are not e qual";
	cout << endl;
	(compareTemp(a, b)) ? cout << "Chars are equal" : cout << "Chars are not equal"; cout << endl;
	(compareTemp(aptr, bptr)) ? cout << "Pointers are equal" : cout << "Pointers are not equal";
	cout << endl;
	(compareTemp(str1, str2)) ? cout << "Strings are equal" : cout << "Strings are n ot equal";
	return 0;
}