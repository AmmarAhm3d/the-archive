#include <iostream>
#include <fstream>      // file reading
#include <cassert>      // assert
using namespace std;

template <typename k, typename v>
class MinHeap {
	//each item in heap will be HeapItem (a <key, value> pair). Both key and value can be of the same datatype or different data type.
	// Key and value can be of a user-defined class as well. If key is of non-primitive datatype, then the > and < operators must be overloaded.
	struct HeapItem {
		k key{};
		v value;
	};

	HeapItem* arr;
	int capacity;
	int totalitems;

	void cap2(){
		if (arr == nullptr){
			arr = new HeapItem[1];
			capacity = 1;
			return;
		}

		capacity *= 2;
		auto* newArr = new HeapItem[capacity];

		for (int i = 0; i < totalitems; i++)
		    newArr[i] = arr[i];

		if (arr != nullptr)
			delete[] arr;
		arr = newArr;
	}

	void siftUp(int pos){
		if (pos < 1)
			return;

		int getparent = (pos - 1) / 2;

		if (arr[pos].key < arr[getparent].key) {
			swap(arr[pos], arr[getparent]);
            siftUp(getparent);
		}

		return;
	}

	void siftDown(int pos){
		int chk = -1;
		int getleftchildof = pos * 2 + 1;
		int getrightchildof = (pos * 2) + 2;

		if (getleftchildof < totalitems)
			if (arr[pos].key > arr[getleftchildof].key)
                chk = getleftchildof;

		if (getrightchildof < totalitems)
			if (arr[(chk == -1 ? pos : chk)].key > arr[getrightchildof].key)
			    chk = getrightchildof;

		if (chk == -1)
			return;

		swap(arr[pos], arr[chk]);
        siftDown(chk);
	}

public:
	MinHeap(){
		arr = nullptr;
		capacity = 0;
		totalitems = 0;
	}

	explicit MinHeap(int _capacity){
		assert(_capacity >= 1);

        capacity = _capacity;
        totalitems = 0;
		arr = new HeapItem[_capacity];
	}

	void insert(k const key, v const value){
		if (totalitems == capacity)
            cap2();

		arr[totalitems].key = key;
		arr[totalitems].value = value;

        siftUp(totalitems);
		totalitems++;
	}

	void getMin(v& value){
		assert(totalitems != 0);

		value = arr[0].value;
	}

	void deleteMin() {
		assert(totalitems != 0);

		swap(arr[0], arr[totalitems - 1]);
		totalitems--;
		//shift down
        siftDown(0);
	}

	bool isEmpty() const { return (totalitems == 0);}

	~MinHeap(){
        if (arr != nullptr){
            delete[]arr;
            arr = nullptr;
            capacity = 0;
            totalitems = 0;
        }
	}
};

class Student { 
	int rollNumber{};
	string name; 
	float cgpa{};
public:
    // setters
    void setr(int roll) { this->rollNumber = roll; }
    void setn(string n) { this->name = n; }
    void setc(float c) { this->cgpa = c; }
    // overloaded operator
    friend ostream& operator<<(ostream& out, const Student& s){ out<<s.rollNumber<<" "<<s.name<<" "<<s.cgpa; return out;}

};

void buildStudentHeap(const string& fileName, MinHeap<int, Student>& stdHeap) {
    fstream fin(fileName, ios::in);
    if (!fin) { cout << "invalid file "; return; }

    string line,name;
    int sSize;

    fin >> sSize;                 // read count of students
    getline(fin, line);   // skip first line
        Student* s = new Student[sSize];
    for (int i = 0; i < sSize; i++) {

        int roll; float cgpa;
         // extraction of:
        //    roll    name    cgpa
        fin >> roll >> name >> cgpa;

        s[i].setr(roll); s[i].setn(name); s[i].setc(cgpa);
        stdHeap.insert(roll, s[i]);
    }
    fin.close();
}

// Run the following main program
int main()
{
    MinHeap<int, Student> stdHeap;
    buildStudentHeap("students.txt", stdHeap);
    while (!stdHeap.isEmpty())
    {
        Student s;
        stdHeap.getMin(s);
        cout << s <<endl<<endl;
        stdHeap.deleteMin();
    }
    system("pause");
}