#include <iostream>
using namespace std;
	void putComma(int num)
	{
		if (num > 999)
		{
			putComma(num / 1000);
			cout <<(',');
			cout <<(num % 1000);
		}
		else
			cout <<num;
	}
	int main()
	{
		putComma(1234567);
	}
