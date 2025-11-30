#include <iostream>
using namespace std;
class Node
{
	Node* DATA;
	int data;
	friend class Stack;
};
class Stack
{
	Node* top;
public:
	Stack()
	{
		top = nullptr;
	}
	void sort()
	{
		Node* curr = top;
		int co = 0;
		while (curr != NULL)
		{
			co++;
			curr = curr->DATA;
		}
		int* array = new int[co];
		int j = 0;
		for (Node* i = top; i != NULL; i = i->DATA)
		{
			array[j] = i->data;
			j++;
		}
		mergeSort(array, 0, co - 1);
		cout << endl;
		Node* temp = top;
		for (int i = 0; i < co; i++)
		{
			temp->data = array[i];
			temp = temp->DATA;
		}
	}
	void mergeSort(int*& arr, int start, int end)
	{
		if (start < end)
		{
			int mid = (start +	end) / 2;
			mergeSort(arr, start, mid);
			mergeSort(arr, mid + 1, end);
			merge(arr, start, mid, mid + 1, end);
		}
	}
	void merge(int*& array, int s, int mid, int Nmid, int end)
	{
		int* tempor = new int[Nmid - s + 1];
		int i = s, j = Nmid, k = 0;
		while (i <= mid && j <= end)
		{
			if (array[i] < array[j])
			{
				tempor[k] = array[i];
				i++;
			}
			else
			{
				tempor[k] = array[j];
				j++;
			}
			k++;
		}
		while (i <= mid)
		{
			tempor[k] = array[i];
			i++;
			k++;
		}
		while (j <= end)
		{
			tempor[k] = array[j];
			j++;
			k++;
		}
		int counter = 0;
		for (int start = s; start <= end; start++)
		{
			array[start] = tempor[counter];
			counter++;
		}
	}
	void display()
	{
		Node* temp = top;
		while (temp != NULL)
		{
			cout << temp->data << "->";
			temp = temp->DATA;
		}
		cout << endl;
	}
	void push(int d)
	{
		Node* temp = new Node;
		temp->DATA = top;
		temp->data = d;
		top = temp;
	}
};
int main()
{
	Stack obj;
	obj.push(5);
	obj.push(53);
	obj.push(25);
	obj.push(6);
	obj.push(85);
	obj.display();
	obj.sort();
	obj.display();
}