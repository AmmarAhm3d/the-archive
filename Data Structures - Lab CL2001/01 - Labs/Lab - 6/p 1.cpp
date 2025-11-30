#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int* temp = new int[r-l+1];
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= m)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    int ind = 0;
    for (int i = l; i <= m; i++)
        arr[i] = temp[ind++];
    for (int j = m + 1; j <= r; j++)
        arr[j] = temp[ind++];


    temp = nullptr;
    delete[] temp;
}

void msort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        msort(arr, start, mid);
        msort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

template <class T> 
const T& MIN(const T& a, const T& b) {
    return !(b < a) ? a : b;    
}

int main() {
	
	int n, m;
	cin >> m;
	n = m * 2;

	int* a = new int[n];
	for (int i = 0; i < n; i++) 
		cin >> a[i];
    msort(a, 0, n-1);
    
    int ans = 0;
    for (int i = 0; i < n; i += 2) 
        ans += MIN(a[i], a[i + 1]);
    
    cout << ans;

	return 0;
}