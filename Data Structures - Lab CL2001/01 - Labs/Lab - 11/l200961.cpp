#include<iostream>
using namespace std;
class Heap
{
	int maxSize, currSize;
	int* h = 0;
public:
	Heap(int n = 10)
	{
		maxSize = n;
		currSize = 0;
		h = new int[maxSize];
	}
	~Heap()
	{
		if (h != 0)
		{
			delete[] h;
			h = 0;
		}
	}

	void heapify(int i)
	{
		int left, right, largest;
		while (1)
		{
			left = 2 * i, right = 2 * i + 1, largest = i;
			if (left <= currSize && h[left] > h[largest])
				largest = left;
			if (right <= currSize && h[right] > h[largest])
				largest = right;
			if (largest == i)
				break;
			else
			{
				swap(h[i], h[largest]);
				i = largest;
			}
		}
	}

	void buildHeap(int* a, int n)
	{
		if (h != 0)
		{
			delete[] h;
			h = 0;
		}
		h = new int[n + 1];
		maxSize = n;
		for (int i = 0; i < n; i++)
		{
			h[i + 1] = a[i];
		}
		currSize = n;
		for (int i = currSize / 2; i >= 1; i--)
		{
			heapify(i);
		}
	}
	void display()
	{
		for (int i = 0; i < currSize; i++)
		{
			cout << h[i + 1] << " ";
		}
	}
	void removeMax(int & a)
	{
		a = h[1];
		h[1] = h[currSize];
		currSize--;
		heapify(1);
	}

	

};
void heapSort(int* a, int n)
{
	Heap mh;
	mh.buildHeap(a, n);
	for (int i = n - 1; i >= 0; i--)
	{
		mh.removeMax(a[i]);
	}
}
void insert(int*& arr,int in, int index){
	arr[index++] = in;
}
int main()
{
	int a[] = { 14, 19, 42, 33, 26, 31, 27, 44, 35, 10 };

	heapSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}