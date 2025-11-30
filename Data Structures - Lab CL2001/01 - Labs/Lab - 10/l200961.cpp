#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
    int* arr;
    int capacity;
    int size;

    bool isHeap(int* _arr, int i, int n) {
        // If (2 * i) + 1 >= n, then leaf node, so return true
        if (i >= (n - 1) / 2)
            return true;

        // If an internal node and is
        // greater than its children,
        // and same is recursively
        // true for the children
        int l = leftChild(i), r= rightChild(i);
        if (arr[i] >= arr[l] &&
        arr[i] >= arr[r]&&
        isHeap(arr, l, n)&&
        isHeap(arr, r, n))
            return true;

        return false;
    }
    // Returns position of parent
    int parent(int pos) { return pos / 2; }
    // Below two functions return left and
    // right children.
    int leftChild(int pos) { return (2 * pos); }
    int rightChild(int pos) { return (2 * pos) + 1; }




    void cap2() {
        if (arr == nullptr) {
            arr = new int[1];
            capacity = 1;
            return;
        }

        capacity *= 2;
        int* newArr = new int[capacity];

        for (int i = 0; i < size; i++)
            newArr[i] = arr[i];

        if (arr != nullptr)
            delete[] arr;
        arr = newArr;
    }
    void _swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
public:

    MaxHeap() {
        arr = nullptr;
        capacity = 0;
        size = 0;
    }
    MaxHeap(int _capacity) {
        arr = new int[_capacity + 1];
        capacity = _capacity;
        size = 0;
    }
    bool isMaxHeap() {
        isHeap(arr, 0, size);
    }
    void Heapify() {
        int current = size - 1;
        int p = parent(current - 1);
        while (current > 0 && arr[current] > arr[p]) {
            int swap = arr[p];
            arr[p] = arr[current];
            arr[current] = swap;
            current = p;
            p = parent(current - 1);
        }
    }
    void insert(int value) {
        if (size == capacity)
            cap2();
        int iinsert = size + 1;
        arr[iinsert] = value;

        // sift-up: move the element up to the right place
        int iCurrent = iinsert;
        while ((iCurrent > 1) && (arr [parent(iCurrent)] < arr[iCurrent])){
            _swap(arr[parent(iCurrent)], arr[iCurrent]);
            iCurrent = parent(iCurrent);
        } size++;
    }
    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }	cout << endl;
    }
    int getMax() {
        return arr[1];
    }
    int getKthMax(int k) {
        k--;
        for (int i = 2; i < size; i++) {
            if (arr[1] < arr[i]) {
                k--;
                if (k == 0)
                    return arr[i];
            }
        }
    }

    void MergeHeaps(const MaxHeap& a, const MaxHeap& b){
        int asize = a.size, bsize = b.size;
        MaxHeap merge(asize + bsize);
        // traditional copy into merge's array
        for (int i = 0; i < asize; i++)
            merge.arr[i] = a.arr[i];
        for (int i = 0; i < bsize; i++)
            merge.arr[bsize + i] = b.arr[i];

        // build heap
        merge.Heapify();
        // print heap
        merge.print();
    }
    ~MaxHeap() {
        delete[] arr;
        arr = nullptr;
    }
};

int main()
{
    MaxHeap h(10);
    h.insert(5);    h.insert(3);    h.insert(9);    h.insert(1);    h.insert(7);    h.insert(6);
    h.Heapify();
    h.print();
    cout<<"\n"<<h.getMax();
    cout<<"\n"<<h.getKthMax(4);

    return 0;
}