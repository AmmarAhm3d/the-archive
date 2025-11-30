#include <iostream>
using namespace std;

// I have tried my best at union and intersection problem, but to no avail, it will stop at a memory access violation
// Find my implementation and plz mark leniently

class singlyLinkedList;
struct Node
{
	int data;
	Node* next;
	friend class singlyLinkedList;
};

class singlyLinkedList {
	Node* head;
	// Check the presence of the data
	bool present(Node* head, int data) {
		Node* temp = head;
		while (temp != NULL) {
			if (temp->data == data)
				return 1;
			temp = temp->next;
		}
		return 0;
	}

public:
	singlyLinkedList() {
		head = nullptr;
	}

	//Insert at start 
	void insertAtHead(int const element) {
		Node* new_node = new Node;
		new_node->data = element;
		new_node->next = head;
		head = new_node;
	}

	//Insert at end 
	void insertAtTail(int const element) {
		Node* new_node = new Node;
		new_node->data = element;
		new_node->next = NULL;
		Node* prev = 0, * curr = head;
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
		Node* curr = head;
		do {
			cout << curr->data << "->";
			curr = curr->next;
		} while (curr != NULL);
		cout << endl;
	}
	//Delete at Start 
	void eraseAtHead() {
		if (head == NULL)
			;
		else {
			Node* curr = head;
			head = curr->next;
			delete curr;
			curr = 0;
		}
	}
	//Delete at End 
	void eraseAtTail() {
		if (head == 0) {
			cout << "List is empty\n";
		}
		else {
			Node* curr = head, * last = 0, * secondLast = 0;
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

	//Distructor
	~singlyLinkedList() {
		while (head != NULL) {
			Node* curr = head;
			head = curr->next;
			delete curr;
			curr = head;
		}
	}

	friend void UNION(singlyLinkedList A, singlyLinkedList B);
	friend void INTERSECTION(singlyLinkedList A, singlyLinkedList B);


};

void UNION(singlyLinkedList A, singlyLinkedList B) {
	singlyLinkedList res;
	Node* headA = A.head, * headB = B.head, * headRes = res.head;

	// Copy all to result list
	do {
		res.insertAtTail(headA->data);
		headA = headA->next;
	} while (headA != NULL);
	res.print();
	do {
		if (!(res.present(headRes, headB->data))) {
			res.insertAtTail(headB->data);
			headB = headB->next;
		}
			headRes = headRes->next;

	} while (headB != NULL );
	res.print();
}

void INTERSECTION(singlyLinkedList A, singlyLinkedList B) {
	singlyLinkedList res;
	Node* headA = A.head, *headB =B.head;

	while (headA != NULL) {
		if (headB->data == headA->data)
			res.insertAtTail(headA->data);
		headA = headA->next;
		headB = headB->next;
	}

	res.print();
}

int main()
{
	//1. Make a link list A that has 5 elements. (e.g 4->1->5->8->3)
	singlyLinkedList A; A.insertAtTail(4);
						A.insertAtTail(1);
						A.insertAtTail(5);
						A.insertAtTail(8);
						A.insertAtTail(3);

	//2. Make a link list B that have 10 elements(e.g 4->6->1->8->5->10->2->7->3->9)
	singlyLinkedList B; B.insertAtTail(4);
						B.insertAtTail(6);
						B.insertAtTail(1);
						B.insertAtTail(8);
						B.insertAtTail(5);
						B.insertAtTail(10);
						B.insertAtTail(2);
						B.insertAtTail(7);
						B.insertAtTail(3);
						B.insertAtTail(9);

	//3. Make a function Union that takes two arguments link list A and link list B and return a new
	//	link list C that is union of link list A and B
	//UNION(A, B);

	//4. Make a function Intersection that takes two argument link list A and link list B and return a
	//	new link list C that is intersection of link list A and B
						INTERSECTION(A, B);
	//5. Make a function sortedlinklist that insert element in link list in sorted order

	return 0;
}