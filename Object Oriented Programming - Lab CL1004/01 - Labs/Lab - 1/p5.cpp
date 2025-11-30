#include <iostream>
using namespace std;

int stringlength(char* p) {
	int size = 0;
	while (p[size] != '\0')
		++size;
	return size;
}

int stringvowel(char* p) {
	int count = 0;
	for (int i = 0; i < stringlength(p); i++) {
		if (p[i] == 'a' || p[i] == 'A')
			++count;
		else if (p[i] == 'e' || p[i] == 'E')
			++count;
		else if (p[i] == 'i' || p[i] == 'I')
			++count;
		else if (p[i] == 'o' || p[i] == 'O')
			++count;
		else if (p[i] == 'u' || p[i] == 'U')
			++count;
	}
	return count;
}

int main()
{
	char arr[20];
	char* p = arr;

	cout << "Please enter string: ";
	cin.getline(arr, 20);

	cout << "String Length: " << stringlength(p) << endl;
	cout << "Vowel: " << stringvowel(p);

	return 0;
}