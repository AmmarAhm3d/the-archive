#include <iostream>
#include "header.h"
using namespace std;

int main() {
	cout << "size: ";
	int n = 0;	cin >> n;
	int *arr = new int[n];
	cout << "values: ";

	for (int i = 0; i < n; i++) 
		cin >> arr[i];
    
	cout<<"Largest: " << largestNumber(n, arr)<<endl;
	bool sorted = issorted(n, arr);

	if (sorted) 
		cout << "Array is Sorted\n";
	else 
		cout << "Array is not Sorted\n";
	
	return 0;
}