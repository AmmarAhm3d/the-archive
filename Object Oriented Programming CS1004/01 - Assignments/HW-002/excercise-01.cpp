// 20L-0961      Ammar Ahmed     HW-002, Excercise 01 //
#include <iostream>
#include <cstring>
using namespace std;

char* init(int size) {
	char* p = new char[size];
	return p;
}


// I have examined both sending oversized array and suitably sized one
// for example with size 5 for "ammar" i get "ramma"
// and for size 10 or a huge buffer i get "════ramma"
// is there a reason for this ?
void reverse(char* in, int size) {
	for (int i = size-1; i >= 0; i--)
		cout << *(in + i);

}

int main()
{
	cout << "Enter size of cstring \n";
	int getSize; cin >> getSize;
	char* str = init(getSize);

	cout << "Enter string \n"; 
	cin >> str;
	cout << "Before change \"" << str << "\"\n";
	cout << "After change \"";
	reverse(str, getSize);
	cout << "\"";


	return 0;
}