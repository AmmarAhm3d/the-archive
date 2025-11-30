#include <iostream>
using namespace std;

template<typename T>
class singlyLinkedList;

template<typename T>
struct Node
{
	T data;
	Node<T>* next;
	friend class singlyLinkedList<T>;
public:
	Node<T>() {
		this->next = NULL;
	}
};

template<typename T>
class singlyLinkedList {
	Node<T>* head;
public:
	singlyLinkedList() {
		head = nullptr;
	}

	//Insert at start 
	void insertAtHead(T const element) {
		Node<T>* new_node = new Node<T>;
		new_node->data = element;
		new_node->next = head;
		head = new_node;
	}

	//Insert at end 
	void insertAtTail(T const element) {
		Node<T>* new_node = new Node<T>;
		new_node->data = element;
		new_node->next = NULL;
		Node<T>* prev = 0, * curr = head;
		while (curr != NULL) {
			prev = curr; curr = curr->next;
		}
		// if the element is first
		if (prev == 0) {
			head = new_node;
		}
		else {
			prev->next = new_node;
		}
	}

	//Print 
	void print() const {
		Node<T>* curr = head;
		do {
			cout << curr->data << "->";
			curr = curr->next;
		} while (curr != NULL);
		cout << endl;
	}
	//Delete at Start 
	void deleteAtStart() {
		if (head == NULL)
			;
		else {
			Node<T>* curr = head;
			head = curr->next;
			delete curr;
			curr = 0;
		}
	}
	//Delete at End 
	void deleteAtEnd() {
		if (head == 0) {
			cout << "List is empty\n";
		}
		else {
			Node<T>* curr = head, * last = 0, * secondLast = 0;
			while (curr != NULL) {
				secondLast = last;
				last = curr;
				curr = curr->next;
			}
			if (secondLast == 0) {
				head = NULL;
				delete	last;
				last = 0;
			}
			else {
				secondLast->next = NULL;
				delete last;
				last = 0;
			}
		}
	}

	void insertSorted(T const val)
	{
		Node<T>* temp = new Node<T>;
		temp->data = val;
		Node<T>* curr = head, * prev = 0;
		while (curr != NULL && curr->data < val)
		{
			prev = curr;
			curr = curr->next;
		}
		if (prev == 0)
		{
			head = temp;
		}
		else
		{
			prev->next = temp;
		}
		temp->next = curr;
		cout << "Element is inserted in Sorted Linked List...!\n";
	}

	void printNth(int index) {
		int length = 0;
		Node<T>* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
			length++;
		}

		if (index > length)
			return;
		else
		{
			temp = head;
			for (int i = 1; i < length - index + 1; i++) 
				temp = temp->next;
			
			cout << temp->data << endl;
			return;
		}

	}

	//Distructor
	~singlyLinkedList() {
		while (head != NULL) {
			Node<T>* curr = head;
			head = curr->next;
			delete curr;
			curr = head;
		}
	}
};

int main()
{
	singlyLinkedList<int> l1;
	l1.insertSorted(4);
	l1.insertSorted(3);
	l1.print();

	l1.printNth(2);
	
	return 0;
}